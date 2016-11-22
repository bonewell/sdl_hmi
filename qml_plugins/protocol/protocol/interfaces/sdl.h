#ifndef SDL_H
#define SDL_H

#include "core/abstractadapter.h"
#include "protocol/structures.h"

#define SDL_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.SDL\">" \
    "<signal name=\"OnAllowSDLFunctionality\">" \
    "<arg name=\"device\" type=\"(b(ss(bi)(bb)))\" />" \
    "<arg name=\"allowed\" type=\"b\" />" \
    "<arg name=\"source\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnReceivedPolicyUpdate\">" \
    "<arg name=\"policyfile\" type=\"s\" />" \
    "</signal>" \
    "<signal name=\"OnPolicyUpdate\" />" \
    "<signal name=\"OnAppPermissionConsent\">" \
    "<arg name=\"appID\" type=\"(bi)\" />" \
    "<arg name=\"consentedFunctions\" type=\"a(si(bb))\" />" \
    "<arg name=\"source\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnSystemError\">" \
    "<arg name=\"error\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"AddStatisticsInfo\">" \
    "<arg name=\"statisticType\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnDeviceStateChanged\">" \
    "<arg name=\"deviceState\" type=\"i\" />" \
    "<arg name=\"deviceInternalId\" type=\"s\" />" \
    "<arg name=\"deviceId\" type=\"(b(ss(bi)(bb)))\" />" \
    "</signal>" \
    "</interface>"

class SDL;

class SDLAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO(1000, "com.ford.sdl.hmi.SDL", SDL_INTROSPECTION)
    REGISTER_ADAPTER(SDLAdapter, SDL)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.SDL")

private slots:
    void OnAppPermissionChanged(int appID, const Optional<bool>& isAppPermissionsRevoked,
        const Optional<QList<PermissionItem> >& appRevokedPermissions,
        const Optional<bool>& appRevoked, const Optional<bool>& appPermissionsConsentNeeded,
        const Optional<bool>& appUnauthorized, const Optional<int>& priority,
        const Optional<QList<int> >& requestType);
    void OnSDLConsentNeeded(const DeviceInfo& device);
    void OnStatusUpdate(int status);

public:
    void ActivateApp(const QJSValue& callback, int appID);
    void GetUserFriendlyMessage(const QJSValue& callback,
        const QStringList& messageCodes, const Optional<int>& language);
    void GetListOfPermissions(const QJSValue& callback, const Optional<int>& appID);
    void UpdateSDL(const QJSValue& callback);
    void GetStatusUpdate(const QJSValue& callback);
    void GetURLS(const QJSValue& callback, int service);
};

class SDL : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(SDL, SDLAdapter)

public:
    Q_INVOKABLE void onAllowSDLFunctionality(const QVariant& device,
        bool allowed, int source);
    Q_INVOKABLE void onReceivedPolicyUpdate(const QString& policyfile);
    Q_INVOKABLE void onPolicyUpdate();
    Q_INVOKABLE void onAppPermissionConsent(const QVariant& appID,
        const QVariantList& consentedFunctions, int source);
    Q_INVOKABLE void onSystemError(int error);
    Q_INVOKABLE void addStatisticsInfo(int statisticType);
    Q_INVOKABLE void onDeviceStateChanged(int deviceState,
        const QString& deviceInternalId, const QVariant& deviceId = QVariant());

    Q_INVOKABLE void activateApp(const QJSValue& callback, int appID);
    Q_INVOKABLE void getUserFriendlyMessage(const QJSValue& callback,
        const QStringList& messageCodes, const QVariant& language = QVariant());
    Q_INVOKABLE void getListOfPermissions(const QJSValue& callback,
        const QVariant& appID = QVariant());
    Q_INVOKABLE void updateSDL(const QJSValue& callback);
    Q_INVOKABLE void getStatusUpdate(const QJSValue& callback);
    Q_INVOKABLE void getURLS(const QJSValue& callback, int service);

signals:
    void onAppPermissionChanged(int appID, const QVariant& isAppPermissionsRevoked,
        const QVariant& appRevokedPermissions, const QVariant& appRevoked,
        const QVariant& appPermissionsConsentNeeded, const QVariant& appUnauthorized,
        const QVariant& priority, const QVariant& requestType);
    void onSDLConsentNeeded(const QVariantMap& device);
    void onStatusUpdate(int status);
};

#endif // SDL_H
