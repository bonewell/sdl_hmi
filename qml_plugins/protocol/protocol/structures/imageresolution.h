#ifndef IMAGERESOLUTION_H
#define IMAGERESOLUTION_H
#include "core/struct.h"

struct ImageResolution
{
    int resolutionWidth;
    int resolutionHeight;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("resolutionWidth", resolutionWidth)
           .set("resolutionHeight", resolutionHeight);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("resolutionWidth", resolutionWidth)
           .get("resolutionHeight", resolutionHeight);
    }
    IMPLICIT_CASTING(ImageResolution)
};

DECLARE_STRUCT(ImageResolution)

#endif // IMAGERESOLUTION_H
