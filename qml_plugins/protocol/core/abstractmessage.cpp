#include "core/abstractmessage.h"

AbstractMessage::AbstractMessage()
    : i_(params_), j_(values_) {}

AbstractMessage::~AbstractMessage() {}

const QString& AbstractMessage::name() const
{
    return name_;
}

void AbstractMessage::setParams(const QList<QByteArray>& params)
{
    params_ = params;
    i_ = QListIterator<QByteArray>(params_);
}

const QByteArray& AbstractMessage::nextParam()
{
    Q_ASSERT_X(i_.hasNext(), "nextParam", "There is no more params!");
    return i_.next();
}

void AbstractMessage::setName(const QString &name)
{
    name_ = name;
}
