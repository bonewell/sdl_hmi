#ifndef WEBSOCKETMESSAGE_H_
#define WEBSOCKETMESSAGE_H_

#include <QByteArray>
#include <QJsonObject>
#include <QVariantList>

#include "core/optional.h"

class Message {
public:
    Message() : id_(0), name_("") {}
    Message(int id, const QString& name) : id_(id), name_(name) {}

    template<typename T>
    Message& arg(const QString& name, const T& value) {
        QJsonValue item;
        item << value;
        response_[name] = item;
        return *this;
    }

    template<typename T>
    Message& arg(const QString& name, const Optional<T>& value) {
        if (value.presence) {
            arg(name, value.value);
        }
        return *this;
    }

    const QJsonObject& arguments() const {
        return response_;
    }

    int id() const {
        return id_;
    }
    const QString& name() const {
        return name_;
    }
private:
    QJsonObject response_;
    int id_;
    QString name_;
};

#endif  // WEBSOCKETMESSAGE_H_
