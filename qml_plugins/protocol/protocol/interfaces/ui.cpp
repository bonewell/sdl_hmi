#include "ui.h"

void UIAdapter::Alert(const QList<TextFieldStruct> &alertStrings, int duration,
    const Optional<QList<SoftButton> > &softButtons,
    const Optional<bool> &progressIndicator, int alertType, int appID,
    const Message &message)
{
    call("alert", message).in(alertStrings).in(duration).in(softButtons)
            .in(progressIndicator).in(alertType).in(appID).run();
}

void UIAdapter::Show(const QList<TextFieldStruct> &showStrings,
    const Optional<int> &aligment, const Optional<Image> &graphic,
    const Optional<Image> &secondaryGraphic,
    const Optional<QList<SoftButton> > &softButtons,
    const Optional<QStringList> &customPresets, int appID, const Message &message)
{
    call("show", message).in(showStrings).in(aligment).in(graphic)
            .in(secondaryGraphic).in(softButtons).in(customPresets).in(appID).run();
}

void UIAdapter::AddCommand(int cmdID, const Optional<MenuParams> &menuParams,
    const Optional<Image> &cmdIcon, int appID, const Message &message)
{
    call("addCommand", message).in(cmdID).in(menuParams).in(cmdIcon).in(appID).run();
}

void UIAdapter::DeleteCommand(int cmdID, int appID, const Message &message)
{
    call("deleteCommand", message).in(cmdID).in(appID).run();
}

void UIAdapter::AddSubMenu(int menuID, const MenuParams &menuParams, int appID,
    const Message& message)
{
    call("addSubMenu", message).in(menuID).in(menuParams).in(appID).run();
}

void UIAdapter::DeleteSubMenu(int menuID, int appID, const Message &message)
{
    call("deleteSubMenu", message).in(menuID).in(appID).run();
}

void UIAdapter::PerformInteraction(const Optional<TextFieldStruct> &initialText,
    const Optional<QList<Choice> > &choiceSet, const Optional<QString> &vrHelpTitle,
    const Optional<QList<VrHelpItem> > &vrHelp, int timeout,
    const Optional<int> &interactionLayout, int appID, const Message &message)
{
    call("performInteraction", message).in(initialText).in(choiceSet)
            .in(vrHelpTitle).in(vrHelp).in(timeout).in(interactionLayout).in(appID).run();
}

void UIAdapter::SetMediaClockTimer(const Optional<TimeFormat> &startTime,
    const Optional<TimeFormat> &endTime, int updateMode, int appID,
    const Message &message)
{
    call("setMediaClockTimer", message).in(startTime).in(endTime)
            .in(updateMode).in(appID).run();
}

void UIAdapter::SetGlobalProperties(const Optional<QString> &vrHelpTitle,
    const Optional<QList<VrHelpItem> > &vrHelp, const Optional<QString> &menuTitle,
    const Optional<Image> &menuIcon, const Optional<KeyboardProperties> &keyboardProperties,
    int appID, const Message &message)
{
    call("setGlobalProperties", message).in(vrHelpTitle).in(vrHelp).in(menuTitle)
            .in(menuIcon).in(keyboardProperties).in(appID).run();
}

void UIAdapter::GetCapabilities(const Message &message)
{
    call("getCapabilities", message).run();
}

void UIAdapter::ChangeRegistration(const Optional<QString> &appName,
    const Optional<QString> &ngnMediaScreenAppName, int language,
    const Optional<QList<int> > &appHMIType, int appID, const Message &message)
{
    call("changeRegistration", message).in(appName).in(ngnMediaScreenAppName)
            .in(language).in(appHMIType).in(appID).run();
}

void UIAdapter::GetSupportedLanguages(const Message &message)
{
    call("getSupportedLanguages", message).run();
}

void UIAdapter::GetLanguage(const Message &message)
{
    call("getLanguage", message).run();
}

void UIAdapter::SetAppIcon(const Image &syncFileName, int appID, const Message &message)
{
    call("setAppIcon", message).in(syncFileName).in(appID).run();
}

void UIAdapter::SetDisplayLayout(const QString &displayLayout, int appID,
    const Message &message)
{
    call("setDisplayLayout", message).in(displayLayout).in(appID).run();
}

void UIAdapter::ShowCustomForm(const QString &customFormID,
    const Optional<QString> &parentFormID, const Message &message)
{
    call("showCustomForm", message).in(customFormID).in(parentFormID).run();
}

void UIAdapter::Slider(int numTicks, int position, const QString &sliderHeader,
    const Optional<QStringList> &sliderFooter, int timeout, int appID,
    const Message &message)
{
    call("slider", message).in(numTicks).in(position).in(sliderHeader)
            .in(sliderFooter).in(timeout).in(appID).run();
}

