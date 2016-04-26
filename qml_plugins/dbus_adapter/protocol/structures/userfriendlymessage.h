#ifndef USERFRIENDLYMESSAGE_H
#define USERFRIENDLYMESSAGE_H
#include "core/struct.h"
#include <QString>

struct UserFriendlyMessage
{
    QString messageCode;
    Optional<QString> ttsString;
    Optional<QString> label;
    Optional<QString> line1;
    Optional<QString> line2;
    Optional<QString> textBody;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("messageCode", messageCode).set("ttsString", ttsString)
           .set("label", label).set("line1", line1)
           .set("line2", line2).set("textBody", textBody);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("messageCode", messageCode).get("ttsString", ttsString)
           .get("label", label).get("line1", line1)
           .get("line2", line2).get("textBody", textBody);
    }
    IMPLICIT_CASTING(UserFriendlyMessage)
};

DECLARE_STRUCT(UserFriendlyMessage)

#endif // USERFRIENDLYMESSAGE_H
