#include "vehicleinfo.h"

void VehicleInfoAdapter::IsReady(const Message &message)
{
    call("isReady", message).run();
}

void VehicleInfoAdapter::GetVehicleType(const Message &message)
{
    call("getVehicleType", message).run();
}

void VehicleInfoAdapter::ReadDID(int ecuName, const QList<int> &didLocation,
    int appID, const Message &message)
{
    call("readDID", message).in(ecuName).in(didLocation).in(appID).run();
}

void VehicleInfoAdapter::GetDTCs(int ecuName, const Optional<int> &dtcMask,
    int appID, const Message &message)
{
    call("getDTCs", message).in(ecuName).in(dtcMask).in(appID).run();
}

void VehicleInfoAdapter::DiagnosticMessage(int targetID, int messageLength,
    const QList<int> &messageData, int appID, const Message &message)
{
    call("diagnosticMessage", message).in(targetID).in(messageLength)
            .in(messageData).in(appID).run();
}

void VehicleInfoAdapter::GetGpsData(int appID, const Message &message)
{
    call("getGpsData", message).in(appID).run();
}

void VehicleInfoAdapter::GetSpeed(int appID, const Message &message)
{
    call("getSpeed", message).in(appID).run();
}

void VehicleInfoAdapter::GetRpm(int appID, const Message &message)
{
    call("getRpm", message).in(appID).run();
}

void VehicleInfoAdapter::GetFuelLevel(int appID, const Message &message)
{
    call("getFuelLevel", message).in(appID).run();
}

void VehicleInfoAdapter::GetFuelLevelState(int appID, const Message &message)
{
    call("getFuelLevelState", message).in(appID).run();
}

void VehicleInfoAdapter::GetInstantFuelConsumption(int appID, const Message &message)
{
    call("getInstantFuelConsumption", message).in(appID).run();
}

void VehicleInfoAdapter::GetExternalTemperature(int appID, const Message &message)
{
    call("getExternalTemperature", message).in(appID).run();
}

void VehicleInfoAdapter::GetVin(int appID, const Message &message)
{
    call("getVin", message).in(appID).run();
}

void VehicleInfoAdapter::GetPrndl(int appID, const Message &message)
{
    call("getPrndl", message).in(appID).run();
}

void VehicleInfoAdapter::GetTirePressure(int appID, const Message &message)
{
    call("getTirePressure", message).in(appID).run();
}

void VehicleInfoAdapter::GetOdometer(int appID, const Message &message)
{
    call("getOdometer", message).in(appID).run();
}

