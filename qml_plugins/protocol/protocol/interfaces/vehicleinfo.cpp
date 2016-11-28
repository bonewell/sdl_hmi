#include "vehicleinfo.h"

void VehicleInfoAdapter::IsReady(const Message &message)
{
    invoke("IsReady", message).run();
}

void VehicleInfoAdapter::GetVehicleType(const Message &message)
{
    invoke("GetVehicleType", message).run();
}

void VehicleInfoAdapter::ReadDID(int ecuName, const QList<int> &didLocation,
    int appID, const Message &message)
{
    invoke("ReadDID", message).in(ecuName).in(didLocation).in(appID).run();
}

void VehicleInfoAdapter::GetDTCs(int ecuName, const Optional<int> &dtcMask,
    int appID, const Message &message)
{
    invoke("GetDTCs", message).in(ecuName).in(dtcMask).in(appID).run();
}

void VehicleInfoAdapter::DiagnosticMessage(int targetID, int messageLength,
    const QList<int> &messageData, int appID, const Message &message)
{
    invoke("DiagnosticMessage", message).in(targetID).in(messageLength)
            .in(messageData).in(appID).run();
}

void VehicleInfoAdapter::GetGpsData(int appID, const Message &message)
{
    invoke("GetGpsData", message).in(appID).run();
}

void VehicleInfoAdapter::GetSpeed(int appID, const Message &message)
{
    invoke("GetSpeed", message).in(appID).run();
}

void VehicleInfoAdapter::GetRpm(int appID, const Message &message)
{
    invoke("GetRpm", message).in(appID).run();
}

void VehicleInfoAdapter::GetFuelLevel(int appID, const Message &message)
{
    invoke("GetFuelLevel", message).in(appID).run();
}

void VehicleInfoAdapter::GetFuelLevelState(int appID, const Message &message)
{
    invoke("GetFuelLevelState", message).in(appID).run();
}

void VehicleInfoAdapter::GetInstantFuelConsumption(int appID, const Message &message)
{
    invoke("GetInstantFuelConsumption", message).in(appID).run();
}

void VehicleInfoAdapter::GetExternalTemperature(int appID, const Message &message)
{
    invoke("GetExternalTemperature", message).in(appID).run();
}

void VehicleInfoAdapter::GetVin(int appID, const Message &message)
{
    invoke("GetVin", message).in(appID).run();
}

void VehicleInfoAdapter::GetPrndl(int appID, const Message &message)
{
    invoke("GetPrndl", message).in(appID).run();
}

void VehicleInfoAdapter::GetTirePressure(int appID, const Message &message)
{
    invoke("GetTirePressure", message).in(appID).run();
}

void VehicleInfoAdapter::GetOdometer(int appID, const Message &message)
{
    invoke("GetOdometer", message).in(appID).run();
}

