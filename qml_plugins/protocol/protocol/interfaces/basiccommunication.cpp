#include "basiccommunication.h"

void BasicCommunicationAdapter::UpdateAppList(const QList<HMIApplication> &applications,
    const Message &message)
{
    call("updateAppList", message).in(applications).run();
}

void BasicCommunicationAdapter::UpdateDeviceList(const QList<DeviceInfo> &deviceList,
    const Message &message)
{
    call("updateDeviceList", message).in(deviceList).run();
}

void BasicCommunicationAdapter::AllowDeviceToConnect(const DeviceInfo &device,
    const Message &message)
{
    call("allowDeviceToConnect", message).in(device).run();
}

void BasicCommunicationAdapter::ActivateApp(int appID, const Optional<int> &priority,
    const Optional<int> &level, const Message &message)
{
    call("activateApp", message).in(appID).in(priority).in(level).run();
}

void BasicCommunicationAdapter::MixingAudioSupported(const Message &message)
{
    call("mixingAudioSupported", message).run();
}

void BasicCommunicationAdapter::DialNumber(const QString &number, int appID,
    const Message &message)
{
    call("dialNumber", message).in(number).in(appID).run();
}

void BasicCommunicationAdapter::SystemRequest(int requestType, const QString &fileName,
    const Optional<QString> &appID, const Message &message)
{
    call("systemRequest", message).in(requestType).in(fileName).in(appID).run();
}

void BasicCommunicationAdapter::PolicyUpdate(const QString &file, int timeout,
    const QList<int> &retry, const Message &message)
{
    call("policyUpdate", message).in(file).in(timeout).in(retry).run();
}

//void BasicCommunicationAdapter::GetSystemInfo(const Message &message)
void BasicCommunicationAdapter::GetSystemInfo()
{
    call("getSystemInfo").run();
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
    notification("OnReady").send();
}

void BasicCommunication::onStartDeviceDiscovery()
{
    notification("OnStartDeviceDiscovery").send();
}

void BasicCommunication::onUpdateDeviceList()
{
    notification("OnUpdateDeviceList").send();
}

void BasicCommunication::onPhoneCall(bool isActive)
{
    notification("OnPhoneCall").arg(isActive).send();
}

void BasicCommunication::onEmergencyEvent(bool enabled)
{
    notification("OnEmergencyEvent").arg(enabled).send();
}

void BasicCommunication::onDeviceChosen(const QVariantMap &deviceInfo)
{
    notification("OnDeviceChosen").arg<DeviceInfo>(deviceInfo).send();
}

void BasicCommunication::onFindApplications(const QVariant &deviceInfo)
{
    notification("OnFindApplications").arg<Optional<DeviceInfo> >(deviceInfo).send();
}

void BasicCommunication::onAppActivated(int appID)
{
    notification("OnAppActivated").arg(appID).send();
}

void BasicCommunication::onAppDeactivated(int appID)
{
    notification("OnAppDeactivated").arg(appID).send();
}

void BasicCommunication::onExitApplication(int reason, int appID)
{
    notification("OnExitApplication").arg(reason).arg(appID).send();
}

void BasicCommunication::onExitAllApplications(int reason)
{
    notification("OnExitAllApplications").arg(reason).send();
}

void BasicCommunication::onAwakeSDL()
{
    notification("OnAwakeSDL").send();
}

void BasicCommunication::onSystemRequest(int requestType, const QVariant &url,
    const QVariant &fileType, const QVariant &offset, const QVariant &length,
    const QVariant &timeout, const QString &fileName, const QVariant &appID)
{
// fileName is mandatory but we added default value to the signature of method
// because of C++ rules
    notification("OnSystemRequest").arg(requestType).arg<Optional<QString> >(url)
            .arg<Optional<int> >(fileType).arg<Optional<int> >(offset)
            .arg<Optional<int> >(length).arg<Optional<int> >(timeout)
            .arg(fileName).arg<Optional<QString> >(appID).send();
}

void BasicCommunication::onSystemInfoChanged(int language)
{
    notification("OnSystemInfoChanged").arg(language).send();
}

void BasicCommunication::onIgnitionCycleOver()
{
    notification("OnIgnitionCycleOver").send();
}

void BasicCommunication::onDeactivateHMI(bool isDeactivated)
{
    notification("OnDeactivateHMI").arg(isDeactivated).send();
}

void BasicCommunication::onEventChanged(int eventName, bool isActive)
{
    notification("OnEventChanged").arg(eventName).arg(isActive).send();
}

void BasicCommunication::replyAllowDeviceToConnect(const QVariantMap& handle,
                                                   bool allow)
{
    response(handle).out(allow).send();
}

void BasicCommunication::replyMixingAudioSupported(const QVariantMap& handle,
                                                   bool attenuatedSupported)
{
    response(handle).out(attenuatedSupported).send();
}

void BasicCommunication::replyGetSystemInfo(const QVariantMap& handle,
    const QString &ccpu_version, int language, const QString &wersCountryCode)
{
    response(handle).out(ccpu_version).out(language).out(wersCountryCode).send();
}
