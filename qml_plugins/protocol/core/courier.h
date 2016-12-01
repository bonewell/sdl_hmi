#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_COURIER_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_COURIER_H_

#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QVariant>
#include <QMetaMethod>

#include "core/castwatcher.h"
#include "core/message.h"

class Courier;
class PrivateInterface;
class Watcher;

typedef void (*CourierCallback)(Courier&);

class Courier : public QObject
{
    Q_OBJECT

public:
    Courier(const QMetaMethod &meta, const QJSValue &callback,
            CourierCallback func, PrivateInterface &impl);
    void call();
    void invoke();

    template<typename T>
    Courier& in(const T& value) {
        request_.arg(names_[index_++], value);
        return *this;
    }

    template<typename T>
    Courier& out() {
        T value = cast_watcher<T>(response_[index_++]);
        QJSValue var(callback_);
        var << value;
        output_ << var;
        return *this;
    }

private slots:
    void response();

private:
    inline QString name() const;
    const QMetaMethod meta_;
    PrivateInterface &impl_;
    QJSValue callback_;
    Message request_;
    QList<QByteArray> names_;
    QVariantList response_;
    QJSValueList output_;
    Watcher* watcher_;
    CourierCallback func_;
    int index_;
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_COURIER_H_
