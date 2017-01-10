#ifndef DBUSMESSAGE_H
#define DBUSMESSAGE_H

#include <QtDBus/QDBusMessage>
#include <QVariantList>

#include "core/messageinterface.h"
//#include "dbus/dbuscastwatcher.h"

typedef QDBusMessage Message;

class DBusMessage : public MessageInterface
{
public:
    DBusMessage();
    DBusMessage(Message& message);
//    explicit Message(const QVariantList& arguments)
//        : arguments_(arguments), index_(0) {}
    DBusMessage& operator=(const DBusMessage& message);
    virtual void setDelayedReply() const;
    void setArguments(const QVariantList& arguments);
    const QVariantList& arguments() const;
    QDBusMessage createReply(const QVariantList& output);
    QDBusMessage createErrorReply(const QString& name, const QString& msg);

    template<typename T>
    void setArgument(const T& value) {
        *p_ << QVariant::fromValue(value);
    }

    template<typename T>
    T argument(const QString &name) {
        Q_UNUSED(name);
        return cast_watcher<T>(i_.next());
    }

private:
    Message* p_;
    QVariantList arguments_;
    QListIterator<QVariant> i_;
};

#endif // DBUSMESSAGE_H
