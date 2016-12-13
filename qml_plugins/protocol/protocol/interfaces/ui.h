#ifndef UI_H
#define UI_H

#include "core/abstractadapter.h"
#include "core/abstractitem.h"
#include "protocol/structures.h"

#define UI_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.UI\">" \
    "<method name=\"Alert\">" \
    "<arg direction=\"in\" name=\"alertStrings\" type=\"a(is)\" />" \
    "<arg direction=\"in\" name=\"duration\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"softButtons\" type=\"(ba(i(bs)(b(si))(bb)ii))\" />" \
    "<arg direction=\"in\" name=\"progressIndicator\" type=\"(bb)\" />" \
    "<arg direction=\"in\" name=\"alertType\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"tryAgainTime\" type=\"(bi)\" />" \
    "</method>" \
    "<method name=\"Show\">" \
    "<arg direction=\"in\" name=\"showStrings\" type=\"a(is)\" />" \
    "<arg direction=\"in\" name=\"alignment\" type=\"(bi)\" />" \
    "<arg direction=\"in\" name=\"graphic\" type=\"(b(si))\" />" \
    "<arg direction=\"in\" name=\"secondaryGraphic\" type=\"(b(si))\" />" \
    "<arg direction=\"in\" name=\"softButtons\" type=\"(ba(i(bs)(b(si))(bb)ii))\" />" \
    "<arg direction=\"in\" name=\"customPresets\" type=\"(bas)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"AddCommand\">" \
    "<arg direction=\"in\" name=\"cmdID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"menuParams\" type=\"(b((bi)(bi)s))\" />" \
    "<arg direction=\"in\" name=\"cmdIcon\" type=\"(b(si))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"DeleteCommand\">" \
    "<arg direction=\"in\" name=\"cmdID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"AddSubMenu\">" \
    "<arg direction=\"in\" name=\"menuID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"menuParams\" type=\"((bi)(bi)s)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"DeleteSubMenu\">" \
    "<arg direction=\"in\" name=\"menuID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"PerformInteraction\">" \
    "<arg direction=\"in\" name=\"initialText\" type=\"(b(is))\" />" \
    "<arg direction=\"in\" name=\"choiceSet\" type=\"(ba(i(bs)(b(si))(bs)(bs)(b(si))))\" />" \
    "<arg direction=\"in\" name=\"vrHelpTitle\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"vrHelp\" type=\"(ba(s(b(si))i))\" />" \
    "<arg direction=\"in\" name=\"timeout\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"interactionLayout\" type=\"(bi)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"choiceID\" type=\"(bi)\" />" \
    "<arg direction=\"out\" name=\"manualTextEntry\" type=\"(bs)\" />" \
    "</method>" \
    "<method name=\"SetMediaClockTimer\">" \
    "<arg direction=\"in\" name=\"startTime\" type=\"(b(iii))\" />" \
    "<arg direction=\"in\" name=\"endTime\" type=\"(b(iii))\" />" \
    "<arg direction=\"in\" name=\"updateMode\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"SetGlobalProperties\">" \
    "<arg direction=\"in\" name=\"vrHelpTitle\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"vrHelp\" type=\"(ba(s(b(si))i))\" />" \
    "<arg direction=\"in\" name=\"menuTitle\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"menuIcon\" type=\"(b(si))\" />" \
    "<arg direction=\"in\" name=\"keyboardProperties\" type=\"(b((bi)(bi)(bi)(bas)(bs)))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"GetCapabilities\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"displayCapabilities\" type=\"(ia(iiii)(ba(i(bai)(b(ii))))ai(bai)bas(b((ii)(b(bbb))))(bi))\" />" \
    "<arg direction=\"out\" name=\"audioPassThruCapabilities\" type=\"(iii)\" />" \
    "<arg direction=\"out\" name=\"hmiZoneCapabilities\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"softButtonCapabilities\" type=\"(ba(bbbb))\" />" \
    "<arg direction=\"out\" name=\"hmiCapabilities\" type=\"(b((bb)(bb)))\" />" \
    "</method>" \
    "<method name=\"ChangeRegistration\">" \
    "<arg direction=\"in\" name=\"appName\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"ngnMediaScreenAppName\" type=\"(bs)\" />" \
    "<arg direction=\"in\" name=\"language\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appHMIType\" type=\"(bai)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"GetSupportedLanguages\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"languages\" type=\"ai\" />" \
    "</method>" \
    "<method name=\"GetLanguage\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"language\" type=\"i\" />" \
    "</method>" \
    "<method name=\"SetAppIcon\">" \
    "<arg direction=\"in\" name=\"syncFileName\" type=\"(si)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"SetDisplayLayout\">" \
    "<arg direction=\"in\" name=\"displayLayout\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"displayCapabilities\" type=\"(b(ia(iiii)(ba(i(bai)(b(ii))))ai(bai)bas(b((ii)(b(bbb))))(bi)))\" />" \
    "<arg direction=\"out\" name=\"buttonCapabilities\" type=\"(ba(ibbb))\" />" \
    "<arg direction=\"out\" name=\"softButtonCapabilities\" type=\"(ba(bbbb))\" />" \
    "<arg direction=\"out\" name=\"presetBankCapabilities\" type=\"(b(b))\" />" \
    "</method>" \
    "<method name=\"ShowCustomForm\">" \
    "<arg direction=\"in\" name=\"customFormID\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"parentFormID\" type=\"(bs)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"info\" type=\"(bs)\" />" \
    "</method>" \
    "<method name=\"Slider\">" \
    "<arg direction=\"in\" name=\"numTicks\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"position\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"sliderHeader\" type=\"s\" />" \
    "<arg direction=\"in\" name=\"sliderFooter\" type=\"(bas)\" />" \
    "<arg direction=\"in\" name=\"timeout\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"sliderPosition\" type=\"(bi)\" />" \
    "</method>" \
    "<method name=\"ScrollableMessage\">" \
    "<arg direction=\"in\" name=\"messageText\" type=\"(is)\" />" \
    "<arg direction=\"in\" name=\"timeout\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"softButtons\" type=\"(ba(i(bs)(b(si))(bb)ii))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"PerformAudioPassThru\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"audioPassThruDisplayTexts\" type=\"a(is)\" />" \
    "<arg direction=\"in\" name=\"maxDuration\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"muteAudio\" type=\"b\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"EndAudioPassThru\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"IsReady\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"available\" type=\"b\" />" \
    "</method>" \
    "<method name=\"ClosePopUp\">" \
    "<arg direction=\"in\" name=\"methodName\" type=\"(bs)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<signal name=\"OnCommand\">" \
    "<arg name=\"cmdID\" type=\"i\" />" \
    "<arg name=\"appID\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnSystemContext\">" \
    "<arg name=\"systemContext\" type=\"i\" />" \
    "<arg name=\"appID\" type=\"(bi)\" />" \
    "</signal>" \
    "<signal name=\"OnLanguageChange\">" \
    "<arg name=\"language\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnDriverDistraction\">" \
    "<arg name=\"state\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnKeyboardInput\">" \
    "<arg name=\"event\" type=\"i\" />" \
    "<arg name=\"data\" type=\"(bs)\" />" \
    "</signal>" \
    "<signal name=\"OnTouchEvent\">" \
    "<arg name=\"type\" type=\"i\" />" \
    "<arg name=\"event\" type=\"a(iaia(ii))\" />" \
    "</signal>" \
    "<signal name=\"OnResetTimeout\">" \
    "<arg name=\"appID\" type=\"i\" />" \
    "<arg name=\"methodName\" type=\"s\" />" \
    "</signal>" \
    "</interface>"

