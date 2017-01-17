#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_

#include <QMap>
#include <QString>
#include <QObject>
#include <QDebug>

#include "core/procedure.h"
#include "core/method.h"
#include "core/connector.h"
#include "core/handle.h"
#include "core/signal.h"

#define ADAPTER_INFO(Uid, Name, Introspection) \
private: \
    virtual int uid() { return Uid; } \
    virtual QString name() { \
        qDebug() << "Interface: " << metaObject()->classInfo(0).value(); \
        return #Name; \
    }

#define REGISTER_ADAPTER(Adapter, Item) \
public: \
    explicit Adapter(Item *item) : \
        AbstractAdapter(reinterpret_cast<QObject*>(item)), \
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

protected:
    virtual bool isConnected() { return false; }
    virtual int uid() { return 0; }
    virtual QString name() { return ""; }
    virtual QString serviceName() { return ""; }
    virtual QString interfaceName() { return ""; }
    AbstractItem* item_;
    Procedure& call(const QString& name, Message message);
    Procedure& call(const QString& name);

private:
    inline void subscribe(const QMetaMethod& meta);
    inline Handle handle() const;
    inline void saveInvokable(const QMetaMethod& meta);
    void sendReply(CoreMessage& request, const CoreMessage &response);
    void sendError(CoreMessage& request, const QString& name, const QString& text);
    Signal& notification(const QString& name, const QMetaMethod& meta);
    Method& request(const QString& name, const QMetaMethod& meta,
                    MethodCallback* callback);
    PrivateAdapter impl_;
    QMap<QString, int> meta_item_;
    friend class AbstractItem;
};

#endif // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_
