#ifndef WEBSOCKETWATCHER_H
#define WEBSOCKETWATCHER_H

#include <QJsonObject>

#include "core/watcher.h"

class WebSocketWatcher : public Watcher
{
    Q_OBJECT
public:
    explicit WebSocketWatcher(QObject *parent = 0);
    virtual const Message& response() const;
    void call(const QJsonObject &params);
private:
    Message response_;
};

#endif  // WEBSOCKETWATCHER_H
