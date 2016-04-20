#ifndef TTS_H
#define TTS_H

#include "core/abstractadapter.h"
#include "protocol/structures.h"

#define TTS_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.TTS\">" \
    "<method name=\"GetCapabilities\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"speechCapabilities\" type=\"ai\" />" \
    "<arg direction=\"out\" name=\"prerecordedSpeechCapabilities\" type=\"ai\" />" \
    "</method>" \
    "<method name=\"IsReady\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"available\" type=\"b\" />" \
    "</method>" \
    "<method name=\"Speak\">" \
    "<arg direction=\"in\" name=\"ttsChunks\" type=\"a(si)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"speakType\" type=\"(bi)\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"StopSpeaking\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<method name=\"ChangeRegistration\">" \
    "<arg direction=\"in\" name=\"ttsName\" type=\"(ba(si))\" />" \
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
    "<method name=\"SetGlobalProperties\">" \
    "<arg direction=\"in\" name=\"helpPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"timeoutPrompt\" type=\"(ba(si))\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "</method>" \
    "<signal name=\"Started\" />" \
    "<signal name=\"Stopped\" />" \
    "<signal name=\"OnLanguageChange\">" \
    "<arg name=\"language\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnResetTimeout\">" \
    "<arg name=\"appID\" type=\"i\" />" \
    "<arg name=\"methodName\" type=\"s\" />" \
    "</signal>" \
    "</interface>"

class TTS;

class TTSAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO("com.ford.sdl.hmi.TTS", TTS_INTROSPECTION)
    REGISTER_ADAPTER(TTSAdapter, TTS)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.TTS")

signals:

public slots:

public:

private slots:
};

class TTS : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(TTS, TTSAdapter)

public:

signals:
};

#endif // TTS_H
