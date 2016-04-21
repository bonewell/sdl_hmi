#ifndef DEVICEINFO_H
#define DEVICEINFO_H
#include "core/struct.h"
#include <QString>

struct DeviceInfo
{
    QString name;
    QString id;
    Optional<int> transportType;
    Optional<bool> isSDLAllowed;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("name", name).set("id", id)
           .set("transportType", transportType).set("isSDLAllowed", isSDLAllowed);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("name", name).get("id", id)
           .get("transportType", transportType).get("isSDLAllowed", isSDLAllowed);
    }
    IMPLICIT_CASTING(DeviceInfo)
};

DECLARE_STRUCT(DeviceInfo)

#endif // DEVICEINFO_H
