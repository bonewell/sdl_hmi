#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <QList>
#include <QString>
#include <QMetaType>
#include <QJSValue>
#include <QtDBus/QDBusMetaType>
#include <QtDBus/QDBusArgument>

void register_optional();

template<typename T>
struct Optional {
    bool presence;
    T value;
    Optional();
    Optional(const T& value);
    Optional(const QVariant& var);
    Optional<T>& operator=(const T& value);
    operator QVariant() const;
};

template<typename T>
Optional<T>::Optional() : presence(false), value()
{
}

template<typename T>
Optional<T>::Optional(const T& value) : presence(true), value(value)
{
}

template<typename T>
Optional<T>::Optional(const QVariant& var) : presence(!var.isNull()), value()
{
    if (presence) {
        var >> value;
    }
}

template<typename T>
Optional<T>& Optional<T>::operator =(const T& value)
{
    this->presence = true;
    this->value = value;
    return *this;
}

template<typename T>
Optional<T>::operator QVariant() const
{
    QVariant var;
    var << *this;
    return var;
}

template<typename T>
inline QDBusArgument &operator<<(QDBusArgument &arg, const Optional<T> &value) {
    arg.beginStructure();
    arg << value.presence << value.value;
    arg.endStructure();
    return arg;
}

template<typename T>
inline const QDBusArgument &operator>>(const QDBusArgument &arg, Optional<T> &value) {
    arg.beginStructure();
    arg >> value.presence >> value.value;
    arg.endStructure();
    return arg;
}

template<typename T>
inline const QVariant &operator>>(const QVariant &argument, Optional<T> &value) {
    value.presence = !argument.isNull();
    if (value.presence) {
        argument >> value.value;
    }
    return argument;
}

template<typename T>
inline QVariant &operator<<(QVariant &argument, const Optional<T> &value) {
    if (value.presence) {
        argument << value.value;
    }
    return argument;
}

template<typename T>
inline QJSValue &operator<<(QJSValue &argument, const Optional<T> &value) {
    if (value.presence) {
        argument << value.value;
    } else {
        argument = QJSValue(QJSValue::UndefinedValue);
    }
    return argument;
}

Q_DECLARE_METATYPE(Optional<int>)
Q_DECLARE_METATYPE(Optional<QList<int> >)
Q_DECLARE_METATYPE(Optional<bool>)
Q_DECLARE_METATYPE(Optional<QList<bool> >)
Q_DECLARE_METATYPE(Optional<double>)
Q_DECLARE_METATYPE(Optional<QList<double> >)
Q_DECLARE_METATYPE(Optional<QString>)
Q_DECLARE_METATYPE(Optional<QStringList>)

#endif // OPTIONAL_H
