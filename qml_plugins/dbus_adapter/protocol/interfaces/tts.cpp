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
    const Message &message)
{
    invoke("SetGlobalProperties", message).in(helpPrompt).in(timeoutPrompt).in(appID).run();
}

void TTSAdapter::ReplyGetCapabilities(const Handle& handle,
    const QList<int> &speechCapabilities,
    const QList<int> &prerecordedSpeechCapabilities)
{
    reply(handle).out(speechCapabilities).out(prerecordedSpeechCapabilities).send();
}

void TTSAdapter::ReplyIsReady(const Handle& handle, bool available)
{
    reply(handle).out(available).send();
}

void TTSAdapter::ReplySpeak(const Handle& handle)
{
    reply(handle).send();
}

void TTSAdapter::ReplyStopSpeaking(const Handle& handle)
{
    reply(handle).send();
}

void TTSAdapter::ReplyChangeRegistration(const Handle& handle)
{
    reply(handle).send();
}

void TTSAdapter::ReplyGetSupportedLanguages(const Handle &handle,
    const QList<int> &languages)
{
    reply(handle).out(languages).send();
}

void TTSAdapter::ReplyGetLanguage(const Handle& handle, int language)
{
    reply(handle).out(language).send();
}

void TTSAdapter::ReplySetGlobalProperties(const Handle& handle)
{
    reply(handle).send();
}

void TTS::replyGetCapabilities(const QVariantMap& handle, const QList<int> &speechCapabilities,
    const QList<int> &prerecordedSpeechCapabilities)
{
    adapter->ReplyGetCapabilities(handle, speechCapabilities,
                                  prerecordedSpeechCapabilities);
}

void TTS::replyIsReady(const QVariantMap& handle, bool available)
{
    adapter->ReplyIsReady(handle, available);
}

void TTS::replySpeak(const QVariantMap& handle)
{
    adapter->ReplySpeak(handle);
}

void TTS::replyStopSpeaking(const QVariantMap& handle)
{
    adapter->ReplyStopSpeaking(handle);
}

void TTS::replyChangeRegistration(const QVariantMap& handle)
{
    adapter->ReplyChangeRegistration(handle);
}

void TTS::replyGetSupportedLanguages(const QVariantMap& handle, const QList<int> &languages)
{
    adapter->ReplyGetSupportedLanguages(handle, languages);
}

void TTS::replyGetLanguage(const QVariantMap& handle, int language)
{
    adapter->ReplyGetLanguage(handle, language);
}

void TTS::replySetGlobalProperties(const QVariantMap& handle)
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
