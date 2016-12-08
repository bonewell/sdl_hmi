#ifndef DBUSCONNECTOR_H
#define DBUSCONNECTOR_H

#include <QtDBus/QDBusAbstractAdaptor>
#include <QMetaMethod>

#include "core/privateinterface.h"

#define ADAPTER_INFORMATION(Name, Introspection) \
    Q_CLASSINFO("D-Bus Interface", Name) \
    Q_CLASSINFO("D-Bus Introspection", Introspection)

typedef QDBusAbstractAdaptor Adaptor;

class QDBusInterface;
class QMetaMethod;
class QChar;

class DBus : public PrivateInterface
{
public:
    DBus(QObject* item, QObject* object);
    virtual void init(int uid, const QString& name);
    virtual void connect(const QString& service, const QString& interface);
    virtual void subscribe(QObject *adapter, const QMetaMethod& meta);
    virtual void setDelayedReply(Message& message);
    virtual void sendReply(Message& request, const Message &response);
    virtual void sendError(Message& request, const QString& name, const QString& text);
    virtual void sendSignal(const QString& name, const Message &message);
    virtual Watcher* call(const QString& name, const Message& request);
    virtual QObject* item() { return item_; }
private:
    inline QString createSlot(const QMetaMethod& meta);
    inline QChar methodType(QMetaMethod::MethodType type) const;
    QString name_;
    QString service_name_;
    QString interface_name_;
    QObject *item_;
    QObject *object_;
    QDBusInterface *interface_;
};
typedef DBus PrivateAdapter;

#endif // DBUSCONNECTOR_H
