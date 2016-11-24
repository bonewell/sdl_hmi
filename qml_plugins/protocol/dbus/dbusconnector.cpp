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

void DBus::sendReply(Message &message, const QVariantList &output)
{
    QDBusMessage response = message.createReply(output);
    QDBusConnection::sessionBus().send(response);
}

void DBus::sendError(Message &message, const QString &name, const QString &text)
{
    QDBusMessage error = message.createErrorReply(name, text);
    QDBusConnection::sessionBus().send(error);
}

void DBus::sendSignal(const QString &name, const ArgumentsList &arguments)
{
    QDBusMessage signal = QDBusMessage::createSignal("/", name_, name);
    QVariantList list;
    foreach (ArgumentsList::const_reference arg, arguments) {
        list << arg.second;
    }
    signal.setArguments(list);
    QDBusConnection::sessionBus().send(signal);
}

Watcher *DBus::call(const QString &name, const QVariantList &input)
{
    return new DBusWatcher(name, input, interface_);
}
