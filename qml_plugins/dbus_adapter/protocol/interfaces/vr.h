#ifndef VR_H
#define VR_H

#include "core/abstractadapter.h"
#include "protocol/structures.h"

#define VR_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.VR\">" \
    "<method name=\"IsReady\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"available\" type=\"b\" />" \
    "</method>" \
    "<method name=\"AddCommand\">" \
    "<arg direction=\"in\" name=\"cmdID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"vrCommands\" type=\"as\" />" \
    "<arg direction=\"in\" name=\"type\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"grammarID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"(bi)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"DeleteCommand\">" \
    "<arg direction=\"in\" name=\"cmdID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"type\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"grammarID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"PerformInteraction\">" \
    "<arg direction=\"in\" name=\"helpPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"initialPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"timeoutPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"timeout\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"grammarID\" type=\"(bai)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"choiceID\" type=\"(bi)\" />" \
    "</method>" \
    "<method name=\"ChangeRegistration\">" \
    "<arg direction=\"in\" name=\"vrSynonyms\" type=\"(bas)\" />" \
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
    "<method name=\"GetCapabilities\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"vrCapabilities\" type=\"(bai)\" />" \
    "</method>" \
    "<signal name=\"Started\" />" \
    "<signal name=\"Stopped\" />" \
    "<signal name=\"OnCommand\">" \
    "<arg name=\"cmdID\" type=\"i\" />" \
    "<arg name=\"appID\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnLanguageChange\">" \
    "<arg name=\"language\" type=\"i\" />" \
    "</signal>" \
    "</interface>"

class VR;

class VRAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO("com.ford.sdl.hmi.VR", VR_INTROSPECTION)
    REGISTER_ADAPTER(VRAdapter, VR)

signals:
    void Started();
    void Stopped();
    void OnCommand(int cmdID, int appID);
    void OnLanguageChange(int language);

public slots:
    void IsReady(const Message& message);
    void AddCommand(int cmdID, const QStringList& vrCommands, int type,
        int grammarID, const Optional<int>& appID, const Message& message);
    void DeleteCommand(int cmdID, int type, int grammarID, int appID,
        const Message& message);
    void PerformInteraction(const Optional<QList<TTSChunk> >& helpPrompt,
        const Optional<QList<TTSChunk> >& initialPrompt,
        const Optional<QList<TTSChunk> >& timeoutPrompt,
        int timeout, const QList<int>& grammarID, int appID, const Message& message);
    void ChangeRegistration(const Optional<QStringList>& vrSynonyms, int language,
        int appID, const Message& message);
    void GetSupportedLanguages(const Message& message);
    void GetLanguage(const Message& message);
    void GetCapabilities(const Message& message);

public:
    void ReplyIsReady(int handle, bool available);
    void ReplyAddCommand(int handle);
    void ReplyDeleteCommand(int handle);
    void ReplyPerformInteraction(int handle, const Optional<int>& choiceID);
    void ReplyChangeRegistration(int handle);
    void ReplyGetSupportedLanguages(int handle, const QList<int>& languages);
    void ReplyGetLanguage(int handle, int language);
    void ReplyGetCapabilities(int handle, const Optional<QList<int> >& vrCapabilities);
};

class VR : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(VR, VRAdapter)

public:
    Q_INVOKABLE void started();
    Q_INVOKABLE void stopped();
    Q_INVOKABLE void onCommand(int cmdID, int appID);
    Q_INVOKABLE void onLanguageChange(int language);

    Q_INVOKABLE void replyIsReady(int handle, bool available);
    Q_INVOKABLE void replyAddCommand(int handle);
    Q_INVOKABLE void replyDeleteCommand(int handle);
    Q_INVOKABLE void replyPerformInteraction(int handle,
        const QVariant& choiceID = QVariant());
    Q_INVOKABLE void replyChangeRegistration(int handle);
    Q_INVOKABLE void replyGetSupportedLanguages(int handle, const QList<int>& Blanguages);
    Q_INVOKABLE void replyGetLanguage(int handle, int language);
    Q_INVOKABLE void replyGetCapabilities(int handle,
        const QVariant& vrCapabilities = QVariant());
};

#endif // VR_H
