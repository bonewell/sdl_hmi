#include "websocketconnector.h"

#include <QtQuick/QQuickItem>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonValue>

#include "websocket/inbox.h"
#include "websocket/websocketwatcher.h"

WebSocket::WebSocket(QObject *item, QObject *object) : item_(item), object_(object)
{
    socket_ = new QWebSocket();
    inbox_ = new Inbox();
    QObject::connect(socket_, &QWebSocket::binaryMessageReceived,
                     inbox_, &Inbox::received);
}

WebSocket::~WebSocket() {
    inbox_->disconnect();
    delete inbox_;
    socket_->close();
    delete socket_;
}

void WebSocket::init() {
}

void WebSocket::connect(const QString &service, const QString &interface)
{
    service_name_ = service;
    interface_name_ = interface;
    socket_->open(QUrl("ws://127.0.0.1:8087"));
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