class UI;

class UIAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO(400, "com.ford.sdl.hmi.UI", UI_INTROSPECTION)
    REGISTER_ADAPTER(UIAdapter, UI)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.UI")

// Incoming requests
public slots:
    void Alert(const QList<TextFieldStruct>& alertStrings, int duration,
        const Optional<QList<SoftButton> >& softButtons,
        const Optional<bool>& progressIndicator, int alertType, int appID,
        const Message& message);
    void Show(const QList<TextFieldStruct>& showStrings,
        const Optional<int>& aligment, const Optional<Image>& graphic,
        const Optional<Image>& secondaryGraphic,
        const Optional<QList<SoftButton> >& softButtons,
        const Optional<QStringList>& customPresets, int appID, const Message& message);
    void AddCommand(int cmdID, const Optional<MenuParams>& menuParams,
        const Optional<Image>& cmdIcon, int appID, const Message& message);
    void DeleteCommand(int cmdID, int appID, const Message& message);
    void AddSubMenu(int menuID, const MenuParams& menuParams, int appID,
        const Message& message);
    void DeleteSubMenu(int menuID, int appID, const Message& message);
    void PerformInteraction(const Optional<TextFieldStruct>& initialText,
        const Optional<QList<Choice> >& choiceSet,
        const Optional<QString>& vrHelpTitle,
        const Optional<QList<VrHelpItem> >& vrHelp, int timeout,
        const Optional<int>& interactionLayout, int appID,
        const Message& message);
    void SetMediaClockTimer(const Optional<TimeFormat>& startTime,
        const Optional<TimeFormat>& endTime, int updateMode, int appID,
        const Message& message);
    void SetGlobalProperties(const Optional<QString>& vrHelpTitle,
        const Optional<QList<VrHelpItem> >& vrHelp, const Optional<QString>& menuTitle,
        const Optional<Image>& menuIcon, const Optional<KeyboardProperties>& keyboardProperties,
        int appID, const Message& message);
    void GetCapabilities(const Message& message);
    void ChangeRegistration(const Optional<QString>& appName,
        const Optional<QString>& ngnMediaScreenAppName, int language,
        const Optional<QList<int> >& appHMIType, int appID, const Message& message);
    void GetSupportedLanguages(const Message& message);
    void GetLanguage(const Message& message);
    void SetAppIcon(const Image& syncFileName, int appID, const Message& message);
    void SetDisplayLayout(const QString& displayLayout, int appID, const Message& message);
    void ShowCustomForm(const QString& customFormID, const Optional<QString>& parentFormID,
        const Message& message);
    void Slider(int numTicks, int position, const QString& sliderHeader,
        const Optional<QStringList>& sliderFooter, int timeout, int appID,
        const Message& message);
    void ScrollableMessage(const TextFieldStruct& messageText, int timeout,
        const Optional<QList<SoftButton> >& softButtons, int appID, const Message& message);
    void PerformAudioPassThru(int appID, const QList<TextFieldStruct>& audioPassThruDisplayTexts,
        int maxDuration, bool muteAudio, const Message& message);
    void EndAudioPassThru(const Message& message);
    void IsReady(const Message& message);
    void ClosePopUp(const Optional<QString>& methodName, const Message& message);

