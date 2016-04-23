#include "buttons.h"

void Buttons::onButtonEvent(int name, int mode, const QVariant &customButtonID,
    const QVariant &appID)
{
    emit adapter->OnButtonEvent(name, mode, customButtonID, appID);
}

void Buttons::onButtonPress(int name, int mode, const QVariant &customButtonID,
    const QVariant &appID)
{
    emit adapter->OnButtonPress(name, mode, customButtonID, appID);
}

void Buttons::replyGetCapabilities(const QVariantMap& handle, const QVariantList &capabilities,
    const QVariant &presetBankCapabilities)
{
    adapter->ReplyGetCapabilities(handle,
        multiple<ButtonCapabilities>(capabilities),
        presetBankCapabilities);
}

void ButtonsAdapter::OnButtonSubscription(int name, bool isSubscribed, int appID)
{
    emit qml->onButtonSubscription(name, isSubscribed, appID);
}

void ButtonsAdapter::GetCapabilities(const Message &message)
{
    invoke("GetCapabilities", message).run();
}

void ButtonsAdapter::ReplyGetCapabilities(const Handle& handle,
    const QList<ButtonCapabilities> &capabilities,
    const Optional<PresetBankCapabilities> &presetBankCapabilities)
{
    reply(handle).out(capabilities).out(presetBankCapabilities).send();
}
