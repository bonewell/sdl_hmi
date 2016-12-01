#include "websocketconnector.h"

#include <QtQuick/QQuickItem>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonValue>
#include <QByteArray>
#include <QDebug>

#include "websocket/websocketwatcher.h"

WebSocket::WebSocket(QObject *item, QObject *object) : QObject(object),
    item_(item), object_(object), id_start_(-1), id_range_(1000), request_id_(-1),
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

void WebSocket::subscribe(const QString& name, QObject* adapter, const QString& signature)
{
    Q_UNUSED(adapter);
    Q_UNUSED(signature);
    subscribes_.append(interface_name_ + "." + name);
}

void WebSocket::setDelayedReply(Message &message)
{
}

void WebSocket::sendReply(Message &request, const Message &response)
{
    QByteArray data;// = QJsonDocument(message.toObject()).toJson();
    socket_->sendBinaryMessage(data);
}

void WebSocket::sendError(Message &request, const QString &name, const QString &text)
{
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
    qDebug() << data;
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
}

bool WebSocket::isCheckinSuccess(const QJsonObject &json)
{
    return json["id"].toInt() == checkin_id_ && !json.contains("method") &&
            json["result"].isDouble() && !json.contains("error");
}

void WebSocket::doSubscribe()
{
    foreach (const QString& name, subscribes_) {
        QJsonObject params
        {
            {"propertyName", name}
        };
        QJsonObject msg
        {
            {"jsonrpc", "2.0"},
            {"id", generateId()},
            {"method", "MB.subscribeTo"},
            {"params", params}
        };
        send(msg);
    }
}

int WebSocket::generateId()
{
    request_id_++;
    if (request_id_ >= id_start_ + id_range_) {
        request_id_ = id_start_;
    }
    return request_id_;
}
