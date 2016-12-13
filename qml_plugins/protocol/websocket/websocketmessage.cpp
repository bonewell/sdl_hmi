#include "websocketmessage.h"

#include <QByteArray>
#include <QJsonDocument>
#include <QVariantList>

//Message::Message() : AbstractMessage() {}

QByteArray Message::reply(const QVariantList &output)
{
    arguments_["jsonrpc"] = "2.0";
    arguments_["id"] = 1;
    QByteArray data = QJsonDocument::fromVariant(output).toJson();
    return data;
}


const QJsonObject& Message::arguments() const
{
    return arguments_;
}

void Message::setDelayedReply()
{

}
