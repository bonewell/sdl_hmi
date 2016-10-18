#ifndef BELTSTATUS_H
#define BELTSTATUS_H
#include "core/struct.h"

struct BeltStatus
{
    Optional<int> driverBeltDeployed;
    Optional<int> passengerBeltDeployed;
    Optional<int> passengerBuckleBelted;
    Optional<int> driverBuckleBelted;
    Optional<int> leftRow2BuckleBelted;
    Optional<int> passengerChildDetected;
    Optional<int> rightRow2BuckleBelted;
    Optional<int> middleRow2BuckleBelted;
    Optional<int> middleRow3BuckleBelted;
    Optional<int> leftRow3BuckleBelted;
    Optional<int> rightRow3BuckleBelted;
    Optional<int> leftRearInflatableBelted;
    Optional<int> rightRearInflatableBelted;
    Optional<int> middleRow1BeltDeployed;
    Optional<int> middleRow1BuckleBelted;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("driverBeltDeployed", driverBeltDeployed)
           .set("passengerBeltDeployed", passengerBeltDeployed)
           .set("passengerBuckleBelted", passengerBuckleBelted)
           .set("driverBuckleBelted", driverBuckleBelted)
           .set("leftRow2BuckleBelted", leftRow2BuckleBelted)
           .set("passengerChildDetected", passengerChildDetected)
           .set("rightRow2BuckleBelted", rightRow2BuckleBelted)
           .set("middleRow2BuckleBelted", middleRow2BuckleBelted)
           .set("middleRow3BuckleBelted", middleRow3BuckleBelted)
           .set("leftRow3BuckleBelted", leftRow3BuckleBelted)
           .set("rightRow3BuckleBelted", rightRow3BuckleBelted)
           .set("leftRearInflatableBelted", leftRearInflatableBelted)
           .set("rightRearInflatableBelted", rightRearInflatableBelted)
           .set("middleRow1BeltDeployed", middleRow1BeltDeployed)
           .set("middleRow1BuckleBelted", middleRow1BuckleBelted);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("driverBeltDeployed", driverBeltDeployed)
           .get("passengerBeltDeployed", passengerBeltDeployed)
           .get("passengerBuckleBelted", passengerBuckleBelted)
           .get("driverBuckleBelted", driverBuckleBelted)
           .get("leftRow2BuckleBelted", leftRow2BuckleBelted)
           .get("passengerChildDetected", passengerChildDetected)
           .get("rightRow2BuckleBelted", rightRow2BuckleBelted)
           .get("middleRow2BuckleBelted", middleRow2BuckleBelted)
           .get("middleRow3BuckleBelted", middleRow3BuckleBelted)
           .get("leftRow3BuckleBelted", leftRow3BuckleBelted)
           .get("rightRow3BuckleBelted", rightRow3BuckleBelted)
           .get("leftRearInflatableBelted", leftRearInflatableBelted)
           .get("rightRearInflatableBelted", rightRearInflatableBelted)
           .get("middleRow1BeltDeployed", middleRow1BeltDeployed)
           .get("middleRow1BuckleBelted", middleRow1BuckleBelted);
    }
    IMPLICIT_CASTING(BeltStatus)
};

DECLARE_STRUCT(BeltStatus)

#endif // BELTSTATUS_H
