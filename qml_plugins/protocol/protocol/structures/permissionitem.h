#ifndef PERMISSIONITEM_H
#define PERMISSIONITEM_H
#include "core/struct.h"
#include <QString>

struct PermissionItem
{
    QString name;
    int id;
    Optional<bool> allowed;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("name", name).set("id", id).set("allowed", allowed);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("name", name).get("id", id).get("allowed", allowed);
    }
    IMPLICIT_CASTING(PermissionItem)
};

DECLARE_STRUCT(PermissionItem)

#endif // PERMISSIONITEM_H
