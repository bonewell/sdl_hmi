#ifndef SIGNAL_H
#define SIGNAL_H

#include <QString>
#include <QVariant>
#include <QList>
#include <QByteArray>
#include <QMetaMethod>

#include "core/convert.h"
#include "core/message.h"

class PrivateInterface;

/**
 * @brief The Signal class
 * instance of this class is used to send notificaftion in the bus
 */
class Signal
{
public:
    Signal(const QString& name, const QList<QByteArray>& params,
           PrivateInterface& impl);
    void send();

    template<typename T>
    Signal& arg(const T& value) {
        message_.setArgument(value);
        return *this;
    }

    template<typename T>
    Signal& arg(const QVariantList& value) {
        return arg(multiple<typename T::value_type>(value));
    }

private:
    PrivateInterface& impl_;
    Message message_;
};

#endif // SIGNAL_H
