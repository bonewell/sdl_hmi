#ifndef WEBSOCKETCONNECTOR_H
#define WEBSOCKETCONNECTOR_H

#include "core/privateinterface.h"

#include <QObject>

class QWebSocket;
class QByteArray;

typedef QObject Adaptor;

#define ADAPTER_INFORMATION(Name, Introspection) // UNUSED

class WebSocket : public QObject, public PrivateInterface
{
    Q_OBJECT
public:
    WebSocket(QObject* item, QObject* object);
    virtual ~WebSocket();
    virtual void init(int uid, const QString& name);
    virtual void connect(const QString& service, const QString& interface);
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature);
    virtual void setDelayedReply(Message& message);
    virtual void sendReply(Message& message, const QVariantList& output);
    virtual void sendError(Message& message, const QString& name, const QString& text);
    virtual void sendSignal(const QString& name, const QVariantList& arguments);
    virtual Watcher* call(const QString& name, const QVariantList& input);
    virtual QObject* item() { return item_; }
private slots:
    void checkin();
    void received(const QString& data);
    void process(const QJsonObject& json);
private:
    inline bool isCheckinSuccess(const QJsonObject& json);
    inline int generateId();
    void send(const QJsonObject& json);
    void doSubscribe();
    QString component_name_;
    QString service_name_;
    QString interface_name_;
    QObject *item_;
    QObject *object_;
    QWebSocket *socket_;
    QStringList subscribes_;
    int id_start_;
    int id_range_;
    int request_id_;
    int checkin_id_;
    int unckeckin_id_;
signals:
    void jsonReceived(const QJsonObject& json);
};

typedef WebSocket PrivateAdapter;

#endif // WEBSOCKETCONNECTOR_H
