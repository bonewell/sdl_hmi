#ifndef TIMEFORMAT_H
#define TIMEFORMAT_H
#include "core/struct.h"

struct TimeFormat
{
    int hours;
    int minutes;
    int seconds;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("hours", hours).set("minutes", minutes).set("seconds", seconds);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("hours", hours).get("minutes", minutes).get("seconds", seconds);
    }
    IMPLICIT_CASTING(TimeFormat)
};

DECLARE_STRUCT(TimeFormat)

#endif // TIMEFORMAT_H
