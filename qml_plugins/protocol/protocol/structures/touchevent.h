#ifndef TOUCHEVENT_H
#define TOUCHEVENT_H
#include "core/struct.h"
#include "touchcoord.h"

struct TouchEvent
{
    int id;
    QList<int> ts;
    QList<TouchCoord> c;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("id", id).set("ts", ts).set("c", c);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("id", id).get("ts", ts).get("c", c);
    }
    IMPLICIT_CASTING(TouchEvent)
};

DECLARE_STRUCT(TouchEvent)

#endif // TOUCHEVENT_H
