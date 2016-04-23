#include "basiccommunication.h"

void BasicCommunicationAdapter::UpdateAppList(const QList<HMIApplication> &applications,
    const Message &message)
{
    invoke("UpdateAppList", message).in(applications).run();
}

void BasicCommunicationAdapter::UpdateDeviceList(const QList<DeviceInfo> &deviceList,
    const Message &message)
{
    invoke("UpdateDeviceList", message).in(deviceList).run();
}

void BasicCommunicationAdapter::AllowDeviceToConnect(const DeviceInfo &device,
    const Message &message)
{
    invoke("AllowDeviceToConnect", message).in(device).run();
}

void BasicCommunicationAdapter::ActivateApp(int appID, const Optional<int> &priority,
    const Optional<int> &level, const Message &message)
{
    invoke("ActivateApp", message).in(appID).in(priority).in(level).run();
}

void BasicCommunicationAdapter::MixingAudioSupported(const Message &message)
{
    invoke("MixingAudioSupported", message).run();
}

void BasicCommunicationAdapter::DialNumber(const QString &number, int appID,
    const Message &message)
{
    invoke("DialNumber", message).in(number).in(appID).run();
}

void BasicCommunicationAdapter::SystemRequest(int requestType, const QString &fileName,
    const Optional<QString> &appID, const Message &message)
{
    invoke("SystemRequest", message).in(requestType).in(fileName).in(appID).run();
}

void BasicCommunicationAdapter::PolicyUpdate(const QString &file, int timeout,
    const QList<int> &retry, const Message &message)
{
    invoke("PolicyUpdate", message).in(file).in(timeout).in(retry).run();
}

void BasicCommunicationAdapter::GetSystemInfo(const Message &message)
{
    invoke("GetSystemInfo", message).run();
}

void BasicCommunicationAdapter::ReplyUpdateAppList(const Handle& handle)
{
    reply(handle).send();
}

void BasicCommunicationAdapter::ReplyUpdateDeviceList(const Handle& handle)
{
    reply(handle).send();
}

void BasicCommunicationAdapter::ReplyAllowDeviceToConnect(const Handle& handle,
                                                          bool allow)
{
    reply(handle).out(allow).send();
}

void BasicCommunicationAdapter::ReplyActivateApp(const Handle& handle)
{
    reply(handle).send();
}

void BasicCommunicationAdapter::ReplyMixingAudioSupported(const Handle& handle,
    bool attenuatedSupported)
{
    reply(handle).out(attenuatedSupported).send();
}

void BasicCommunicationAdapter::ReplyDialNumber(const Handle& handle)
{
    reply(handle).send();
}

void BasicCommunicationAdapter::ReplySystemRequest(const Handle& handle)
{
    reply(handle).send();
}

void BasicCommunicationAdapter::ReplyPolicyUpdate(const Handle& handle)
{
    reply(handle).send();
}

void BasicCommunicationAdapter::ReplyGetSystemInfo(const Handle& handle,
    const QString &ccpu_version, int language, const QString &wersCountryCode)
{
    reply(handle).out(ccpu_version).out(language).out(wersCountryCode).send();
}

void BasicCommunicationAdapter::OnResumeAudioSource(int appID)
{
    emit qml->onResumeAudioSource(appID);
}

void BasicCommunicationAdapter::OnSDLPersistenceComplete()
{
    emit qml->onSDLPersistenceComplete();
}

void BasicCommunicationAdapter::OnFileRemoved(const QString &fileName,
    int fileType, int appID)
{
    emit qml->onFileRemoved(fileName, fileType, appID);
}

void BasicCommunicationAdapter::OnAppRegistered(const HMIApplication &application,
    const Optional<QList<TTSChunk> > &ttsName, const Optional<QStringList> &vrSynonyms,
    const Optional<bool> &resumeVrGrammars, const Optional<int> &priority)
{
    emit qml->onAppRegistered(application, ttsName, vrSynonyms, resumeVrGrammars, priority);
}

void BasicCommunicationAdapter::OnAppUnregistered(bool unexpectedDisconnect, int appID)
{
    emit qml->onAppUnregistered(unexpectedDisconnect, appID);
}

void BasicCommunicationAdapter::OnSDLClose()
{
    emit qml->onSDLClose();
}

