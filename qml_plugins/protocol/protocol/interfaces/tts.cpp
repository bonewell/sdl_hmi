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

void TTS::replyGetCapabilities(const QVariantMap& handle, const QList<int> &speechCapabilities,
    const QList<int> &prerecordedSpeechCapabilities)
{
    adapter->reply(handle).out(speechCapabilities).out(prerecordedSpeechCapabilities).send();
}

void TTS::replyIsReady(const QVariantMap& handle, bool available)
{
    adapter->reply(handle).out(available).send();
}

void TTS::replyGetSupportedLanguages(const QVariantMap& handle, const QList<int> &languages)
{
    adapter->reply(handle).out(languages).send();
}

void TTS::replyGetLanguage(const QVariantMap& handle, int language)
{
    adapter->reply(handle).out(language).send();
}

void TTS::started()
{
    adapter->signal("Started").send();
}

void TTS::stopped()
{
    adapter->signal("Stopped").send();
}

void TTS::onLanguageChange(int language)
{
    adapter->signal("OnLanguageChange").arg(language).send();
}

void TTS::onResetTimeout(int appID, const QString &methodName)
{
    adapter->signal("OnResetTimeout").arg(appID).arg(methodName).send();
}
