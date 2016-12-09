#include "slave.h"
#include <QMetaMethod>
#include <QtQuick/QQuickItem>
#include <QJsonObject>

#include "core/connector.h"

Slave::Slave(const Handle& handle, const Message &message,
             const QMetaMethod& meta, const QMetaMethod& reply_meta,
             PrivateInterface &impl)
    : handle_(handle), meta_(meta), reply_meta_(reply_meta),
      request_(message), impl_(impl), index_(0), reply_index_(0),
      names_(meta.parameterNames()), reply_names_(reply_meta.parameterNames()),
      input_(), response_()
{
    reply_names_.removeAll("handle");
    reply_names_.push_front("message");
    reply_names_.push_front("code");
    connect(this, SIGNAL(pass()), this, SLOT(sendReply()), Qt::QueuedConnection);
    connect(this, SIGNAL(fail(const QString&, const QString&)),
            this, SLOT(sendError(const QString&, const QString&)), Qt::QueuedConnection);
}

void Slave::run()
{
    impl_.setDelayedReply(request_);
    if (!invoke()) {
        QString text = QString("No method ").append(name().c_str());
        error("Error.NoMethod", text);
    }
    if (!hasHandle()) {
        out(handle_.code).out(handle_.message).send();
    }
}

bool Slave::hasHandle() const {
    return names_.size() > 0 && names_[0] == "handle";
}

bool Slave::canSplit(int max) const
{
    if (hasHandle()) {
        return input_.size() < max;
    } else {
        return input_.size() <= max;
    }
}

bool Slave::invoke()
{
    const int kMaxArgs = 10;
    QVector<QGenericArgument> args(kMaxArgs);

    int i = 0;

    QVariant hdl = QVariantMap(handle_);
    if (hasHandle()) {
        args[i++] = Q_ARG(QVariant, hdl);
    }

    if (canSplit(kMaxArgs)) {
        foreach (const QByteArray& v, names_) {
            if (input_.contains(v)) {
                args[i] = Q_ARG(QVariant, input_[v]);
            }
            ++i;
        }
    } else {
        args[i] = Q_ARG(QVariant, QVariant(input_));
    }

    return QMetaObject::invokeMethod(impl_.item(), name().c_str(),
                                     Qt::DirectConnection, args[0],
                                     args[1], args[2], args[3],
                                     args[4], args[5], args[6],
                                     args[7], args[8], args[9]);
}

void Slave::send()
{
    emit pass();
}

void Slave::error(const QString& name, const QString& text = QString())
{
    emit fail(name, text);
}

void Slave::sendReply()
{
    impl_.sendReply(request_, response_);
    this->deleteLater();
}

void Slave::sendError(const QString& name, const QString& text)
{
    impl_.sendError(request_, name, text);
    this->deleteLater();
}

std::string Slave::name() const
{
    QString name = QString::fromLatin1(meta_.name());
    return name.toStdString();
}

#ifdef WEBSOCKET
void Slave::execute()
{
    const int kMaxArgs = 10;
    QVector<QGenericArgument> args(kMaxArgs);

    int i = 0;

    QVariant hdl = QVariantMap(handle_);
    if (hasHandle()) {
        args[i++] = Q_ARG(QVariant, hdl);
    }

    const QJsonObject& input = request_.arguments();
    index_ += names_.count();
    if (canSplit(kMaxArgs)) {
        foreach (const QByteArray& v, names_) {
            if (input_.contains(v)) {
                args[i] = Q_ARG(QVariant, input[v].toVariant());
            }
            ++i;
        }
    } else {
        args[i] = Q_ARG(QVariant, QVariant(input.toVariantMap()));
    }

    QMetaObject::invokeMethod(impl_.item(), name().c_str(),
                                     Qt::DirectConnection, args[0],
                                     args[1], args[2], args[3],
                                     args[4], args[5], args[6],
                                     args[7], args[8], args[9]);
}
#endif  // WEBSOCKET
