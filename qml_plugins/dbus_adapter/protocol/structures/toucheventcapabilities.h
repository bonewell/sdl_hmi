#ifndef TOUCHEVENTCAPABILITIES_H
#define TOUCHEVENTCAPABILITIES_H
#include "core/struct.h"

struct TouchEventCapabilities
{
    bool pressAvailable;
    bool multiTouchAvailable;
    bool doublePressAvailable;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("pressAvailable", pressAvailable)
           .set("multiTouchAvailable", multiTouchAvailable)
           .set("doublePressAvailable", doublePressAvailable);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("pressAvailable", pressAvailable)
           .get("multiTouchAvailable", multiTouchAvailable)
           .get("doublePressAvailable", doublePressAvailable);
    }
    IMPLICIT_CASTING(TouchEventCapabilities)
};

DECLARE_STRUCT(TouchEventCapabilities)

#endif // TOUCHEVENTCAPABILITIES_H