void VehicleInfoAdapter::GetBeltStatus(int appID, const Message &message)
{
    invoke("GetBeltStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetBodyInformation(int appID, const Message &message)
{
    invoke("GetBodyInformation", message).in(appID).run();
}

void VehicleInfoAdapter::GetDeviceStatus(int appID, const Message &message)
{
    invoke("GetDeviceStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetDriverBraking(int appID, const Message &message)
{
    invoke("GetDriverBraking", message).in(appID).run();
}

void VehicleInfoAdapter::GetWiperStatus(int appID, const Message &message)
{
    invoke("GetWiperStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetHeadLampStatus(int appID, const Message &message)
{
    invoke("GetHeadLampStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetEngineTorque(int appID, const Message &message)
{
    invoke("GetEngineTorque", message).in(appID).run();
}

void VehicleInfoAdapter::GetAccPedalPosition(int appID, const Message &message)
{
    invoke("GetAccPedalPosition", message).in(appID).run();
}

void VehicleInfoAdapter::GetSteeringWheelAngle(int appID, const Message &message)
{
    invoke("GetSteeringWheelAngle", message).in(appID).run();
}

void VehicleInfoAdapter::GetECallInfo(int appID, const Message &message)
{
    invoke("GetECallInfo", message).in(appID).run();
}

void VehicleInfoAdapter::GetAirbagStatus(int appID, const Message &message)
{
    invoke("GetAirbagStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetEmergencyEvent(int appID, const Message &message)
{
    invoke("GetEmergencyEvent", message).in(appID).run();
}

void VehicleInfoAdapter::GetClusterModeStatus(int appID, const Message &message)
{
    invoke("GetClusterModeStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetMyKey(int appID, const Message &message)
{
    invoke("GetMyKey", message).in(appID).run();
}

void VehicleInfoAdapter::SubscribeGps(const Message &message)
{
    invoke("SubscribeGp", message).run();
}

void VehicleInfoAdapter::SubscribeSpeed(const Message &message)
{
    invoke("SubscribeSpeed", message).run();
}

void VehicleInfoAdapter::SubscribeRpm(const Message &message)
{
    invoke("SubscribeRpm", message).run();
}

void VehicleInfoAdapter::SubscribeFuelLevel(const Message &message)
{
    invoke("SubscribeFuelLevel", message).run();
}

void VehicleInfoAdapter::SubscribeFuelLevel_State(const Message &message)
{
    invoke("SubscribeFuelLevel_State", message).run();
}

void VehicleInfoAdapter::SubscribeInstantFuelConsumption(const Message &message)
{
    invoke("SubscribeInstantFuelConsumption", message).run();
}

void VehicleInfoAdapter::SubscribeExternalTemperature(const Message &message)
{
    invoke("SubscribeExternalTemperature", message).run();
}

void VehicleInfoAdapter::SubscribeVin(const Message &message)
{
    invoke("SubscribeVin", message).run();
}

void VehicleInfoAdapter::SubscribePrndl(const Message &message)
{
    invoke("SubscribePrndl", message).run();
}

void VehicleInfoAdapter::SubscribeTirePressure(const Message &message)
{
    invoke("SubscribeTirePressure", message).run();
}

void VehicleInfoAdapter::SubscribeOdometer(const Message &message)
{
    invoke("SubscribeOdometer", message).run();
}

void VehicleInfoAdapter::SubscribeBeltStatus(const Message &message)
{
    invoke("SubscribeBeltStatus", message).run();
}

void VehicleInfoAdapter::SubscribeBodyInformation(const Message &message)
{
    invoke("SubscribeBodyInformation", message).run();
}

void VehicleInfoAdapter::SubscribeDeviceStatus(const Message &message)
{
    invoke("SubscribeDeviceStatus", message).run();
}

void VehicleInfoAdapter::SubscribeDriverBraking(const Message &message)
{
    invoke("SubscribeDriverBraking", message).run();
}

void VehicleInfoAdapter::SubscribeWiperStatus(const Message &message)
{
    invoke("SubscribeWiperStatus", message).run();
}

void VehicleInfoAdapter::SubscribeHeadLampStatus(const Message &message)
{
    invoke("SubscribeHeadLampStatus", message).run();
}

void VehicleInfoAdapter::SubscribeEngineTorque(const Message &message)
{
    invoke("SubscribeEngineTorque", message).run();
}

void VehicleInfoAdapter::SubscribeAccPedalPosition(const Message &message)
{
    invoke("SubscribeAccPedalPosition", message).run();
}

void VehicleInfoAdapter::SubscribeSteeringWheelAngle(const Message &message)
{
    invoke("SubscribeSteeringWheelAngle", message).run();
}

void VehicleInfoAdapter::SubscribeECallInfo(const Message &message)
{
    invoke("SubscribeECallInfo", message).run();
}

void VehicleInfoAdapter::SubscribeAirbagStatus(const Message &message)
{
    invoke("SubscribeAirbagStatus", message).run();
}

void VehicleInfoAdapter::SubscribeEmergencyEvent(const Message &message)
{
    invoke("SubscribeEmergencyEvent", message).run();
}

void VehicleInfoAdapter::SubscribeClusterModeStatus(const Message &message)
{
    invoke("SubscribeClusterModeStatus", message).run();
}

void VehicleInfoAdapter::SubscribeMyKey(const Message &message)
{
    invoke("SubscribeMyKey", message).run();
}

void VehicleInfoAdapter::UnsubscribeGps(const Message &message)
{
    invoke("UnsubscribeGps", message).run();
}

void VehicleInfoAdapter::UnsubscribeSpeed(const Message &message)
{
    invoke("UnsubscribeSpeed", message).run();
}

void VehicleInfoAdapter::UnsubscribeRpm(const Message &message)
{
    invoke("UnsubscribeRpm", message).run();
}

void VehicleInfoAdapter::UnsubscribeFuelLevel(const Message &message)
{
    invoke("UnsubscribeFuelLevel", message).run();
}

void VehicleInfoAdapter::UnsubscribeFuelLevel_State(const Message &message)
{
    invoke("UnsubscribeFuelLevel_State", message).run();
}

void VehicleInfoAdapter::UnsubscribeInstantFuelConsumption(const Message &message)
{
    invoke("UnsubscribeInstantFuelConsumption", message).run();
}

void VehicleInfoAdapter::UnsubscribeExternalTemperature(const Message &message)
{
    invoke("UnsubscribeExternalTemperature", message).run();
}

void VehicleInfoAdapter::UnsubscribeVin(const Message &message)
{
    invoke("UnsubscribeVin", message).run();
}

void VehicleInfoAdapter::UnsubscribePrndl(const Message &message)
{
    invoke("UnsubscribePrndl", message).run();
}

void VehicleInfoAdapter::UnsubscribeTirePressure(const Message &message)
{
    invoke("UnsubscribeTirePressure", message).run();
}

void VehicleInfoAdapter::UnsubscribeOdometer(const Message &message)
{
    invoke("UnsubscribeOdometer", message).run();
}

void VehicleInfoAdapter::UnsubscribeBeltStatus(const Message &message)
{
    invoke("UnsubscribeBeltStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeBodyInformation(const Message &message)
{
    invoke("UnsubscribeBodyInformation", message).run();
}

void VehicleInfoAdapter::UnsubscribeDeviceStatus(const Message &message)
{
    invoke("UnsubscribeDeviceStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeDriverBraking(const Message &message)
{
    invoke("UnsubscribeDriverBraking", message).run();
}

void VehicleInfoAdapter::UnsubscribeWiperStatus(const Message &message)
{
    invoke("UnsubscribeWiperStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeHeadLampStatus(const Message &message)
{
    invoke("UnsubscribeHeadLampStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeEngineTorque(const Message &message)
{
    invoke("UnsubscribeEngineTorque", message).run();
}

void VehicleInfoAdapter::UnsubscribeAccPedalPosition(const Message &message)
{
    invoke("UnsubscribeAccPedalPosition", message).run();
}

void VehicleInfoAdapter::UnsubscribeSteeringWheelAngle(const Message &message)
{
    invoke("UnsubscribeSteeringWheelAngle", message).run();
}

void VehicleInfoAdapter::UnsubscribeECallInfo(const Message &message)
{
    invoke("UnsubscribeECallInfo", message).run();
}

void VehicleInfoAdapter::UnsubscribeAirbagStatus(const Message &message)
{
    invoke("UnsubscribeAirbagStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeEmergencyEvent(const Message &message)
{
    invoke("UnsubscribeEmergencyEvent", message).run();
}

void VehicleInfoAdapter::UnsubscribeClusterModeStatus(const Message &message)
{
    invoke("UnsubscribeClusterModeStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeMyKey(const Message &message)
{
    invoke("UnsubscribeMyKey", message).run();
}

void VehicleInfo::replyIsReady(const QVariantMap &handle, bool available)
{
    adapter->reply(handle).out(available).send();
}

void VehicleInfo::replyGetVehicleType(const QVariantMap &handle,
    const QVariantMap &vehicleType)
{
    adapter->reply(handle).out(single<VehicleType>(vehicleType)).send();
}

void VehicleInfo::replyReadDID(const QVariantMap &handle, const QVariantList &didResult)
{
    adapter->reply(handle).out(multiple<DIDResult>(didResult)).send();
}

void VehicleInfo::replyGetDTCs(const QVariantMap &handle, int ecuHeader, const QVariant &dtc)
{
    adapter->reply(handle).out(ecuHeader).out<Optional<QStringList> >(dtc).send();
}

void VehicleInfo::replyDiagnosticMessage(const QVariantMap &handle,
    const QList<int> &messageDataResult)
{
    adapter->reply(handle).out(messageDataResult).send();
}

void VehicleInfo::replyGetGpsData(const QVariantMap &handle, const QVariantMap &gps)
{
    adapter->reply(handle).out(single<GPSData>(gps)).send();
}

void VehicleInfo::replyGetSpeed(const QVariantMap &handle, double speed)
{
    adapter->reply(handle).out(speed).send();
}

void VehicleInfo::replyGetRpm(const QVariantMap &handle, int rpm)
{
    adapter->reply(handle).out(rpm).send();
}

void VehicleInfo::replyGetFuelLevel(const QVariantMap &handle, double fuelLevel)
{
    adapter->reply(handle).out(fuelLevel).send();
}

void VehicleInfo::replyGetFuelLevelState(const QVariantMap &handle, int fuelLevel_State)
{
    adapter->reply(handle).out(fuelLevel_State).send();
}

void VehicleInfo::replyGetInstantFuelConsumption(const QVariantMap &handle,
    double instantFuelConsumption)
{
    adapter->reply(handle).out(instantFuelConsumption).send();
}

void VehicleInfo::replyGetExternalTemperature(const QVariantMap &handle,
    double externalTemperature)
{
    adapter->reply(handle).out(externalTemperature).send();
}

void VehicleInfo::replyGetVin(const QVariantMap &handle, const QString &vin)
{
    adapter->reply(handle).out(vin).send();
}

void VehicleInfo::replyGetPrndl(const QVariantMap &handle, int prndl)
{
    adapter->reply(handle).out(prndl).send();
}

void VehicleInfo::replyGetTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    adapter->reply(handle).out(single<TireStatus>(tirePressure)).send();
}

void VehicleInfo::replyGetOdometer(const QVariantMap &handle, int odometer)
{
    adapter->reply(handle).out(odometer).send();
}

void VehicleInfo::replyGetBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    adapter->reply(handle).out(single<BeltStatus>(beltStatus)).send();
}

void VehicleInfo::replyGetBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    adapter->reply(handle).out(single<BodyInformation>(bodyInformation)).send();
}

void VehicleInfo::replyGetDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    adapter->reply(handle).out(single<DeviceStatus>(deviceStatus)).send();
}

void VehicleInfo::replyGetDriverBraking(const QVariantMap &handle, int driverBraking)
{
    adapter->reply(handle).out(driverBraking).send();
}

void VehicleInfo::replyGetWiperStatus(const QVariantMap &handle, int wiperStatus)
{
    adapter->reply(handle).out(wiperStatus).send();
}

void VehicleInfo::replyGetHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    adapter->reply(handle).out(single<HeadLampStatus>(headLampStatus)).send();
}

void VehicleInfo::replyGetEngineTorque(const QVariantMap &handle, double engineTorque)
{
    adapter->reply(handle).out(engineTorque).send();
}

void VehicleInfo::replyGetAccPedalPosition(const QVariantMap &handle,
    double accPedalPosition)
{
    adapter->reply(handle).out(accPedalPosition).send();
}

void VehicleInfo::replyGetSteeringWheelAngle(const QVariantMap &handle,
    double steeringWheelAngle)
{
    adapter->reply(handle).out(steeringWheelAngle).send();
}

void VehicleInfo::replyGetECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    adapter->reply(handle).out(single<ECallInfo>(eCallInfo)).send();
}

void VehicleInfo::replyGetAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    adapter->reply(handle).out(single<AirbagStatus>(airbagStatus)).send();
}

void VehicleInfo::replyGetEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    adapter->reply(handle).out(single<EmergencyEvent>(emergencyEvent)).send();
}

void VehicleInfo::replyGetClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    adapter->reply(handle).out(single<ClusterModeStatus>(clusterModeStatus)).send();
}

void VehicleInfo::replyGetMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    adapter->reply(handle).out(single<MyKey>(myKey)).send();
}

void VehicleInfo::replySubscribeGps(const QVariantMap &handle, const QVariantMap &gps)
{
    adapter->reply(handle).out(single<VehicleDataResult>(gps)).send();
}

void VehicleInfo::replySubscribeSpeed(const QVariantMap &handle, const QVariantMap &speed)
{
    adapter->reply(handle).out(single<VehicleDataResult>(speed)).send();
}

void VehicleInfo::replySubscribeRpm(const QVariantMap &handle, const QVariantMap &rpm)
{
    adapter->reply(handle).out(single<VehicleDataResult>(rpm)).send();
}

void VehicleInfo::replySubscribeFuelLevel(const QVariantMap &handle,
    const QVariantMap &fuelLevel)
{
    adapter->reply(handle).out(single<VehicleDataResult>(fuelLevel)).send();
}

void VehicleInfo::replySubscribeFuelLevel_State(const QVariantMap &handle,
    const QVariantMap &fuelLevel_State)
{
    adapter->reply(handle).out(single<VehicleDataResult>(fuelLevel_State)).send();
}

void VehicleInfo::replySubscribeInstantFuelConsumption(const QVariantMap &handle,
    const QVariantMap &instantFuelConsumption)
{
    adapter->reply(handle).out(single<VehicleDataResult>(instantFuelConsumption)).send();
}

void VehicleInfo::replySubscribeExternalTemperature(const QVariantMap &handle,
    const QVariantMap &externalTemperature)
{
    adapter->reply(handle).out(single<VehicleDataResult>(externalTemperature)).send();
}

void VehicleInfo::replySubscribeVin(const QVariantMap &handle, const QString &vin)
{
    adapter->reply(handle).out(vin).send();
}

void VehicleInfo::replySubscribePrndl(const QVariantMap &handle, const QVariantMap &prndl)
{
    adapter->reply(handle).out(single<VehicleDataResult>(prndl)).send();
}

void VehicleInfo::replySubscribeTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    adapter->reply(handle).out(single<VehicleDataResult>(tirePressure)).send();
}

void VehicleInfo::replySubscribeOdometer(const QVariantMap &handle,
    const QVariantMap &odometer)
{
    adapter->reply(handle).out(single<VehicleDataResult>(odometer)).send();
}

void VehicleInfo::replySubscribeBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(beltStatus)).send();
}

void VehicleInfo::replySubscribeBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    adapter->reply(handle).out(single<VehicleDataResult>(bodyInformation)).send();
}

void VehicleInfo::replySubscribeDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(deviceStatus)).send();
}

void VehicleInfo::replySubscribeDriverBraking(const QVariantMap &handle,
    const QVariantMap &driverBraking)
{
    adapter->reply(handle).out(single<VehicleDataResult>(driverBraking)).send();
}

void VehicleInfo::replySubscribeWiperStatus(const QVariantMap &handle,
    const QVariantMap &wiperStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(wiperStatus)).send();
}

void VehicleInfo::replySubscribeHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(headLampStatus)).send();
}

void VehicleInfo::replySubscribeEngineTorque(const QVariantMap &handle,
    const QVariantMap &engineTorque)
{
    adapter->reply(handle).out(single<VehicleDataResult>(engineTorque)).send();
}

void VehicleInfo::replySubscribeAccPedalPosition(const QVariantMap &handle,
    const QVariantMap &accPedalPosition)
{
    adapter->reply(handle).out(single<VehicleDataResult>(accPedalPosition)).send();
}

void VehicleInfo::replySubscribeSteeringWheelAngle(const QVariantMap &handle,
    const QVariantMap &steeringWheelAngle)
{
    adapter->reply(handle).out(single<VehicleDataResult>(steeringWheelAngle)).send();
}

void VehicleInfo::replySubscribeECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    adapter->reply(handle).out(single<VehicleDataResult>(eCallInfo)).send();
}

void VehicleInfo::replySubscribeAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(airbagStatus)).send();
}

void VehicleInfo::replySubscribeEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    adapter->reply(handle).out(single<VehicleDataResult>(emergencyEvent)).send();
}

void VehicleInfo::replySubscribeClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(clusterModeStatus)).send();
}