void VehicleInfoAdapter::GetBeltStatus(int appID, const Message &message)
{
    call("getBeltStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetBodyInformation(int appID, const Message &message)
{
    call("getBodyInformation", message).in(appID).run();
}

void VehicleInfoAdapter::GetDeviceStatus(int appID, const Message &message)
{
    call("getDeviceStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetDriverBraking(int appID, const Message &message)
{
    call("getDriverBraking", message).in(appID).run();
}

void VehicleInfoAdapter::GetWiperStatus(int appID, const Message &message)
{
    call("getWiperStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetHeadLampStatus(int appID, const Message &message)
{
    call("getHeadLampStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetEngineTorque(int appID, const Message &message)
{
    call("getEngineTorque", message).in(appID).run();
}

void VehicleInfoAdapter::GetAccPedalPosition(int appID, const Message &message)
{
    call("getAccPedalPosition", message).in(appID).run();
}

void VehicleInfoAdapter::GetSteeringWheelAngle(int appID, const Message &message)
{
    call("getSteeringWheelAngle", message).in(appID).run();
}

void VehicleInfoAdapter::GetECallInfo(int appID, const Message &message)
{
    call("getECallInfo", message).in(appID).run();
}

void VehicleInfoAdapter::GetAirbagStatus(int appID, const Message &message)
{
    call("getAirbagStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetEmergencyEvent(int appID, const Message &message)
{
    call("getEmergencyEvent", message).in(appID).run();
}

void VehicleInfoAdapter::GetClusterModeStatus(int appID, const Message &message)
{
    call("getClusterModeStatus", message).in(appID).run();
}

void VehicleInfoAdapter::GetMyKey(int appID, const Message &message)
{
    call("getMyKey", message).in(appID).run();
}

void VehicleInfoAdapter::SubscribeGps(const Message &message)
{
    call("subscribeGp", message).run();
}

void VehicleInfoAdapter::SubscribeSpeed(const Message &message)
{
    call("subscribeSpeed", message).run();
}

void VehicleInfoAdapter::SubscribeRpm(const Message &message)
{
    call("subscribeRpm", message).run();
}

void VehicleInfoAdapter::SubscribeFuelLevel(const Message &message)
{
    call("subscribeFuelLevel", message).run();
}

void VehicleInfoAdapter::SubscribeFuelLevel_State(const Message &message)
{
    call("subscribeFuelLevel_State", message).run();
}

void VehicleInfoAdapter::SubscribeInstantFuelConsumption(const Message &message)
{
    call("subscribeInstantFuelConsumption", message).run();
}

void VehicleInfoAdapter::SubscribeExternalTemperature(const Message &message)
{
    call("subscribeExternalTemperature", message).run();
}

void VehicleInfoAdapter::SubscribeVin(const Message &message)
{
    call("subscribeVin", message).run();
}

void VehicleInfoAdapter::SubscribePrndl(const Message &message)
{
    call("subscribePrndl", message).run();
}

void VehicleInfoAdapter::SubscribeTirePressure(const Message &message)
{
    call("subscribeTirePressure", message).run();
}

void VehicleInfoAdapter::SubscribeOdometer(const Message &message)
{
    call("subscribeOdometer", message).run();
}

void VehicleInfoAdapter::SubscribeBeltStatus(const Message &message)
{
    call("subscribeBeltStatus", message).run();
}

void VehicleInfoAdapter::SubscribeBodyInformation(const Message &message)
{
    call("subscribeBodyInformation", message).run();
}

void VehicleInfoAdapter::SubscribeDeviceStatus(const Message &message)
{
    call("subscribeDeviceStatus", message).run();
}

void VehicleInfoAdapter::SubscribeDriverBraking(const Message &message)
{
    call("subscribeDriverBraking", message).run();
}

void VehicleInfoAdapter::SubscribeWiperStatus(const Message &message)
{
    call("subscribeWiperStatus", message).run();
}

void VehicleInfoAdapter::SubscribeHeadLampStatus(const Message &message)
{
    call("subscribeHeadLampStatus", message).run();
}

void VehicleInfoAdapter::SubscribeEngineTorque(const Message &message)
{
    call("subscribeEngineTorque", message).run();
}

void VehicleInfoAdapter::SubscribeAccPedalPosition(const Message &message)
{
    call("subscribeAccPedalPosition", message).run();
}

void VehicleInfoAdapter::SubscribeSteeringWheelAngle(const Message &message)
{
    call("subscribeSteeringWheelAngle", message).run();
}

void VehicleInfoAdapter::SubscribeECallInfo(const Message &message)
{
    call("subscribeECallInfo", message).run();
}

void VehicleInfoAdapter::SubscribeAirbagStatus(const Message &message)
{
    call("subscribeAirbagStatus", message).run();
}

void VehicleInfoAdapter::SubscribeEmergencyEvent(const Message &message)
{
    call("subscribeEmergencyEvent", message).run();
}

void VehicleInfoAdapter::SubscribeClusterModeStatus(const Message &message)
{
    call("subscribeClusterModeStatus", message).run();
}

void VehicleInfoAdapter::SubscribeMyKey(const Message &message)
{
    call("subscribeMyKey", message).run();
}

void VehicleInfoAdapter::UnsubscribeGps(const Message &message)
{
    call("unsubscribeGps", message).run();
}

void VehicleInfoAdapter::UnsubscribeSpeed(const Message &message)
{
    call("unsubscribeSpeed", message).run();
}

void VehicleInfoAdapter::UnsubscribeRpm(const Message &message)
{
    call("unsubscribeRpm", message).run();
}

void VehicleInfoAdapter::UnsubscribeFuelLevel(const Message &message)
{
    call("unsubscribeFuelLevel", message).run();
}

void VehicleInfoAdapter::UnsubscribeFuelLevel_State(const Message &message)
{
    call("unsubscribeFuelLevel_State", message).run();
}

void VehicleInfoAdapter::UnsubscribeInstantFuelConsumption(const Message &message)
{
    call("unsubscribeInstantFuelConsumption", message).run();
}

void VehicleInfoAdapter::UnsubscribeExternalTemperature(const Message &message)
{
    call("unsubscribeExternalTemperature", message).run();
}

void VehicleInfoAdapter::UnsubscribeVin(const Message &message)
{
    call("unsubscribeVin", message).run();
}

void VehicleInfoAdapter::UnsubscribePrndl(const Message &message)
{
    call("unsubscribePrndl", message).run();
}

void VehicleInfoAdapter::UnsubscribeTirePressure(const Message &message)
{
    call("unsubscribeTirePressure", message).run();
}

void VehicleInfoAdapter::UnsubscribeOdometer(const Message &message)
{
    call("unsubscribeOdometer", message).run();
}

void VehicleInfoAdapter::UnsubscribeBeltStatus(const Message &message)
{
    call("unsubscribeBeltStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeBodyInformation(const Message &message)
{
    call("unsubscribeBodyInformation", message).run();
}

void VehicleInfoAdapter::UnsubscribeDeviceStatus(const Message &message)
{
    call("unsubscribeDeviceStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeDriverBraking(const Message &message)
{
    call("unsubscribeDriverBraking", message).run();
}

void VehicleInfoAdapter::UnsubscribeWiperStatus(const Message &message)
{
    call("unsubscribeWiperStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeHeadLampStatus(const Message &message)
{
    call("unsubscribeHeadLampStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeEngineTorque(const Message &message)
{
    call("unsubscribeEngineTorque", message).run();
}

void VehicleInfoAdapter::UnsubscribeAccPedalPosition(const Message &message)
{
    call("unsubscribeAccPedalPosition", message).run();
}

void VehicleInfoAdapter::UnsubscribeSteeringWheelAngle(const Message &message)
{
    call("unsubscribeSteeringWheelAngle", message).run();
}

void VehicleInfoAdapter::UnsubscribeECallInfo(const Message &message)
{
    call("unsubscribeECallInfo", message).run();
}

void VehicleInfoAdapter::UnsubscribeAirbagStatus(const Message &message)
{
    call("unsubscribeAirbagStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeEmergencyEvent(const Message &message)
{
    call("unsubscribeEmergencyEvent", message).run();
}

void VehicleInfoAdapter::UnsubscribeClusterModeStatus(const Message &message)
{
    call("unsubscribeClusterModeStatus", message).run();
}

void VehicleInfoAdapter::UnsubscribeMyKey(const Message &message)
{
    call("unsubscribeMyKey", message).run();
}

void VehicleInfo::replyIsReady(const QVariantMap &handle, bool available)
{
    response(handle).out(available).send();
}

void VehicleInfo::replyGetVehicleType(const QVariantMap &handle,
    const QVariantMap &vehicleType)
{
    response(handle).out<VehicleType>(vehicleType).send();
}

void VehicleInfo::replyReadDID(const QVariantMap &handle, const QVariantList &didResult)
{
    response(handle).out<QList<DIDResult> >(didResult).send();
}

void VehicleInfo::replyGetDTCs(const QVariantMap &handle, int ecuHeader, const QVariant &dtc)
{
    response(handle).out(ecuHeader).out<Optional<QStringList> >(dtc).send();
}

void VehicleInfo::replyDiagnosticMessage(const QVariantMap &handle,
    const QList<int> &messageDataResult)
{
    response(handle).out(messageDataResult).send();
}

void VehicleInfo::replyGetGpsData(const QVariantMap &handle, const QVariantMap &gps)
{
    response(handle).out<GPSData>(gps).send();
}

void VehicleInfo::replyGetSpeed(const QVariantMap &handle, double speed)
{
    response(handle).out(speed).send();
}

void VehicleInfo::replyGetRpm(const QVariantMap &handle, int rpm)
{
    response(handle).out(rpm).send();
}

void VehicleInfo::replyGetFuelLevel(const QVariantMap &handle, double fuelLevel)
{
    response(handle).out(fuelLevel).send();
}

void VehicleInfo::replyGetFuelLevelState(const QVariantMap &handle, int fuelLevel_State)
{
    response(handle).out(fuelLevel_State).send();
}

void VehicleInfo::replyGetInstantFuelConsumption(const QVariantMap &handle,
    double instantFuelConsumption)
{
    response(handle).out(instantFuelConsumption).send();
}

void VehicleInfo::replyGetExternalTemperature(const QVariantMap &handle,
    double externalTemperature)
{
    response(handle).out(externalTemperature).send();
}

void VehicleInfo::replyGetVin(const QVariantMap &handle, const QString &vin)
{
    response(handle).out(vin).send();
}

void VehicleInfo::replyGetPrndl(const QVariantMap &handle, int prndl)
{
    response(handle).out(prndl).send();
}

void VehicleInfo::replyGetTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    response(handle).out<TireStatus>(tirePressure).send();
}

void VehicleInfo::replyGetOdometer(const QVariantMap &handle, int odometer)
{
    response(handle).out(odometer).send();
}

void VehicleInfo::replyGetBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    response(handle).out<BeltStatus>(beltStatus).send();
}

void VehicleInfo::replyGetBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    response(handle).out<BodyInformation>(bodyInformation).send();
}

void VehicleInfo::replyGetDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    response(handle).out<DeviceStatus>(deviceStatus).send();
}

void VehicleInfo::replyGetDriverBraking(const QVariantMap &handle, int driverBraking)
{
    response(handle).out(driverBraking).send();
}

void VehicleInfo::replyGetWiperStatus(const QVariantMap &handle, int wiperStatus)
{
    response(handle).out(wiperStatus).send();
}

void VehicleInfo::replyGetHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    response(handle).out<HeadLampStatus>(headLampStatus).send();
}

void VehicleInfo::replyGetEngineTorque(const QVariantMap &handle, double engineTorque)
{
    response(handle).out(engineTorque).send();
}

void VehicleInfo::replyGetAccPedalPosition(const QVariantMap &handle,
    double accPedalPosition)
{
    response(handle).out(accPedalPosition).send();
}

void VehicleInfo::replyGetSteeringWheelAngle(const QVariantMap &handle,
    double steeringWheelAngle)
{
    response(handle).out(steeringWheelAngle).send();
}

void VehicleInfo::replyGetECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    response(handle).out<ECallInfo>(eCallInfo).send();
}

void VehicleInfo::replyGetAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    response(handle).out<AirbagStatus>(airbagStatus).send();
}

void VehicleInfo::replyGetEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    response(handle).out<EmergencyEvent>(emergencyEvent).send();
}

void VehicleInfo::replyGetClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    response(handle).out<ClusterModeStatus>(clusterModeStatus).send();
}

void VehicleInfo::replyGetMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    response(handle).out<MyKey>(myKey).send();
}

void VehicleInfo::replySubscribeGps(const QVariantMap &handle, const QVariantMap &gps)
{
    response(handle).out<VehicleDataResult>(gps).send();
}

void VehicleInfo::replySubscribeSpeed(const QVariantMap &handle, const QVariantMap &speed)
{
    response(handle).out<VehicleDataResult>(speed).send();
}

void VehicleInfo::replySubscribeRpm(const QVariantMap &handle, const QVariantMap &rpm)
{
    response(handle).out<VehicleDataResult>(rpm).send();
}

void VehicleInfo::replySubscribeFuelLevel(const QVariantMap &handle,
    const QVariantMap &fuelLevel)
{
    response(handle).out<VehicleDataResult>(fuelLevel).send();
}

void VehicleInfo::replySubscribeFuelLevel_State(const QVariantMap &handle,
    const QVariantMap &fuelLevel_State)
{
    response(handle).out<VehicleDataResult>(fuelLevel_State).send();
}

void VehicleInfo::replySubscribeInstantFuelConsumption(const QVariantMap &handle,
    const QVariantMap &instantFuelConsumption)
{
    response(handle).out<VehicleDataResult>(instantFuelConsumption).send();
}

void VehicleInfo::replySubscribeExternalTemperature(const QVariantMap &handle,
    const QVariantMap &externalTemperature)
{
    response(handle).out<VehicleDataResult>(externalTemperature).send();
}

void VehicleInfo::replySubscribeVin(const QVariantMap &handle, const QString &vin)
{
    response(handle).out(vin).send();
}

void VehicleInfo::replySubscribePrndl(const QVariantMap &handle, const QVariantMap &prndl)
{
    response(handle).out<VehicleDataResult>(prndl).send();
}

void VehicleInfo::replySubscribeTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    response(handle).out<VehicleDataResult>(tirePressure).send();
}

void VehicleInfo::replySubscribeOdometer(const QVariantMap &handle,
    const QVariantMap &odometer)
{
    response(handle).out<VehicleDataResult>(odometer).send();
}

void VehicleInfo::replySubscribeBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    response(handle).out<VehicleDataResult>(beltStatus).send();
}

void VehicleInfo::replySubscribeBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    response(handle).out<VehicleDataResult>(bodyInformation).send();
}

void VehicleInfo::replySubscribeDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    response(handle).out<VehicleDataResult>(deviceStatus).send();
}

void VehicleInfo::replySubscribeDriverBraking(const QVariantMap &handle,
    const QVariantMap &driverBraking)
{
    response(handle).out<VehicleDataResult>(driverBraking).send();
}

void VehicleInfo::replySubscribeWiperStatus(const QVariantMap &handle,
    const QVariantMap &wiperStatus)
{
    response(handle).out<VehicleDataResult>(wiperStatus).send();
}

void VehicleInfo::replySubscribeHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    response(handle).out<VehicleDataResult>(headLampStatus).send();
}

void VehicleInfo::replySubscribeEngineTorque(const QVariantMap &handle,
    const QVariantMap &engineTorque)
{
    response(handle).out<VehicleDataResult>(engineTorque).send();
}

void VehicleInfo::replySubscribeAccPedalPosition(const QVariantMap &handle,
    const QVariantMap &accPedalPosition)
{
    response(handle).out<VehicleDataResult>(accPedalPosition).send();
}

void VehicleInfo::replySubscribeSteeringWheelAngle(const QVariantMap &handle,
    const QVariantMap &steeringWheelAngle)
{
    response(handle).out<VehicleDataResult>(steeringWheelAngle).send();
}

void VehicleInfo::replySubscribeECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    response(handle).out<VehicleDataResult>(eCallInfo).send();
}

void VehicleInfo::replySubscribeAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    response(handle).out<VehicleDataResult>(airbagStatus).send();
}

void VehicleInfo::replySubscribeEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    response(handle).out<VehicleDataResult>(emergencyEvent).send();
}

void VehicleInfo::replySubscribeClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    response(handle).out<VehicleDataResult>(clusterModeStatus).send();
}

void VehicleInfo::replySubscribeMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    response(handle).out<VehicleDataResult>(myKey).send();
}

