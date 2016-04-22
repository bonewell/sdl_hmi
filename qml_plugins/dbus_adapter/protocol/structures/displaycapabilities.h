#ifndef DISPLAYCAPABILITIES_H
#define DISPLAYCAPABILITIES_H
#include "core/struct.h"
#include <QString>
#include <QList>
#include "textfield.h"
#include "imagefield.h"
#include "screenparams.h"

struct DisplayCapabilities
{
    int displayType;
    QList<TextField> textFields;
    Optional<QList<ImageField> > imageFields;
    QList<int> mediaClockFormats;
    Optional<QList<int> > imageCapabilities;
    bool graphicSupported;
    QStringList templatesAvailable;
    Optional<ScreenParams> screenParams;
    Optional<int> numCustomPresetsAvailable;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("displayType", displayType).set("textFields", textFields)
           .set("imageFields", imageFields).set("mediaClockFormats", mediaClockFormats)
           .set("imageCapabilities", imageCapabilities).set("graphicSupported", graphicSupported)
           .set("templatesAvailable", templatesAvailable).set("screenParams", screenParams)
           .set("numCustomPresetsAvailable", numCustomPresetsAvailable);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("displayType", displayType).get("textFields", textFields)
           .get("imageFields", imageFields).get("mediaClockFormats", mediaClockFormats)
           .get("imageCapabilities", imageCapabilities).get("graphicSupported", graphicSupported)
           .get("templatesAvailable", templatesAvailable).get("screenParams", screenParams)
           .get("numCustomPresetsAvailable", numCustomPresetsAvailable);
    }
    IMPLICIT_CASTING(DisplayCapabilities)
};

DECLARE_STRUCT(DisplayCapabilities)

#endif // DISPLAYCAPABILITIES_H
