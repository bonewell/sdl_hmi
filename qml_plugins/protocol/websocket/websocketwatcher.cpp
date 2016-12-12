#include "websocketwatcher.h"

#include <QVariantList>
#include <QJsonObject>

WebSocketWatcher::WebSocketWatcher() : Watcher()
{
}

Message WebSocketWatcher::response()
{
    return Message(output_);
}

void WebSocketWatcher::response(const QJsonObject &value)
{
    output_ = value;
    emit finished();
}
