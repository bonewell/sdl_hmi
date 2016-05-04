/*
 * \file dbus_plugin.cpp
 * \brief DbusPlugin class source file.
 * Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "dbus_plugin.h"

#ifdef ENABLE_LOG
#  include <log4cxx/logger.h>
#  include <log4cxx/propertyconfigurator.h>
#endif  // ENABLE_LOG

#include <QtCore/QString>
#include <QtDBus/QDBusConnection>
#if QT_4
#  include <QtDeclarative/QDeclarativeContext>
#  include <QtDeclarative/QDeclarativeListReference>
#  include <QtDeclarative/QDeclarativeEngine>
#  include "qml_dbus.h"
#  include "dbus_controller.h"
#  include "request_to_sdl.h"
#  include "hmi_proxy.h"
#  include "sdl_proxy.h"
#  include "optional_argument.h"
#elif QT_5
#  include <QtQml/qqml.h>
#  include <QtQml/QQmlContext>
#  include <QtQml/QQmlListReference>
#  include <QtQml/QQmlEngine>
#  include "protocol/interfaces/buttons.h"
#  include "protocol/interfaces/tts.h"
#  include "protocol/interfaces/vr.h"
#  include "protocol/interfaces/navigation.h"
#  include "protocol/interfaces/basiccommunication.h"
#  include "protocol/interfaces/ui.h"
#  include "protocol/interfaces/vehicleinfo.h"
#  include "protocol/interfaces/sdl.h"
#endif  // QT_VERSION

#ifdef ENABLE_LOG
log4cxx::LoggerPtr logger_ = log4cxx::LoggerPtr(
                              log4cxx::Logger::getLogger("DBusPlugin"));
#endif  // ENABLE_LOG

void DbusPlugin::registerTypes(const char *uri) {
#ifdef ENABLE_LOG
  log4cxx::PropertyConfigurator::configure("log4cxx.properties");
#endif  // ENABLE_LOG

#if QT_4
  // @uri sdl.core.api
  qmlRegisterType<HmiProxy>(uri, 1, 0, "HMIAdapter");
  qmlRegisterType<SdlProxy>(uri, 1, 0, "SDLAdapter");
  RegisterDbusMetatypes();
  qDBusRegisterMetaType<OptionalArgument<int> >();
  qDBusRegisterMetaType<OptionalArgument<QList<int> > >();
  qDBusRegisterMetaType<OptionalArgument<QString> >();
  qDBusRegisterMetaType<OptionalArgument<QStringList> >();
  qDBusRegisterMetaType<OptionalArgument<bool> >();
  qDBusRegisterMetaType<OptionalArgument<QList<bool> > >();
  qDBusRegisterMetaType<OptionalArgument<double> >();
  qDBusRegisterMetaType<OptionalArgument<QList<double> > >();

  HmiProxy::api_adaptors_.Init(this);

  QDBusConnection::sessionBus().registerObject("/", this);

  dbusController_ = new DBusController();
  requestToSDL_ = new RequestToSDL();

  HmiProxy::api_adaptors_.SetDBusController(dbusController_);

#elif QT_5
  register_optional();

  register_struct<ButtonCapabilities>();
  register_struct<PresetBankCapabilities>();
  register_struct<TTSChunk>();
  register_struct<Image>();
  register_struct<TextFieldStruct>();
  register_struct<SoftButton>();
  register_struct<Turn>();
  register_struct<MenuParams>();
  register_struct<Choice>();
  register_struct<VrHelpItem>();
  register_struct<TimeFormat>();
  register_struct<KeyboardProperties>();
  register_struct<TextField>();
  register_struct<ImageResolution>();
  register_struct<ImageField>();
  register_struct<TouchEventCapabilities>();
  register_struct<ScreenParams>();
  register_struct<DisplayCapabilities>();
  register_struct<AudioPassThruCapabilities>();
  register_struct<SoftButtonCapabilities>();
  register_struct<HMICapabilities>();
  register_struct<TouchCoord>();
  register_struct<TouchEvent>();
  register_struct<VehicleType>();
  register_struct<DIDResult>();
  register_struct<GPSData>();
  register_struct<SingleTireStatus>();
  register_struct<TireStatus>();
  register_struct<BeltStatus>();
  register_struct<BodyInformation>();
  register_struct<HMIApplication>();
  register_struct<DeviceInfo>();
  register_struct<DeviceStatus>();
  register_struct<HeadLampStatus>();
  register_struct<ECallInfo>();
  register_struct<AirbagStatus>();
  register_struct<EmergencyEvent>();
  register_struct<ClusterModeStatus>();
  register_struct<MyKey>();
  register_struct<VehicleDataResult>();
  register_struct<PermissionItem>();
  register_struct<UserFriendlyMessage>();
  register_struct<ServiceInfo>();
  register_struct<DateTime>();
  register_struct<OASISAddress>();
  register_struct<Coordinate>();
  register_struct<LocationDetails>();

  // @uri sdl.core.api
  qmlRegisterType<Buttons>(uri, 1, 0, "Buttons");
  qmlRegisterType<TTS>(uri, 1, 0, "TTS");
  qmlRegisterType<VR>(uri, 1, 0, "VR");
  qmlRegisterType<Navigation>(uri, 1, 0, "Navigation");
  qmlRegisterType<BasicCommunication>(uri, 1, 0, "BasicCommunication");
  qmlRegisterType<UI>(uri, 1, 0, "UI");
  qmlRegisterType<VehicleInfo>(uri, 1, 0, "VehicleInfo");
  qmlRegisterType<SDL>(uri, 1, 0, "SDL");
#endif  // QT_VERSION

  QDBusConnection::sessionBus().registerService("com.ford.sdl.hmi");
}

#if QT_4
void DbusPlugin::initializeEngine(QDeclarativeEngine *engine, const char *uri) {
    engine->rootContext()->setContextProperty("DBus", dbusController_);
    engine->rootContext()->setContextProperty("RequestToSDL", requestToSDL_);
}

Q_EXPORT_PLUGIN2(DbusAdapter, DbusPlugin)
#endif  // QT_4
