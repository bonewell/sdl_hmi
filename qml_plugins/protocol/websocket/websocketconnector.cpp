#include "websocketconnector.h"

#include <QtQuick/QQuickItem>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonValue>

#include "websocket/websocketwatcher.h"

WebSocket::WebSocket(QObject *item, QObject *object) : item_(item), object_(object)
{
//    QObject::connect(socket_, &QWebSocket::binaryMessageReceived,
//                     this, &WebSocket::handleReceivedMessage);
}

void WebSocket::init() {
}

void WebSocket::connect(const QString &service, const QString &interface)
{
    service_name_ = service;
    interface_name_ = interface;
}

void WebSocket::subscribe(const QString& name, QObject* adapter, const QString& signature)
{
}

void WebSocket::setDelayedReply(Message &message)
{
}

void WebSocket::sendReply(Message &message, const QVariantList &output)
{
    QByteArray data;// = QJsonDocument(message.toObject()).toJson();
    socket_->sendBinaryMessage(data);
}

void WebSocket::sendError(Message &message, const QString &name, const QString &text)
{
}

Watcher *WebSocket::call(const QString &name, const QVariantList &input)
{
    return new WebSocketWatcher(name, input);
}

void WebSocket::handleReceivedMessage(const QByteArray &data)
{

}
