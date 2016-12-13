#ifndef WEBSOCKETMESSAGE_H_
#define WEBSOCKETMESSAGE_H_

#include <QByteArray>
#include <QJsonObject>
#include <QVariantList>

#include "core/abstractmessage.h"
#include "core/optional.h"
#include "websocket/websocketcastwatcher.h"

class Message : public AbstractMessage
{
public:
//    Message();
//    Message(int id, const QString& name, const QJsonObject& result)
//        : AbstractMessage(name), id_(id), response_(result) {}

    template<typename T>
    Message& setArgument(const T& value) {
        QJsonValue item;
        item << value;
        arguments_[nextParam()] = item;
        return *this;
    }

    template<typename T>
    Message& setArgument(const Optional<T>& value) {
        if (value.presence) {
            return setArgument(value.value);
        }
        Q_UNUSED(nextParam());
        return *this;
    }

    template<typename T>
    T argument(const QString& name) const {
        return cast_watcher<T>(arguments_[name]);
    }

    const QJsonObject& arguments() const;
    virtual void setDelayedReply();

    int id() const {
        return id_;
    }
private:
    int id_;
};

#endif  // WEBSOCKETMESSAGE_H_