void VehicleInfo::replyUnsubscribeGps(const QVariantMap &handle, const QVariantMap &gps)
{
    response(handle).out<VehicleDataResult>(gps).send();
}

void VehicleInfo::replyUnsubscribeSpeed(const QVariantMap &handle, const QVariantMap &speed)
{
    response(handle).out<VehicleDataResult>(speed).send();
}

void VehicleInfo::replyUnsubscribeRpm(const QVariantMap &handle, const QVariantMap &rpm)
{
    response(handle).out<VehicleDataResult>(rpm).send();
}

void VehicleInfo::replyUnsubscribeFuelLevel(const QVariantMap &handle,
    const QVariantMap &fuelLevel)
{
    response(handle).out<VehicleDataResult>(fuelLevel).send();
}

void VehicleInfo::replyUnsubscribeFuelLevel_State(const QVariantMap &handle,
    const QVariantMap &fuelLevel_State)
{
    response(handle).out<VehicleDataResult>(fuelLevel_State).send();
}

void VehicleInfo::replyUnsubscribeInstantFuelConsumption(const QVariantMap &handle,
    const QVariantMap &instantFuelConsumption)
{
    response(handle).out<VehicleDataResult>(instantFuelConsumption).send();
}

void VehicleInfo::replyUnsubscribeExternalTemperature(const QVariantMap &handle,
    const QVariantMap &externalTemperature)
{
    response(handle).out<VehicleDataResult>(externalTemperature).send();
}

