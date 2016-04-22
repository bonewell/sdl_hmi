#ifndef CHOICE_H
#define CHOICE_H
#include "core/struct.h"
#include <QString>
#include "image.h"

struct Choice
{
    int choiceID;
    Optional<QString> menuName;
    Optional<Image> image;
    Optional<QString> secondaryText;
    Optional<QString> tertiaryText;
    Optional<Image> secondaryImage;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("choiceID", choiceID).set("menuName", menuName).set("image", image)
           .set("secondaryText", secondaryText).set("tertiaryText", tertiaryText)
           .set("secondaryImage", secondaryImage);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("choiceID", choiceID).get("menuName", menuName).get("image", image)
           .get("secondaryText", secondaryText).get("tertiaryText", tertiaryText)
           .get("secondaryImage", secondaryImage);
    }
    IMPLICIT_CASTING(Choice)
};

DECLARE_STRUCT(Choice)

#endif // CHOICE_H
