#ifndef AUDIOPASSTHRUCAPABILITIES_H
#define AUDIOPASSTHRUCAPABILITIES_H
#include "core/struct.h"

struct AudioPassThruCapabilities
{
    int samplingRate;
    int bitsPerSample;
    int audioType;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("samplingRate", samplingRate)
           .set("bitsPerSample", bitsPerSample)
           .set("audioType", audioType);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("samplingRate", samplingRate)
           .get("bitsPerSample", bitsPerSample)
           .get("audioType", audioType);
    }
    IMPLICIT_CASTING(AudioPassThruCapabilities)
};

DECLARE_STRUCT(AudioPassThruCapabilities)

#endif // AUDIOPASSTHRUCAPABILITIES_H
