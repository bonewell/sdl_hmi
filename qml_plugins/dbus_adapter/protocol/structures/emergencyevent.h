#ifndef EMERGENCYEVENT_H
#define EMERGENCYEVENT_H
#include "core/struct.h"

struct EmergencyEvent
{
    int emergencyEventType;
    int fuelCutoffStatus;
    int rolloverEvent;
    int maximumChangeVelocity;
    int multipleEvents;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("emergencyEventType", emergencyEventType)
           .set("fuelCutoffStatus", fuelCutoffStatus)
           .set("rolloverEvent", rolloverEvent)
           .set("maximumChangeVelocity", maximumChangeVelocity)
           .set("multipleEvents", multipleEvents);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("emergencyEventType", emergencyEventType)
           .get("fuelCutoffStatus", fuelCutoffStatus)
           .get("rolloverEvent", rolloverEvent)
           .get("maximumChangeVelocity", maximumChangeVelocity)
           .get("multipleEvents", multipleEvents);
    }
    IMPLICIT_CASTING(EmergencyEvent)
};

DECLARE_STRUCT(EmergencyEvent)

#endif // EMERGENCYEVENT_H
