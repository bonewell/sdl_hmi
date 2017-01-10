#include "coremessage.h"

CoreMessage::CoreMessage()
    : i_(params_), j_(values_) {}

CoreMessage::CoreMessage(const Message &msg)
    : i_(params_), j_(values_), msg_(msg) {
}

const QString& CoreMessage::name() const
{
    return name_;
}

void CoreMessage::setParams(const QList<QByteArray>& params)
{
    params_ = params;
    i_ = QListIterator<QByteArray>(params_);
}

void CoreMessage::setName(const QString &name)
{
    name_ = name;
}

Message& CoreMessage::msg()
{
    return msg_;
}

const Message& CoreMessage::msg() const
{
    return msg_;
}