void VehicleInfo::replySubscribeMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    adapter->reply(handle).out(single<VehicleDataResult>(myKey)).send();
}

void VehicleInfo::replyUnsubscribeGps(const QVariantMap &handle, const QVariantMap &gps)
{
    adapter->reply(handle).out(single<VehicleDataResult>(gps)).send();
}

void VehicleInfo::replyUnsubscribeSpeed(const QVariantMap &handle, const QVariantMap &speed)
{
    adapter->reply(handle).out(single<VehicleDataResult>(speed)).send();
}

void VehicleInfo::replyUnsubscribeRpm(const QVariantMap &handle, const QVariantMap &rpm)
{
    adapter->reply(handle).out(single<VehicleDataResult>(rpm)).send();
}

void VehicleInfo::replyUnsubscribeFuelLevel(const QVariantMap &handle,
    const QVariantMap &fuelLevel)
{
    adapter->reply(handle).out(single<VehicleDataResult>(fuelLevel)).send();
}

void VehicleInfo::replyUnsubscribeFuelLevel_State(const QVariantMap &handle,
    const QVariantMap &fuelLevel_State)
{
    adapter->reply(handle).out(single<VehicleDataResult>(fuelLevel_State)).send();
}

void VehicleInfo::replyUnsubscribeInstantFuelConsumption(const QVariantMap &handle,
    const QVariantMap &instantFuelConsumption)
{
    adapter->reply(handle).out(single<VehicleDataResult>(instantFuelConsumption)).send();
}

