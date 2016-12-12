#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_WATCHER_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_WATCHER_H_

#include <QObject>

#include "core/message.h"

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject *parent = 0) : QObject(parent) {}
    virtual ~Watcher() {}
    virtual Message response() = 0;
signals:
    void finished();
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_WATCHER_H_
