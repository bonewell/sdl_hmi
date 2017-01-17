#ifndef TTS_H
#define TTS_H

#include "core/abstractadapter.h"
#include "core/abstractitem.h"
#include "protocol/structures.h"

#define TTS_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.TTS\">" \
    "<method name=\"GetCapabilities\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"speechCapabilities\" type=\"ai\" />" \
    "<arg direction=\"out\" name=\"prerecordedSpeechCapabilities\" type=\"ai\" />" \
    "</method>" \
    "<method name=\"IsReady\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"available\" type=\"b\" />" \
    "</method>" \
    "<method name=\"Speak\">" \
    "<arg direction=\"in\" name=\"ttsChunks\" type=\"a(si)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"speakType\" type=\"(bi)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"StopSpeaking\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<method name=\"ChangeRegistration\">" \
    "<arg direction=\"in\" name=\"ttsName\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"language\" type=\"i\" />" \
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
    "<method name=\"SetGlobalProperties\">" \
    "<arg direction=\"in\" name=\"helpPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"timeoutPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "</method>" \
    "<signal name=\"Started\" />" \
    "<signal name=\"Stopped\" />" \
    "<signal name=\"OnLanguageChange\">" \
    "<arg name=\"language\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnResetTimeout\">" \
    "<arg name=\"appID\" type=\"i\" />" \
    "<arg name=\"methodName\" type=\"s\" />" \
    "</signal>" \
    "</interface>"

class TTS;

class TTSAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO(300, TTS, TTS_INTROSPECTION)
    REGISTER_ADAPTER(TTSAdapter, TTS)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.TTS")

// Incoming requests
public slots:
    void GetCapabilities(const Message& message);
    void IsReady(const Message& message);
    void Speak(const QList<TTSChunk>& ttsChunks, int appID,
        const Optional<int>& speakType, const Optional<bool>& playTone,
        const Message& message);
    void StopSpeaking(const Message& message);
    void ChangeRegistration(const Optional<QList<TTSChunk> >& ttsName,
        int language, int appID, const Message& message);
    void GetSupportedLanguages(const Message& message);
    void GetLanguage(const Message& message);
    void SetGlobalProperties(const Optional<QList<TTSChunk> >& helpPrompt,
        const Optional<QList<TTSChunk> >& timeoutPrompt, int appID,
        const Message& message);
};

class TTS : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(TTS, TTSAdapter)

public:
// Outcoming notifications
    Q_INVOKABLE void started();
    Q_INVOKABLE void stopped();
    Q_INVOKABLE void onLanguageChange(int language);
    Q_INVOKABLE void onResetTimeout(int appID, const QString& methodName);

// Outcoming responses
    Q_INVOKABLE void replyGetCapabilities(const QVariantMap& handle,
        const QList<int>& speechCapabilities,
        const QList<int>& prerecordedSpeechCapabilities);
    Q_INVOKABLE void replyIsReady(const QVariantMap& handle, bool available);
    Q_INVOKABLE void replyGetSupportedLanguages(const QVariantMap& handle, const QList<int>& languages);
    Q_INVOKABLE void replyGetLanguage(const QVariantMap& handle, int language);
};

#endif // TTS_H
