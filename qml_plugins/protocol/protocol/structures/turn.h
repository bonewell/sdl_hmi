#ifndef TURN_H
#define TURN_H
#include "core/struct.h"
#include "textfieldstruct.h"
#include "image.h"

struct Turn
{
    Optional<TextFieldStruct> navigationText;
    Optional<Image> turnIcon;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("navigationText", navigationText).set("turnIcon", turnIcon);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("navigationText", navigationText).get("turnIcon", turnIcon);
    }
    IMPLICIT_CASTING(Turn)
};

DECLARE_STRUCT(Turn)

#endif // TURN_H
