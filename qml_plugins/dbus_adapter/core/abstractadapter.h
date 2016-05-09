#ifndef LADY_H
#define LADY_H

#include <QMap>
#include <QString>
#include <QObject>
#include <QtQml/QQmlParserStatus>

#include "core/slave.h"
#include "core/courier.h"
#include "core/connector.h"
#include "core/handle.h"

#define ADAPTER_INFO(Name, Introspection) \
    ADAPTER_INFORMATION(Name, Introspection)

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

protected:
    virtual bool isConnected() { return false; }
    virtual QString serviceName() { return ""; }
    virtual QString interfaceName() { return ""; }
    Slave& invoke(const QString& name, const Message& message);
    Slave& reply(Handle handle);
    Courier& request(const QString &name, const QJSValue& callback,
                     CourierCallback func);

private:
    inline void subscribe(const QMetaMethod& meta);
    inline void publish(const QMetaMethod& meta);
    inline Handle handle() const;
    inline QString createSlot(const QMetaMethod meta);
    inline QChar methodType(QMetaMethod::MethodType type) const;
    inline bool compare(const QMetaMethod& m1, const QMetaMethod& m2) const;
    PrivateAdapter impl_;
    QMap<QString, int> meta_;
    QMap<int, Slave*> msgs_;
};

class AbstractItem : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QObject* object MEMBER object_)
public:
    explicit AbstractItem(QObject *parent=0) : QObject(parent), object_(0) {}
    virtual ~AbstractItem() {}
    virtual void classBegin() {}
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
};

#endif // LADY_H