void VehicleInfo::replyUnsubscribeVin(const QVariantMap &handle, const QString &vin)
{
    response(handle).out(vin).send();
}

void VehicleInfo::replyUnsubscribePrndl(const QVariantMap &handle, const QVariantMap &prndl)
{
    response(handle).out<VehicleDataResult>(prndl).send();
}

void VehicleInfo::replyUnsubscribeTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    response(handle).out<VehicleDataResult>(tirePressure).send();
}

void VehicleInfo::replyUnsubscribeOdometer(const QVariantMap &handle,
    const QVariantMap &odometer)
{
    response(handle).out<VehicleDataResult>(odometer).send();
}

void VehicleInfo::replyUnsubscribeBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    response(handle).out<VehicleDataResult>(beltStatus).send();
}

void VehicleInfo::replyUnsubscribeBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    response(handle).out<VehicleDataResult>(bodyInformation).send();
}

void VehicleInfo::replyUnsubscribeDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    response(handle).out<VehicleDataResult>(deviceStatus).send();
}

void VehicleInfo::replyUnsubscribeDriverBraking(const QVariantMap &handle,
    const QVariantMap &driverBraking)
{
    response(handle).out<VehicleDataResult>(driverBraking).send();
}

void VehicleInfo::replyUnsubscribeWiperStatus(const QVariantMap &handle,
    const QVariantMap &wiperStatus)
{
    response(handle).out<VehicleDataResult>(wiperStatus).send();
}

