#include "websocketmessage.h"

#include <QByteArray>
#include <QJsonDocument>
#include <QVariantList>

QByteArray Message::reply(const QVariantList &output) {
    response_["jsonrpc"] = "2.0";
    response_["id"] = 1;
    QByteArray data = QJsonDocument::fromVariant(output).toJson();
    return data;
}