void VehicleInfo::replyUnsubscribeExternalTemperature(const QVariantMap &handle,
    const QVariantMap &externalTemperature)
{
    adapter->reply(handle).out(single<VehicleDataResult>(externalTemperature)).send();
}

void VehicleInfo::replyUnsubscribeVin(const QVariantMap &handle, const QString &vin)
{
    adapter->reply(handle).out(vin).send();
}

void VehicleInfo::replyUnsubscribePrndl(const QVariantMap &handle, const QVariantMap &prndl)
{
    adapter->reply(handle).out(single<VehicleDataResult>(prndl)).send();
}

void VehicleInfo::replyUnsubscribeTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    adapter->reply(handle).out(single<VehicleDataResult>(tirePressure)).send();
}

void VehicleInfo::replyUnsubscribeOdometer(const QVariantMap &handle,
    const QVariantMap &odometer)
{
    adapter->reply(handle).out(single<VehicleDataResult>(odometer)).send();
}

void VehicleInfo::replyUnsubscribeBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(beltStatus)).send();
}

void VehicleInfo::replyUnsubscribeBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    adapter->reply(handle).out(single<VehicleDataResult>(bodyInformation)).send();
}

void VehicleInfo::replyUnsubscribeDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(deviceStatus)).send();
}

void VehicleInfo::replyUnsubscribeDriverBraking(const QVariantMap &handle,
    const QVariantMap &driverBraking)
{
    adapter->reply(handle).out(single<VehicleDataResult>(driverBraking)).send();
}

