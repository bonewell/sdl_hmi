#ifndef PRESETBANKCAPABILITIES_H
#define PRESETBANKCAPABILITIES_H
#include "core/struct.h"

struct PresetBankCapabilities
{
    bool onScreenPresetsAvailable;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("onScreenPresetsAvailable", onScreenPresetsAvailable);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("onScreenPresetsAvailable", onScreenPresetsAvailable);
    }
    IMPLICIT_CASTING(PresetBankCapabilities)
};

DECLARE_STRUCT(PresetBankCapabilities)

#endif // PRESETBANKCAPABILITIES_H
