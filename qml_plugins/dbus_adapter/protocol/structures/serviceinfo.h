#ifndef SERVICEINFO_H
#define SERVICEINFO_H
#include "core/struct.h"
#include <QString>

struct ServiceInfo
{
    QString url;
    Optional<QString> policyAppId;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("url", url).set("policyAppId", policyAppId);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("url", url).get("policyAppId", policyAppId);
    }
    IMPLICIT_CASTING(ServiceInfo)
};

DECLARE_STRUCT(ServiceInfo)

#endif // SERVICEINFO_H
