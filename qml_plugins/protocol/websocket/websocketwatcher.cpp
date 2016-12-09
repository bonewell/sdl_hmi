#include "websocketwatcher.h"

#include <QVariantList>
#include <QJsonObject>

WebSocketWatcher::WebSocketWatcher(const QString& name,
                                   const QJsonObject &input) : Watcher()
{
    //websocket->send();
}

QVariantList WebSocketWatcher::output()
{
    return QVariantList();
}
