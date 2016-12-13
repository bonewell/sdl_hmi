#include "abstractadapter.h"

#include <QMetaMethod>

#include "core/abstractitem.h"

AbstractAdapter::AbstractAdapter(QObject *parent) :
    Adaptor(parent), impl_(parent, parent), meta_(), meta_item_(), msgs_()
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

void AbstractAdapter::sendReply(Message &request, const Message &response)
{
    impl_.sendReply(request, response);
}

void AbstractAdapter::sendError(Message &request, const QString &name, const QString &text)
{
    impl_.sendError(request, name, text);
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

Procedure &AbstractAdapter::call(const QString& name, const Message &message)
{
    return item_->call(name, message);
}

Method& AbstractAdapter::request(const QString& name, MethodCallback *callback)
{
    QMetaMethod meta = impl_.item()->metaObject()->method(meta_item_[name]);
    return *new Method(name, meta.parameterNames(), callback, impl_);
}

Signal& AbstractAdapter::notification(const QString& name)
{
    QMetaMethod meta = impl_.item()->metaObject()->method(meta_item_[name]);
    return *new Signal(name, meta.parameterNames(), impl_);
}

void AbstractAdapter::subscribe(const QMetaMethod &meta)
{
    if (!isConnected()) return;
    if (meta.methodType() == QMetaMethod::Slot &&
        meta.access() == QMetaMethod::Private) {
        impl_.subscribe(this, meta);
    }
}
