#ifndef DATETIME_H
#define DATETIME_H
#include "core/struct.h"

struct DateTime
{
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
    int tz_hour;
    int tz_minute;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("second", second).set("minute", minute)
           .set("hour", hour).set("day", day)
           .set("month", month).set("year", year)
           .set("tz_hour", tz_hour).set("tz_minute", tz_minute);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("second", second).get("minute", minute)
           .get("hour", hour).get("day", day)
           .get("month", month).get("year", year)
           .get("tz_hour", tz_hour).get("tz_minute", tz_minute);
    }
    IMPLICIT_CASTING(DateTime)
};

DECLARE_STRUCT(DateTime)

#endif // DATETIME_H
