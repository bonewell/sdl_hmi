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

void UIAdapter::ReplyAlert(int handle, const Optional<int> &tryAgainTime)
{
    reply(handle).out(tryAgainTime).send();
}

void UIAdapter::ReplyShow(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyAddCommand(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyDeleteCommand(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyAddSubMenu(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyDeleteSubMenu(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyPerformInteraction(int handle, const Optional<int> &choiceID,
    const Optional<QString> &manualTextEntry)
{
    reply(handle).out(choiceID).out(manualTextEntry).send();
}

void UIAdapter::ReplySetMediaClockTimer(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplySetGlobalProperties(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyGetCapabilities(int handle,
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

void UIAdapter::ReplyChangeRegistration(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyGetSupportedLanguages(int handle, const QList<int> &languages)
{
    reply(handle).out(languages).send();
}

void UIAdapter::ReplyGetLanguage(int handle, int language)
{
    reply(handle).out(language).send();
}

void UIAdapter::ReplySetAppIcon(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplySetDisplayLayout(int handle,
    const Optional<DisplayCapabilities> &displayCapabilities,
    const Optional<QList<ButtonCapabilities> > &buttonCapabilities,
    const Optional<QList<SoftButtonCapabilities> > &softButtonCapabilities,
    const Optional<PresetBankCapabilities> &presetBankCapabilities)
{
    reply(handle).out(displayCapabilities).out(buttonCapabilities)
            .out(softButtonCapabilities).out(presetBankCapabilities).send();
}

void UIAdapter::ReplyShowCustomForm(int handle, const Optional<QString> &info)
{
    reply(handle).out(info).send();
}

void UIAdapter::ReplySlider(int handle, const Optional<int> &sliderPosition)
{
    reply(handle).out(sliderPosition).send();
}

void UIAdapter::ReplyScrollableMessage(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyPerformAudioPassThru(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyEndAudioPassThru(int handle)
{
    reply(handle).send();
}

void UIAdapter::ReplyIsReady(int handle, bool available)
{
    reply(handle).out(available).send();
}

void UIAdapter::ReplyClosePopUp(int handle)
{
    reply(handle).send();
}

void UIAdapter::OnRecordStart(int appID)
{
    emit qml->onRecordStart(appID);
}

void UI::replyAlert(int handle, const QVariant &tryAgainTime)
{
    adapter->ReplyAlert(handle, tryAgainTime);
}

void UI::replyShow(int handle)
{
    adapter->ReplyShow(handle);
}

void UI::replyAddCommand(int handle)
{
    adapter->ReplyAddCommand(handle);
}

void UI::replyDeleteCommand(int handle)
{
    adapter->ReplyDeleteCommand(handle);
}

void UI::replyAddSubMenu(int handle)
{
    adapter->ReplyAddSubMenu(handle);
}

void UI::replyDeleteSubMenu(int handle)
{
    adapter->ReplyDeleteSubMenu(handle);
}

void UI::replyPerformInteraction(int handle, const QVariant &choiceID,
    const QVariant &manualTextEntry)
{
    adapter->ReplyPerformInteraction(handle, choiceID, manualTextEntry);
}

void UI::replySetMediaClockTimer(int handle)
{
    adapter->ReplySetMediaClockTimer(handle);
}

void UI::replySetGlobalProperties(int handle)
{
    adapter->ReplySetGlobalProperties(handle);
}

void UI::replyGetCapabilities(int handle, const QVariantMap &displayCapabilities,
    const QVariantMap &audioPassThruCapabilities, int hmiZoneCapabilities,
    const QVariant &softButtonCapabilities, const QVariant &hmiCapabilities)
{
    adapter->ReplyGetCapabilities(handle, single<DisplayCapabilities>(displayCapabilities),
        single<AudioPassThruCapabilities>(audioPassThruCapabilities),
                                  hmiZoneCapabilities, softButtonCapabilities, hmiCapabilities);
}

void UI::replyChangeRegistration(int handle)
{
    adapter->ReplyChangeRegistration(handle);
}

void UI::replyGetSupportedLanguages(int handle, const QList<int> &languages)
{
    adapter->ReplyGetSupportedLanguages(handle, languages);
}

void UI::replyGetLanguage(int handle, int language)
{
    adapter->ReplyGetLanguage(handle, language);
}

void UI::replySetAppIcon(int handle)
{
    adapter->ReplySetAppIcon(handle);
}

void UI::replySetDisplayLayout(int handle, const QVariant &displayCapabilities,
    const QVariant &buttonCapabilities, const QVariant &softButtonCapabilities,
    const QVariant &presetBankCapabilities)
{
    adapter->ReplySetDisplayLayout(handle, displayCapabilities, buttonCapabilities,
                                   softButtonCapabilities, presetBankCapabilities);
}

void UI::replyShowCustomForm(int handle, const QVariant &info)
{
    adapter->ReplyShowCustomForm(handle, info);
}

void UI::replyScrollableMessage(int handle)
{
    adapter->ReplyScrollableMessage(handle);
}

void UI::replyPerformAudioPassThru(int handle)
{
    adapter->ReplyPerformAudioPassThru(handle);
}

void UI::replyEndAudioPassThru(int handle)
{
    adapter->ReplyEndAudioPassThru(handle);
}

void UI::replyIsReady(int handle, bool available)
{
    adapter->ReplyIsReady(handle, available);
}

void UI::replyClosePopUp(int handle)
{
    adapter->ReplyClosePopUp(handle);
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
