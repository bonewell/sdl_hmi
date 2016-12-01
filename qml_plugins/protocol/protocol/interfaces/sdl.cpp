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

static void ReplyGetUserFriendlyMessage(Courier &courier)
{
    courier.out<Optional<QList<UserFriendlyMessage> > >().invoke();
}

static void ReplyGetListOfPermissions(Courier &courier)
{
    courier.out<QList<PermissionItem> >().invoke();
}

static void ReplyUpdateSDL(Courier &courier)
{
    courier.out<int>().invoke();
}

static void ReplyGetStatusUpdate(Courier &courier)
{
    courier.out<int>().invoke();
}

static void ReplyGetURLS(Courier &courier)
{
    courier.out<Optional<QList<ServiceInfo> > >().invoke();
}

void SDL::activateApp(const QJSValue &callback, int appID)
{
    adapter->request("ActivateApp", callback, ReplyActivateApp).in(appID).call();
}

void SDL::getUserFriendlyMessage(const QJSValue &callback,
    const QStringList &messageCodes, const QVariant &language)
{
    adapter->request("GetUserFriendlyMessage", callback,
                     ReplyGetUserFriendlyMessage)
            .in(messageCodes).in<Optional<int> >(language).call();
}

void SDL::getListOfPermissions(const QJSValue &callback, const QVariant &appID)
{
    adapter->request("GetListOfPermissions", callback,
                     ReplyGetListOfPermissions).in<Optional<int> >(appID).call();
}

void SDL::updateSDL(const QJSValue &callback)
{
    adapter->request("UpdateSDL", callback, ReplyUpdateSDL).call();
}

void SDL::getStatusUpdate(const QJSValue &callback)
{
    adapter->request("GetStatusUpdate", callback, ReplyGetStatusUpdate).call();
}

void SDL::getURLS(const QJSValue &callback, int service)
{
    adapter->request("GetURLS", callback, ReplyGetURLS).in(service).call();
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
