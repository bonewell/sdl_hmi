#ifndef VRHELPITEM_H
#define VRHELPITEM_H
#include "core/struct.h"
#include <QString>
#include "image.h"

struct VrHelpItem
{
    QString text;
    Optional<Image> image;
    int position;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("text", text).set("image", image).set("position", position);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("text", text).get("image", image).get("position", position);
    }
    IMPLICIT_CASTING(VrHelpItem)
};

DECLARE_STRUCT(VrHelpItem)

#endif // VRHELPITEM_H
