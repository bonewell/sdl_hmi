#ifndef LADY_H
#define LADY_H

#include <QMap>
#include <QString>
#include <QObject>
#include <QtQml/QQmlParserStatus>

#include "core/slave.h"
#include "core/courier.h"
#include "core/connector.h"

#define ADAPTER_INFO(Name, Introspection) \
    ADAPTER_INFORMATION(Name, Introspection)

#define REGISTER_ADAPTER(Adapter, Item) \
public: \
    explicit Adapter(Item *parent) : \
        AbstractAdapter(reinterpret_cast<QObject*>(parent)), \
        qml(parent) {} \
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
          : AbstractItem(parent), adapter(new Adapter(this)) {} \
private: \
    AbstractAdapter* getAdapter() { return adapter; } \
    Adapter *adapter;

class AbstractAdapter : public Adaptor
{
    Q_OBJECT

public:
    explicit AbstractAdapter(QObject *parent);
    void init();
    void sendError(int handle, const QString& error, const QString& text);

protected:
    virtual bool isConnected() { return false; }
    virtual QString serviceName() { return ""; }
    virtual QString interfaceName() { return ""; }
    Slave& invoke(const QString& name, const Message& message);
    Slave& reply(int handle);
    Courier& request(const QString &name, const QJSValue& callback,
                     CourierCallback func);

private:
    inline void subscribe(const QMetaMethod& meta);
    inline void publish(const QMetaMethod& meta);
    inline int handle() const;
    inline QString createSlot(const QMetaMethod meta);
    inline QChar methodType(QMetaMethod::MethodType type) const;
    PrivateAdapter impl_;
    QMap<QString, int> meta_;
    QMap<int, Slave*> msgs_;
};

class AbstractItem : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
public:
    explicit AbstractItem(QObject *parent=0) : QObject(parent) {}
    virtual ~AbstractItem() {}
    virtual void componentComplete() {
        getAdapter()->init();
    }
    virtual void classBegin() {}
    Q_INVOKABLE void sendError(int handle, const QString& code, const QString& text) {
        getAdapter()->sendError(handle, code, text);
    }
protected:
    virtual AbstractAdapter* getAdapter() = 0;
};

#endif // LADY_H