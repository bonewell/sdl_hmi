#ifndef WEBSOCKETCONNECTOR_H
#define WEBSOCKETCONNECTOR_H

#include "core/privateinterface.h"

class QWebSocket;

typedef QObject Adaptor;

#define ADAPTER_INFORMATION(Name, Introspection)

class WebSocket : public PrivateInterface
{
//    Q_OBJECT
public:
    WebSocket(QObject* item, QObject* object);
    virtual void init();
    virtual void connect(const QString& service, const QString& interface);
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature);
    virtual void setDelayedReply(Message& message);
    virtual void sendReply(Message& message, const QVariantList& output);
    virtual void sendError(Message& message, const QString& name, const QString& text);
    virtual Watcher* call(const QString& name, const QVariantList& input);
    virtual QObject* item() { return item_; }
//private slots:
    void handleReceivedMessage(const QByteArray& data);
private:
    QString service_name_;
    QString interface_name_;
    QObject *item_;
    QObject *object_;
    QWebSocket *socket_;
};

typedef WebSocket PrivateAdapter;

#endif // WEBSOCKETCONNECTOR_H
