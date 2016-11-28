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

void NavigationAdapter::SendLocation(int appID, const Optional<double> &longitudeDegrees,
    const Optional<double> &latitudeDegrees, const Optional<QString> &locationName,
    const Optional<QString> &locationDescription, const Optional<QStringList> &addressLines,
    const Optional<QString> &phoneNumber, const Optional<Image> &locationImage,
    const Optional<DateTime> &timeStamp, const Optional<OASISAddress> &address,
    const Message &message)
{
    invoke("SendLocation", message).in(appID).in(longitudeDegrees).in(latitudeDegrees)
        .in(locationName).in(locationDescription).in(addressLines).in(phoneNumber)
            .in(locationImage).in(timeStamp).in(address).run();
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

void NavigationAdapter::GetWayPoints(const Optional<int> &wayPointType, const Message &message)
{
    invoke("GetWayPoints", message).in(wayPointType).run();
}

void NavigationAdapter::SubscribeWayPoints(const Message &message)
{
    invoke("SubscribeWayPoints", message).run();
}

void NavigationAdapter::UnsubscribeWayPoints(const Message &message)
{
    invoke("UnsubscribeWayPoints", message).run();
}

void Navigation::replyIsReady(const QVariantMap& handle, bool available)
{
    adapter->reply(handle).out(available).send();
}

void Navigation::replyGetWayPoints(const QVariantMap &handle, int appID,
    const QVariant &wayPoints)
{
    adapter->reply(handle).out(appID).out<Optional<LocationDetails> >(wayPoints).send();
}

void Navigation::onTBTClientState(int state)
{
    adapter->signal("OnTBTClientState").arg(state).send();
}

void Navigation::onWayPointChange(const QVariantList &wayPoints)
{
    adapter->signal("OnWayPointChange").arg(multiple<LocationDetails>(wayPoints)).send();
}
