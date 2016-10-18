#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_

#include "core/message.h"

class Watcher;

class PrivateInterface
{
public:
    virtual ~PrivateInterface() {}
    virtual void init() = 0;
    virtual void connect(const QString& service, const QString& interface) = 0;
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature) = 0;
    virtual void setDelayedReply(Message& message) = 0;
    virtual void sendReply(Message& message, const QVariantList& output) = 0;
    virtual void sendError(Message& message, const QString& name, const QString& text) = 0;
    virtual Watcher* call(const QString& name, const QVariantList& input) = 0;
    virtual QObject* item() = 0;
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
