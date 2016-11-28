#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_

#include <QMap>
#include <QString>
#include <QObject>
#include <QtQml/QQmlParserStatus>
#include "core/slave.h"
#include "core/context.h"
#include "core/courier.h"
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
    Adapter(Item *item, QObject *object) : \
        AbstractAdapter(reinterpret_cast<QObject*>(item), object), \
        qml(item) {} \
private: \
    Item *qml;

#define CONNECT_SERVICE(Name, Interface) \
private: \
    virtual bool isConnected() { return true; } \
    virtual QString serviceName() { return Name; } \
    virtual QString interfaceName() { return Interface; }

#define CONNECT_ADAPTER(Item, Adapter) \
    Q_INTERFACES(QQmlParserStatus) \
public: \
    explicit Item(QObject *parent = 0) \
          : AbstractItem(parent), adapter(0) {} \
    virtual void componentComplete() { \
        adapter = new Adapter(this, object_); \
        adapter->init(); \
        adapter->saveSignals(metaObject_); \
    } \
private: \
    AbstractAdapter* getAdapter() { return adapter; } \
    Adapter *adapter;

class AbstractAdapter : public Adaptor
{
    Q_OBJECT

public:
    AbstractAdapter(QObject *item, QObject *object);
    void init();
    void sendError(Handle handle, const QString& error, const QString& text);
    void sendResult(Handle handle);
    Slave& reply(const Handle &handle);
    Signal& signal(const QString& name);
    void saveSignals(const QMetaObject* metaObject);

protected:
    virtual bool isConnected() { return false; }
    virtual int uid() { return 0; }
    virtual QString name() { return ""; }
    virtual QString serviceName() { return ""; }
    virtual QString interfaceName() { return ""; }
    Slave& invoke(const QString& name, const Message& message);
    Courier& request(const QString &name, const QJSValue& callback,
                     CourierCallback func);

private:
    inline void subscribe(const QMetaMethod& meta);
    inline void publish(const QMetaMethod& meta);
    inline Handle handle() const;
    inline QString createSlot(const QMetaMethod meta);
    inline QChar methodType(QMetaMethod::MethodType type) const;
    inline bool compare(const QMetaMethod& m1, const QMetaMethod& m2) const;
    inline void saveSignal(const QMetaMethod& meta);
    PrivateAdapter impl_;
    QMap<QString, int> meta_;
    QMap<QString, int> meta_signals_;
    QMap<int, Slave*> msgs_;
};

class AbstractItem : public QObject, public QQmlParserStatus, public Context
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QObject* object MEMBER object_)
public:
    explicit AbstractItem(QObject *parent=0) : QObject(parent), object_(0) {}
    virtual ~AbstractItem() {}
    virtual void classBegin()
    {
        metaObject_ = metaObject();
    }
    Q_INVOKABLE void sendError(const QVariantMap& handle, const QString& code,
        const QString& text)
    {
        getAdapter()->sendError(handle, code, text);
    }
    Q_INVOKABLE void sendResult(const QVariantMap& handle)
    {
        getAdapter()->sendResult(handle);
    }
protected:
    virtual AbstractAdapter* getAdapter() = 0;
    QObject *object_;
    const QMetaObject* metaObject_;
};

#endif // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_ABSTRACTADAPTER_H_
