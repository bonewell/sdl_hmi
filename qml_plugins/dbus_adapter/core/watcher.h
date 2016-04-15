#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject *parent = 0) : QObject(parent) {}
    virtual ~Watcher() {}
    virtual QVariantList output() = 0;
signals:
    void finished();
};

#endif // WATCHER_H
