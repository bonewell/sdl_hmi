#ifndef IMAGE_H
#define IMAGE_H
#include "core/struct.h"
#include <QString>

struct Image
{
    QString value;
    int imageType;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("value", value).set("imageType", imageType);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("value", value).get("imageType", imageType);
    }
    IMPLICIT_CASTING(Image)
};

DECLARE_STRUCT(Image)

#endif // IMAGE_H
