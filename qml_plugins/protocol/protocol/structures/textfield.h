#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#include "core/struct.h"

struct TextField
{
    int name;
    int characterSet;
    int width;
    int rows;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("name", name).set("characterSet", characterSet)
           .set("width", width).set("rows", rows);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("name", name).get("characterSet", characterSet)
           .get("width", width).get("rows", rows);
    }
    IMPLICIT_CASTING(TextField)
};

DECLARE_STRUCT(TextField)

#endif // TEXTFIELD_H
