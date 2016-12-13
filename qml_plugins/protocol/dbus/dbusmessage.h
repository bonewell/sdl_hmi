#ifndef DBUSMESSAGE_H
#define DBUSMESSAGE_H

#include <QtDBus/QDBusMessage>
#include <QVariantList>

#include "core/abstractmessage.h"
#include "dbus/dbuscastwatcher.h"

class Message : public QDBusMessage, public AbstractMessage
{
public:
    Message();
//    explicit Message(const QVariantList& arguments)
//        : arguments_(arguments), index_(0) {}
    virtual void setDelayedReply() const;
    void setArguments(const QVariantList& arguments);

    template<typename T>
    void setArgument(const T& value) {
        *this << QVariant::fromValue(value);
    }

    template<typename T>
    T argument(const QString &name) {
        Q_UNUSED(name);
        return cast_watcher<T>(i_.next());
    }

private:
    QVariantList arguments_;
    QListIterator<QVariant> i_;
};

#endif // DBUSMESSAGE_H
