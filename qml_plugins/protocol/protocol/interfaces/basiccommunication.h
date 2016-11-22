#ifndef BASICCOMMUNICATION_H
#define BASICCOMMUNICATION_H

#include "core/abstractadapter.h"
#include "protocol/structures.h"

#define BASICCOMMUNICATION_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.BasicCommunication\">" \
    "<method name=\"UpdateAppList\">" \
    "<arg direction=\"in\" name=\"applications\" type=\"a(s(bs)(bs)(ss(bi)(bb))s(ba(si))(bas)i(bi)(bb)(bai)(bb)(bai))\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"UpdateDeviceList\">" \
    "<arg direction=\"in\" name=\"deviceList\" type=\"a(ss(bi)(bb))\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"AllowDeviceToConnect\">" \
    "<arg direction=\"in\" name=\"device\" type=\"(ss(bi)(bb))\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"allow\" type=\"b\" />" \
    "</method>" \
    "<method name=\"ActivateApp\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"priority\" type=\"(bi)\" />" \
    "<arg direction=\"in\" name=\"level\" type=\"(bi)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"MixingAudioSupported\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"attenuatedSupported\" type=\"b\" />" \
    "</method>" \
    "<method name=\"DialNumber\">" \
    "<arg direction=\"in\" name=\"number\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"SystemRequest\">" \
    "<arg direction=\"in\" name=\"requestType\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"fileName\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"(bs)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"PolicyUpdate\">" \
    "<arg direction=\"in\" name=\"file\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"timeout\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"retry\" type=\"ai\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"GetSystemInfo\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"ccpu_version\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"language\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"wersCountryCode\" type=\"s\" />" \
    "</method>" \
    "<signal name=\"OnReady\" />" \
    "<signal name=\"OnStartDeviceDiscovery\" />" \
    "<signal name=\"OnUpdateDeviceList\" />" \
    "<signal name=\"OnPhoneCall\">" \
    "<arg name=\"isActive\" type=\"b\" />" \
    "</signal>" \
    "<signal name=\"OnEmergencyEvent\">" \
    "<arg name=\"enabled\" type=\"b\" />" \
    "</signal>" \
    "<signal name=\"OnDeviceChosen\">" \
    "<arg name=\"deviceInfo\" type=\"(ss(bi)(bb))\" />" \
    "</signal>" \
    "<signal name=\"OnFindApplications\">" \
    "<arg name=\"deviceInfo\" type=\"(b(ss(bi)(bb)))\" />" \
    "</signal>" \
    "<signal name=\"OnAppActivated\">" \
    "<arg name=\"appID\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnAppDeactivated\">" \
    "<arg name=\"appID\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnExitApplication\">" \
    "<arg name=\"reason\" type=\"i\" />" \
    "<arg name=\"appID\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnExitAllApplications\">" \
    "<arg name=\"reason\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnAwakeSDL\" />" \
    "<signal name=\"OnSystemRequest\">" \
    "<arg name=\"requestType\" type=\"i\" />" \
    "<arg name=\"url\" type=\"(bs)\" />" \
    "<arg name=\"fileType\" type=\"(bi)\" />" \
    "<arg name=\"offset\" type=\"(bi)\" />" \
    "<arg name=\"length\" type=\"(bi)\" />" \
    "<arg name=\"timeout\" type=\"(bi)\" />" \
    "<arg name=\"fileName\" type=\"s\" />" \
    "<arg name=\"appID\" type=\"(bs)\" />" \
    "</signal>" \
    "<signal name=\"OnSystemInfoChanged\">" \
    "<arg name=\"language\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnIgnitionCycleOver\" />" \
    "<signal name=\"OnDeactivateHMI\">" \
    "<arg name=\"isDeactivated\" type=\"b\" />" \
    "</signal>" \
    "<signal name=\"OnEventChanged\">" \
    "<arg name=\"eventName\" type=\"i\" />" \
    "<arg name=\"isActive\" type=\"b\" />" \
    "</signal>" \
    "</interface>"

class BasicCommunication;

class BasicCommunicationAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO(600, "com.ford.sdl.hmi.BasicCommunication", BASICCOMMUNICATION_INTROSPECTION)
    REGISTER_ADAPTER(BasicCommunicationAdapter, BasicCommunication)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.BasicCommunication")

