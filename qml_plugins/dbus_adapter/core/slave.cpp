#include "slave.h"
#include <QMetaMethod>
#include <QtQuick/QQuickItem>

#include "core/connector.h"

Slave::Slave(int handle, const Message &message,
             const QMetaMethod& meta, PrivateInterface &impl)
    : handle_(handle), meta_(meta), request_(message), impl_(impl), index_(0),
      names_(meta.parameterNames()), input_(), output_()
{
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
}

bool Slave::invoke()
{
    const int kMaxArgs = 10;
    if (input_.size() < kMaxArgs) {
        QVector<QGenericArgument> args(kMaxArgs);
        int i = 0;
        foreach (const QVariant& v, input_) {
            args[i] = Q_ARG(QVariant, v);
            ++i;
        }
        return QMetaObject::invokeMethod(impl_.item(), name().c_str(),
                                         Qt::DirectConnection,
                                         Q_ARG(QVariant, QVariant(handle_)),
                                         args[0], args[1], args[2],
                                         args[3], args[4], args[5],
                                         args[6], args[7], args[8]);

    }
    return QMetaObject::invokeMethod(impl_.item(), name().c_str(),
                                     Qt::DirectConnection,
                                     Q_ARG(QVariant, QVariant(handle_)),
                                     Q_ARG(QVariant, QVariant(input_)));
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
    impl_.sendReply(request_, output_);
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
    name[0] = name[0].toLower();
    return name.toStdString();
}