// Incoming notifications
private slots:
    void OnRecordStart(int appID);
};

class UI : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(UI, UIAdapter)

public:
// Outcoming notifications
    Q_INVOKABLE void onCommand(int cmdID, int appID);
    Q_INVOKABLE void onSystemContext(int systemContext, const QVariant& appID = QVariant());
    Q_INVOKABLE void onLanguageChange(int language);
    Q_INVOKABLE void onDriverDistraction(int state);
    Q_INVOKABLE void onKeyboardInput(int event, const QVariant& data = QVariant());
    Q_INVOKABLE void onTouchEvent(int type, const QVariantList& event);
    Q_INVOKABLE void onResetTimeout(int appID, const QString& methodName);

// Outcoming responses
    Q_INVOKABLE void replyAlert(const QVariantMap& handle,
                                const QVariant& tryAgainTime = QVariant());
    Q_INVOKABLE void replyPerformInteraction(const QVariantMap& handle,
        const QVariant& choiceID = QVariant(),
        const QVariant& manualTextEntry = QVariant());
    Q_INVOKABLE void replyGetCapabilities(const QVariantMap& handle,
        const QVariantMap& displayCapabilities,
        const QVariantMap& audioPassThruCapabilities, int hmiZoneCapabilities,
        const QVariant& softButtonCapabilities = QVariant(),
        const QVariant& hmiCapabilities = QVariant());
    Q_INVOKABLE void replyGetSupportedLanguages(const QVariantMap& handle,
                                                const QList<int>& languages);
    Q_INVOKABLE void replyGetLanguage(const QVariantMap& handle, int language);
    Q_INVOKABLE void replySetDisplayLayout(const QVariantMap& handle,
        const QVariant& displayCapabilities = QVariant(),
        const QVariant& buttonCapabilities = QVariant(),
        const QVariant& softButtonCapabilities = QVariant(),
        const QVariant& presetBankCapabilities = QVariant());
    Q_INVOKABLE void replyShowCustomForm(const QVariantMap& handle,
                                         const QVariant& info = QVariant());
    Q_INVOKABLE void replySlider(const QVariantMap& handle,
                                 const QVariant& sliderPosition = QVariant());
    Q_INVOKABLE void replyIsReady(const QVariantMap& handle, bool available);

// Incoming notifications
signals:
    void onRecordStart(int appID);
};

#endif // UI_H
