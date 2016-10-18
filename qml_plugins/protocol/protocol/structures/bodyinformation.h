#ifndef BODYINFORMATION_H
#define BODYINFORMATION_H
#include "core/struct.h"

struct BodyInformation
{
    bool parkBrakeActive;
    int ignitionStableStatus;
    int ignitionStatus;
    Optional<bool> driverDoorAjar;
    Optional<bool> passengerDoorAjar;
    Optional<bool> rearLeftDoorAjar;
    Optional<bool> rearRightDoorAjar;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("parkBrakeActive", parkBrakeActive)
           .set("ignitionStableStatus", ignitionStableStatus)
           .set("ignitionStatus", ignitionStatus)
           .set("driverDoorAjar", driverDoorAjar)
           .set("passengerDoorAjar", passengerDoorAjar)
           .set("rearLeftDoorAjar", rearLeftDoorAjar)
           .set("rearRightDoorAjar", rearRightDoorAjar);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("parkBrakeActive", parkBrakeActive)
           .get("ignitionStableStatus", ignitionStableStatus)
           .get("ignitionStatus", ignitionStatus)
           .get("driverDoorAjar", driverDoorAjar)
           .get("passengerDoorAjar", passengerDoorAjar)
           .get("rearLeftDoorAjar", rearLeftDoorAjar)
           .get("rearRightDoorAjar", rearRightDoorAjar);
    }
    IMPLICIT_CASTING(BodyInformation)
};

DECLARE_STRUCT(BodyInformation)

#endif // BODYINFORMATION_H
