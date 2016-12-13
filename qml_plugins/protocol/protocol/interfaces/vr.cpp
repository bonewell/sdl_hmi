#include "vr.h"

void VRAdapter::IsReady(const Message &message)
{
    call("isReady", message).run();
}

void VRAdapter::AddCommand(int cmdID, const QStringList &vrCommands, int type,
    int grammarID, const Optional<int> &appID, const Message &message)
{
    call("addCommand", message).in(cmdID).in(vrCommands).in(type)
            .in(grammarID).in(appID).run();
}

void VRAdapter::DeleteCommand(int cmdID, int type, int grammarID, int appID,
    const Message &message)
{
    call("deleteCommand", message).in(cmdID).in(type).in(grammarID).in(appID).run();
}

void VRAdapter::PerformInteraction(const Optional<QList<TTSChunk> > &helpPrompt,
    const Optional<QList<TTSChunk> > &initialPrompt,
    const Optional<QList<TTSChunk> > &timeoutPrompt, int timeout,
    const QList<int> &grammarID, int appID, const Message &message)
{
    call("performInteraction", message).in(helpPrompt).in(initialPrompt)
            .in(timeoutPrompt).in(timeout).in(grammarID).in(appID).run();
}

void VRAdapter::ChangeRegistration(const Optional<QStringList> &vrSynonyms,
    int language, int appID, const Message &message)
{
    call("changeRegistration", message).in(vrSynonyms).in(language).in(appID).run();
}

void VRAdapter::GetSupportedLanguages(const Message &message)
{
    call("getSupportedLanguages", message).run();
}

void VRAdapter::GetLanguage(const Message &message)
{
    call("getLanguage", message).run();
}

void VRAdapter::GetCapabilities(const Message &message)
{
    call("getCapabilities", message).run();
}

void VR::replyIsReady(const QVariantMap& handle, bool available)
{
    response(handle).out(available).send();
}

void VR::replyPerformInteraction(const QVariantMap& handle, const QVariant &choiceID)
{
    response(handle).out<Optional<int> >(choiceID).send();
}

void VR::replyGetSupportedLanguages(const QVariantMap& handle, const QList<int> &languages)
{
    response(handle).out(languages).send();
}

void VR::replyGetLanguage(const QVariantMap& handle, int language)
{
    response(handle).out(language).send();
}

void VR::replyGetCapabilities(const QVariantMap& handle, const QVariant &vrCapabilities)
{
    response(handle).out<Optional<QList<int> > >(vrCapabilities).send();
}

void VR::started()
{
    notification("Started").send();
}

void VR::stopped()
{
    notification("Stopped").send();
}

void VR::onCommand(int cmdID, int appID)
{
    notification("OnCommand").arg(cmdID).arg(appID).send();
}

void VR::onLanguageChange(int language)
{
    notification("OnLanguageChange").arg(language).send();
}
