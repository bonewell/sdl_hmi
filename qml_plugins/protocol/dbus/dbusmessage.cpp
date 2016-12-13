#include "dbusmessage.h"

Message::Message() : QDBusMessage(), AbstractMessage(), i_(arguments_) {}

void Message::setArguments(const QVariantList& arguments)
{
    arguments_ = arguments;
}

void Message::setDelayedReply() const
{
    QDBusMessage::setDelayedReply(true);
}
