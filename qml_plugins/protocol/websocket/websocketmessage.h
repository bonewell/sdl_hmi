#ifndef WEBSOCKETMESSAGE_H_
#define WEBSOCKETMESSAGE_H_

#include <QByteArray>
#include <QJsonObject>
#include <QVariantList>

class Message {
public:
    QByteArray reply(const QVariantList& output);
private:
    QJsonObject response_;
};

#endif  // WEBSOCKETMESSAGE_H_
