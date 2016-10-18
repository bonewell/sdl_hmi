#ifndef HEADLAMPSTATUS_H
#define HEADLAMPSTATUS_H
#include "core/struct.h"

struct HeadLampStatus
{
    bool lowBeamsOn;
    bool highBeamsOn;
    int ambientLightSensorStatus;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("lowBeamsOn", lowBeamsOn).set("highBeamsOn", highBeamsOn)
           .set("ambientLightSensorStatus", ambientLightSensorStatus);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("lowBeamsOn", lowBeamsOn).get("highBeamsOn", highBeamsOn)
           .get("ambientLightSensorStatus", ambientLightSensorStatus);
    }
    IMPLICIT_CASTING(HeadLampStatus)
};

DECLARE_STRUCT(HeadLampStatus)

#endif // HEADLAMPSTATUS_H
