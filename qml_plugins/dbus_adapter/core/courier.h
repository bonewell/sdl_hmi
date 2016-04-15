#ifndef COURIER_H
#define COURIER_H

#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QVariant>

#include "core/castwatcher.h"

class Courier;
class PrivateInterface;
class Watcher;

typedef void (*CourierCallback)(Courier&);

class Courier : public QObject
{
    Q_OBJECT

public:
    Courier(const QString &name, const QJSValue &callback,
            CourierCallback func, PrivateInterface &impl);
    void call();
    void invoke();

    template<typename T>
    Courier& in(const T& value) {
        QVariant var = QVariant::fromValue(value);
        input_ << var;
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
    QString name_;
    PrivateInterface &impl_;
    QJSValue callback_;
    QVariantList input_;
    QVariantList response_;
    QJSValueList output_;
    Watcher* watcher_;
    CourierCallback func_;
    int index_;
};

#endif // COURIER_H
