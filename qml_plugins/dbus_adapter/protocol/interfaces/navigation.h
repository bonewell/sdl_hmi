#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "core/abstractadapter.h"
#include "protocol/structures.h"

#define NAVIGATION_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.Navigation\">" \
    "<method name=\"IsReady\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"available\" type=\"b\" />" \
    "</method>" \
    "<method name=\"SendLocation\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"longitudeDegrees\" type=\"d\" />" \
    "<arg direction=\"in\" name=\"latitudeDegrees\" type=\"d\" />" \
    "<arg direction=\"in\" name=\"locationName\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"locationDescription\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"addressLines\" type=\"(bas)\" />" \
    "<arg direction=\"in\" name=\"phoneNumber\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"locationImage\" type=\"(b(si))\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"ShowConstantTBT\">" \
    "<arg direction=\"in\" name=\"navigationTexts\" type=\"a(is)\" />" \
    "<arg direction=\"in\" name=\"turnIcon\" type=\"(b(si))\" />" \
    "<arg direction=\"in\" name=\"nextTurnIcon\" type=\"(b(si))\" />" \
    "<arg direction=\"in\" name=\"distanceToManeuver\" type=\"d\" />" \
    "<arg direction=\"in\" name=\"distanceToManeuverScale\" type=\"d\" />" \
    "<arg direction=\"in\" name=\"maneuverComplete\" type=\"(bb)\" />" \
    "<arg direction=\"in\" name=\"softButtons\" type=\"(ba(i(bs)(b(si))(bb)ii))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"AlertManeuver\">" \
    "<arg direction=\"in\" name=\"softButtons\" type=\"(ba(i(bs)(b(si))(bb)ii))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"UpdateTurnList\">" \
    "<arg direction=\"in\" name=\"turnList\" type=\"(ba((b(is))(b(si))))\" />" \
    "<arg direction=\"in\" name=\"softButtons\" type=\"(ba(i(bs)(b(si))(bb)ii))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"StartStream\">" \
    "<arg direction=\"in\" name=\"url\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"StopStream\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"StartAudioStream\">" \
    "<arg direction=\"in\" name=\"url\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"StopAudioStream\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<signal name=\"OnTBTClientState\">" \
    "<arg name=\"state\" type=\"i\" />" \
    "</signal>" \
    "</interface>"

class Navigation;

class NavigationAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO("com.ford.sdl.hmi.Navigation", NAVIGATION_INTROSPECTION)
    REGISTER_ADAPTER(NavigationAdapter, Navigation)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.Navigation")

signals:
    void OnTBTClientState(int state);

public slots:
    void IsReady(const Message& message);
    void SendLocation(int appID, double longitudeDegrees, double latitudeDegrees,
        const Optional<QString>& locationName, const Optional<QString>& locationDescription,
        const Optional<QStringList>& addressLines, const Optional<QString>& phoneNumber,
        const Optional<Image>& locationImage, const Message& message);
    void ShowConstantTBT(const QList<TextFieldStruct>& navigationTexts,
        const Optional<Image>& turnIcon, const Optional<Image>& nextTurnIcon,
        double distanceToManeuver, double distanceToManeuverScale,
        const Optional<bool>& maneuverComplete,
        const Optional<QList<SoftButton> >& softButtons, int appID, const Message& message);
    void AlertManeuver(const Optional<QList<SoftButton> >& softButtons, int appID,
        const Message& message);
    void UpdateTurnList(const Optional<QList<Turn> >& turnList,
        const Optional<QList<SoftButton> >& softButtons, int appID, const Message& message);
    void StartStream(const QString& url, int appID, const Message& message);
    void StopStream(int appID, const Message& message);
    void StartAudioStream(const QString& url, int appID, const Message& message);
    void StopAudioStream(int appID, const Message& message);

private slots:
    void OnAudioDataStreaming(bool available);
    void OnVideoDataStreaming(bool available);

public:
    void ReplyIsReady(int handle, bool available);
    void ReplySendLocation(int handle);
    void ReplyShowConstantTBT(int handle);
    void ReplyAlertManeuver(int handle);
    void ReplyUpdateTurnList(int handle);
    void ReplyStartStream(int handle);
    void ReplyStopStream(int handle);
    void ReplyStartAudioStream(int handle);
    void ReplyStopAudioStream(int handle);
};

class Navigation : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(Navigation, NavigationAdapter)

public:
    Q_INVOKABLE void OnTBTClientState(int state);

    Q_INVOKABLE void replyIsReady(int handle, bool available);
    Q_INVOKABLE void replySendLocation(int handle);
    Q_INVOKABLE void replyShowConstantTBT(int handle);
    Q_INVOKABLE void replyAlertManeuver(int handle);
    Q_INVOKABLE void replyUpdateTurnList(int handle);
    Q_INVOKABLE void replyStartStream(int handle);
    Q_INVOKABLE void replyStopStream(int handle);
    Q_INVOKABLE void replyStartAudioStream(int handle);
    Q_INVOKABLE void replyStopAudioStream(int handle);

signals:
    void onAudioDataStreaming(bool available);
    void onVideoDataStreaming(bool available);
};

#endif // NAVIGATION_H
