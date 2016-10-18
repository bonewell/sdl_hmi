#ifndef BUTTONCAPABILITIES_H
#define BUTTONCAPABILITIES_H
#include "core/struct.h"

struct ButtonCapabilities
{
    int name;
    bool shortPressAvailable;
    bool longPressAvailable;
    bool upDownAvailable;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("name", name).set("shortPressAvailable", shortPressAvailable)
           .set("longPressAvailable", longPressAvailable)
           .set("upDownAvailable", upDownAvailable);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("name", name).get("shortPressAvailable", shortPressAvailable)
           .get("longPressAvailable", longPressAvailable)
           .get("upDownAvailable", upDownAvailable);
    }
    IMPLICIT_CASTING(ButtonCapabilities)
};

DECLARE_STRUCT(ButtonCapabilities)

#endif // BUTTONCAPABILITIES_H
