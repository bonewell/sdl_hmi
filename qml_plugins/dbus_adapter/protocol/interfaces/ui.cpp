#include "ui.h"

void UIAdapter::Alert(const QList<TextFieldStruct> &alertStrings, int duration,
    const Optional<QList<SoftButton> > &softButtons,
    const Optional<bool> &progressIndicator, int alertType, int appID,
    const Message &message)
{
    invoke("Alert", message).in(alertStrings).in(duration).in(softButtons)
            .in(progressIndicator).in(alertType).in(appID).run();
}

void UIAdapter::Show(const QList<TextFieldStruct> &showStrings,
    const Optional<int> &aligment, const Optional<Image> &graphic,
    const Optional<Image> &secondaryGraphic,
    const Optional<QList<SoftButton> > &softButtons,
    const Optional<QStringList> &customPresets, int appID, const Message &message)
{
    invoke("Show", message).in(showStrings).in(aligment).in(graphic)
            .in(secondaryGraphic).in(softButtons).in(customPresets).in(appID).run();
}

void UIAdapter::AddCommand(int cmdID, const Optional<MenuParams> &menuParams,
    const Optional<Image> &cmdIcon, int appID, const Message &message)
{
    invoke("AddCommand", message).in(cmdID).in(menuParams).in(cmdIcon).in(appID).run();
}

void UIAdapter::DeleteCommand(int cmdID, int appID, const Message &message)
{
    invoke("DeleteCommand", message).in(cmdID).in(appID).run();
}

void UIAdapter::AddSubMenu(int menuID, const MenuParams &menuParams, int appID,
    const Message& message)
{
    invoke("AddSubMenu", message).in(menuID).in(menuParams).in(appID).run();
}

void UIAdapter::DeleteSubMenu(int menuID, int appID, const Message &message)
{
    invoke("DeleteSubMenu", message).in(menuID).in(appID).run();
}

void UIAdapter::PerformInteraction(const Optional<TextFieldStruct> &initialText,
    const Optional<QList<Choice> > &choiceSet, const Optional<QString> &vrHelpTitle,
    const Optional<QList<VrHelpItem> > &vrHelp, int timeout,
    const Optional<int> &interactionLayout, int appID, const Message &message)
{
    invoke("PerformInteraction", message).in(initialText).in(choiceSet)
            .in(vrHelpTitle).in(vrHelp).in(timeout).in(interactionLayout).in(appID).run();
}

void UIAdapter::SetMediaClockTimer(const Optional<TimeFormat> &startTime,
    const Optional<TimeFormat> &endTime, int updateMode, int appID,
    const Message &message)
{
    invoke("SetMediaClockTimer", message).in(startTime).in(endTime)
            .in(updateMode).in(appID).run();
}

void UIAdapter::SetGlobalProperties(const Optional<QString> &vrHelpTitle,
    const Optional<QList<VrHelpItem> > &vrHelp, const Optional<QString> &menuTitle,
    const Optional<Image> &menuIcon, const Optional<KeyboardProperties> &keyboardProperties,
    int appID, const Message &message)
{
    invoke("SetGlobalProperties", message).in(vrHelpTitle).in(vrHelp).in(menuTitle)
            .in(menuIcon).in(keyboardProperties).in(appID).run();
}

void UIAdapter::GetCapabilities(const Message &message)
{
    invoke("GetCapabilities", message).run();
}

void UIAdapter::ChangeRegistration(const Optional<QString> &appName,
    const Optional<QString> &ngnMediaScreenAppName, int language,
    const Optional<QList<int> > &appHMIType, int appID, const Message &message)
{
    invoke("ChangeRegistration", message).in(appName).in(ngnMediaScreenAppName)
            .in(language).in(appHMIType).in(appID).run();
}

void UIAdapter::GetSupportedLanguages(const Message &message)
{
    invoke("GetSupportedLanguages", message).run();
}

void UIAdapter::GetLanguage(const Message &message)
{
    invoke("GetLanguage", message).run();
}

void UIAdapter::SetAppIcon(const Image &syncFileName, int appID, const Message &message)
{
    invoke("SetAppIcon", message).in(syncFileName).in(appID).run();
}

void UIAdapter::SetDisplayLayout(const QString &displayLayout, int appID,
    const Message &message)
{
    invoke("SetDisplayLayout", message).in(displayLayout).in(appID).run();
}

void UIAdapter::ShowCustomForm(const QString &customFormID,
    const Optional<QString> &parentFormID, const Message &message)
{
    invoke("ShowCustomForm", message).in(customFormID).in(parentFormID).run();
}

void UIAdapter::Slider(int numTicks, int position, const QString &sliderHeader,
    const Optional<QStringList> &sliderFooter, int timeout, int appID,
    const Message &message)
{
    invoke("Slider", message).in(numTicks).in(position).in(sliderHeader)
            .in(sliderFooter).in(timeout).in(appID).run();
}

void UIAdapter::ScrollableMessage(const TextFieldStruct &messageText, int timeout,
    const Optional<QList<SoftButton> > &softButtons, int appID, const Message &message)
{
    invoke("ScrollableMessage", message).in(messageText).in(timeout)
            .in(softButtons).in(appID).run();
}

void UIAdapter::PerformAudioPassThru(int appID,
    const QList<TextFieldStruct> &audioPassThruDisplayTexts, int maxDuration,
    bool muteAudio, const Message &message)
{
    invoke("PerformAudioPassThru", message).in(appID).in(audioPassThruDisplayTexts)
            .in(maxDuration).in(muteAudio).run();
}

void UIAdapter::EndAudioPassThru(const Message &message)
{
    invoke("EndAudioPassThru", message).run();
}

