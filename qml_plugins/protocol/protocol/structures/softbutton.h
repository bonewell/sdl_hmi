#ifndef SOFTBUTTON_H
#define SOFTBUTTON_H
#include "core/struct.h"
#include <QString>
#include "image.h"

struct SoftButton
{
    int type;
    Optional<QString> text;
    Optional<Image> image;
    Optional<bool> isHighlighted;
    int softButtonID;
    int systemAction;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("type", type).set("text", text).set("image", image)
           .set("isHighlighted", isHighlighted).set("softButtonID", softButtonID)
           .set("systemAction", systemAction);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("type", type).get("text", text).get("image", image)
           .get("isHighlighted", isHighlighted).get("softButtonID", softButtonID)
           .get("systemAction", systemAction);
    }
    IMPLICIT_CASTING(SoftButton)
};

DECLARE_STRUCT(SoftButton)

#endif // SOFTBUTTON_H
