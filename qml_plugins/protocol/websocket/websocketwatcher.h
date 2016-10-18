#ifndef WEBSOCKETWATCHER_H
#define WEBSOCKETWATCHER_H

#include "core/watcher.h"

class WebSocketWatcher : public Watcher
{
    Q_OBJECT
public:
    WebSocketWatcher(const QString& name, const QVariantList& input);
    virtual QVariantList output();
private:
};

#endif  // WEBSOCKETWATCHER_H
