#ifndef DBUSWATCHER_H
#define DBUSWATCHER_H

#include "core/watcher.h"

class QDBusInterface;
class QDBusPendingCallWatcher;

class DBusWatcher : public Watcher
{
    Q_OBJECT
public:
    DBusWatcher(const QString& name, const QVariantList& input,
                QDBusInterface *interface);
    virtual const Message& response();
private:
    QDBusPendingCallWatcher *watcher_;
    Message response_;
};

#endif // DBUSWATCHER_H