void BasicCommunicationAdapter::OnPutFile(const Optional<int> &offset,
    const Optional<int> &length, const Optional<int> &fileSize, const QString &FileName,
    const QString &syncFileName, int fileType, const Optional<bool> &persistentFile)
{
    emit qml->onPutFile(offset, length, fileSize, FileName, syncFileName,
        fileType, persistentFile);
}

void BasicCommunication::onReady()
{
    emit adapter->OnReady();
}

void BasicCommunication::onStartDeviceDiscovery()
{
    emit adapter->OnStartDeviceDiscovery();
}

void BasicCommunication::onUpdateDeviceList()
{
    emit adapter->OnUpdateDeviceList();
}

void BasicCommunication::onPhoneCall(bool isActive)
{
    emit adapter->OnPhoneCall(isActive);
}

void BasicCommunication::onEmergencyEvent(bool enabled)
{
    emit adapter->OnEmergencyEvent(enabled);
}

void BasicCommunication::onDeviceChosen(const QVariantMap &deviceInfo)
{
    emit adapter->OnDeviceChosen(single<DeviceInfo>(deviceInfo));
}

void BasicCommunication::onFindApplications(const QVariant &deviceInfo)
{
    emit adapter->OnFindApplications(deviceInfo);
}

void BasicCommunication::onAppDeactivated(int appID)
{
    emit adapter->OnAppDeactivated(appID);
}

void BasicCommunication::onExitApplication(int reason, int appID)
{
    emit adapter->OnExitApplication(reason, appID);
}

void BasicCommunication::onExitAllApplications(int reason)
{
    emit adapter->OnExitAllApplications(reason);
}

void BasicCommunication::onAwakeSDL()
{
    emit adapter->OnAwakeSDL();
}

void BasicCommunication::OnSystemRequest(int requestType, const QVariant &url,
    const QVariant &fileType, const QVariant &offset, const QVariant &length,
    const QVariant &timeout, const QString &fileName, const QVariant &appID)
{
// fileName is mandatory but we added default value to the signature of method
// because of C++ rules
    emit adapter->OnSystemRequest(requestType, url, fileType, offset, length,
                                  timeout, fileName, appID);
}

void BasicCommunication::onSystemInfoChanged(int language)
{
    emit adapter->OnSystemInfoChanged(language);
}

void BasicCommunication::onIgnitionCycleOver()
{
    emit adapter->OnIgnitionCycleOver();
}

void BasicCommunication::onDeactivateHMI(bool isDeactivated)
{
    emit adapter->OnDeactivateHMI(isDeactivated);
}

void BasicCommunication::onEventChanged(int eventName, bool isActive)
{
    emit adapter->OnEventChanged(eventName, isActive);
}

void BasicCommunication::replyUpdateAppList(const QVariantMap& handle)
{
    adapter->ReplyUpdateAppList(handle);
}

void BasicCommunication::replyUpdateDeviceList(const QVariantMap& handle)
{
    adapter->ReplyUpdateDeviceList(handle);
}

void BasicCommunication::replyAllowDeviceToConnect(const QVariantMap& handle,
                                                   bool allow)
{
    adapter->ReplyAllowDeviceToConnect(handle, allow);
}

void BasicCommunication::replyActivateApp(const QVariantMap& handle)
{
    adapter->ReplyActivateApp(handle);
}

void BasicCommunication::replyMixingAudioSupported(const QVariantMap& handle,
                                                   bool attenuatedSupported)
{
    adapter->ReplyMixingAudioSupported(handle, attenuatedSupported);
}

void BasicCommunication::replyDialNumber(const QVariantMap& handle)
{
    adapter->ReplyDialNumber(handle);
}

void BasicCommunication::replySystemRequest(const QVariantMap& handle)
{
    adapter->ReplySystemRequest(handle);
}

void BasicCommunication::replyPolicyUpdate(const QVariantMap& handle)
{
    adapter->ReplyPolicyUpdate(handle);
}

void BasicCommunication::replyGetSystemInfo(const QVariantMap& handle,
    const QString &ccpu_version, int language, const QString &wersCountryCode)
{
    adapter->ReplyGetSystemInfo(handle, ccpu_version, language, wersCountryCode);
}
