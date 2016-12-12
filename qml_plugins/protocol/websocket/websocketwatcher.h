#ifndef WEBSOCKETWATCHER_H
#define WEBSOCKETWATCHER_H

#include <QJsonObject>

#include "core/watcher.h"

class WebSocketWatcher : public Watcher
{
    Q_OBJECT
public:
    WebSocketWatcher();
    virtual Message response();
    void response(const QJsonObject &value);
private:
    QJsonObject output_;
};

#endif  // WEBSOCKETWATCHER_H
