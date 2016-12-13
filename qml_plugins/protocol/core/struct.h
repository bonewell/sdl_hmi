#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_STRUCT_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_STRUCT_H_

#ifdef DBUS
#include <QtDBus/QDBusArgument>
#include <QtDBus/QDBusMetaType>
#endif
#include <QMetaType>
#include <QList>
#include <QMetaType>
#include <QJSValue>
#include <QJSEngine>
#include <QVariantMap>
#include "core/argument.h"
#include "core/convert.h"
#include "core/optional.h"

#define IMPLICIT_CASTING(T) \
T() {} \
T(const QVariantMap& map) { \
    Argument<const QVariantMap> a(map); \
    extract(a); \
} \
operator QVariantMap() const { \
    QVariantMap map; \
    Argument<QVariantMap> a(map); \
    pack(a); \
    return map; \
}

#ifdef DBUS
#define DECLARE_STRUCT_DBUS(T) \
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
}
#else
#define DECLARE_STRUCT_DBUS(T)
#endif

#ifdef WEBSOCKET
#define DECLARE_STRUCT_WEBSOCKET(T) \
inline QJsonValue &operator<<(QJsonValue &argument, const T &value) { \
    QJsonObject object; \
    Argument<QJsonObject> a(object); \
    value.pack(a); \
    argument = object; \
    return argument; \
} \
\
inline const QJsonValue &operator>>(const QJsonValue &argument, T &value) { \
    const QJsonObject& object = argument.toObject(); \
    Argument<const QJsonObject> a(object); \
    value.extract(a); \
    return argument; \
}
#else
#define DECLARE_STRUCT_WEBSOCKET(T)
#endif

#define DECLARE_STRUCT(T) \
Q_DECLARE_METATYPE(T) \
Q_DECLARE_METATYPE(Optional<T>) \
Q_DECLARE_METATYPE(QList<T>) \
Q_DECLARE_METATYPE(Optional<QList<T> >) \
\
DECLARE_STRUCT_DBUS(T) \
DECLARE_STRUCT_WEBSOCKET(T) \
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
#ifdef DBUS
    qDBusRegisterMetaType<T>();
    qDBusRegisterMetaType<QList<T> >();
    qDBusRegisterMetaType<Optional<T> >();
    qDBusRegisterMetaType<Optional<QList<T> > >();
#endif
    qRegisterMetaType<T>();
    qRegisterMetaType<QList<T> >();
    qRegisterMetaType<Optional<T> >();
    qRegisterMetaType<Optional<QList<T> > >();
}

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_STRUCT_H_
