#ifndef AIRBAGSTATUS_H
#define AIRBAGSTATUS_H
#include "core/struct.h"

struct AirbagStatus
{
    int driverAirbagDeployed;
    int driverSideAirbagDeployed;
    int driverCurtainAirbagDeployed;
    int passengerAirbagDeployed;
    int passengerCurtainAirbagDeployed;
    int driverKneeAirbagDeployed;
    int passengerSideAirbagDeployed;
    int passengerKneeAirbagDeployed;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("driverAirbagDeployed", driverAirbagDeployed)
           .set("driverSideAirbagDeployed", driverSideAirbagDeployed)
           .set("driverCurtainAirbagDeployed", driverCurtainAirbagDeployed)
           .set("passengerAirbagDeployed", passengerAirbagDeployed)
           .set("passengerCurtainAirbagDeployed", passengerCurtainAirbagDeployed)
           .set("driverKneeAirbagDeployed", driverKneeAirbagDeployed)
           .set("passengerSideAirbagDeployed", passengerSideAirbagDeployed)
           .set("passengerKneeAirbagDeployed", passengerKneeAirbagDeployed);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("driverAirbagDeployed", driverAirbagDeployed)
           .get("driverSideAirbagDeployed", driverSideAirbagDeployed)
           .get("driverCurtainAirbagDeployed", driverCurtainAirbagDeployed)
           .get("passengerAirbagDeployed", passengerAirbagDeployed)
           .get("passengerCurtainAirbagDeployed", passengerCurtainAirbagDeployed)
           .get("driverKneeAirbagDeployed", driverKneeAirbagDeployed)
           .get("passengerSideAirbagDeployed", passengerSideAirbagDeployed)
           .get("passengerKneeAirbagDeployed", passengerKneeAirbagDeployed);
    }
    IMPLICIT_CASTING(AirbagStatus)
};

DECLARE_STRUCT(AirbagStatus)

#endif // AIRBAGSTATUS_H
