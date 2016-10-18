#ifndef VEHICLETYPE_H
#define VEHICLETYPE_H
#include "core/struct.h"
#include <QString>

struct VehicleType
{
    Optional<QString> make;
    Optional<QString> model;
    Optional<QString> modelYear;
    Optional<QString> trim;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("make", make).set("model", model).set("modelYear", modelYear)
           .set("trim", trim);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("make", make).get("model", model).get("modelYear", modelYear)
           .get("trim", trim);
    }
    IMPLICIT_CASTING(VehicleType)
};

DECLARE_STRUCT(VehicleType)

#endif // VEHICLETYPE_H
