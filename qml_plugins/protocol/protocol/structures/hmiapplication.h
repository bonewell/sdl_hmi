#ifndef HMIAPPLICATION_H
#define HMIAPPLICATION_H
#include "core/struct.h"
#include <QString>
#include "ttschunk.h"
#include "deviceinfo.h"

struct HMIApplication
{
    QString appName;
    Optional<QString> ngnMediaScreenAppName;
    Optional<QString> icon;
    DeviceInfo deviceInfo;
    QString policyAppID;
    Optional<QList<TTSChunk> > ttsName;
    Optional<QStringList> vrSynonyms;
    int appID;
    Optional<int> hmiDisplayLanguageDesired;
    Optional<bool> isMediaApplication;
    Optional<QList<int> > appType;
    Optional<bool> greyOut;
    Optional<QList<int> > requestType;
    template<class T>
    void pack(Argument<T> &arg) const {
        arg.set("appName", appName).set("ngnMediaScreenAppName", ngnMediaScreenAppName)
           .set("icon", icon).set("deviceInfo", deviceInfo).set("policyAppID", policyAppID)
           .set("ttsName", ttsName).set("vrSynonyms", vrSynonyms).set("appID", appID)
           .set("hmiDisplayLanguageDesired", hmiDisplayLanguageDesired)
           .set("isMediaApplication", isMediaApplication).set("appType", appType)
           .set("greyOut", greyOut).set("requestType", requestType);
    }
    template<class T>
    void extract(const Argument<const T> &arg) {
        arg.get("appName", appName).get("ngnMediaScreenAppName", ngnMediaScreenAppName)
           .get("icon", icon).get("deviceInfo", deviceInfo).get("policyAppID", policyAppID)
           .get("ttsName", ttsName).get("vrSynonyms", vrSynonyms).get("appID", appID)
           .get("hmiDisplayLanguageDesired", hmiDisplayLanguageDesired)
           .get("isMediaApplication", isMediaApplication).get("appType", appType)
           .get("greyOut", greyOut).get("requestType", requestType);
    }
    IMPLICIT_CASTING(HMIApplication)
};

DECLARE_STRUCT(HMIApplication)

#endif // HMIAPPLICATION_H
