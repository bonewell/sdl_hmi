#include "buttons.h"

void Buttons::onButtonEvent(int name, int mode, const QVariant &customButtonID,
    const QVariant &appID)
{
    adapter->signal("OnButtonEvent").arg(name).arg(mode)
            .arg<Optional<int> >(customButtonID).arg<Optional<int> >(appID).send();
}

void Buttons::onButtonPress(int name, int mode, const QVariant &customButtonID,
    const QVariant &appID)
{
    adapter->signal("OnButtonPress").arg(name).arg(mode)
            .arg<Optional<int> >(customButtonID).arg<Optional<int> >(appID).send();
}

void Buttons::replyGetCapabilities(const QVariantMap& handle, const QVariantList &capabilities,
    const QVariant &presetBankCapabilities)
{
    adapter->reply(handle).out(multiple<ButtonCapabilities>(capabilities))
            .out<Optional<PresetBankCapabilities> >(presetBankCapabilities).send();
}

void ButtonsAdapter::OnButtonSubscription(int name, bool isSubscribed, int appID)
{
    qml->onButtonSubscription(name, isSubscribed, appID);
}

void ButtonsAdapter::GetCapabilities(const Message &message)
{
    invoke("GetCapabilities", message).run();
}
