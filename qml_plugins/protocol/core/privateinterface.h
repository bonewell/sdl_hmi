#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_

class AbstractAdapter;
class Message;
class Watcher;
class QString;
class QMetaMethod;
class QObject;

class PrivateInterface
{
public:
    virtual ~PrivateInterface() {}
    virtual QObject* item() = 0;
    virtual void setAdapter(AbstractAdapter* adapter) = 0;
    virtual void init(int uid, const QString& name) = 0;
    virtual void connect(const QString& service, const QString& interface) = 0;
    virtual void subscribe(QObject *adapter, const QMetaMethod &meta) = 0;
    virtual void setDelayedReply(Message& message) = 0;
    virtual Watcher* sendRequest(const Message& request) = 0;
    virtual void sendSignal(const Message& message) = 0;
    virtual void sendReply(Message& request, const Message& response) = 0;
    virtual void sendError(Message& request, const QString& name, const QString& text) = 0;
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_PRIVATEINTERFACE_H_
