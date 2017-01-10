#include "dbusmessage.h"

DBusMessage::DBusMessage() : AbstractMessage(), i_(arguments_) {}

DBusMessage::DBusMessage(Message &message) : AbstractMessage(),
    p_(&message), i_(arguments_)
{
    setArguments(p_->arguments());
}

DBusMessage& DBusMessage::operator=(const DBusMessage& other)
{
    if (this != &other) {
        *this = other;
    }
    return *this;
}

void DBusMessage::setArguments(const QVariantList& arguments)
{
    arguments_ = arguments;
}

const QVariantList &DBusMessage::arguments() const
{
    return arguments_;
}

QDBusMessage DBusMessage::createReply(const QVariantList &output)
{
    return p_->createReply(output);
}

QDBusMessage DBusMessage::createErrorReply(const QString &name, const QString &msg)
{
    return p_->createErrorReply(name, msg);
}

void DBusMessage::setDelayedReply() const
{
    p_->setDelayedReply(true);
}
