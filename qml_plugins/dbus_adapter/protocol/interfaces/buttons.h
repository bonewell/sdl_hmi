#ifndef BUTTONS_H
#define BUTTONS_H

#include "core/abstractadapter.h"
#include "protocol/structures.h"

#define BUTTONS_INTROSPECTION \
  "<interface name=\"com.ford.sdl.hmi.Buttons\">" \
  "<method name=\"GetCapabilities\">" \
  "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
  "<arg direction=\"out\" name=\"capabilities\" type=\"a(ibbb)\" />" \
  "<arg direction=\"out\" name=\"presetBankCapabilities\" type=\"(b(b))\" />" \
  "</method>" \
  "<signal name=\"OnButtonEvent\">" \
  "<arg name=\"name\" type=\"i\" />" \
  "<arg name=\"mode\" type=\"i\" />" \
  "<arg name=\"customButtonID\" type=\"(bi)\" />" \
  "<arg name=\"appID\" type=\"(bi)\" />" \
  "</signal>" \
  "<signal name=\"OnButtonPress\">" \
  "<arg name=\"name\" type=\"i\" />" \
  "<arg name=\"mode\" type=\"i\" />" \
  "<arg name=\"customButtonID\" type=\"(bi)\" />" \
  "<arg name=\"appID\" type=\"(bi)\" />" \
  "</signal>" \
  "</interface>"

class Buttons;

class ButtonsAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO("com.ford.sdl.hmi.Buttons", BUTTONS_INTROSPECTION)
    REGISTER_ADAPTER(ButtonsAdapter, Buttons)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.Buttons")

signals:
    void OnButtonEvent(int name, int mode,
                       const Optional<int>& customButtonID,
                       const Optional<int>& appID);
    void OnButtonPress(int name, int mode,
                       const Optional<int>& customButtonID,
                       const Optional<int>& appID);

public slots:
    void GetCapabilities(const Message& message);

public:
    void ReplyGetCapabilities(int handle,
        const QList<ButtonCapabilities>& capabilities,
        const Optional<PresetBankCapabilities>& presetBankCapabilities);

private slots:
    void OnButtonSubscription(int name, bool isSubscribed, int appID);
};

class Buttons : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(Buttons, ButtonsAdapter)

public:
    Q_INVOKABLE void onButtonEvent(int name, int mode,
                                   const QVariant& customButtonID = QVariant(),
                                   const QVariant& appID = QVariant());
    Q_INVOKABLE void onButtonPress(int name, int mode,
                                   const QVariant& customButtonID = QVariant(),
                                   const QVariant& appID = QVariant());

    Q_INVOKABLE void replyGetCapabilities(int handle,
        const QVariantList& capabilities,
        const QVariant& presetBankCapabilities = QVariant());

signals:
    void onButtonSubscription(int name, bool isSubscribed, int appID);
};

#endif // BUTTONS_H
