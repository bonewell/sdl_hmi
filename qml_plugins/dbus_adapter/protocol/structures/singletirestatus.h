#ifndef SINGLETIRESTATUS_H
#define SINGLETIRESTATUS_H
#include "core/struct.h"

struct SingleTireStatus
{
    int status;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("status", status);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("status", status);
    }
    IMPLICIT_CASTING(SingleTireStatus)
};

DECLARE_STRUCT(SingleTireStatus)

#endif // SINGLETIRESTATUS_H
