#ifndef DBUSCONNECTOR_H
#define DBUSCONNECTOR_H

#include <QtDBus/QDBusAbstractAdaptor>
#include <QMetaMethod>

#include "core/privateinterface.h"

#define DBUS_SERVICE com.ford.sdl.hmi

#define ADAPTER_NAME(Name) \
    Q_CLASSINFO("D-Bus Interface", DBUS_SERVICE)

#define ADAPTER_INTROSPECTION(Introspection) \
    Q_CLASSINFO("D-Bus Introspection", Introspection)

typedef QDBusAbstractAdaptor Adaptor;

class AbstractAdapter;
class QDBusInterface;
class QMetaMethod;
class QChar;

class DBus : public PrivateInterface
{
public:
    explicit DBus(QObject* object);
    virtual void setAdapter(AbstractAdapter* adapter);
    virtual void init(int uid, const QString& name);
    virtual void connect(const QString& service, const QString& interface);
    virtual void subscribe(QObject *adapter, const QMetaMethod& meta);
    virtual void setDelayedReply(Message& message);
    virtual void sendReply(Message& request, const Message &response);
    virtual void sendError(Message& request, const QString& name, const QString& text);
    virtual void sendSignal(const QString &nick, const Message &message);
    virtual Watcher* sendRequest(const QString &nick, const Message& request);
private:
    inline QString createSlot(const QMetaMethod& meta);
    inline QChar methodType(QMetaMethod::MethodType type) const;
    QString path_;
    QString name_;
    QString service_name_;
    QString interface_name_;
    QObject *object_;
    QDBusInterface *interface_;
};
typedef DBus PrivateAdapter;

#endif // DBUSCONNECTOR_H
