#ifndef SCREENPARAMS_H
#define SCREENPARAMS_H
#include "core/struct.h"
#include <QString>
#include "imageresolution.h"
#include "toucheventcapabilities.h"

struct ScreenParams
{
    ImageResolution resolution;
    Optional<TouchEventCapabilities> touchEventAvailable;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("resolution", resolution)
           .set("touchEventAvailable", touchEventAvailable);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("resolution", resolution)
           .get("touchEventAvailable", touchEventAvailable);
    }
    IMPLICIT_CASTING(ScreenParams)
};

DECLARE_STRUCT(ScreenParams)

#endif // SCREENPARAMS_H
