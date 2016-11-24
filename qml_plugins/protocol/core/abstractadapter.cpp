#include "abstractadapter.h"

#include <QMetaMethod>
#include <QDebug>

AbstractAdapter::AbstractAdapter(QObject *item, QObject *object) :
    Adaptor(object), impl_(item, object), meta_(), meta_signals_(), msgs_()
{
}

void AbstractAdapter::init()
{
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

void AbstractAdapter::saveSignals(const QMetaObject *metaObject)
{
    for(int i = metaObject->methodOffset(); i < metaObject->methodCount(); ++i) {
        QMetaMethod meta = metaObject->method(i);
        saveSignal(meta);
    }
}

void AbstractAdapter::saveSignal(const QMetaMethod &meta)
{
    if (meta.methodType() == QMetaMethod::Method) {
        QString name = meta.name();
        name[0] = name[0].toUpper();
        qDebug() << name << meta.parameterNames();
        meta_signals_[name] = meta.methodIndex();
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
    Q_ASSERT(meta.isValid());
    Slave* s = new Slave(hdl, message, meta, impl_);
    if (s->hasHandle()) {
        msgs_[hdl.uid] = s;
    }
    return *s;
}

Slave& AbstractAdapter::reply(Handle handle)
{
    Slave& s = *q_check_ptr(msgs_.take(handle.uid));
    s.out(handle.code).out(handle.message); // no effect for error
    return s;
}

Courier& AbstractAdapter::request(const QString& name, const QJSValue &callback,
    CourierCallback func)
{
    return *new Courier(name, callback, func, impl_);
}

Signal& AbstractAdapter::signal(const QString& name)
{
    QMetaMethod meta = impl_.item()->metaObject()->method(meta_signals_[name]);
    return *new Signal(name, meta, impl_);
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

QChar AbstractAdapter::methodType(QMetaMethod::MethodType type) const
{
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
