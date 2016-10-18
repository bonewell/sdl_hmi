#ifndef TOUCHCOORD_H
#define TOUCHCOORD_H
#include "core/struct.h"

struct TouchCoord
{
    int x;
    int y;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("x", x).set("y", y);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("x", x).get("y", y);
    }
    IMPLICIT_CASTING(TouchCoord)
};

DECLARE_STRUCT(TouchCoord)

#endif // TOUCHCOORD_H
