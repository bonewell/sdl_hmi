#ifndef PRIVATEINTERFACE_H
#define PRIVATEINTERFACE_H

#include "core/message.h"

class Watcher;

class PrivateInterface
{
public:
    virtual ~PrivateInterface() {}
    virtual void connect(const QString& service, const QString& interface) = 0;
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature) = 0;
    virtual void setDelayedReply(Message& message) = 0;
    virtual void sendReply(Message& message, const QVariantList& output) = 0;
    virtual void sendError(Message& message, const QString& name, const QString& text) = 0;
    virtual Watcher* call(const QString& name, const QVariantList& input) = 0;
    virtual QObject* item() = 0;
};

#endif // PRIVATEINTERFACE_H
