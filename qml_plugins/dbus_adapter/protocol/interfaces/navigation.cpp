#include "navigation.h"

void NavigationAdapter::OnAudioDataStreaming(bool available)
{
    emit qml->onAudioDataStreaming(available);
}

void NavigationAdapter::OnVideoDataStreaming(bool available)
{
    emit qml->onVideoDataStreaming(available);
}

void NavigationAdapter::IsReady(const Message &message)
{
    invoke("IsReady", message).run();
}

void NavigationAdapter::SendLocation(int appID, double longitudeDegrees,
    double latitudeDegrees, const Optional<QString> &locationName,
    const Optional<QString> &locationDescription,
    const Optional<QStringList> &addressLines,
    const Optional<QString> &phoneNumber, const Optional<Image> &locationImage,
    const Message &message)
{
    invoke("SendLocation", message).in(appID).in(longitudeDegrees).in(latitudeDegrees)
        .in(locationName).in(locationDescription).in(addressLines).in(phoneNumber)
            .in(locationImage).run();
}

void NavigationAdapter::ShowConstantTBT(const QList<TextFieldStruct> &navigationTexts,
    const Optional<Image> &turnIcon, const Optional<Image> &nextTurnIcon,
    double distanceToManeuver, double distanceToManeuverScale,
    const Optional<bool> &maneuverComplete, const Optional<QList<SoftButton> > &softButtons,
    int appID, const Message &message)
{
    invoke("ShowConstantTBT", message).in(navigationTexts).in(turnIcon).in(nextTurnIcon)
        .in(distanceToManeuver).in(distanceToManeuverScale).in(maneuverComplete)
            .in(softButtons).in(appID).run();
}

void NavigationAdapter::AlertManeuver(const Optional<QList<SoftButton> > &softButtons,
    int appID, const Message &message)
{
    invoke("AlertManeuver", message).in(softButtons).in(appID).run();
}

void NavigationAdapter::UpdateTurnList(const Optional<QList<Turn> > &turnList,
    const Optional<QList<SoftButton> > &softButtons, int appID, const Message &message)
{
    invoke("UpdateTurnList", message).in(turnList).in(softButtons).in(appID).run();
}

void NavigationAdapter::StartStream(const QString &url, int appID, const Message &message)
{
    invoke("StartStream", message).in(url).in(appID).run();
}

void NavigationAdapter::StopStream(int appID, const Message &message)
{
    invoke("StopStream", message).in(appID).run();
}

void NavigationAdapter::StartAudioStream(const QString &url, int appID, const Message &message)
{
    invoke("StartAudioStream", message).in(url).in(appID).run();
}

void NavigationAdapter::StopAudioStream(int appID, const Message &message)
{
    invoke("StopAudioStream", message).in(appID).run();
}

void NavigationAdapter::ReplyIsReady(const Handle& handle, bool available)
{
    reply(handle).out(available).send();
}

void NavigationAdapter::ReplySendLocation(const Handle& handle)
{
    reply(handle).send();
}

void NavigationAdapter::ReplyShowConstantTBT(const Handle& handle)
{
    reply(handle).send();
}

void NavigationAdapter::ReplyAlertManeuver(const Handle& handle)
{
    reply(handle).send();
}

void NavigationAdapter::ReplyUpdateTurnList(const Handle& handle)
{
    reply(handle).send();
}

void NavigationAdapter::ReplyStartStream(const Handle& handle)
{
    reply(handle).send();
}

void NavigationAdapter::ReplyStopStream(const Handle& handle)
{
    reply(handle).send();
}

void NavigationAdapter::ReplyStartAudioStream(const Handle& handle)
{
    reply(handle).send();
}

void NavigationAdapter::ReplyStopAudioStream(const Handle& handle)
{
    reply(handle).send();
}

void Navigation::replyIsReady(const QVariantMap& handle, bool available)
{
    adapter->ReplyIsReady(handle, available);
}

void Navigation::replySendLocation(const QVariantMap& handle)
{
    adapter->ReplySendLocation(handle);
}

void Navigation::replyShowConstantTBT(const QVariantMap& handle)
{
    adapter->ReplyShowConstantTBT(handle);
}

void Navigation::replyAlertManeuver(const QVariantMap& handle)
{
    adapter->ReplyAlertManeuver(handle);
}

void Navigation::replyUpdateTurnList(const QVariantMap& handle)
{
    adapter->ReplyUpdateTurnList(handle);
}

void Navigation::replyStartStream(const QVariantMap& handle)
{
    adapter->ReplyStartStream(handle);
}

void Navigation::replyStopStream(const QVariantMap& handle)
{
    adapter->ReplyStopStream(handle);
}

void Navigation::replyStartAudioStream(const QVariantMap& handle)
{
    adapter->ReplyStartAudioStream(handle);
}

void Navigation::replyStopAudioStream(const QVariantMap& handle)
{
    adapter->ReplyStopAudioStream(handle);
}

void Navigation::OnTBTClientState(int state)
{
    emit adapter->OnTBTClientState(state);
}
