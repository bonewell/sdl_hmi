#ifndef IMAGEFIELD_H
#define IMAGEFIELD_H
#include "core/struct.h"
#include <QList>
#include "imageresolution.h"

struct ImageField
{
    int name;
    Optional<QList<int> > imageTypeSupported;
    Optional<ImageResolution> imageResolution;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("name", name).set("imageTypeSupported", imageTypeSupported)
           .set("imageResolution", imageResolution);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("name", name).get("imageTypeSupported", imageTypeSupported)
           .get("imageResolution", imageResolution);
    }
    IMPLICIT_CASTING(ImageField)
};

DECLARE_STRUCT(ImageField)

#endif // IMAGEFIELD_H
