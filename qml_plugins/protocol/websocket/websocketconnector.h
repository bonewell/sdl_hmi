#ifndef WEBSOCKETCONNECTOR_H
#define WEBSOCKETCONNECTOR_H

#include "core/privateinterface.h"

#include <QObject>
#include <QMetaMethod>
#include <QMap>

#define ADAPTER_INFORMATION(Name, Introspection) // UNUSED

typedef QObject Adaptor;

class QWebSocket;
class QByteArray;

class WebSocket : public QObject, public PrivateInterface
{
    Q_OBJECT
public:
    WebSocket(QObject* item, QObject* object);
    virtual ~WebSocket();
    virtual void init(int uid, const QString& name);
    virtual void connect(const QString& service, const QString& interface);
    virtual void subscribe(QObject *adapter, const QMetaMethod& meta);
    virtual void setDelayedReply(Message& message);
    virtual void sendReply(Message& request, const Message& response);
    virtual void sendError(Message& request, const QString& name, const QString& text);
    virtual void sendSignal(const QString& name, const Message& message);
    virtual Watcher* call(const QString& name, const Message &request);
    virtual QObject* item() { return item_; }
private slots:
    void checkin();
    void received(const QString& data);
    void process(const QJsonObject& json);
private:
    typedef QPair<QObject*, QMetaMethod> Notification;
    typedef QMap<QString, Notification> SubscribeList;
    inline int generateId();
    inline QString name(const QMetaMethod &meta) const;
    inline bool isCheckinSuccess(const QJsonObject& json);
    inline bool isNotification(const QJsonObject& json) const;
    inline void emitSignal(const QJsonObject& json) const;
    inline bool invoke(const Notification& signal, const QJsonObject& json) const;
    void send(const QJsonObject& json);
    void doSubscribe();
    QString component_name_;
    QString service_name_;
    QString interface_name_;
    QObject *item_;
    QWebSocket *socket_;
    SubscribeList subscribes_;
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
