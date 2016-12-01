#ifndef WEBSOCKETMESSAGE_H_
#define WEBSOCKETMESSAGE_H_

#include <QByteArray>
#include <QJsonObject>
#include <QVariantList>

class Message {
public:
    template<typename T>
    Message& arg(const QString& name, const T& value) {
        QJsonValue item;
        item << value;
        response_[name] = item;
        return *this;
    }

    const QJsonObject& arguments() const {
        return response_;
    }
private:
    QJsonObject response_;
};

#endif  // WEBSOCKETMESSAGE_H_
