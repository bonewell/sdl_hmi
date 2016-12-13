#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_

#include <QMap>
#include <QString>
#include <QObject>

#include "core/procedure.h"
#include "core/method.h"
#include "core/connector.h"
#include "core/handle.h"
#include "core/signal.h"

#define ADAPTER_INFO(Uid, Name, Introspection) \
    ADAPTER_INFORMATION(Name, Introspection) \
private: \
    virtual int uid() { return Uid; } \
    virtual QString name() { return Name; }

#define REGISTER_ADAPTER(Adapter, Item) \
public: \
    Adapter(Item *item, QObject* object) : \
        AbstractAdapter(object), \
        qml(item) {} \
private: \
    Item *qml;

#define CONNECT_SERVICE(Name, Interface) \
private: \
    virtual bool isConnected() { return true; } \
    virtual QString serviceName() { return Name; } \
    virtual QString interfaceName() { return Interface; }

class AbstractItem;

class AbstractAdapter : public Adaptor
{
    Q_OBJECT

public:
    explicit AbstractAdapter(QObject *parent = 0);
    void init();
    void initInvokables(const QMetaObject* metaObject);

protected:
    virtual bool isConnected() { return false; }
    virtual int uid() { return 0; }
    virtual QString name() { return ""; }
    virtual QString serviceName() { return ""; }
    virtual QString interfaceName() { return ""; }
    AbstractItem* item_;
    Procedure& call(const QString& name, const Message& message);

private:
    inline void subscribe(const QMetaMethod& meta);
    inline void publish(const QMetaMethod& meta);
    inline Handle handle() const;
    inline bool compare(const QMetaMethod& m1, const QMetaMethod& m2) const;
    inline void saveInvokable(const QMetaMethod& meta);
    void sendReply(Message& request, const Message &response);
    void sendError(Message& request, const QString& name, const QString& text);
    Signal& notification(const QString& name);
    Method& request(const QString &name, MethodCallback *callback);
    PrivateAdapter impl_;
    QMap<QString, int> meta_;
    QMap<QString, int> meta_item_;
    QMap<int, Procedure*> msgs_;
    friend class AbstractItem;
};

#endif // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_
