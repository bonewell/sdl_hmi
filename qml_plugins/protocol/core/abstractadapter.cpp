#include "abstractadapter.h"

#include <QMetaMethod>

AbstractAdapter::AbstractAdapter(QObject *item, QObject *object) :
    Adaptor(object), impl_(item, object), meta_(), meta_item_(), msgs_()
{
}

void AbstractAdapter::init()
{
    impl_.setAdapter(this);
    impl_.init(uid(), name());
    if (isConnected()) {
        impl_.connect(serviceName(), interfaceName());
    }
    const QMetaObject *mo = this->metaObject();
    for(int i = mo->methodOffset(); i < mo->methodCount(); ++i) {
        QMetaMethod meta = mo->method(i);
        subscribe(meta);
        publish(meta);
    }
}

void AbstractAdapter::initInvokables(const QMetaObject *metaObject)
{
    for(int i = metaObject->methodOffset(); i < metaObject->methodCount(); ++i) {
        QMetaMethod meta = metaObject->method(i);
        saveInvokable(meta);
    }
}

void AbstractAdapter::saveInvokable(const QMetaMethod &meta)
{
    if (meta.methodType() == QMetaMethod::Method &&
        meta.access() == QMetaMethod::Public) {
        QString name = meta.name();
        name[0] = name[0].toUpper();
        if (!meta_item_.contains(name)) {
            meta_item_.insert(name, meta.methodIndex());
        }
    }
}

bool AbstractAdapter::compare(const QMetaMethod &m1, const QMetaMethod &m2) const
{
    return m1.name().toLower() == m2.name().toLower();
}

void AbstractAdapter::publish(const QMetaMethod &meta)
{
    if (meta.methodType() == QMetaMethod::Slot &&
        meta.access() == QMetaMethod::Public) {
        const QMetaObject *mo = impl_.item()->metaObject();
        for(int i = mo->methodOffset(); i < mo->methodCount(); ++i) {
            QMetaMethod qml_meta = mo->method(i);
            if (compare(qml_meta, meta)) {
                QString name = QString::fromLatin1(meta.name());
                meta_[name] = qml_meta.methodIndex();
            }
        }
    }
}

Slave& AbstractAdapter::invoke(const QString& name, const Message &message)
{
    Handle hdl = handle();
    QMetaMethod meta = impl_.item()->metaObject()->method(meta_[name]);
    QString reply_name = name;
    reply_name[0] = reply_name[0].toUpper();
    reply_name = "Reply" + reply_name;
    QMetaMethod reply_meta = impl_.item()->metaObject()->method(meta_item_[reply_name]);
    Q_ASSERT(meta.isValid());
    Q_ASSERT(reply_meta.isValid());
    Slave* s = new Slave(hdl, message, meta, reply_meta, impl_);
    if (s->hasHandle()) {
        msgs_[hdl.uid] = s;
    }
    return *s;
}

Slave& AbstractAdapter::reply(const Handle& handle)
{
    Slave& s = *q_check_ptr(msgs_.take(handle.uid));
    s.out(handle.code).out(handle.message); // no effect for error
    return s;
}

Courier& AbstractAdapter::request(const QString& name, const QJSValue &callback,
    CourierCallback func)
{
    QMetaMethod meta = impl_.item()->metaObject()->method(meta_item_[name]);
    return *new Courier(meta, callback, func, impl_);
}

Signal& AbstractAdapter::signal(const QString& name)
{
    QMetaMethod meta = impl_.item()->metaObject()->method(meta_item_[name]);
    return *new Signal(meta, impl_);
}

void AbstractAdapter::sendError(Handle handle, const QString& error, const QString& text)
{
    reply(handle).error(error, text);
}

void AbstractAdapter::sendResult(Handle handle)
{
    reply(handle).send();
}

Handle AbstractAdapter::handle() const
{
    static int i = 0;
    return Handle(++i);
}

void AbstractAdapter::subscribe(const QMetaMethod &meta)
{
    if (!isConnected()) return;
    if (meta.methodType() == QMetaMethod::Slot &&
        meta.access() == QMetaMethod::Private) {
        impl_.subscribe(this, meta);
    }
}
