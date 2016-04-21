#ifndef TEXTFIELDSTRUCT_H
#define TEXTFIELDSTRUCT_H
#include "core/struct.h"
#include <QString>

struct TextFieldStruct
{
    int fieldName;
    QString fieldText;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("fieldName", fieldName).set("fieldText", fieldText);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("fieldName", fieldName).get("fieldText", fieldText);
    }
    IMPLICIT_CASTING(TextFieldStruct)
};

DECLARE_STRUCT(TextFieldStruct)

#endif // TEXTFIELDSTRUCT_H
