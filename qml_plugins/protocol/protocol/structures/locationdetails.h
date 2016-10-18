#ifndef LOCATIONDETAILS_H
#define LOCATIONDETAILS_H
#include "core/struct.h"
#include <QString>
#include "coordinate.h"
#include "image.h"
#include "oasisaddress.h"

struct LocationDetails
{
    Optional<Coordinate> coordinate;
    Optional<QString> locationName;
    Optional<QStringList> addressLines;
    Optional<QString> locationDescription;
    Optional<QString> phoneNumber;
    Optional<Image> locationImage;
    Optional<OASISAddress> searchAddress;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("coordinate", coordinate).set("locationName", locationName)
           .set("addressLines", addressLines)
           .set("locationDescription", locationDescription)
           .set("phoneNumber", phoneNumber).set("locationImage", locationImage)
           .set("searchAddress", searchAddress);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("coordinate", coordinate).get("locationName", locationName)
           .get("addressLines", addressLines)
           .get("locationDescription", locationDescription)
           .get("phoneNumber", phoneNumber).get("locationImage", locationImage)
           .get("searchAddress", searchAddress);
    }
    IMPLICIT_CASTING(LocationDetails)
};

DECLARE_STRUCT(LocationDetails)

#endif // LOCATIONDETAILS_H
