#ifndef TTSCHUNK_H
#define TTSCHUNK_H
#include "core/struct.h"
#include <QString>

struct TTSChunk
{
    QString text;
    int type;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("text", text).set("type", type);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("text", text).get("type", type);
    }
    IMPLICIT_CASTING(TTSChunk)
};

DECLARE_STRUCT(TTSChunk)

#endif // TTSCHUNK_H
