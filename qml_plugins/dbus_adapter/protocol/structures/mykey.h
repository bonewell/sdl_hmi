#ifndef MYKEY_H
#define MYKEY_H
#include "core/struct.h"

struct MyKey
{
    int e911Override;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("e911Override", e911Override);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("e911Override", e911Override);
    }
    IMPLICIT_CASTING(MyKey)
};

DECLARE_STRUCT(MyKey)

#endif // MYKEY_H
