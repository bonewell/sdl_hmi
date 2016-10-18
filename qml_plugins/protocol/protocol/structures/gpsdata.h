#ifndef GPSDATA_H
#define GPSDATA_H
#include "core/struct.h"

struct GPSData
{
    Optional<double> longitudeDegrees;
    Optional<double> latitudeDegrees;
    Optional<int> utcYear;
    Optional<int> utcMonth;
    Optional<int> utcDay;
    Optional<int> utcHours;
    Optional<int> utcMinutes;
    Optional<int> utcSeconds;
    Optional<int> compassDirection;
    Optional<double> pdop;
    Optional<double> hdop;
    Optional<double> vdop;
    Optional<bool> actual;
    Optional<int> satellites;
    Optional<int> dimension;
    Optional<double> altitude;
    Optional<double> heading;
    Optional<double> speed;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("longitudeDegrees", longitudeDegrees)
           .set("latitudeDegrees", latitudeDegrees).set("utcYear", utcYear)
           .set("utcMonth", utcMonth).set("utcDay", utcDay).set("utcHours", utcHours)
           .set("utcMinutes", utcMinutes).set("utcSeconds", utcSeconds)
           .set("compassDirection", compassDirection).set("pdop", pdop)
           .set("pdop", pdop).set("hdop", hdop).set("vdop", vdop).set("actual", actual)
           .set("satellites", satellites).set("dimension", dimension).set("altitude", altitude)
           .set("heading", heading).set("speed", speed);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("longitudeDegrees", longitudeDegrees)
           .get("latitudeDegrees", latitudeDegrees).get("utcYear", utcYear)
           .get("utcMonth", utcMonth).get("utcDay", utcDay).get("utcHours", utcHours)
           .get("utcMinutes", utcMinutes).get("utcSeconds", utcSeconds)
           .get("compassDirection", compassDirection).get("pdop", pdop)
           .get("pdop", pdop).get("hdop", hdop).get("vdop", vdop).get("actual", actual)
           .get("satellites", satellites).get("dimension", dimension).get("altitude", altitude)
           .get("heading", heading).get("speed", speed);
    }
    IMPLICIT_CASTING(GPSData)
};

DECLARE_STRUCT(GPSData)

#endif // GPSDATA_H
