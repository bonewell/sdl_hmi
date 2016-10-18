#ifndef COORDINATE_H
#define COORDINATE_H
#include "core/struct.h"

struct Coordinate
{
    double latitudeDegrees;
    double longitudeDegrees;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("latitudeDegrees", latitudeDegrees)
           .set("longitudeDegrees", longitudeDegrees);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("latitudeDegrees", latitudeDegrees)
           .get("longitudeDegrees", longitudeDegrees);
    }
    IMPLICIT_CASTING(Coordinate)
};

DECLARE_STRUCT(Coordinate)

#endif // COORDINATE_H