void VehicleInfo::replyUnsubscribeHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    response(handle).out<VehicleDataResult>(headLampStatus).send();
}

void VehicleInfo::replyUnsubscribeEngineTorque(const QVariantMap &handle,
    const QVariantMap &engineTorque)
{
    response(handle).out<VehicleDataResult>(engineTorque).send();
}

void VehicleInfo::replyUnsubscribeAccPedalPosition(const QVariantMap &handle,
    const QVariantMap &accPedalPosition)
{
    response(handle).out<VehicleDataResult>(accPedalPosition).send();
}

void VehicleInfo::replyUnsubscribeSteeringWheelAngle(const QVariantMap &handle,
    const QVariantMap &steeringWheelAngle)
{
    response(handle).out<VehicleDataResult>(steeringWheelAngle).send();
}

void VehicleInfo::replyUnsubscribeECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    response(handle).out<VehicleDataResult>(eCallInfo).send();
}

void VehicleInfo::replyUnsubscribeAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    response(handle).out<VehicleDataResult>(airbagStatus).send();
}

void VehicleInfo::replyUnsubscribeEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    response(handle).out<VehicleDataResult>(emergencyEvent).send();
}

void VehicleInfo::replyUnsubscribeClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    response(handle).out<VehicleDataResult>(clusterModeStatus).send();
}

