#ifndef COREMESSAGE_H
#define COREMESSAGE_H

#include <QString>
#include <QList>
#include <QByteArray>
#include <QVariant>

#include "core/convert.h"
#include "core/message.h"

class CoreMessage
{
public:
    CoreMessage();
    CoreMessage(const Message& msg);
    void setName(const QString& name);
    const QString& name() const;
    void setParams(const QList<QByteArray>& params);
    Message& msg();
    const Message& msg() const;

    template<typename T>
    void setArgument(const T& value) {
        Q_ASSERT_X(i_.hasNext(), "setArgument", "List of parameters is full!");
        QVariant var;
        var << value;
        j_.insert(var);
    }

    template<typename T>
    T argument(const QString &name) {
//        params_.indexOf(name.toLatin1());
//        Q_UNUSED(name);
//        return cast_watcher<T>(i_.next());
        return T();
    }

private:
    QString name_;
    QList<QByteArray> params_;
    QListIterator<QByteArray> i_;
    QVariantList values_;
    QMutableListIterator<QVariant> j_;
    Message msg_;
};

#endif // COREMESSAGE_H
