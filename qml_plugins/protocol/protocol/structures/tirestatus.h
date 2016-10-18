#ifndef TIRESTATUS_H
#define TIRESTATUS_H
#include "core/struct.h"
#include "singletirestatus.h"

struct TireStatus
{
    Optional<int> pressureTelltale;
    Optional<SingleTireStatus> leftFront;
    Optional<SingleTireStatus> rightFront;
    Optional<SingleTireStatus> leftRear;
    Optional<SingleTireStatus> rightRear;
    Optional<SingleTireStatus> innerLeftRear;
    Optional<SingleTireStatus> innerRightRear;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("pressureTelltale", pressureTelltale).set("leftFront", leftFront)
           .set("rightFront", rightFront).set("leftRear", leftRear)
           .set("rightRear", rightRear).set("innerLeftRear", innerLeftRear)
           .set("innerRightRear", innerRightRear);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("pressureTelltale", pressureTelltale).get("leftFront", leftFront)
           .get("rightFront", rightFront).get("leftRear", leftRear)
           .get("rightRear", rightRear).get("innerLeftRear", innerLeftRear)
           .get("innerRightRear", innerRightRear);
    }
    IMPLICIT_CASTING(TireStatus)
};

DECLARE_STRUCT(TireStatus)

#endif // TIRESTATUS_H
