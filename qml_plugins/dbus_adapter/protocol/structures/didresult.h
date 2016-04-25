#ifndef DIDRESULT_H
#define DIDRESULT_H
#include "core/struct.h"
#include <QString>

struct DIDResult
{
    int resultCode;
    int didLocation;
    Optional<QString> data;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("resultCode", resultCode).set("didLocation", didLocation)
           .set("data", data);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("resultCode", resultCode).get("didLocation", didLocation)
           .get("data", data);
    }
    IMPLICIT_CASTING(DIDResult)
};

DECLARE_STRUCT(DIDResult)

#endif // DIDRESULT_H
