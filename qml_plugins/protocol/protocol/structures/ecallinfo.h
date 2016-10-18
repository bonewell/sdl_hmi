#ifndef ECALLINFO_H
#define ECALLINFO_H
#include "core/struct.h"

struct ECallInfo
{
    int eCallNotificationStatus;
    int auxECallNotificationStatus;
    int eCallConfirmationStatus;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("eCallNotificationStatus", eCallNotificationStatus)
           .set("auxECallNotificationStatus", auxECallNotificationStatus)
           .set("eCallConfirmationStatus", eCallConfirmationStatus);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("eCallNotificationStatus", eCallNotificationStatus)
           .get("auxECallNotificationStatus", auxECallNotificationStatus)
           .get("eCallConfirmationStatus", eCallConfirmationStatus);
    }
    IMPLICIT_CASTING(ECallInfo)
};

DECLARE_STRUCT(ECallInfo)

#endif // ECALLINFO_H
