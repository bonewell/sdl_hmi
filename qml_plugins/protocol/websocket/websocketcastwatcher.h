#ifndef WEBSOCKETCASTWATCHER_H
#define WEBSOCKETCASTWATCHER_H

#include <QJsonValue>
#include <QJsonArray>

#include "core/connector.h"

template<typename T>
inline T cast_watcher(const QJsonValue& var) {
    T value;
    var >> value;
    return value;
}

template<>
inline int cast_watcher(const QJsonValue& var) {
    return var.toInt();
}
template<>
inline bool cast_watcher(const QJsonValue& var) {
    return var.toBool();
}
template<>
inline double cast_watcher(const QJsonValue& var) {
    return var.toDouble();
}
template<>
inline QString cast_watcher(const QJsonValue& var) {
    return var.toString();
}
template<>
inline QStringList cast_watcher(const QJsonValue& var) {
    QStringList list;
    const QJsonArray& array = var.toArray();
    foreach (const QJsonValue& item, array) {
        QString element = item.toString();
        list.append(element);
    }
    return list;
}

#endif // WEBSOCKETCASTWATCHER_H