void VehicleInfo::replyUnsubscribeMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    response(handle).out<VehicleDataResult>(myKey).send();
}

void VehicleInfo::onGpsData(const QVariantMap &gps)
{
    notification("OnGpsData").arg<GPSData>(gps).send();
}

void VehicleInfo::onSpeed(double speed)
{
    notification("OnSpeed").arg(speed).send();
}

void VehicleInfo::onRpm(int rpm)
{
    notification("OnRpm").arg(rpm).send();
}

void VehicleInfo::onFuelLevel(double fuelLevel)
{
    notification("OnFuelLevel").arg(fuelLevel).send();
}

void VehicleInfo::onFuelLevelState(int fuelLevel_State)
{
    notification("OnFuelLevelState").arg(fuelLevel_State).send();
}

void VehicleInfo::onInstantFuelConsumption(double instantFuelConsumption)
{
    notification("OnInstantFuelConsumption").arg(instantFuelConsumption).send();
}

void VehicleInfo::onExternalTemperature(double externalTemperature)
{
    notification("OnExternalTemperature").arg(externalTemperature).send();
}

void VehicleInfo::onVin(const QString &vin)
{
    notification("OnVin").arg(vin).send();
}

void VehicleInfo::onPrndl(int prndl)
{
    notification("OnPrndl").arg(prndl).send();
}

