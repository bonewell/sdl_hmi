#ifndef SIGNAL_H
#define SIGNAL_H

#include <QString>
#include <QVariant>
#include <QList>
#include <QByteArray>
#include <QMetaMethod>

#include "core/convert.h"

typedef QList<QPair<QString, QVariant> > ArgumentsList;

class PrivateInterface;

class Signal
{
public:
    Signal(const QString& name, const QMetaMethod& meta, PrivateInterface& impl);
    void send();

    template<typename T>
    Signal& arg(const T& value) {
        QVariant var = QVariant::fromValue(value);
        arguments_ << qMakePair(QString(names_[index_++]), var);
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
    const QString name_;
    const QMetaMethod meta_;
    PrivateInterface& impl_;
    const QList<QByteArray> names_;
    ArgumentsList arguments_;
    int index_;
};

#endif // SIGNAL_H
