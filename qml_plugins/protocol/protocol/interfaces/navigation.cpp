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
    call("IsReady", message).run();
}

void NavigationAdapter::SendLocation(int appID, const Optional<double> &longitudeDegrees,
    const Optional<double> &latitudeDegrees, const Optional<QString> &locationName,
    const Optional<QString> &locationDescription, const Optional<QStringList> &addressLines,
    const Optional<QString> &phoneNumber, const Optional<Image> &locationImage,
    const Optional<DateTime> &timeStamp, const Optional<OASISAddress> &address,
    const Message &message)
{
    call("sendLocation", message).in(appID).in(longitudeDegrees).in(latitudeDegrees)
        .in(locationName).in(locationDescription).in(addressLines).in(phoneNumber)
            .in(locationImage).in(timeStamp).in(address).run();
}

void NavigationAdapter::ShowConstantTBT(const QList<TextFieldStruct> &navigationTexts,
    const Optional<Image> &turnIcon, const Optional<Image> &nextTurnIcon,
    double distanceToManeuver, double distanceToManeuverScale,
    const Optional<bool> &maneuverComplete, const Optional<QList<SoftButton> > &softButtons,
    int appID, const Message &message)
{
    call("showConstantTBT", message).in(navigationTexts).in(turnIcon).in(nextTurnIcon)
        .in(distanceToManeuver).in(distanceToManeuverScale).in(maneuverComplete)
            .in(softButtons).in(appID).run();
}

void NavigationAdapter::AlertManeuver(const Optional<QList<SoftButton> > &softButtons,
    int appID, const Message &message)
{
    call("alertManeuver", message).in(softButtons).in(appID).run();
}

void NavigationAdapter::UpdateTurnList(const Optional<QList<Turn> > &turnList,
    const Optional<QList<SoftButton> > &softButtons, int appID, const Message &message)
{
    call("updateTurnList", message).in(turnList).in(softButtons).in(appID).run();
}

void NavigationAdapter::StartStream(const QString &url, int appID, const Message &message)
{
    call("startStream", message).in(url).in(appID).run();
}

void NavigationAdapter::StopStream(int appID, const Message &message)
{
    call("stopStream", message).in(appID).run();
}

void NavigationAdapter::StartAudioStream(const QString &url, int appID, const Message &message)
{
    call("startAudioStream", message).in(url).in(appID).run();
}

void NavigationAdapter::StopAudioStream(int appID, const Message &message)
{
    call("stopAudioStream", message).in(appID).run();
}

void NavigationAdapter::GetWayPoints(const Optional<int> &wayPointType, const Message &message)
{
    call("getWayPoints", message).in(wayPointType).run();
}

void NavigationAdapter::SubscribeWayPoints(const Message &message)
{
    call("subscribeWayPoints", message).run();
}

void NavigationAdapter::UnsubscribeWayPoints(const Message &message)
{
    call("unsubscribeWayPoints", message).run();
}

void Navigation::replyIsReady(const QVariantMap& handle, bool available)
{
    response(handle).out(available).send();
}

void Navigation::replyGetWayPoints(const QVariantMap &handle, int appID,
    const QVariant &wayPoints)
{
    response(handle).out(appID).out<Optional<LocationDetails> >(wayPoints).send();
}

void Navigation::onTBTClientState(int state)
{
    notification("OnTBTClientState").arg(state).send();
}

void Navigation::onWayPointChange(const QVariantList &wayPoints)
{
    notification("OnWayPointChange").arg<QList<LocationDetails> >(wayPoints).send();
}