void VehicleInfo::onTirePressure(const QVariantMap &tirePressure)
{
    notification("OnTirePressure").arg<TireStatus>(tirePressure).send();
}

void VehicleInfo::onOdometer(int odometer)
{
    notification("OnOdometer").arg(odometer).send();
}

void VehicleInfo::onBeltStatus(const QVariantMap &beltStatus)
{
    notification("OnBeltStatus").arg<BeltStatus>(beltStatus).send();
}

void VehicleInfo::onBodyInformation(const QVariantMap &bodyInformation)
{
    notification("OnBodyInformation").arg<BodyInformation>(bodyInformation).send();
}

void VehicleInfo::onDeviceStatus(const QVariantMap &deviceStatus)
{
    notification("OnDeviceStatus").arg<DeviceStatus>(deviceStatus).send();
}

void VehicleInfo::onDriverBraking(int driverBraking)
{
    notification("OnDriverBraking").arg(driverBraking).send();
}

void VehicleInfo::onWiperStatus(int wiperStatus)
{
    notification("OnWiperStatus").arg(wiperStatus).send();
}

void VehicleInfo::onHeadLampStatus(const QVariantMap &headLampStatus)
{
    notification("OnHeadLampStatus").arg<HeadLampStatus>(headLampStatus).send();
}

void VehicleInfo::onEngineTorque(double engineTorque)
{
    notification("OnEngineTorque").arg(engineTorque).send();
}

void VehicleInfo::onAccPedalPosition(double accPedalPosition)
{
    notification("OnAccPedalPosition").arg(accPedalPosition).send();
}

void VehicleInfo::onSteeringWheelAngle(double steeringWheelAngle)
{
    notification("OnSteeringWheelAngle").arg(steeringWheelAngle).send();
}

void VehicleInfo::onECallInfo(const QVariantMap &eCallInfo)
{
    notification("OnECallInfo").arg<ECallInfo>(eCallInfo).send();
}

void VehicleInfo::onAirbagStatus(const QVariantMap &airbagStatus)
{
    notification("OnAirbagStatus").arg<AirbagStatus>(airbagStatus).send();
}

void VehicleInfo::onEmergencyEvent(const QVariantMap &emergencyEvent)
{
    notification("OnEmergencyEvent").arg<EmergencyEvent>(emergencyEvent).send();
}

void VehicleInfo::onClusterModeStatus(const QVariantMap &clusterModeStatus)
{
    notification("OnClusterModeStatus").arg<ClusterModeStatus>(clusterModeStatus).send();
}

void VehicleInfo::onMyKey(const QVariantMap &myKey)
{
    notification("OnMyKey").arg<MyKey>(myKey).send();
}
