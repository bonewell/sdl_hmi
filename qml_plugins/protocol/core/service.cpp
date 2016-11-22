#include "service.h"

#ifdef DBUS
#include <QtDBus/QDBusConnection>
#include "protocol/structures.h"
#endif

Service::Service(const QString &name) : name_(name)
{

}

void Service::run() {
#ifdef DBUS
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

  QDBusConnection::sessionBus().registerService(name_);
#endif
}
