#include "dbusconnector.h"

#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusPendingCall>
#include <QtDBus/QDBusPendingReply>
#include <QtQuick/QQuickItem>

#include "dbus/dbuswatcher.h"

DBus::DBus(QObject *item, QObject *object) : item_(item), object_(object),
    interface_(0)
{
}

void DBus::init(int uid, const QString& name) {
    Q_UNUSED(uid);
    name_ = name;
    QDBusConnection::sessionBus().registerObject("/", object_);
}

void DBus::connect(const QString &service, const QString &interface)
{
    service_name_ = service;
    interface_name_ = interface;
    interface_ = new QDBusInterface(service_name_, "/", interface_name_,
                                    QDBusConnection::sessionBus(), item_);
}

void DBus::subscribe(const QString& name, QObject* adapter, const QString& signature)
{
    QDBusConnection::sessionBus().connect(service_name_, "/", interface_name_,
        name, adapter, signature.toStdString().c_str());
}

void DBus::setDelayedReply(Message &message)
{
    message.setDelayedReply(true);
}

void DBus::sendReply(Message &request, const Message &response)
{
    QVariantList output = response.arguments();
    QDBusMessage message = request.createReply(output);
    QDBusConnection::sessionBus().send(message);
}

void DBus::sendError(Message &request, const QString &name, const QString &text)
{
    QDBusMessage error = request.createErrorReply(name, text);
    QDBusConnection::sessionBus().send(error);
}

void DBus::sendSignal(const QString &name, const Message &message)
{
    QDBusMessage signal = QDBusMessage::createSignal("/", name_, name);
    signal.setArguments(message.arguments());
    QDBusConnection::sessionBus().send(signal);
}

Watcher *DBus::call(const QString &name, const Message &request)
{
    return new DBusWatcher(name, request.arguments(), interface_);
}