void UIAdapter::IsReady(const Message &message)
{
    invoke("IsReady", message).run();
}

void UIAdapter::ClosePopUp(const Optional<QString> &methodName, const Message &message)
{
    invoke("ClosePopUp", message).in(methodName).run();
}

void UIAdapter::ReplyAlert(const Handle& handle,
                           const Optional<int> &tryAgainTime)
{
    reply(handle).out(tryAgainTime).send();
}

void UIAdapter::ReplyPerformInteraction(const Handle& handle,
    const Optional<int> &choiceID, const Optional<QString> &manualTextEntry)
{
    reply(handle).out(choiceID).out(manualTextEntry).send();
}

void UIAdapter::ReplyGetCapabilities(const Handle& handle,
    const DisplayCapabilities &displayCapabilities,
    const AudioPassThruCapabilities &audioPassThruCapabilities,
    int hmiZoneCapabilities,
    const Optional<QList<SoftButtonCapabilities> > &softButtonCapabilities,
    const Optional<HMICapabilities> &hmiCapabilities)
{
    reply(handle).out(displayCapabilities).out(audioPassThruCapabilities)
        .out(hmiZoneCapabilities).out(softButtonCapabilities)
            .out(hmiCapabilities).send();
}

void UIAdapter::ReplyGetSupportedLanguages(const Handle& handle,
                                           const QList<int> &languages)
{
    reply(handle).out(languages).send();
}

void UIAdapter::ReplyGetLanguage(const Handle& handle, int language)
{
    reply(handle).out(language).send();
}

void UIAdapter::ReplySetDisplayLayout(const Handle& handle,
    const Optional<DisplayCapabilities> &displayCapabilities,
    const Optional<QList<ButtonCapabilities> > &buttonCapabilities,
    const Optional<QList<SoftButtonCapabilities> > &softButtonCapabilities,
    const Optional<PresetBankCapabilities> &presetBankCapabilities)
{
    reply(handle).out(displayCapabilities).out(buttonCapabilities)
            .out(softButtonCapabilities).out(presetBankCapabilities).send();
}

void UIAdapter::ReplyShowCustomForm(const Handle& handle,
                                    const Optional<QString> &info)
{
    reply(handle).out(info).send();
}

void UIAdapter::ReplySlider(const Handle& handle,
                            const Optional<int> &sliderPosition)
{
    reply(handle).out(sliderPosition).send();
}

void UIAdapter::ReplyIsReady(const Handle& handle, bool available)
{
    reply(handle).out(available).send();
}

void UIAdapter::OnRecordStart(int appID)
{
    emit qml->onRecordStart(appID);
}

void UI::replyAlert(const QVariantMap& handle, const QVariant &tryAgainTime)
{
    adapter->ReplyAlert(handle, tryAgainTime);
}

void UI::replyPerformInteraction(const QVariantMap& handle,
    const QVariant &choiceID, const QVariant &manualTextEntry)
{
    adapter->ReplyPerformInteraction(handle, choiceID, manualTextEntry);
}

void UI::replyGetCapabilities(const QVariantMap& handle,
    const QVariantMap &displayCapabilities,
    const QVariantMap &audioPassThruCapabilities, int hmiZoneCapabilities,
    const QVariant &softButtonCapabilities, const QVariant &hmiCapabilities)
{
    adapter->ReplyGetCapabilities(handle, single<DisplayCapabilities>(displayCapabilities),
        single<AudioPassThruCapabilities>(audioPassThruCapabilities),
                                  hmiZoneCapabilities, softButtonCapabilities, hmiCapabilities);
}

void UI::replyGetSupportedLanguages(const QVariantMap& handle,
                                    const QList<int> &languages)
{
    adapter->ReplyGetSupportedLanguages(handle, languages);
}

void UI::replyGetLanguage(const QVariantMap& handle, int language)
{
    adapter->ReplyGetLanguage(handle, language);
}

void UI::replySetDisplayLayout(const QVariantMap& handle,
    const QVariant &displayCapabilities,
    const QVariant &buttonCapabilities, const QVariant &softButtonCapabilities,
    const QVariant &presetBankCapabilities)
{
    adapter->ReplySetDisplayLayout(handle, displayCapabilities, buttonCapabilities,
                                   softButtonCapabilities, presetBankCapabilities);
}

void UI::replyShowCustomForm(const QVariantMap& handle, const QVariant &info)
{
    adapter->ReplyShowCustomForm(handle, info);
}

void UI::replySlider(const QVariantMap &handle, const QVariant &sliderPosition)
{
    adapter->ReplySlider(handle, sliderPosition);
}

void UI::replyIsReady(const QVariantMap& handle, bool available)
{
    adapter->ReplyIsReady(handle, available);
}

void UI::onCommand(int cmdID, int appID)
{
    emit adapter->OnCommand(cmdID, appID);
}

void UI::onSystemContext(int systemContext, const QVariant &appID)
{
    emit adapter->OnSystemContext(systemContext, appID);
}

void UI::onLanguageChange(int language)
{
    emit adapter->OnLanguageChange(language);
}

void UI::onDriverDistraction(int state)
{
    emit adapter->OnDriverDistraction(state);
}

void UI::onKeyboardInput(int event, const QVariant &data)
{
    emit adapter->OnKeyboardInput(event, data);
}

void UI::onTouchEvent(int type, const QVariantList &event)
{
    emit adapter->OnTouchEvent(type, multiple<TouchEvent>(event));
}

void UI::onResetTimeout(int appID, const QString &methodName)
{
    emit adapter->OnResetTimeout(appID, methodName);
}
