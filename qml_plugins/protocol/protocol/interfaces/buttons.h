#ifndef BUTTONS_H
#define BUTTONS_H

#include "core/abstractadapter.h"
#include "core/abstractitem.h"
#include "protocol/structures.h"

#define BUTTONS_INTROSPECTION \
  "<interface name=\"com.ford.sdl.hmi.Buttons\">" \
  "<method name=\"GetCapabilities\">" \
  "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
  "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
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
    ADAPTER_INFO(200, Buttons, BUTTONS_INTROSPECTION)
    REGISTER_ADAPTER(ButtonsAdapter, Buttons)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.Buttons")

// Incoming requests
public slots:
    void GetCapabilities(const Message& message);

// Incoming notifications
private slots:
    void OnButtonSubscription(int name, bool isSubscribed, int appID);
};

class Buttons : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(Buttons, ButtonsAdapter)

public:
// Outcoming notifications
    Q_INVOKABLE void onButtonEvent(int name, int mode,
                                   const QVariant& customButtonID = QVariant(),
                                   const QVariant& appID = QVariant());
    Q_INVOKABLE void onButtonPress(int name, int mode,
                                   const QVariant& customButtonID = QVariant(),
                                   const QVariant& appID = QVariant());

// Outcoming responses
    Q_INVOKABLE void replyGetCapabilities(const QVariantMap& handle,
        const QVariantList& capabilities,
        const QVariant& presetBankCapabilities = QVariant());

// Incoming notifications
signals:
    void onButtonSubscription(int name, bool isSubscribed, int appID);
};

#endif // BUTTONS_H
