#ifndef TTS_H
#define TTS_H

#include "core/abstractadapter.h"
#include "protocol/structures.h"

#define TTS_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.TTS\">" \
    "<method name=\"GetCapabilities\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"speechCapabilities\" type=\"ai\" />" \
    "<arg direction=\"out\" name=\"prerecordedSpeechCapabilities\" type=\"ai\" />" \
    "</method>" \
    "<method name=\"IsReady\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"available\" type=\"b\" />" \
    "</method>" \
    "<method name=\"Speak\">" \
    "<arg direction=\"in\" name=\"ttsChunks\" type=\"a(si)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"speakType\" type=\"(bi)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"StopSpeaking\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"ChangeRegistration\">" \
    "<arg direction=\"in\" name=\"ttsName\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"language\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"GetSupportedLanguages\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"languages\" type=\"ai\" />" \
    "</method>" \
    "<method name=\"GetLanguage\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"language\" type=\"i\" />" \
    "</method>" \
    "<method name=\"SetGlobalProperties\">" \
    "<arg direction=\"in\" name=\"helpPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"timeoutPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
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
    ADAPTER_INFO("com.ford.sdl.hmi.TTS", TTS_INTROSPECTION)
    REGISTER_ADAPTER(TTSAdapter, TTS)

signals:
    void Started();
    void Stopped();
    void OnLanguageChange(int language);
    void OnResetTimeout(int appID, const QString& methodName);

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

public:
    void ReplyGetCapabilities(int handle,
        const QList<int>& speechCapabilities,
        const QList<int>& prerecordedSpeechCapabilities);
    void ReplyIsReady(int handle, bool available);
    void ReplySpeak(int handle);
    void ReplyStopSpeaking(int handle);
    void ReplyChangeRegistration(int handle);
    void ReplyGetSupportedLanguages(int handle, const QList<int>& languages);
    void ReplyGetLanguage(int handle, int language);
    void ReplySetGlobalProperties(int handle);
};

class TTS : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(TTS, TTSAdapter)

public:
    Q_INVOKABLE void started();
    Q_INVOKABLE void stopped();
    Q_INVOKABLE void onLanguageChange(int language);
    Q_INVOKABLE void onResetTimeout(int appID, const QString& methodName);

    Q_INVOKABLE void replyGetCapabilities(int handle,
        const QList<int>& speechCapabilities,
        const QList<int>& prerecordedSpeechCapabilities);
    Q_INVOKABLE void replyIsReady(int handle, bool available);
    Q_INVOKABLE void replySpeak(int handle);
    Q_INVOKABLE void replyStopSpeaking(int handle);
    Q_INVOKABLE void replyChangeRegistration(int handle);
    Q_INVOKABLE void replyGetSupportedLanguages(int handle, const QList<int>& languages);
    Q_INVOKABLE void replyGetLanguage(int handle, int language);
    Q_INVOKABLE void replySetGlobalProperties(int handle);
};

#endif // TTS_H
