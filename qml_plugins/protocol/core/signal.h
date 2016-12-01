#ifndef SIGNAL_H
#define SIGNAL_H

#include <QString>
#include <QVariant>
#include <QList>
#include <QByteArray>
#include <QMetaMethod>

#include "core/convert.h"
#include <core/message.h>

class PrivateInterface;

class Signal
{
public:
    Signal(const QMetaMethod& meta, PrivateInterface& impl);
    void send();

    template<typename T>
    Signal& arg(const T& value) {
        message_.arg(names_[index_++], value);
        return *this;
    }

    template<typename T>
    Signal& arg(const QVariantMap& value) {
        return arg(single<T>(value));
    }

    template<typename T>
    Signal& arg(const QVariantList& value) {
        return arg(multiple<typename T::value_type>(value));
    }

private:
    inline QString name() const;
    const QMetaMethod meta_;
    PrivateInterface& impl_;
    const QList<QByteArray> names_;
    Message message_;
    int index_;
};

#endif // SIGNAL_H
