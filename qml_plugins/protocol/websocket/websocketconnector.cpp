#include "websocketconnector.h"

#include <QtQuick/QQuickItem>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QByteArray>
#include <QDebug>
#include <QMetaObject>

#include "core/slave.h"
#include "core/abstractadapter.h"
#include "websocket/websocketwatcher.h"

// TODO: maybe enums are strings

WebSocket::WebSocket(QObject *item, QObject *object) : QObject(object),
    item_(item), id_start_(-1), id_range_(1000), request_id_(-1),
    checkin_id_(-1), unckeckin_id_(-1)
{
    socket_ = new QWebSocket();
    QObject::connect(socket_, &QWebSocket::connected, this, &WebSocket::checkin);
    QObject::connect(socket_, &QWebSocket::textMessageReceived,
                     this, &WebSocket::received);
    QObject::connect(this, &WebSocket::jsonReceived, this, &WebSocket::process);
}

WebSocket::~WebSocket()
{
    socket_->close();
    delete socket_;
}

void WebSocket::init(int uid, const QString &name)
{
    id_start_ = uid;
    component_name_ = name.split(".").back();
}

void WebSocket::connect(const QString &service, const QString &interface)
{
    service_name_ = service;
    interface_name_ = interface.split(".").back();
    socket_->open(QUrl("ws://127.0.0.1:8087"));
}

void WebSocket::checkin()
{
    // Workaround: SmartDeviceLink has the same name of component
    QString name = (component_name_ == "SDL") ? "SDLHMI" : component_name_;
    checkin_id_ = id_start_;
    QJsonObject params
    {
        {"componentName", name}
    };
    QJsonObject msg
    {
        {"jsonrpc", "2.0"},
        {"id", checkin_id_},
        {"method", "MB.registerComponent"},
        {"params", params}
    };
    send(msg);
}

void WebSocket::subscribe(QObject* adapter, const QMetaMethod& meta)
{
    subscribes_[name(meta)] = qMakePair(adapter, meta);
}

void WebSocket::setDelayedReply(Message &message)
{
    Q_UNUSED(message);
}

void WebSocket::sendReply(Message &request, const Message &response)
{
    QJsonObject result(response.arguments());
    result["method"] = request.name();
    QJsonObject msg
    {
        {"jsonrpc", "2.0"},
        {"id", request.id()},
        {"result", result}
    };
    send(msg);
}

void WebSocket::sendError(Message &request, const QString &name, const QString &text)
{
    QJsonObject data
    {
        {"method", request.name()}
    };
    QJsonObject error
    {
        {"code", name},
        {"message", text},
        {"data", data}
    };
    QJsonObject msg
    {
        {"jsonrpc", "2.0"},
        {"id", request.id()},
        {"error", error}
    };
    send(msg);
}

void WebSocket::sendSignal(const QString &name, const Message &message)
{
    QJsonObject msg
    {
        {"jsonrpc", "2.0"},
        {"method", component_name_ + "." + name},
    };
    const QJsonObject& params = message.arguments();
    if (!params.empty()) {
        msg["params"] = params;
    }
    send(msg);
}

Watcher *WebSocket::call(const QString &name, const Message &request)
{
    return new WebSocketWatcher(name, request.arguments());
}

void WebSocket::received(const QString &data)
{
    qDebug() << "RECV: " << data;
    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(data.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Could not parse json string";
    } else if (!json.isObject()) {
        qWarning() << "Json is not object";
    } else {
        emit jsonReceived(json.object());
    }
}

void WebSocket::send(const QJsonObject &json)
{
    QByteArray data = QJsonDocument(json).toJson(QJsonDocument::Compact);
    qDebug() << "SEND: " << data;
    qint64 size = socket_->sendTextMessage(QString(data));
    if (size != data.size()) {
        qWarning() << "Message was sent no fully";
    }
}

void WebSocket::process(const QJsonObject &json)
{
    if (isCheckinSuccess(json)) {
        request_id_ = id_start_ = json["result"].toInt();
        doSubscribe();
    }
    if (isNotification(json)) {
        emitSignal(json);
    } else if (isResponse(json)) {

    } else if (isError(json)) {

    } else {
        invokeMethod(json);
    }

}

bool WebSocket::isCheckinSuccess(const QJsonObject &json)
{
    return json["id"].toInt() == checkin_id_ && !json.contains("method") &&
            json["result"].isDouble() && !json.contains("error");
}

bool WebSocket::isNotification(const QJsonObject &json) const
{
    return !json.contains("id");
}

bool WebSocket::isError(const QJsonObject &json) const
{
    return json.contains("error");
}

bool WebSocket::isResponse(const QJsonObject &json) const
{
    return json.contains("result");
}

void WebSocket::emitSignal(const QJsonObject &json) const
{
    QString name_notification = json["method"].toString();
    SubscribeList::ConstIterator i = subscribes_.find(name_notification);
    if (i != subscribes_.constEnd()) {
        const Notification& signal = i.value();
        if (!invoke(signal, json)) {
            qWarning() << "Could not process notification";
        }
    }
}

void WebSocket::invokeMethod(const QJsonObject &json) const
{
    int id = json["id"].toInt();
    QString name_method = json["method"].toString();
    Message request(id, name_method);
    QString n = name_method.split(".").last();
    adapter_->invoke(n, request).execute();
}

void WebSocket::doSubscribe()
{
    QMapIterator<QString, Notification> i(subscribes_);
    while (i.hasNext()) {
        QJsonObject params
        {
            {"propertyName", i.key() }
        };
        QJsonObject msg
        {
            {"jsonrpc", "2.0"},
            {"id", generateId()},
            {"method", "MB.subscribeTo"},
            {"params", params}
        };
        send(msg);
        i.next();
    }
}

QString WebSocket::name(const QMetaMethod& meta) const
{
    return interface_name_ + "." + QString::fromLatin1(meta.name());
}

int WebSocket::generateId()
{
    request_id_++;
    if (request_id_ >= id_start_ + id_range_) {
        request_id_ = id_start_;
    }
    return request_id_;
}

bool WebSocket::invoke(const Notification& signal, const QJsonObject& json) const
{
    const QMetaMethod& meta = signal.second;

    const int kMaxArgs = 10;
    QVector<QGenericArgument> args(kMaxArgs);

    if (json.contains("params")) {
        const QJsonObject& input = json.value("params").toObject();
        int i = 0;
        const QList<QByteArray>& params = meta.parameterNames();
        Message message;
        foreach (const QByteArray& name, params) {
            if (input.contains(name)) {
                args[i++] = Q_ARG(QVariant, input[name].toVariant());
            }
        }
    }

    QString name_signal = meta.name();
    name_signal[0] = name_signal[0].toLower();
    return QMetaObject::invokeMethod(item_, name_signal.toStdString().c_str(),
                       Qt::QueuedConnection, args[0],
                       args[1], args[2], args[3],
                       args[4], args[5], args[6],
                       args[7], args[8], args[9]);
}

void WebSocket::setAdapter(AbstractAdapter *adapter)
{
    adapter_ = adapter;
}
