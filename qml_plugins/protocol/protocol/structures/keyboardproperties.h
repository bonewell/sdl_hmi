#ifndef KEYBOARDPROPERTIES_H
#define KEYBOARDPROPERTIES_H
#include "core/struct.h"
#include <QString>

struct KeyboardProperties
{
    Optional<int> language;
    Optional<int> keyboardLayout;
    Optional<int> keypressMode;
    Optional<QStringList> limitedCharacterList;
    Optional<QString> autoCompleteText;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("language", language).set("keyboardLayout", keyboardLayout)
           .set("keypressMode", keypressMode)
           .set("limitedCharacterList", limitedCharacterList)
           .set("autoCompleteText", autoCompleteText);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("language", language).get("keyboardLayout", keyboardLayout)
           .get("keypressMode", keypressMode)
           .get("limitedCharacterList", limitedCharacterList)
           .get("autoCompleteText", autoCompleteText);
    }
    IMPLICIT_CASTING(KeyboardProperties)
};

DECLARE_STRUCT(KeyboardProperties)

#endif // KEYBOARDPROPERTIES_H
