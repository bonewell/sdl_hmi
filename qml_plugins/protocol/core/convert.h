#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CONVERT_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CONVERT_H_

#include <QVariant>
#include <QJSValue>
#include <QJSEngine>
#include "core/optional.h"

template<typename T>
inline T single(const QVariantMap &input) {
    T output;
    input >> output;
    return output;
}

template<typename T>
inline QList<T> multiple(const QVariantList &input) {
    QList<T> output;
    input >> output;
    return output;
}

template<typename T>
inline QVariantList qvariantlist(const QList<T> &input) {
    QVariantList output;
    output << input;
    return output;
}

template<typename T>
inline QVariantMap qvariantmap(const T &input) {
    QVariantMap output;
    output << input;
    return output;
}

template<typename T>
inline T value(const QVariant &argument) {
    T value;
    argument >> value;
    return value;
}

template<typename T>
inline const QVariant &operator>>(const QVariant &argument, T &value) {
    value = single<T>(argument.toMap());
    return argument;
}

template<>
inline const QVariant &operator>>(const QVariant &argument, int &value) {
    value = argument.toInt();
    return argument;
}

template<>
inline const QVariant &operator>>(const QVariant &argument, bool &value) {
    value = argument.toBool();
    return argument;
}

template<>
inline const QVariant &operator>>(const QVariant &argument, double &value) {
    value = argument.toDouble();
    return argument;
}

template<>
inline const QVariant &operator>>(const QVariant &argument, QString &value) {
    value = argument.toString();
    return argument;
}

template<>
inline const QVariant &operator>>(const QVariant &argument, QStringList &value) {
    value = argument.toStringList();
    return argument;
}

template<typename T>
inline const QVariant &operator>>(const QVariant &argument, QList<T> &value) {
    argument.toList() >> value;
    return argument;
}

template<typename T>
inline const QVariantList &operator>>(const QVariantList &argument, QList<T> &value) {
    foreach (const QVariant& item, argument) {
        T element;
        item >> element;
        value.append(element);
    }
    return argument;
}

template<typename T>
inline QVariant &operator<<(QVariant &argument, const T &value) {
    QVariantMap map;
    map << value;
    argument.setValue(map);
    return argument;
}

template<>
inline QVariant &operator<<(QVariant &argument, const int &value) {
    argument.setValue(value);
    return argument;
}

template<>
inline QVariant &operator<<(QVariant &argument, const bool &value) {
    argument.setValue(value);
    return argument;
}

template<>
inline QVariant &operator<<(QVariant &argument, const double &value) {
    argument.setValue(value);
    return argument;
}

template<>
inline QVariant &operator<<(QVariant &argument, const QString &value) {
    argument.setValue(value);
    return argument;
}

template<>
inline QVariant &operator<<(QVariant &argument, const QStringList &value) {
    argument.setValue(value);
    return argument;
}

template<typename T>
inline QVariant &operator<<(QVariant &argument, const QList<T> &value) {
    QVariantList list;
    list << value;
    argument.setValue(list);
    return argument;
}

template<typename T>
inline QVariantList &operator<<(QVariantList &argument, const QList<T> &value) {
    foreach (const T& item, value) {
        QVariant element;
        element << item;
        argument.append(element);
    }
    return argument;
}

template<typename T>
inline QJSValue &operator<<(QJSValue &argument, const T &value) {
    argument = QJSValue(value);
    return argument;
}

inline QJSValue &operator<<(QJSValue &argument, const QStringList &value) {
    QJSEngine *engine = argument.engine();
    argument = engine->newArray();
    int i = 0;
    foreach (const QString& item, value) {
        QJSValue element(argument);
        element << item;
        argument.setProperty(i, element);
        ++i;
    }
    return argument;
}

template<typename T>
inline QJSValue &operator<<(QJSValue &argument, const QList<T> &value) {
    QJSEngine *engine = argument.engine();
    argument = engine->newArray();
    int i = 0;
    foreach (const T& item, value) {
        QJSValue element(argument);
        element << item;
        argument.setProperty(i, element);
        ++i;
    }
    return argument;
}

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CONVERT_H_
