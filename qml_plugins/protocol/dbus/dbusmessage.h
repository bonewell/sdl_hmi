#ifndef DBUSMESSAGE_H
#define DBUSMESSAGE_H

#include <QtDBus/QDBusMessage>

#include "dbus/dbuscastwatcher.h"

class Message : public QDBusMessage
{
public:
    Message() {}
    explicit Message(const QVariantList& arguments)
        : arguments_(arguments), index_(0) {}

    template<typename T>
    Message& arg(const QString& name, const T& value) {
        Q_UNUSED(name);
        *this << QVariant::fromValue(value);
        return *this;
    }

    template<typename T>
    T arg(const QString &name) {
        Q_UNUSED(name);
        return cast_watcher<T>(arguments_[index_++]);
    }

private:
    QVariantList arguments_;
    int index_;
};

#endif // DBUSMESSAGE_H
