#ifndef CLUSTERMODESTATUS_H
#define CLUSTERMODESTATUS_H
#include "core/struct.h"

struct ClusterModeStatus
{
    bool powerModeActive;
    int powerModeQualificationStatus;
    int carModeStatus;
    int powerModeStatus;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("powerModeActive", powerModeActive)
           .set("powerModeQualificationStatus", powerModeQualificationStatus)
           .set("carModeStatus", carModeStatus)
           .set("powerModeStatus", powerModeStatus);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("powerModeActive", powerModeActive)
           .get("powerModeQualificationStatus", powerModeQualificationStatus)
           .get("carModeStatus", carModeStatus)
           .get("powerModeStatus", powerModeStatus);
    }
    IMPLICIT_CASTING(ClusterModeStatus)
};

DECLARE_STRUCT(ClusterModeStatus)

#endif // CLUSTERMODESTATUS_H
