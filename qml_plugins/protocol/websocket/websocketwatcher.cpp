#include "websocketwatcher.h"

#include <QVariantList>
#include <QJsonObject>

WebSocketWatcher::WebSocketWatcher(const QString& name,
                                   const QJsonObject &input) : Watcher()
{
}

QVariantList WebSocketWatcher::output()
{
    return QVariantList();
}
