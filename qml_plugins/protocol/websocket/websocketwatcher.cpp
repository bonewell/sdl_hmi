#include "websocketwatcher.h"

#include <QVariantList>

WebSocketWatcher::WebSocketWatcher(const QString& name,
                                   const QVariantList& input) : Watcher()
{
}

QVariantList WebSocketWatcher::output()
{
    return QVariantList();
}