public slots:
    void UpdateAppList(const QList<HMIApplication>& applications, const Message& message);
    void UpdateDeviceList(const QList<DeviceInfo>& deviceList, const Message& message);
    void AllowDeviceToConnect(const DeviceInfo& device, const Message& message);
    void ActivateApp(int appID, const Optional<int>& priority,
        const Optional<int>& level, const Message& message);
    void MixingAudioSupported(const Message& message);
    void DialNumber(const QString& number, int appID, const Message& message);
    void SystemRequest(int requestType, const QString& fileName,
        const Optional<QString>& appID, const Message &message);
    void PolicyUpdate(const QString& file, int timeout, const QList<int>& retry,
        const Message& message);
    void GetSystemInfo(const Message& message);

public:
    void ReplyAllowDeviceToConnect(const Handle& handle, bool allow);
    void ReplyMixingAudioSupported(const Handle& handle, bool attenuatedSupported);
    void ReplyGetSystemInfo(const Handle& handle, const QString& ccpu_version,
                            int language, const QString& wersCountryCode);

private slots:
    void OnResumeAudioSource(int appID);
    void OnSDLPersistenceComplete();
    void OnFileRemoved(const QString& fileName, int fileType, int appID);
    void OnAppRegistered(const HMIApplication& application,
        const Optional<QList<TTSChunk> >& ttsName,
        const Optional<QStringList>& vrSynonyms,
        const Optional<bool>& resumeVrGrammars, const Optional<int>& priority);
    void OnAppUnregistered(bool unexpectedDisconnect, int appID);
    void OnSDLClose();
    void OnPutFile(const Optional<int>& offset, const Optional<int>& length,
        const Optional<int>& fileSize, const QString& FileName, const QString& syncFileName,
        int fileType, const Optional<bool>& persistentFile);
};

class BasicCommunication : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(BasicCommunication, BasicCommunicationAdapter)

public:
    Q_INVOKABLE void onReady();
    Q_INVOKABLE void onStartDeviceDiscovery();
    Q_INVOKABLE void onUpdateDeviceList();
    Q_INVOKABLE void onPhoneCall(bool isActive);
    Q_INVOKABLE void onEmergencyEvent(bool enabled);
    Q_INVOKABLE void onDeviceChosen(const QVariantMap& deviceInfo);
    Q_INVOKABLE void onFindApplications(const QVariant& deviceInfo = QVariant());
    Q_INVOKABLE void onAppActivated(int appID);
    Q_INVOKABLE void onAppDeactivated(int appID);
    Q_INVOKABLE void onExitApplication(int reason, int appID);
    Q_INVOKABLE void onExitAllApplications(int reason);
    Q_INVOKABLE void onAwakeSDL();
    Q_INVOKABLE void OnSystemRequest(int requestType, const QVariant& url = QVariant(),
        const QVariant& fileType = QVariant(), const QVariant& offset = QVariant(),
        const QVariant& length = QVariant(), const QVariant& timeout = QVariant(),
        const QString& fileName = "", const QVariant& appID = QVariant());
    Q_INVOKABLE void onSystemInfoChanged(int language);
    Q_INVOKABLE void onIgnitionCycleOver();
    Q_INVOKABLE void onDeactivateHMI(bool isDeactivated);
    Q_INVOKABLE void onEventChanged(int eventName, bool isActive);

    Q_INVOKABLE void replyAllowDeviceToConnect(const QVariantMap& handle, bool allow);
    Q_INVOKABLE void replyMixingAudioSupported(const QVariantMap& handle,
                                               bool attenuatedSupported);
    Q_INVOKABLE void replyGetSystemInfo(const QVariantMap& handle,
        const QString& ccpu_version, int language, const QString& wersCountryCode);

signals:
    void onResumeAudioSource(int appID);
    void onSDLPersistenceComplete();
    void onFileRemoved(const QString& fileName, int fileType, int appID);
    void onAppRegistered(const QVariantMap& application,
        const QVariant& ttsName, const QVariant& vrSynonyms,
        const QVariant& resumeVrGrammars, const QVariant& priority);
    void onAppUnregistered(bool unexpectedDisconnect, int appID);
    void onSDLClose();
    void onPutFile(const QVariant& offset, const QVariant& length,
        const QVariant& fileSize, const QString& FileName, const QString& syncFileName,
        int fileType, const QVariant& persistentFile);
};

#endif // BASICCOMMUNICATION_H
