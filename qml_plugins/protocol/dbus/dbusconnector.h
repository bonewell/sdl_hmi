#ifndef DBUSCONNECTOR_H
#define DBUSCONNECTOR_H

#include <QtDBus/QDBusAbstractAdaptor>

#include "core/privateinterface.h"

#define ADAPTER_INFORMATION(Name, Introspection) \
    Q_CLASSINFO("D-Bus Interface", Name) \
    Q_CLASSINFO("D-Bus Introspection", Introspection)

typedef QDBusAbstractAdaptor Adaptor;
typedef QList<QPair<QString, QVariant> > ArgumentsList;

class QDBusInterface;

class DBus : public PrivateInterface
{
public:
    DBus(QObject* item, QObject* object);
    virtual void init(int uid, const QString& name);
    virtual void connect(const QString& service, const QString& interface);
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature);
    virtual void setDelayedReply(Message& message);
    virtual void sendReply(Message& request, const Message &response);
    virtual void sendError(Message& request, const QString& name, const QString& text);
    virtual void sendSignal(const QString& name, const Message &message);
    virtual Watcher* call(const QString& name, const QVariantList& input);
    virtual QObject* item() { return item_; }
private:
    QString name_;
    QString service_name_;
    QString interface_name_;
    QObject *item_;
    QObject *object_;
    QDBusInterface *interface_;
};
typedef DBus PrivateAdapter;

#endif // DBUSCONNECTOR_H
