#include "optional.h"

void register_optional() {
    qDBusRegisterMetaType<Optional<int> >();
    qDBusRegisterMetaType<Optional<QList<int> > >();
    qDBusRegisterMetaType<Optional<QString> >();
    qDBusRegisterMetaType<Optional<QStringList> >();
    qDBusRegisterMetaType<Optional<bool> >();
    qDBusRegisterMetaType<Optional<QList<bool> > >();
    qDBusRegisterMetaType<Optional<double> >();
    qDBusRegisterMetaType<Optional<QList<double> > >();
}
