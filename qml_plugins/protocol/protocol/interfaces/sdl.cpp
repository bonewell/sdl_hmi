#include "sdl.h"

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

static void ReplyActivateApp(Courier &courier)
{
    courier.out<bool>().out<Optional<DeviceInfo> >()
        .out<bool>().out<bool>().out<Optional<QList<PermissionItem> > >()
        .out<bool>().out<Optional<int> >().invoke();
}

void SDLAdapter::ActivateApp(const QJSValue &callback, int appID)
{
    request("ActivateApp", callback, ReplyActivateApp).in(appID).call();
}

static void ReplyGetUserFriendlyMessage(Courier &courier)
{
    courier.out<Optional<QList<UserFriendlyMessage> > >().invoke();
}

void SDLAdapter::GetUserFriendlyMessage(const QJSValue &callback,
    const QStringList &messageCodes, const Optional<int> &language)
{
    request("GetUserFriendlyMessage", callback, ReplyGetUserFriendlyMessage)
            .in(messageCodes).in(language).call();
}

static void ReplyGetListOfPermissions(Courier &courier)
{
    courier.out<QList<PermissionItem> >().invoke();
}

void SDLAdapter::GetListOfPermissions(const QJSValue &callback, const Optional<int> &appID)
{
    request("GetListOfPermissions", callback, ReplyGetListOfPermissions).in(appID).call();
}

static void ReplyUpdateSDL(Courier &courier)
{
    courier.out<int>().invoke();
}

void SDLAdapter::UpdateSDL(const QJSValue &callback)
{
    request("UpdateSDL", callback, ReplyUpdateSDL).call();
}

static void ReplyGetStatusUpdate(Courier &courier)
{
    courier.out<int>().invoke();
}

void SDLAdapter::GetStatusUpdate(const QJSValue &callback)
{
    request("GetStatusUpdate", callback, ReplyGetStatusUpdate).call();
}

static void ReplyGetURLS(Courier &courier)
{
    courier.out<Optional<QList<ServiceInfo> > >().invoke();
}

void SDLAdapter::GetURLS(const QJSValue &callback, int service)
{
    request("GetURLS", callback, ReplyGetURLS).in(service).call();
}

void SDL::activateApp(const QJSValue &callback, int appID)
{
    adapter->ActivateApp(callback, appID);
}

void SDL::getUserFriendlyMessage(const QJSValue &callback,
    const QStringList &messageCodes, const QVariant &language)
{
    adapter->GetUserFriendlyMessage(callback, messageCodes, language);
}

void SDL::getListOfPermissions(const QJSValue &callback, const QVariant &appID)
{
    adapter->GetListOfPermissions(callback, appID);
}

void SDL::updateSDL(const QJSValue &callback)
{
    adapter->UpdateSDL(callback);
}

void SDL::getStatusUpdate(const QJSValue &callback)
{
    adapter->GetStatusUpdate(callback);
}

void SDL::getURLS(const QJSValue &callback, int service)
{
    adapter->GetURLS(callback, service);
}

void SDL::onAllowSDLFunctionality(const QVariant &device, bool allowed, int source)
{
    // device is optional parameter, but C++ rules denies using mandatory parameters after optional
    adapter->signal("OnAllowSDLFunctionality").arg<Optional<DeviceInfo> >(device)
            .arg(allowed).arg(source).send();
}

void SDL::onReceivedPolicyUpdate(const QString &policyfile)
{
    adapter->signal("OnReceivedPolicyUpdate").arg(policyfile).send();
}

void SDL::onPolicyUpdate()
{
    adapter->signal("OnPolicyUpdate").send();
}

void SDL::onAppPermissionConsent(const QVariant &appID,
    const QVariantList &consentedFunctions, int source)
{
    // appID is optional parameter, but C++ rules denies using mandatory parameters after optional
    adapter->signal("OnAppPermissionConsent").arg<Optional<int> >(appID)
            .arg<QList<PermissionItem> >(consentedFunctions).arg(source).send();
}

void SDL::onSystemError(int error)
{
    adapter->signal("OnSystemError").arg(error).send();
}

void SDL::addStatisticsInfo(int statisticType)
{
    adapter->signal("AddStatisticsInfo").arg(statisticType).send();
}

void SDL::onDeviceStateChanged(int deviceState, const QString &deviceInternalId,
    const QVariant &deviceId)
{
    adapter->signal("OnDeviceStateChanged").arg(deviceState).arg(deviceInternalId)
            .arg<Optional<DeviceInfo> >(deviceId).send();
}
