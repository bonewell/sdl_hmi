#include "tts.h"

void TTSAdapter::GetCapabilities(const Message &message)
{
    invoke("GetCapabilities", message).run();
}

void TTSAdapter::IsReady(const Message &message)
{
    invoke("IsReady", message).run();
}

void TTSAdapter::Speak(const QList<TTSChunk> &ttsChunks, int appID,
    const Optional<int> &speakType, const Optional<bool> &playTone,
    const Message &message)
{
    invoke("Speak", message).in(ttsChunks).in(appID)
            .in(speakType).in(playTone).run();
}

void TTSAdapter::StopSpeaking(const Message &message)
{
    invoke("StopSpeaking", message).run();
}

void TTSAdapter::ChangeRegistration(const Optional<QList<TTSChunk> > &ttsName,
    int language, int appID, const Message &message)
{
    invoke("ChangeRegistration", message).in(ttsName).in(language).in(appID).run();
}

void TTSAdapter::GetSupportedLanguages(const Message &message)
{
    invoke("GetSupportedLanguages", message).run();
}

void TTSAdapter::GetLanguage(const Message &message)
{
    invoke("GetLanguage", message).run();
}

void TTSAdapter::SetGlobalProperties(const Optional<QList<TTSChunk> > &helpPrompt,
    const Optional<QList<TTSChunk> > &timeoutPrompt, int appID,
    const QDBusMessage &message)
{
    invoke("SetGlobalProperties", message).in(helpPrompt).in(timeoutPrompt).in(appID).run();
}

void TTSAdapter::ReplyGetCapabilities(int handle,
    const QList<int> &speechCapabilities,
    const QList<int> &prerecordedSpeechCapabilities)
{
    reply(handle).out(speechCapabilities).out(prerecordedSpeechCapabilities).send();
}

void TTSAdapter::ReplyIsReady(int handle, bool available)
{
    reply(handle).out(available).send();
}

void TTSAdapter::ReplySpeak(int handle)
{
    reply(handle).send();
}

void TTSAdapter::ReplyStopSpeaking(int handle)
{
    reply(handle).send();
}

void TTSAdapter::ReplyChangeRegistration(int handle)
{
    reply(handle).send();
}

void TTSAdapter::ReplyGetLanguage(int handle, int language)
{
    reply(handle).out(language).send();
}

void TTSAdapter::ReplySetGlobalProperties(int handle)
{
    reply(handle).send();
}

void TTS::replyGetCapabilities(int handle, const QList<int> &speechCapabilities,
    const QList<int> &prerecordedSpeechCapabilities)
{
    adapter->ReplyGetCapabilities(handle, speechCapabilities,
                                  prerecordedSpeechCapabilities);
}

void TTS::replyIsReady(int handle, bool available)
{
    adapter->ReplyIsReady(handle, available);
}

void TTS::replySpeak(int handle)
{
    adapter->ReplySpeak(handle);
}

void TTS::replyStopSpeaking(int handle)
{
    adapter->ReplyStopSpeaking(handle);
}

void TTS::replyChangeRegistration(int handle)
{
    adapter->ReplyChangeRegistration(handle);
}

void TTS::replyGetSupportedLanguages(int handle, const QList<int> &languages)
{
    adapter->ReplyGetSupportedLanguages(handle, languages);
}

void TTS::replyGetLanguage(int handle, int language)
{
    adapter->ReplyGetLanguage(handle, language);
}

void TTS::replySetGlobalProperties(int handle)
{
    adapter->ReplySetGlobalProperties(handle);
}

void TTS::started()
{
    emit adapter->Started();
}

void TTS::stopped()
{
    emit adapter->Stopped();
}

void TTS::onLanguageChange(int language)
{
    emit adapter->OnLanguageChange(language);
}

void TTS::onResetTimeout(int appID, const QString &methodName)
{
    emit adapter->OnResetTimeout(appID, methodName);
}
