#include "abstractadapter.h"

#include <QMetaMethod>

AbstractAdapter::AbstractAdapter(QObject *item, QObject *object) :
    Adaptor(object), impl_(item, object), meta_(), msgs_()
{
}

void AbstractAdapter::init()
{
    impl_.init();
    if (isConnected()) {
        impl_.connect(serviceName(), interfaceName());
    }
    const QMetaObject* mo = this->metaObject();
    for(int i = mo->methodOffset(); i < mo->methodCount(); ++i) {
        QMetaMethod meta = mo->method(i);
        subscribe(meta);
        publish(meta);
    }
}

void AbstractAdapter::publish(const QMetaMethod &meta)
{
    if (meta.methodType() == QMetaMethod::Slot &&
        meta.access() == QMetaMethod::Public) {
        QString name = QString::fromLatin1(meta.name());
        meta_[name] = meta.methodIndex();
    }
}

Slave& AbstractAdapter::invoke(const QString& name, const Message &message)
{
    int id = handle();
    QMetaMethod meta = this->metaObject()->method(meta_[name]);
    Slave* s = new Slave(id, message, meta, impl_);
    msgs_[id] = s;
    return *s;
}

Slave& AbstractAdapter::reply(int handle)
{
    return *q_check_ptr(msgs_.take(handle));
}

Courier& AbstractAdapter::request(const QString& name, const QJSValue &callback,
    CourierCallback func)
{
    return *new Courier(name, callback, func, impl_);
}

void AbstractAdapter::sendError(int handle, const QString& error, const QString& text)
{
    reply(handle).error(error, text);
}

int AbstractAdapter::handle() const
{
    static int i = 0;
    return ++i;
}

QChar AbstractAdapter::methodType(QMetaMethod::MethodType type) const {
    switch (type) {
    case QMetaMethod::Method: return QChar(QMETHOD_CODE); break;
    case QMetaMethod::Slot: return QChar(QSLOT_CODE); break;
    case QMetaMethod::Signal: return QChar(QSIGNAL_CODE); break;
    case QMetaMethod::Constructor:
    default: return QChar(-1);
    }
    return QChar();
}

void AbstractAdapter::subscribe(const QMetaMethod &meta)
{
    if (!isConnected()) return;
    if (meta.methodType() == QMetaMethod::Slot &&
        meta.access() == QMetaMethod::Private) {
        QString name = QString::fromLatin1(meta.name());
        impl_.subscribe(name, this, createSlot(meta));
    }
}

QString AbstractAdapter::createSlot(const QMetaMethod meta)
{
    QString signature = QString::fromLatin1(meta.methodSignature());
    QString code(methodType(meta.methodType()));
    return code + signature;
}
