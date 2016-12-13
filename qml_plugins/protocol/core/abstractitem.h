#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QObject>
#include <QtQml/QQmlParserStatus>

#include "core/context.h"
#include "core/handle.h"

#define CONNECT_ADAPTER(Item, Adapter) \
    Q_INTERFACES(QQmlParserStatus) \
public: \
    explicit Item(QObject *parent = 0) : AbstractItem(parent) {} \
    virtual void componentComplete() { \
        setAdapter(new Adapter(this, object())); \
        AbstractItem::componentComplete(); \
    }

class AbstractAdapter;
class Procedure;
class Signal;
class Method;
class MethodCallback;
class Message;

class AbstractItem : public QObject, public QQmlParserStatus, public Context
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QObject* object MEMBER object_)

public:
    virtual ~AbstractItem() {}
    virtual void classBegin();
    virtual void componentComplete();
    Q_INVOKABLE void fail(const QVariantMap& handle, const QString& code,
        const QString& text);
    Q_INVOKABLE void reply(const QVariantMap& handle);

protected:
    explicit AbstractItem(QObject *parent = 0);
    QObject* object() const;
    void setAdapter(AbstractAdapter* adapter);
    Procedure& response(const Handle &handle);
    Signal& notification(const QString& name);
    Method& request(const QString& name, MethodCallback* callback);

private:
    typedef int IndexMethod;
    typedef QMap<QString, IndexMethod> MetaList;
    typedef QMap<HandleId, Procedure*> ProceduresList;
    inline Handle handle() const;
    inline QString replyName(const QString& name) const;
    Procedure& call(const QString& name, const Message &message);
    bool invoke(const QString& name, const QVector<QGenericArgument>& args,
                Qt::ConnectionType type = Qt::DirectConnection);
    void sendReply(Message& request, const Message &response);
    void sendError(Message& request, const QString& name, const QString& text);
    QObject *object_;
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
