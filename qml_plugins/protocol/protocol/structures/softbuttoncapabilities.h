#ifndef SOFTBUTTONCAPABILITIES_H
#define SOFTBUTTONCAPABILITIES_H
#include "core/struct.h"

struct SoftButtonCapabilities
{
    bool shortPressAvailable;
    bool longPressAvailable;
    bool upDownAvailable;
    bool imageSupported;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("shortPressAvailable", shortPressAvailable)
           .set("longPressAvailable", longPressAvailable)
           .set("upDownAvailable", upDownAvailable)
           .set("imageSupported", imageSupported);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("shortPressAvailable", shortPressAvailable)
           .get("longPressAvailable", longPressAvailable)
           .get("upDownAvailable", upDownAvailable)
           .get("imageSupported", imageSupported);
    }
    IMPLICIT_CASTING(SoftButtonCapabilities)
};

DECLARE_STRUCT(SoftButtonCapabilities)

#endif // SOFTBUTTONCAPABILITIES_H
