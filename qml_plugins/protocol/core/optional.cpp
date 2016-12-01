#include "optional.h"

void register_optional() {
#ifdef DBUS
    qDBusRegisterMetaType<Optional<int> >();
    qDBusRegisterMetaType<Optional<QList<int> > >();
    qDBusRegisterMetaType<Optional<QString> >();
    qDBusRegisterMetaType<Optional<QStringList> >();
    qDBusRegisterMetaType<Optional<bool> >();
    qDBusRegisterMetaType<Optional<QList<bool> > >();
    qDBusRegisterMetaType<Optional<double> >();
    qDBusRegisterMetaType<Optional<QList<double> > >();
#endif
    qRegisterMetaType<Optional<int> >();
    qRegisterMetaType<Optional<QList<int> > >();
    qRegisterMetaType<Optional<QString> >();
    qRegisterMetaType<Optional<QStringList> >();
    qRegisterMetaType<Optional<bool> >();
    qRegisterMetaType<Optional<QList<bool> > >();
    qRegisterMetaType<Optional<double> >();
    qRegisterMetaType<Optional<QList<double> > >();
}