void VehicleInfo::replyUnsubscribeWiperStatus(const QVariantMap &handle,
    const QVariantMap &wiperStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(wiperStatus)).send();
}

void VehicleInfo::replyUnsubscribeHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(headLampStatus)).send();
}

void VehicleInfo::replyUnsubscribeEngineTorque(const QVariantMap &handle,
    const QVariantMap &engineTorque)
{
    adapter->reply(handle).out(single<VehicleDataResult>(engineTorque)).send();
}

void VehicleInfo::replyUnsubscribeAccPedalPosition(const QVariantMap &handle,
    const QVariantMap &accPedalPosition)
{
    adapter->reply(handle).out(single<VehicleDataResult>(accPedalPosition)).send();
}

void VehicleInfo::replyUnsubscribeSteeringWheelAngle(const QVariantMap &handle,
    const QVariantMap &steeringWheelAngle)
{
    adapter->reply(handle).out(single<VehicleDataResult>(steeringWheelAngle)).send();
}

void VehicleInfo::replyUnsubscribeECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    adapter->reply(handle).out(single<VehicleDataResult>(eCallInfo)).send();
}

void VehicleInfo::replyUnsubscribeAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(airbagStatus)).send();
}

void VehicleInfo::replyUnsubscribeEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    adapter->reply(handle).out(single<VehicleDataResult>(emergencyEvent)).send();
}

