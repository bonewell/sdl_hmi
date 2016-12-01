#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_

#include <QVariant>
#include "core/message.h"

class Watcher;
class QString;

class PrivateInterface
{
public:
    virtual ~PrivateInterface() {}
    virtual void init(int uid, const QString& name) = 0;
    virtual void connect(const QString& service, const QString& interface) = 0;
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature) = 0;
    virtual void setDelayedReply(Message& message) = 0;
    virtual void sendReply(Message& request, const Message& response) = 0;
    virtual void sendError(Message& request, const QString& name, const QString& text) = 0;
    virtual void sendSignal(const QString& name, const Message& message) = 0;
    virtual Watcher* call(const QString& name, const Message& request) = 0;
    virtual QObject* item() = 0;
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
