#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QObject>
#include <QtQml/QQmlParserStatus>

#include "core/context.h"
#include "core/handle.h"
#include "core/coremessage.h"

#define CONNECT_ADAPTER(Item, Adapter) \
    Q_INTERFACES(QQmlParserStatus) \
public: \
    explicit Item(QObject *parent = 0) : AbstractItem(parent) {} \
    virtual void componentComplete() { \
        setAdapter(new Adapter(this)); \
        AbstractItem::componentComplete(); \
    }

class AbstractAdapter;
class Procedure;
class Signal;
class Method;
class MethodCallback;
class CoreMessage;

class AbstractItem : public QObject, public QQmlParserStatus, public Context
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)

public:
    virtual ~AbstractItem() {}
    virtual void classBegin();
    virtual void componentComplete();
    Q_INVOKABLE void fail(const QVariantMap& handle, const QString& code,
        const QString& text);
    Q_INVOKABLE void reply(const QVariantMap& handle);

protected:
    explicit AbstractItem(QObject *parent = 0);
    void setAdapter(AbstractAdapter* adapter);
    Procedure& response(const Handle &handle);
    Signal& notification(const QString& name);
    Method& request(const QString& name, MethodCallback* callback);

private:
    typedef int IndexMethod;
    typedef QMap<QString, IndexMethod> MetaList;
    typedef QMap<HandleId, Procedure*> ProceduresList;
    inline Handle handle() const;
    inline QString signalName(const QMetaMethod& meta) const;
    inline QString methodName(const QMetaMethod& meta) const;
    inline QString replyName(const QString& name) const;
    Procedure& call(const QString& name, const Message &message);
    Procedure& call(const QString& name);
    bool invoke(const QString& name, const QVector<QGenericArgument>& args,
                Qt::ConnectionType type = Qt::DirectConnection);
    void sendReply(CoreMessage& request, const CoreMessage &response);
    void sendError(CoreMessage& request, const QString& name, const QString& text);
    AbstractAdapter* adapter_;
    const QMetaObject* cppMeta_;
    MetaList cppMethods_;
    const QMetaObject* qmlMeta_;
    MetaList qmlMethods_;
    ProceduresList procedures_;
    friend class AbstractAdapter;
    friend class Procedure;
};

#endif // ABSTRACTITEM_H
