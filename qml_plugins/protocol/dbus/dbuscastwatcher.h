#ifndef DBUSCASTWATCHER_H
#define DBUSCASTWATCHER_H

#include <QtDBus/QDBusArgument>

template<typename T>
inline T cast_watcher(const QVariant& var) {
    QDBusArgument a = var.value<QDBusArgument>();
    T value;
    a >> value;
    return value;
}

template<>
inline int cast_watcher(const QVariant& var) {
    return var.toInt();
}
template<>
inline bool cast_watcher(const QVariant& var) {
    return var.toBool();
}
template<>
inline double cast_watcher(const QVariant& var) {
    return var.toDouble();
}
template<>
inline QString cast_watcher(const QVariant& var) {
    return var.toString();
}
template<>
inline QStringList cast_watcher(const QVariant& var) {
    return var.toStringList();
}

#endif // DBUSCASTWATCHER_H