void VehicleInfo::replyUnsubscribeClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    adapter->reply(handle).out(single<VehicleDataResult>(clusterModeStatus)).send();
}

void VehicleInfo::replyUnsubscribeMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    adapter->reply(handle).out(single<VehicleDataResult>(myKey)).send();
}

void VehicleInfo::onGpsData(const QVariantMap &gps)
{
    adapter->signal("OnGpsData").arg(single<GPSData>(gps)).send();
}

void VehicleInfo::onSpeed(double speed)
{
    adapter->signal("OnSpeed").arg(speed).send();
}

void VehicleInfo::onRpm(int rpm)
{
    adapter->signal("OnRpm").arg(rpm).send();
}

void VehicleInfo::onFuelLevel(double fuelLevel)
{
    adapter->signal("OnFuelLevel").arg(fuelLevel).send();
}

void VehicleInfo::onFuelLevelState(int fuelLevel_State)
{
    adapter->signal("OnFuelLevelState").arg(fuelLevel_State).send();
}

void VehicleInfo::onInstantFuelConsumption(double instantFuelConsumption)
{
    adapter->signal("OnInstantFuelConsumption").arg(instantFuelConsumption).send();
}

void VehicleInfo::onExternalTemperature(double externalTemperature)
{
    adapter->signal("OnExternalTemperature").arg(externalTemperature).send();
}

