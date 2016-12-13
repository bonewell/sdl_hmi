#include "websocketwatcher.h"

#include <QVariantList>
#include <QJsonObject>
#include <QDebug>

WebSocketWatcher::WebSocketWatcher(QObject *parent) : Watcher(parent)
{
}

const Message& WebSocketWatcher::response() const
{
    return response_;
}

void WebSocketWatcher::call(const QJsonObject &params)
{
    response_.setArguments(params);
    emit finished();
}
