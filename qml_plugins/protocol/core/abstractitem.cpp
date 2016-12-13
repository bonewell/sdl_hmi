#include "abstractitem.h"

#include <QVector>

#include "core/abstractadapter.h"
#include "core/procedure.h"
#include "core/signal.h"

AbstractItem::AbstractItem(QObject *parent)
    : QObject(parent), object_(0), adapter_(0), cppMeta_(0), qmlMeta_(0) {}

QObject* AbstractItem::object() const
{
    return object_;
}

void AbstractItem::classBegin()
{
    cppMeta_ = metaObject();
    for(int i = cppMeta_->methodOffset(); i < cppMeta_->methodCount(); ++i) {
        QMetaMethod meta = cppMeta_->method(i);
        QString name = QString::fromLatin1(meta.name());
        cppMethods_[name] = meta.methodIndex();
    }
}

void AbstractItem::componentComplete()
{
    qmlMeta_ = metaObject();
    for(int i = qmlMeta_->methodOffset(); i < qmlMeta_->methodCount(); ++i) {
        QMetaMethod meta = qmlMeta_->method(i);
        QString name = QString::fromLatin1(meta.name());
        qmlMethods_[name] = meta.methodIndex();
    }
}

void AbstractItem::fail(const QVariantMap& handle, const QString& code,
    const QString& text)
{
    response(handle).error(code, text);
}

void AbstractItem::reply(const QVariantMap& handle)
{
    response(handle).send();
}

void AbstractItem::setAdapter(AbstractAdapter *adapter)
{
    adapter_ = adapter;
    adapter_->init();
}

Procedure &AbstractItem::call(const QString& name, const Message &message)
{
    message.setDelayedReply();
    QMetaMethod meta = qmlMeta_->method(qmlMethods_[name]);
    Q_ASSERT(meta.isValid());
    QList<QByteArray> input_params = meta.parameterNames();
    QMetaMethod reply_meta = cppMeta_->method(cppMethods_[replyName(name)]);
    QList<QByteArray> output_params;
    if (reply_meta.isValid()) {
        output_params = reply_meta.parameterNames();
    }
    Handle hdl = handle();
    Procedure* procedure = new Procedure(this, name, input_params, output_params,
                                         hdl, message);
    if (procedure->hasHandle()) {
        procedures_[hdl.uid] = procedure;
    }
    return *procedure;
}

bool AbstractItem::invoke(const QString& name,
                          const QVector<QGenericArgument>& args,
                          Qt::ConnectionType type)
{
    return QMetaObject::invokeMethod(this, name.toStdString().c_str(),
                                     type, args[0],
                                     args[1], args[2], args[3],
                                     args[4], args[5], args[6],
            args[7], args[8], args[9]);
}

void AbstractItem::sendReply(Message &request, const Message &response)
{
    adapter_->sendReply(request, response);
}

void AbstractItem::sendError(Message &request, const QString &name, const QString &text)
{
    adapter_->sendError(request, name, text);
}

Procedure &AbstractItem::response(const Handle& handle)
{
    Procedure& procedure = *q_check_ptr(procedures_.take(handle.uid));
    procedure.out(handle.code).out(handle.message); // no effect for error
    return procedure;
}

Signal& AbstractItem::notification(const QString& name)
{
    return adapter_->notification(name);
}

Method &AbstractItem::request(const QString& name, MethodCallback* callback)
{
    return adapter_->request(name, callback);
}

Handle AbstractItem::handle() const
{
    static int i = 0;
    return Handle(++i);
}

QString AbstractItem::replyName(const QString &name) const
{
    QString reply_name = name;
    reply_name[0] = reply_name[0].toUpper();
    return "reply" + reply_name;
}