void VehicleInfo::onVin(const QString &vin)
{
    adapter->signal("OnVin").arg(vin).send();
}

void VehicleInfo::onPrndl(int prndl)
{
    adapter->signal("OnPrndl").arg(prndl).send();
}

void VehicleInfo::onTirePressure(const QVariantMap &tirePressure)
{
    adapter->signal("OnTirePressure").arg(single<TireStatus>(tirePressure)).send();
}

void VehicleInfo::onOdometer(int odometer)
{
    adapter->signal("OnOdometer").arg(odometer).send();
}

void VehicleInfo::onBeltStatus(const QVariantMap &beltStatus)
{
    adapter->signal("OnBeltStatus").arg(single<BeltStatus>(beltStatus)).send();
}

void VehicleInfo::onBodyInformation(const QVariantMap &bodyInformation)
{
    adapter->signal("OnBodyInformation").arg(single<BodyInformation>(bodyInformation)).send();
}

void VehicleInfo::onDeviceStatus(const QVariantMap &deviceStatus)
{
    adapter->signal("OnDeviceStatus").arg(single<DeviceStatus>(deviceStatus)).send();
}

void VehicleInfo::onDriverBraking(int driverBraking)
{
    adapter->signal("OnDriverBraking").arg(driverBraking).send();
}

void VehicleInfo::onWiperStatus(int wiperStatus)
{
    adapter->signal("OnWiperStatus").arg(wiperStatus).send();
}

void VehicleInfo::onHeadLampStatus(const QVariantMap &headLampStatus)
{
    adapter->signal("OnHeadLampStatus").arg(single<HeadLampStatus>(headLampStatus)).send();
}

void VehicleInfo::onEngineTorque(double engineTorque)
{
    adapter->signal("OnEngineTorque").arg(engineTorque).send();
}

void VehicleInfo::onAccPedalPosition(double accPedalPosition)
{
    adapter->signal("OnAccPedalPosition").arg(accPedalPosition).send();
}

void VehicleInfo::onSteeringWheelAngle(double steeringWheelAngle)
{
    adapter->signal("OnSteeringWheelAngle").arg(steeringWheelAngle).send();
}

void VehicleInfo::onECallInfo(const QVariantMap &eCallInfo)
{
    adapter->signal("OnECallInfo").arg(single<ECallInfo>(eCallInfo)).send();
}

void VehicleInfo::onAirbagStatus(const QVariantMap &airbagStatus)
{
    adapter->signal("OnAirbagStatus").arg(single<AirbagStatus>(airbagStatus)).send();
}

void VehicleInfo::onEmergencyEvent(const QVariantMap &emergencyEvent)
{
    adapter->signal("OnEmergencyEvent").arg(single<EmergencyEvent>(emergencyEvent)).send();
}

void VehicleInfo::onClusterModeStatus(const QVariantMap &clusterModeStatus)
{
    adapter->signal("OnClusterModeStatus").arg(single<ClusterModeStatus>(clusterModeStatus)).send();
}

void VehicleInfo::onMyKey(const QVariantMap &myKey)
{
    adapter->signal("OnMyKey").arg(single<MyKey>(myKey)).send();
}
