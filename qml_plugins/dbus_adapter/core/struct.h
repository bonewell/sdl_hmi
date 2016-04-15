#ifndef STRUCT_H
#define STRUCT_H

#include <QtDBus/QDBusArgument>
#include <QMetaType>
#include <QList>
#include <QMetaType>
#include <QtDBus/QDBusMetaType>
#include <QJSValue>
#include <QJSEngine>
#include <QVariantMap>
#include "core/argument.h"
#include "core/convert.h"
#include "core/optional.h"

#define IMPLICIT_CASTING(T) \
operator QVariantMap() const { \
    QVariantMap map; \
    Argument<QVariantMap> a(map); \
    pack(a); \
    return map; \
}

#define DECLARE_STRUCT(T) \
Q_DECLARE_METATYPE(T) \
Q_DECLARE_METATYPE(Optional<T>) \
Q_DECLARE_METATYPE(QList<T>) \
Q_DECLARE_METATYPE(Optional<QList<T> >) \
\
inline QDBusArgument &operator<<(QDBusArgument &argument, const T &value) { \
    argument.beginStructure(); \
    Argument<QDBusArgument> a(argument); \
    value.pack(a); \
    argument.endStructure(); \
    return argument; \
} \
\
inline const QDBusArgument &operator>>(const QDBusArgument &argument, T &value) { \
    argument.beginStructure(); \
    Argument<const QDBusArgument> a(argument); \
    value.extract(a); \
    argument.endStructure(); \
    return argument; \
} \
\
inline QVariantMap &operator<<(QVariantMap &argument, const T &value) { \
    Argument<QVariantMap> a(argument); \
    value.pack(a); \
    return argument; \
} \
\
inline const QVariantMap &operator>>(const QVariantMap &argument, T &value) { \
    Argument<const QVariantMap> a(argument); \
    value.extract(a); \
    return argument; \
} \
\
inline QJSValue &operator<<(QJSValue &argument, const T &value) { \
    QJSEngine *engine = argument.engine(); \
    argument = engine->newObject(); \
    Argument<QJSValue> a(argument); \
    value.pack(a); \
    return argument; \
}

template<typename T>
inline void register_struct() {
    qDBusRegisterMetaType<T>();
    qDBusRegisterMetaType<QList<T> >();
    qDBusRegisterMetaType<Optional<T> >();
    qDBusRegisterMetaType<Optional<QList<T> > >();
}

#endif // STRUCT_H
