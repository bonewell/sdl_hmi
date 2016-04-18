#ifndef DBUSCONNECTOR_H
#define DBUSCONNECTOR_H

#include <QtDBus/QDBusAbstractAdaptor>

#include "core/privateinterface.h"

class QDBusInterface;

typedef QDBusAbstractAdaptor Adaptor;

#define ADAPTER_INFORMATION(Name, Introspection) \
    Q_CLASSINFO("D-Bus Interface", Name) \
    Q_CLASSINFO("D-Bus Introspection", Introspection)

class DBus : public PrivateInterface
{
public:
    DBus(QObject* item);
    virtual void init();
    virtual void connect(const QString& service, const QString& interface);
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature);
    virtual void setDelayedReply(Message& message);
    virtual void sendReply(Message& message, const QVariantList& output);
    virtual void sendError(Message& message, const QString& name, const QString& text);
    virtual Watcher* call(const QString& name, const QVariantList& input);
    virtual QObject* item() { return item_; }
private:
    QString service_name_;
    QString interface_name_;
    QObject *item_;
    QDBusInterface *interface_;
};
typedef DBus PrivateAdapter;

#endif // DBUSCONNECTOR_H
