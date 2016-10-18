#ifndef HMICAPABILITIES_H
#define HMICAPABILITIES_H
#include "core/struct.h"

struct HMICapabilities
{
    Optional<bool> navigation;
    Optional<bool> phoneCall;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("navigation", navigation).set("phoneCall", phoneCall);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("navigation", navigation).get("phoneCall", phoneCall);
    }
    IMPLICIT_CASTING(HMICapabilities)
};

DECLARE_STRUCT(HMICapabilities)

#endif // HMICAPABILITIES_H
