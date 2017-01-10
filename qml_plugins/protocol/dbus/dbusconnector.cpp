#include "dbusconnector.h"

#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusPendingCall>
#include <QtDBus/QDBusPendingReply>
#include <QtQuick/QQuickItem>

#include "dbus/dbuswatcher.h"
#include "core/coremessage.h"

DBus::DBus(QObject *item, QObject *object) : item_(item), object_(object),
    interface_(0)
{
}

void DBus::setAdapter(AbstractAdapter *adapter)
{
    Q_UNUSED(adapter);
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
                                    QDBusConnection::sessionBus(), object_);
}

void DBus::subscribe(QObject* adapter, const QMetaMethod& meta)
{
    QString name = QString::fromLatin1(meta.name());
    QDBusConnection::sessionBus().connect(service_name_, "/", interface_name_,
        name, adapter, createSlot(meta).toStdString().c_str());
}

QChar DBus::methodType(QMetaMethod::MethodType type) const
{
    switch (type) {
    case QMetaMethod::Method: return QChar(QMETHOD_CODE); break;
    case QMetaMethod::Slot: return QChar(QSLOT_CODE); break;
    case QMetaMethod::Signal: return QChar(QSIGNAL_CODE); break;
    case QMetaMethod::Constructor:
    default: return QChar(-1);
    }
    return QChar();
}

QString DBus::createSlot(const QMetaMethod& meta)
{
    QString signature = QString::fromLatin1(meta.methodSignature());
    QString code(methodType(meta.methodType()));
    return code + signature;
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

void DBus::sendSignal(const Message &message)
{
    QDBusMessage signal = QDBusMessage::createSignal("/", name_, message.name());
    signal.setArguments(message.arguments());
    QDBusConnection::sessionBus().send(signal);
}

Watcher *DBus::sendRequest(const Message &request)
{
    return new DBusWatcher(request.name(), request.arguments(), interface_);
}
