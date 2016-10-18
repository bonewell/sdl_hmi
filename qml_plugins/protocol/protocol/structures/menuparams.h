#ifndef MENUPARAMS_H
#define MENUPARAMS_H
#include "core/struct.h"
#include <QString>

struct MenuParams
{
    Optional<int> parentID;
    Optional<int> position;
    QString menuName;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("parentID", parentID).set("position", position)
           .set("menuName", menuName);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("parentID", parentID).get("position", position)
           .get("menuName", menuName);
    }
    IMPLICIT_CASTING(MenuParams)
};

DECLARE_STRUCT(MenuParams)

#endif // MENUPARAMS_H
