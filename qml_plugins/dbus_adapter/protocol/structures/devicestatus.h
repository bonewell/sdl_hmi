#ifndef DEVICESTATUS_H
#define DEVICESTATUS_H
#include "core/struct.h"

struct DeviceStatus
{
    Optional<bool> voiceRecOn;
    Optional<bool> btIconOn;
    Optional<bool> callActive;
    Optional<bool> phoneRoaming;
    Optional<bool> textMsgAvailable;
    Optional<int> battLevelStatus;
    Optional<bool> stereoAudioOutputMuted;
    Optional<bool> monoAudioOutputMuted;
    Optional<int> signalLevelStatus;
    Optional<int> primaryAudioSource;
    Optional<bool> eCallEventActive;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("voiceRecOn", voiceRecOn).set("btIconOn", btIconOn)
           .set("callActive", callActive).set("phoneRoaming", phoneRoaming)
           .set("textMsgAvailable", textMsgAvailable)
           .set("battLevelStatus", battLevelStatus)
           .set("stereoAudioOutputMuted", stereoAudioOutputMuted)
           .set("monoAudioOutputMuted", monoAudioOutputMuted)
           .set("signalLevelStatus", signalLevelStatus)
           .set("primaryAudioSource", primaryAudioSource)
           .set("eCallEventActive", eCallEventActive);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("voiceRecOn", voiceRecOn).get("btIconOn", btIconOn)
           .get("callActive", callActive).get("phoneRoaming", phoneRoaming)
           .get("textMsgAvailable", textMsgAvailable)
           .get("battLevelStatus", battLevelStatus)
           .get("stereoAudioOutputMuted", stereoAudioOutputMuted)
           .get("monoAudioOutputMuted", monoAudioOutputMuted)
           .get("signalLevelStatus", signalLevelStatus)
           .get("primaryAudioSource", primaryAudioSource)
           .get("eCallEventActive", eCallEventActive);
    }
    IMPLICIT_CASTING(DeviceStatus)
};

DECLARE_STRUCT(DeviceStatus)

#endif // DEVICESTATUS_H
