#include "dbuswatcher.h"

#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusPendingCall>
#include <QtDBus/QDBusPendingCallWatcher>

DBusWatcher::DBusWatcher(const QString& name, const QVariantList& input,
                         QDBusInterface *interface) : Watcher()
{
    QDBusPendingCall pcall = interface->asyncCallWithArgumentList(name, input);
    watcher_ = new QDBusPendingCallWatcher(pcall, this);
    connect(watcher_, SIGNAL(finished(QDBusPendingCallWatcher*)), SIGNAL(finished()));
}

const Message &DBusWatcher::response()
{
    QDBusMessage reply = watcher_->reply();
    response_.setArguments(reply.arguments());
    return response_;
}
