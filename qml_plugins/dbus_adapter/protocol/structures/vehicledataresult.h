#ifndef VEHICLEDATARESULT_H
#define VEHICLEDATARESULT_H
#include "core/struct.h"

struct VehicleDataResult
{
    int dataType;
    int resultCode;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("dataType", dataType).set("resultCode", resultCode);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("dataType", dataType).get("resultCode", resultCode);
    }
    IMPLICIT_CASTING(VehicleDataResult)
};

DECLARE_STRUCT(VehicleDataResult)

#endif // VEHICLEDATARESULT_H
