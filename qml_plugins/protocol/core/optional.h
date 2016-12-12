#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_OPTIONAL_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_OPTIONAL_H_

#include <QList>
#include <QString>
#include <QMetaType>
#include <QJSValue>
#include <QVariant>
#ifdef DBUS
#include <QtDBus/QDBusMetaType>
#include <QtDBus/QDBusArgument>
#endif
#ifdef WEBSOCKET
#include <QJsonValue>
#endif

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

#ifdef DBUS
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
#endif

#ifdef WEBSOCKET
template<typename T>
inline QJsonValue &operator<<(QJsonValue &arg, const Optional<T> &value) {
    if (value.presence) {
        arg << value.value;
    }
    return arg;
}

template<typename T>
inline const QJsonValue &operator>>(const QJsonValue &arg, Optional<T> &value) {
    value.presence = !arg.isUndefined() && !arg.isNull();
    if (value.presence) {
        arg >> value.value;
    }
    return arg;
}

#endif

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

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_OPTIONAL_H_
