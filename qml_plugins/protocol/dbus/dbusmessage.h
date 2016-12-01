#ifndef DBUSMESSAGE_H
#define DBUSMESSAGE_H

#include <QtDBus/QDBusMessage>

class Message : public QDBusMessage
{
public:
    template<typename T>
    Message& arg(const QString& name, const T& value) {
        Q_UNUSED(name);
        *this << QVariant::fromValue(value);
        return *this;
    }
};

#endif // DBUSMESSAGE_H
