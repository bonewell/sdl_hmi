#include "sdl.h"

#include "core/method.h"

void SDLAdapter::OnAppPermissionChanged(int appID,
    const Optional<bool> &isAppPermissionsRevoked,
    const Optional<QList<PermissionItem> > &appRevokedPermissions,
    const Optional<bool> &appRevoked, const Optional<bool> &appPermissionsConsentNeeded,
    const Optional<bool> &appUnauthorized, const Optional<int> &priority,
    const Optional<QList<int> > &requestType)
{
    emit qml->onAppPermissionChanged(appID, isAppPermissionsRevoked,
        appRevokedPermissions, appRevoked, appPermissionsConsentNeeded,
                                     appUnauthorized, priority, requestType);
}

void SDLAdapter::OnSDLConsentNeeded(const DeviceInfo &device)
{
    emit qml->onSDLConsentNeeded(device);
}

void SDLAdapter::OnStatusUpdate(int status)
{
    emit qml->onStatusUpdate(status);
}

InitResponse(ActivateAppResponse)
{
    response.out<bool>("isSDLAllowe").out<Optional<DeviceInfo> >("device")
            .out<bool>("isPermissionsConsentNeeded")
            .out<bool>("isAppPermissionsRevoked")
            .out<Optional<QList<PermissionItem> > >("appRevokedPermissions")
            .out<bool>("isAppRevoked").out<Optional<int> >("priority").run();
}

InitResponse(GetUserFriendlyMessageResponse)
{
    response.out<Optional<QList<UserFriendlyMessage> > >("messages").run();
}

InitResponse(GetListOfPermissionsResponse)
{
    response.out<QList<PermissionItem> >("allowedFunctions").run();
}

InitResponse(UpdateSDLResponse)
{
    response.out<int>("result").run();
}

InitResponse(GetStatusUpdateResponse)
{
    response.out<int>("status").run();
}

InitResponse(GetURLSResponse)
{
    response.out<Optional<QList<ServiceInfo> > >("urls").run();
}

void SDL::activateApp(const QJSValue &callback, int appID)
{
    request("ActivateApp", new ActivateAppResponse(callback))
            .in(appID).send();
}

void SDL::getUserFriendlyMessage(const QJSValue &callback,
    const QStringList &messageCodes, const QVariant &language)
{
    request("GetUserFriendlyMessage",
                     new GetUserFriendlyMessageResponse(callback))
            .in(messageCodes).in<Optional<int> >(language).send();
}

void SDL::getListOfPermissions(const QJSValue &callback, const QVariant &appID)
{
    request("GetListOfPermissions",
                     new GetListOfPermissionsResponse(callback))
            .in<Optional<int> >(appID).send();
}

void SDL::updateSDL(const QJSValue &callback)
{
    request("UpdateSDL", new UpdateSDLResponse(callback)).send();
}

void SDL::getStatusUpdate(const QJSValue &callback)
{
    request("GetStatusUpdate", new GetStatusUpdateResponse(callback)).send();
}

void SDL::getURLS(const QJSValue &callback, int service)
{
    request("GetURLS", new GetURLSResponse(callback)).in(service).send();
}

void SDL::onAllowSDLFunctionality(const QVariant &device, bool allowed, int source)
{
    // device is optional parameter, but C++ rules denies using mandatory parameters after optional
    notification("OnAllowSDLFunctionality").arg<Optional<DeviceInfo> >(device)
            .arg(allowed).arg(source).send();
}

void SDL::onReceivedPolicyUpdate(const QString &policyfile)
{
    notification("OnReceivedPolicyUpdate").arg(policyfile).send();
}

void SDL::onPolicyUpdate()
{
    notification("OnPolicyUpdate").send();
}

void SDL::onAppPermissionConsent(const QVariant &appID,
    const QVariantList &consentedFunctions, int source)
{
    // appID is optional parameter, but C++ rules denies using mandatory parameters after optional
    notification("OnAppPermissionConsent").arg<Optional<int> >(appID)
            .arg<QList<PermissionItem> >(consentedFunctions).arg(source).send();
}

void SDL::onSystemError(int error)
{
    notification("OnSystemError").arg(error).send();
}

void SDL::addStatisticsInfo(int statisticType)
{
    notification("AddStatisticsInfo").arg(statisticType).send();
}

void SDL::onDeviceStateChanged(int deviceState, const QString &deviceInternalId,
    const QVariant &deviceId)
{
    notification("OnDeviceStateChanged").arg(deviceState).arg(deviceInternalId)
            .arg<Optional<DeviceInfo> >(deviceId).send();
}
