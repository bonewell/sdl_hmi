#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_

#include <QVariant>
#include "core/message.h"

class Watcher;
class QString;

typedef QList<QPair<QString, QVariant> > ArgumentsList;

class PrivateInterface
{
public:
    virtual ~PrivateInterface() {}
    virtual void init(int uid, const QString& name) = 0;
    virtual void connect(const QString& service, const QString& interface) = 0;
    virtual void subscribe(const QString &name, QObject *adapter,
                           const QString &signature) = 0;
    virtual void setDelayedReply(Message& message) = 0;
    virtual void sendReply(Message& message, const QVariantList& output) = 0;
    virtual void sendError(Message& message, const QString& name, const QString& text) = 0;
    virtual void sendSignal(const QString& name, const ArgumentsList& arguments) = 0;
    virtual Watcher* call(const QString& name, const QVariantList& input) = 0;
    virtual QObject* item() = 0;
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
