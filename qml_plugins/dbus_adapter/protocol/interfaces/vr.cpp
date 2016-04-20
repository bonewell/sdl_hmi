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

void VRAdapter::ReplyIsReady(int handle, bool available)
{
    reply(handle).out(available).send();
}

void VRAdapter::ReplyAddCommand(int handle)
{
    reply(handle).send();
}

void VRAdapter::ReplyDeleteCommand(int handle)
{
    reply(handle).send();
}

void VRAdapter::ReplyPerformInteraction(int handle, const Optional<int> &choiceID)
{
    reply(handle).out(choiceID).send();
}

void VRAdapter::ReplyChangeRegistration(int handle)
{
    reply(handle).send();
}

void VRAdapter::ReplyGetSupportedLanguages(int handle, const QList<int> &languages)
{
    reply(handle).out(languages).send();
}

void VRAdapter::ReplyGetLanguage(int handle, int language)
{
    reply(handle).out(language).send();
}

void VRAdapter::ReplyGetCapabilities(int handle, const Optional<QList<int> > &vrCapabilities)
{
    reply(handle).out(vrCapabilities).send();
}

void VR::replyIsReady(int handle, bool available)
{
    adapter->ReplyIsReady(handle, available);
}

void VR::replyAddCommand(int handle)
{
    adapter->ReplyAddCommand(handle);
}

void VR::replyDeleteCommand(int handle)
{
    adapter->ReplyDeleteCommand(handle);
}

void VR::replyPerformInteraction(int handle, const QVariant &choiceID)
{
    adapter->ReplyPerformInteraction(handle, choiceID);
}

void VR::replyChangeRegistration(int handle)
{
    adapter->ReplyChangeRegistration(handle);
}

void VR::replyGetSupportedLanguages(int handle, const QList<int> &languages)
{
    adapter->ReplyGetSupportedLanguages(handle, languages);
}

void VR::replyGetLanguage(int handle, int language)
{
    adapter->ReplyGetLanguage(handle, language);
}

void VR::replyGetCapabilities(int handle, const QVariant &vrCapabilities)
{
    adapter->ReplyGetCapabilities(handle, vrCapabilities);
}

void VR::started()
{
    emit adapter->Started();
}

void VR::stopped()
{
    emit adapter->Stopped();
}

void VR::onCommand(int cmdID, int appID)
{
    emit adapter->OnCommand(cmdID, appID);
}

void VR::onLanguageChange(int language)
{
    emit adapter->OnLanguageChange(language);
}
