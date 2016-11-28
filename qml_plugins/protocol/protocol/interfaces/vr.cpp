#include "vr.h"

void VRAdapter::IsReady(const Message &message)
{
    invoke("IsReady", message).run();
}

void VRAdapter::AddCommand(int cmdID, const QStringList &vrCommands, int type,
    int grammarID, const Optional<int> &appID, const Message &message)
{
    invoke("AddCommand", message).in(cmdID).in(vrCommands).in(type)
            .in(grammarID).in(appID).run();
}

void VRAdapter::DeleteCommand(int cmdID, int type, int grammarID, int appID,
    const Message &message)
{
    invoke("DeleteCommand", message).in(cmdID).in(type).in(grammarID).in(appID).run();
}

void VRAdapter::PerformInteraction(const Optional<QList<TTSChunk> > &helpPrompt,
    const Optional<QList<TTSChunk> > &initialPrompt,
    const Optional<QList<TTSChunk> > &timeoutPrompt, int timeout,
    const QList<int> &grammarID, int appID, const Message &message)
{
    invoke("PerformInteraction", message).in(helpPrompt).in(initialPrompt)
            .in(timeoutPrompt).in(timeout).in(grammarID).in(appID).run();
}

void VRAdapter::ChangeRegistration(const Optional<QStringList> &vrSynonyms,
    int language, int appID, const Message &message)
{
    invoke("ChangeRegistration", message).in(vrSynonyms).in(language).in(appID).run();
}

void VRAdapter::GetSupportedLanguages(const Message &message)
{
    invoke("GetSupportedLanguages", message).run();
}

void VRAdapter::GetLanguage(const Message &message)
{
    invoke("GetLanguage", message).run();
}

void VRAdapter::GetCapabilities(const Message &message)
{
    invoke("GetCapabilities", message).run();
}

void VR::replyIsReady(const QVariantMap& handle, bool available)
{
    adapter->reply(handle).out(available).send();
}

void VR::replyPerformInteraction(const QVariantMap& handle, const QVariant &choiceID)
{
    adapter->reply(handle).out<Optional<int> >(choiceID).send();
}

void VR::replyGetSupportedLanguages(const QVariantMap& handle, const QList<int> &languages)
{
    adapter->reply(handle).out(languages).send();
}

void VR::replyGetLanguage(const QVariantMap& handle, int language)
{
    adapter->reply(handle).out(language).send();
}

void VR::replyGetCapabilities(const QVariantMap& handle, const QVariant &vrCapabilities)
{
    adapter->reply(handle).out<Optional<QList<int> > >(vrCapabilities).send();
}

void VR::started()
{
    adapter->signal("Started").send();
}

void VR::stopped()
{
    adapter->signal("Stopped").send();
}

void VR::onCommand(int cmdID, int appID)
{
    adapter->signal("OnCommand").arg(cmdID).arg(appID).send();
}

void VR::onLanguageChange(int language)
{
    adapter->signal("OnLanguageChange").arg(language).send();
}
