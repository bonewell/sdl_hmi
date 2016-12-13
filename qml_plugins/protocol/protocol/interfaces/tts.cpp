#include "tts.h"

void TTSAdapter::GetCapabilities(const Message &message)
{
    call("getCapabilities", message).run();
}

void TTSAdapter::IsReady(const Message &message)
{
    call("isReady", message).run();
}

void TTSAdapter::Speak(const QList<TTSChunk> &ttsChunks, int appID,
    const Optional<int> &speakType, const Optional<bool> &playTone,
    const Message &message)
{
    call("speak", message).in(ttsChunks).in(appID)
            .in(speakType).in(playTone).run();
}

void TTSAdapter::StopSpeaking(const Message &message)
{
    call("stopSpeaking", message).run();
}

void TTSAdapter::ChangeRegistration(const Optional<QList<TTSChunk> > &ttsName,
    int language, int appID, const Message &message)
{
    call("changeRegistration", message).in(ttsName).in(language).in(appID).run();
}

void TTSAdapter::GetSupportedLanguages(const Message &message)
{
    call("getSupportedLanguages", message).run();
}

void TTSAdapter::GetLanguage(const Message &message)
{
    call("getLanguage", message).run();
}

void TTSAdapter::SetGlobalProperties(const Optional<QList<TTSChunk> > &helpPrompt,
    const Optional<QList<TTSChunk> > &timeoutPrompt, int appID,
    const Message &message)
{
    call("setGlobalProperties", message).in(helpPrompt).in(timeoutPrompt).in(appID).run();
}

void TTS::replyGetCapabilities(const QVariantMap& handle, const QList<int> &speechCapabilities,
    const QList<int> &prerecordedSpeechCapabilities)
{
    response(handle).out(speechCapabilities).out(prerecordedSpeechCapabilities).send();
}

void TTS::replyIsReady(const QVariantMap& handle, bool available)
{
    response(handle).out(available).send();
}

void TTS::replyGetSupportedLanguages(const QVariantMap& handle, const QList<int> &languages)
{
    response(handle).out(languages).send();
}

void TTS::replyGetLanguage(const QVariantMap& handle, int language)
{
    response(handle).out(language).send();
}

void TTS::started()
{
    notification("Started").send();
}

void TTS::stopped()
{
    notification("Stopped").send();
}

void TTS::onLanguageChange(int language)
{
    notification("OnLanguageChange").arg(language).send();
}

void TTS::onResetTimeout(int appID, const QString &methodName)
{
    notification("OnResetTimeout").arg(appID).arg(methodName).send();
}
