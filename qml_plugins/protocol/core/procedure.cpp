#include "procedure.h"

#include <QJsonObject>

#include "core/connector.h"
#include "core/abstractitem.h"

Procedure::Procedure(AbstractItem* item, const QString& name,
                     const QList<QByteArray>& input,
              const QList<QByteArray>& output, const Handle& handle,
              const Message& message)
    : item_(item), name_(name), handle_(handle), request_(message),
      input_(input), output_(output), args_(kMaxArgs)
{
//    request_.setName(name);
//    response_.setName(name);
//    QList<QByteArray> reply_names = reply_meta.parameterNames();
//    reply_names.removeAll("handle");
//    reply_names.push_front("message");
//    reply_names.push_front("code");
//    response_.setParams(reply_names);
    connect(this, SIGNAL(pass()), this, SLOT(sendReply()), Qt::QueuedConnection);
    connect(this, SIGNAL(fail(const QString&, const QString&)),
            this, SLOT(sendError(const QString&, const QString&)), Qt::QueuedConnection);
}

void Procedure::run()
{
    if (!invoke()) {
        QString text = "No method " + name_;
        error("Error.NoMethod", text);
    }
    if (!hasHandle()) {
        out(handle_.code).out(handle_.message).send();
    }
}

bool Procedure::hasHandle() const {
    return true;
//    return names_.size() > 0 && names_[0] == "handle";
}

bool Procedure::canSplit(int max) const
{
//    if (hasHandle()) {
//        return names_.size() < max;
//    } else {
//        return names_.size() <= max;
//    }
    return true;
}

bool Procedure::invoke()
{
    const int kMaxArgs = 10;
    QVector<QGenericArgument> args(kMaxArgs);

    int i = 0;

    QVariant hdl = QVariantMap(handle_);
    if (hasHandle()) {
        args[i++] = Q_ARG(QVariant, hdl);
    }

    if (canSplit(kMaxArgs)) {
        foreach (const QByteArray& v, input_) {
            if (input_.contains(v)) {
                args[i] = Q_ARG(QVariant, params_[v]);
            }
            ++i;
        }
    } else {
        args[i] = Q_ARG(QVariant, QVariant(params_));
    }

    return item_->invoke(name_, args);
}

void Procedure::send()
{
    emit pass();
}

void Procedure::error(const QString& name, const QString& text = QString())
{
    emit fail(name, text);
}

void Procedure::sendReply()
{
    item_->sendReply(request_, response_);
    this->deleteLater();
}

void Procedure::sendError(const QString& name, const QString& text)
{
    item_->sendError(request_, name, text);
    this->deleteLater();
}

#ifdef WEBSOCKET
void Procedure::execute()
{
    const int kMaxArgs = 10;
    QVector<QGenericArgument> args(kMaxArgs);

    /*
    int i = 0;

    QVariant hdl = QVariantMap(handle_);
    if (hasHandle()) {
        args[i++] = Q_ARG(QVariant, hdl);
    }

    const QJsonObject& input = request_.arguments();
    if (canSplit(kMaxArgs)) {
    qDebug() << "Parameters' names of request: " << names_;
    qDebug() << "Input values: " << input;
        foreach (const QByteArray& v, names_) {
            qDebug() << v << i;
            if (v == "handle") continue;
            if (input.contains(v)) {
                args[i] = Q_ARG(QVariant, input[v].toVariant());
                qDebug() << input[v];
            } else {
                args[i] = Q_ARG(QVariant, QVariant());
            }
            ++i;
        }
        index_ += names_.count();
    } else {
        args[i] = Q_ARG(QVariant, QVariant(input.toVariantMap()));
        ++index_;
    }
*/
    item_->invokeMethod(name_, args);
}
#endif  // WEBSOCKET
