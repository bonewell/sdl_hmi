#include "abstractitem.h"

#include <QVector>
#include <QDebug>

#include "core/abstractadapter.h"
#include "core/procedure.h"
#include "core/signal.h"

AbstractItem::AbstractItem(QObject *parent)
    : QObject(parent), adapter_(0), cppMeta_(0), qmlMeta_(0) {}

void AbstractItem::classBegin()
{
    // Save signals and methods
    cppMeta_ = metaObject();
    for(int i = cppMeta_->methodOffset(); i < cppMeta_->methodCount(); ++i) {
        QMetaMethod meta = cppMeta_->method(i);
        switch (meta.methodType()) {
        case QMetaMethod::Method:
            if (meta.access() == QMetaMethod::Public) {
                cppMethods_[methodName(meta)] = meta.methodIndex();
            }
            break;
        case QMetaMethod::Signal:
            cppMethods_[signalName(meta)] = meta.methodIndex();
            break;
        default:
            // It is not interesting.
            break;
        }
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

Procedure &AbstractItem::call(const QString& name)
{
    if (calledFromDBus()) {
      qDebug() << "call: set delayed reply";
      setDelayedReply(true);
      qDebug() << "call: set delayed reply is done";
      return call(name, message());
    }
    Message message;
    return call(name, message);
}

Procedure &AbstractItem::call(const QString& name, const Message &message)
{
    QMetaMethod meta = qmlMeta_->method(qmlMethods_[name]);
    Q_ASSERT(meta.isValid());
    QList<QByteArray> input_params = meta.parameterNames();
    QMetaMethod reply_meta = cppMeta_->method(cppMethods_[replyName(name)]);
    QList<QByteArray> output_params;
    if (reply_meta.isValid()) {
        output_params = reply_meta.parameterNames();
    }
    Handle hdl = handle();
    Procedure* procedure = new Procedure(this, name, input_params, output_params, message);
    if (procedure->hasHandle()) {
        procedure->in(hdl);
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

void AbstractItem::sendReply(CoreMessage &request, const CoreMessage &response)
{
    adapter_->sendReply(request, response);
}

void AbstractItem::sendError(CoreMessage &request, const QString &name, const QString &text)
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
    QMetaMethod meta = cppMeta_->method(cppMethods_[name]);
    return adapter_->notification(name, meta);
}

Method &AbstractItem::request(const QString& name, MethodCallback* callback)
{
    QMetaMethod meta = cppMeta_->method(cppMethods_[name]);
    return adapter_->request(name, meta, callback);
}

Handle AbstractItem::handle() const
{
    static int i = 0;
    return Handle(++i);
}

QString AbstractItem::methodName(const QMetaMethod& meta) const
{
    QString name = QString::fromLatin1(meta.name());
    name[0] = name[0].toUpper();
    return name;
}

QString AbstractItem::signalName(const QMetaMethod &meta) const
{
    QString name = QString::fromLatin1(meta.name());
    return name;
}

QString AbstractItem::replyName(const QString &name) const
{
    QString reply_name = name;
    reply_name[0] = reply_name[0].toUpper();
    return "reply" + reply_name;
}
