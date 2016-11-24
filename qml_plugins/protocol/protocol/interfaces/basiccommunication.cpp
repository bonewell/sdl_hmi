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

void BasicCommunicationAdapter::ReplyAllowDeviceToConnect(const Handle& handle,
                                                          bool allow)
{
    reply(handle).out(allow).send();
}

void BasicCommunicationAdapter::ReplyMixingAudioSupported(const Handle& handle,
    bool attenuatedSupported)
{
    reply(handle).out(attenuatedSupported).send();
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
    adapter->signal("OnReady").send();
}

void BasicCommunication::onStartDeviceDiscovery()
{
    adapter->signal("OnStartDeviceDiscovery").send();
}

void BasicCommunication::onUpdateDeviceList()
{
    adapter->signal("OnUpdateDeviceList").send();
}

void BasicCommunication::onPhoneCall(bool isActive)
{
    adapter->signal("OnPhoneCall").arg(isActive).send();
}

void BasicCommunication::onEmergencyEvent(bool enabled)
{
    adapter->signal("OnEmergencyEvent").arg(enabled).send();
}

void BasicCommunication::onDeviceChosen(const QVariantMap &deviceInfo)
{
    adapter->signal("OnDeviceChosen").arg(single<DeviceInfo>(deviceInfo)).send();
}

void BasicCommunication::onFindApplications(const QVariant &deviceInfo)
{
    adapter->signal("OnFindApplications").arg<Optional<DeviceInfo> >(deviceInfo).send();
}

void BasicCommunication::onAppActivated(int appID)
{
    adapter->signal("OnAppActivated").arg(appID).send();
}

void BasicCommunication::onAppDeactivated(int appID)
{
    adapter->signal("OnAppDeactivated").arg(appID).send();
}

void BasicCommunication::onExitApplication(int reason, int appID)
{
    adapter->signal("OnExitApplication").arg(reason).arg(appID).send();
}

void BasicCommunication::onExitAllApplications(int reason)
{
    adapter->signal("OnExitAllApplications").arg(reason).send();
}

void BasicCommunication::onAwakeSDL()
{
    adapter->signal("OnAwakeSDL").send();
}

void BasicCommunication::onSystemRequest(int requestType, const QVariant &url,
    const QVariant &fileType, const QVariant &offset, const QVariant &length,
    const QVariant &timeout, const QString &fileName, const QVariant &appID)
{
// fileName is mandatory but we added default value to the signature of method
// because of C++ rules
    adapter->signal("OnSystemRequest").arg(requestType).arg<Optional<QString> >(url)
            .arg<Optional<int> >(fileType).arg<Optional<int> >(offset)
            .arg<Optional<int> >(length).arg<Optional<int> >(timeout)
            .arg(fileName).arg<Optional<QString> >(appID).send();
}

void BasicCommunication::onSystemInfoChanged(int language)
{
    adapter->signal("OnSystemInfoChanged").arg(language).send();
}

void BasicCommunication::onIgnitionCycleOver()
{
    adapter->signal("OnIgnitionCycleOver").send();
}

void BasicCommunication::onDeactivateHMI(bool isDeactivated)
{
    adapter->signal("OnDeactivateHMI").arg(isDeactivated).send();
}

void BasicCommunication::onEventChanged(int eventName, bool isActive)
{
    adapter->signal("OnEventChanged").arg(eventName).arg(isActive).send();
}

void BasicCommunication::replyAllowDeviceToConnect(const QVariantMap& handle,
                                                   bool allow)
{
    adapter->ReplyAllowDeviceToConnect(handle, allow);
}

void BasicCommunication::replyMixingAudioSupported(const QVariantMap& handle,
                                                   bool attenuatedSupported)
{
    adapter->ReplyMixingAudioSupported(handle, attenuatedSupported);
}

void BasicCommunication::replyGetSystemInfo(const QVariantMap& handle,
    const QString &ccpu_version, int language, const QString &wersCountryCode)
{
    adapter->ReplyGetSystemInfo(handle, ccpu_version, language, wersCountryCode);
}