void UIAdapter::ScrollableMessage(const TextFieldStruct &messageText, int timeout,
    const Optional<QList<SoftButton> > &softButtons, int appID, const Message &message)
{
    call("scrollableMessage", message).in(messageText).in(timeout)
            .in(softButtons).in(appID).run();
}

void UIAdapter::PerformAudioPassThru(int appID,
    const QList<TextFieldStruct> &audioPassThruDisplayTexts, int maxDuration,
    bool muteAudio, const Message &message)
{
    call("performAudioPassThru", message).in(appID).in(audioPassThruDisplayTexts)
            .in(maxDuration).in(muteAudio).run();
}

void UIAdapter::EndAudioPassThru(const Message &message)
{
    call("endAudioPassThru", message).run();
}

void UIAdapter::IsReady(const Message &message)
{
    call("isReady", message).run();
}

void UIAdapter::ClosePopUp(const Optional<QString> &methodName, const Message &message)
{
    call("closePopUp", message).in(methodName).run();
}

void UIAdapter::OnRecordStart(int appID)
{
    emit qml->onRecordStart(appID);
}

void UI::replyAlert(const QVariantMap& handle, const QVariant &tryAgainTime)
{
    response(handle).out<Optional<int> >(tryAgainTime).send();
}

void UI::replyPerformInteraction(const QVariantMap& handle,
    const QVariant &choiceID, const QVariant &manualTextEntry)
{
    response(handle).out<Optional<int> >(choiceID)
            .out<Optional<QString> >(manualTextEntry).send();
}

void UI::replyGetCapabilities(const QVariantMap& handle,
    const QVariantMap &displayCapabilities,
    const QVariantMap &audioPassThruCapabilities, int hmiZoneCapabilities,
    const QVariant &softButtonCapabilities, const QVariant &hmiCapabilities)
{
    response(handle).out<DisplayCapabilities>(displayCapabilities)
            .out<AudioPassThruCapabilities>(audioPassThruCapabilities)
            .out(hmiZoneCapabilities)
            .out<Optional<QList<SoftButtonCapabilities> > >(softButtonCapabilities)
            .out<Optional<HMICapabilities> >(hmiCapabilities).send();
}

void UI::replyGetSupportedLanguages(const QVariantMap& handle,
                                    const QList<int> &languages)
{
    response(handle).out(languages).send();
}

void UI::replyGetLanguage(const QVariantMap& handle, int language)
{
    response(handle).out(language).send();
}

void UI::replySetDisplayLayout(const QVariantMap& handle,
    const QVariant &displayCapabilities,
    const QVariant &buttonCapabilities, const QVariant &softButtonCapabilities,
    const QVariant &presetBankCapabilities)
{
    response(handle).out<Optional<DisplayCapabilities> >(displayCapabilities)
            .out<Optional<QList<ButtonCapabilities> > >(buttonCapabilities)
            .out<Optional<QList<SoftButtonCapabilities> > >(softButtonCapabilities)
            .out<Optional<PresetBankCapabilities> >(presetBankCapabilities).send();
}

void UI::replyShowCustomForm(const QVariantMap& handle, const QVariant &info)
{
    response(handle).out<Optional<QString> >(info).send();
}

void UI::replySlider(const QVariantMap &handle, const QVariant &sliderPosition)
{
    response(handle).out<Optional<int> >(sliderPosition).send();
}

void UI::replyIsReady(const QVariantMap& handle, bool available)
{
    response(handle).out(available).send();
}

void UI::onCommand(int cmdID, int appID)
{
    notification("OnCommand").arg(cmdID).arg(appID).send();
}

void UI::onSystemContext(int systemContext, const QVariant &appID)
{
    notification("OnSystemContext").arg(systemContext)
            .arg<Optional<int> >(appID).send();
}

void UI::onLanguageChange(int language)
{
    notification("OnLanguageChange").arg(language).send();
}

void UI::onDriverDistraction(int state)
{
    notification("OnDriverDistraction").arg(state).send();
}

void UI::onKeyboardInput(int event, const QVariant &data)
{
    notification("OnKeyboardInput").arg(event).arg<Optional<QString> >(data).send();
}

void UI::onTouchEvent(int type, const QVariantList &event)
{
    notification("OnTouchEvent").arg(type).arg<QList<TouchEvent> >(event).send();
}

void UI::onResetTimeout(int appID, const QString &methodName)
{
    notification("OnResetTimeout").arg(appID).arg(methodName).send();
}
