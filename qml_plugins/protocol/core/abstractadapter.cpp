#include "abstractadapter.h"

#include <QMetaMethod>
#include <QDebug>

#include "core/abstractitem.h"

AbstractAdapter::AbstractAdapter(QObject *parent) :
    Adaptor(parent), impl_(parent)
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
    }
}

void AbstractAdapter::sendReply(CoreMessage &request, const CoreMessage &response)
{
    impl_.sendReply(request.msg(), response.msg());
}

void AbstractAdapter::sendError(CoreMessage &request, const QString &name, const QString &text)
{
    impl_.sendError(request.msg(), name, text);
}

Procedure &AbstractAdapter::call(const QString& name, Message message)
{
    qDebug() << "MethodCall: " << name;
    return item_->call(name, message);
}

Procedure& AbstractAdapter::call(const QString &name)
{
    qDebug() << "MethodCall: " << name;
    return item_->call(name);
}

Method& AbstractAdapter::request(const QString& name, const QMetaMethod& meta,
                                 MethodCallback *callback)
{
    return *new Method(name, meta.parameterNames(), callback, impl_);
}

Signal& AbstractAdapter::notification(const QString& name, const QMetaMethod& meta)
{
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
