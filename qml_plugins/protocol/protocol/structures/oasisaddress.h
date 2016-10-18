#ifndef OASISADDRESS_H
#define OASISADDRESS_H
#include "core/struct.h"
#include <QString>

struct OASISAddress
{
    Optional<QString> countryName;
    Optional<QString> countryCode;
    Optional<QString> postalCode;
    Optional<QString> administrativeArea;
    Optional<QString> subAdministrativeArea;
    Optional<QString> locality;
    Optional<QString> subLocality;
    Optional<QString> thoroughfare;
    Optional<QString> subThoroughfare;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("countryName", countryName).set("countryCode", countryCode)
           .set("postalCode", postalCode).set("administrativeArea", administrativeArea)
           .set("subAdministrativeArea", subAdministrativeArea).set("locality", locality)
           .set("subLocality", subLocality).set("thoroughfare", thoroughfare)
           .set("subThoroughfare", subThoroughfare);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("countryName", countryName).get("countryCode", countryCode)
           .get("postalCode", postalCode).get("administrativeArea", administrativeArea)
           .get("subAdministrativeArea", subAdministrativeArea).get("locality", locality)
           .get("subLocality", subLocality).get("thoroughfare", thoroughfare)
           .get("subThoroughfare", subThoroughfare);
    }
    IMPLICIT_CASTING(OASISAddress)
};

DECLARE_STRUCT(OASISAddress)

#endif // OASISADDRESS_H
