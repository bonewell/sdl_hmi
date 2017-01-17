#ifndef ABSTRACT_MESSAGE_H
#define ABSTRACT_MESSAGE_H

#include <QString>
#include <QList>
#include <QByteArray>
#include <QVariant>

#include "core/convert.h"

class AbstractMessage
{
public:
    AbstractMessage();
    virtual ~AbstractMessage();
    virtual void setDelayedReply() const = 0;
    void setName(const QString& name);
    const QString& name() const;
    void setParams(const QList<QByteArray>& params);

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
        Q_UNUSED(name);
        return cast_watcher<T>(i_.next());
    }
protected:
    const QByteArray& nextParam();
private:
    QString name_;
    QList<QByteArray> params_;
    QListIterator<QByteArray> i_;
    QVariantList values_;
    QMutableListIterator<QVariant> j_;
};

#endif // ABSTRACT_MESSAGE_H