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

void VehicleInfoAdapter::ReplyIsReady(const Handle &handle, bool available)
{
    reply(handle).out(available).send();
}

void VehicleInfoAdapter::ReplyGetVehicleType(const Handle &handle,
    const VehicleType &vehicleType)
{
    reply(handle).out(vehicleType).send();
}

void VehicleInfoAdapter::ReplyReadDID(const Handle &handle,
    const QList<DIDResult> &didResult)
{
    reply(handle).out(didResult).send();
}

void VehicleInfoAdapter::ReplyGetDTCs(const Handle &handle, int ecuHeader,
    const Optional<QStringList> &dtc)
{
    reply(handle).out(ecuHeader).out(dtc).send();
}

void VehicleInfoAdapter::ReplyDiagnosticMessage(const Handle &handle,
    const QList<int> &messageDataResult)
{
    reply(handle).out(messageDataResult).send();
}

void VehicleInfoAdapter::ReplyGetGpsData(const Handle &handle, const GPSData &gps)
{
    reply(handle).out(gps).send();
}

void VehicleInfoAdapter::ReplyGetSpeed(const Handle &handle, double speed)
{
    reply(handle).out(speed).send();
}

void VehicleInfoAdapter::ReplyGetRpm(const Handle &handle, int rpm)
{
    reply(handle).out(rpm).send();
}

void VehicleInfoAdapter::ReplyGetFuelLevel(const Handle &handle, double fuelLevel)
{
    reply(handle).out(fuelLevel).send();
}

void VehicleInfoAdapter::ReplyGetFuelLevelState(const Handle &handle, int fuelLevel_State)
{
    reply(handle).out(fuelLevel_State).send();
}

void VehicleInfoAdapter::ReplyGetInstantFuelConsumption(const Handle &handle,
    double instantFuelConsumption)
{
    reply(handle).out(instantFuelConsumption).send();
}

void VehicleInfoAdapter::ReplyGetExternalTemperature(const Handle &handle,
    double externalTemperature)
{
    reply(handle).out(externalTemperature).send();
}

void VehicleInfoAdapter::ReplyGetVin(const Handle &handle, const QString &vin)
{
    reply(handle).out(vin).send();
}

void VehicleInfoAdapter::ReplyGetPrndl(const Handle &handle, int prndl)
{
    reply(handle).out(prndl).send();
}

void VehicleInfoAdapter::ReplyGetTirePressure(const Handle &handle,
    const TireStatus &tirePressure)
{
    reply(handle).out(tirePressure).send();
}

void VehicleInfoAdapter::ReplyGetOdometer(const Handle &handle, int odometer)
{
    reply(handle).out(odometer).send();
}

void VehicleInfoAdapter::ReplyGetBeltStatus(const Handle &handle,
    const BeltStatus &beltStatus)
{
    reply(handle).out(beltStatus).send();
}

void VehicleInfoAdapter::ReplyGetBodyInformation(const Handle &handle,
    const BodyInformation &bodyInformation)
{
    reply(handle).out(bodyInformation).send();
}

void VehicleInfoAdapter::ReplyGetDeviceStatus(const Handle &handle,
    const DeviceStatus &deviceStatus)
{
    reply(handle).out(deviceStatus).send();
}

void VehicleInfoAdapter::ReplyGetDriverBraking(const Handle &handle, int driverBraking)
{
    reply(handle).out(driverBraking).send();
}

void VehicleInfoAdapter::ReplyGetWiperStatus(const Handle &handle, int wiperStatus)
{
    reply(handle).out(wiperStatus).send();
}

void VehicleInfoAdapter::ReplyGetHeadLampStatus(const Handle &handle,
    const HeadLampStatus &headLampStatus)
{
    reply(handle).out(headLampStatus).send();
}

void VehicleInfoAdapter::ReplyGetEngineTorque(const Handle &handle, double engineTorque)
{
    reply(handle).out(engineTorque).send();
}

void VehicleInfoAdapter::ReplyGetAccPedalPosition(const Handle &handle,
    double accPedalPosition)
{
    reply(handle).out(accPedalPosition).send();
}

void VehicleInfoAdapter::ReplyGetSteeringWheelAngle(const Handle &handle,
    double steeringWheelAngle)
{
    reply(handle).out(steeringWheelAngle).send();
}

void VehicleInfoAdapter::ReplyGetAirbagStatus(const Handle &handle,
    const AirbagStatus &airbagStatus)
{
    reply(handle).out(airbagStatus).send();
}

void VehicleInfoAdapter::ReplyGetEmergencyEvent(const Handle &handle,
    const EmergencyEvent &emergencyEvent)
{
    reply(handle).out(emergencyEvent).send();
}

void VehicleInfoAdapter::ReplyGetClusterModeStatus(const Handle &handle,
    const ClusterModeStatus &clusterModeStatus)
{
    reply(handle).out(clusterModeStatus).send();
}

void VehicleInfoAdapter::ReplyGetMyKey(const Handle &handle, const MyKey &myKey)
{
    reply(handle).out(myKey).send();
}

void VehicleInfoAdapter::ReplySubscribeGps(const Handle &handle,
    const VehicleDataResult &gps)
{
    reply(handle).out(gps).send();
}

void VehicleInfoAdapter::ReplySubscribeSpeed(const Handle &handle,
    const VehicleDataResult &speed)
{
    reply(handle).out(speed).send();
}

void VehicleInfoAdapter::ReplySubscribeRpm(const Handle &handle,
    const VehicleDataResult &rpm)
{
    reply(handle).out(rpm).send();
}

void VehicleInfoAdapter::ReplySubscribeFuelLevel(const Handle &handle,
    const VehicleDataResult &fuelLevel)
{
    reply(handle).out(fuelLevel).send();
}

void VehicleInfoAdapter::ReplySubscribeFuelLevel_State(const Handle &handle,
    const VehicleDataResult &fuelLevel_State)
{
    reply(handle).out(fuelLevel_State).send();
}

void VehicleInfoAdapter::ReplySubscribeInstantFuelConsumption(const Handle &handle,
    const VehicleDataResult &instantFuelConsumption)
{
    reply(handle).out(instantFuelConsumption).send();
}

void VehicleInfoAdapter::ReplySubscribeExternalTemperature(const Handle &handle,
    const VehicleDataResult &externalTemperature)
{
    reply(handle).out(externalTemperature).send();
}

void VehicleInfoAdapter::ReplySubscribeVin(const Handle &handle,
    const QString &vin)
{
    reply(handle).out(vin).send();
}

void VehicleInfoAdapter::ReplySubscribePrndl(const Handle &handle,
    const VehicleDataResult &prndl)
{
    reply(handle).out(prndl).send();
}

void VehicleInfoAdapter::ReplySubscribeTirePressure(const Handle &handle,
    const VehicleDataResult &tirePressure)
{
    reply(handle).out(tirePressure).send();
}

void VehicleInfoAdapter::ReplySubscribeOdometer(const Handle &handle,
    const VehicleDataResult &odometer)
{
    reply(handle).out(odometer).send();
}

void VehicleInfoAdapter::ReplySubscribeBeltStatus(const Handle &handle,
    const VehicleDataResult &beltStatus)
{
    reply(handle).out(beltStatus).send();
}

void VehicleInfoAdapter::ReplySubscribeBodyInformation(const Handle &handle,
    const VehicleDataResult &bodyInformation)
{
    reply(handle).out(bodyInformation).send();
}

void VehicleInfoAdapter::ReplySubscribeDeviceStatus(const Handle &handle,
    const VehicleDataResult &deviceStatus)
{
    reply(handle).out(deviceStatus).send();
}

void VehicleInfoAdapter::ReplySubscribeDriverBraking(const Handle &handle,
    const VehicleDataResult &driverBraking)
{
    reply(handle).out(driverBraking).send();
}

void VehicleInfoAdapter::ReplySubscribeWiperStatus(const Handle &handle,
    const VehicleDataResult &wiperStatus)
{
    reply(handle).out(wiperStatus).send();
}

void VehicleInfoAdapter::ReplySubscribeHeadLampStatus(const Handle &handle,
    const VehicleDataResult &headLampStatus)
{
    reply(handle).out(headLampStatus).send();
}

void VehicleInfoAdapter::ReplySubscribeEngineTorque(const Handle &handle,
    const VehicleDataResult &engineTorque)
{
    reply(handle).out(engineTorque).send();
}

void VehicleInfoAdapter::ReplySubscribeAccPedalPosition(const Handle &handle,
    const VehicleDataResult &accPedalPosition)
{
    reply(handle).out(accPedalPosition).send();
}

void VehicleInfoAdapter::ReplySubscribeSteeringWheelAngle(const Handle &handle,
    const VehicleDataResult &steeringWheelAngle)
{
    reply(handle).out(steeringWheelAngle).send();
}

void VehicleInfoAdapter::ReplySubscribeECallInfo(const Handle &handle,
    const VehicleDataResult &eCallInfo)
{
    reply(handle).out(eCallInfo).send();
}

void VehicleInfoAdapter::ReplySubscribeAirbagStatus(const Handle &handle,
    const VehicleDataResult &airbagStatus)
{
    reply(handle).out(airbagStatus).send();
}

void VehicleInfoAdapter::ReplySubscribeEmergencyEvent(const Handle &handle,
    const VehicleDataResult &emergencyEvent)
{
    reply(handle).out(emergencyEvent).send();
}

void VehicleInfoAdapter::ReplySubscribeClusterModeStatus(const Handle &handle,
    const VehicleDataResult &clusterModeStatus)
{
    reply(handle).out(clusterModeStatus).send();
}

void VehicleInfoAdapter::ReplySubscribeMyKey(const Handle &handle,
    const VehicleDataResult &myKey)
{
    reply(handle).out(myKey).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeGps(const Handle &handle,
    const VehicleDataResult &gps)
{
    reply(handle).out(gps).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeSpeed(const Handle &handle,
    const VehicleDataResult &speed)
{
    reply(handle).out(speed).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeRpm(const Handle &handle,
    const VehicleDataResult &rpm)
{
    reply(handle).out(rpm).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeFuelLevel(const Handle &handle,
    const VehicleDataResult &fuelLevel)
{
    reply(handle).out(fuelLevel).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeFuelLevel_State(const Handle &handle,
    const VehicleDataResult &fuelLevel_State)
{
    reply(handle).out(fuelLevel_State).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeInstantFuelConsumption(const Handle &handle,
    const VehicleDataResult &instantFuelConsumption)
{
    reply(handle).out(instantFuelConsumption).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeExternalTemperature(const Handle &handle,
    const VehicleDataResult &externalTemperature)
{
    reply(handle).out(externalTemperature).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeVin(const Handle &handle,
    const QString &vin)
{
    reply(handle).out(vin).send();
}

void VehicleInfoAdapter::ReplyUnsubscribePrndl(const Handle &handle,
    const VehicleDataResult &prndl)
{
    reply(handle).out(prndl).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeTirePressure(const Handle &handle,
    const VehicleDataResult &tirePressure)
{
    reply(handle).out(tirePressure).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeOdometer(const Handle &handle,
    const VehicleDataResult &odometer)
{
    reply(handle).out(odometer).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeBeltStatus(const Handle &handle,
    const VehicleDataResult &beltStatus)
{
    reply(handle).out(beltStatus).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeBodyInformation(const Handle &handle,
    const VehicleDataResult &bodyInformation)
{
    reply(handle).out(bodyInformation).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeDeviceStatus(const Handle &handle,
    const VehicleDataResult &deviceStatus)
{
    reply(handle).out(deviceStatus).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeDriverBraking(const Handle &handle,
    const VehicleDataResult &driverBraking)
{
    reply(handle).out(driverBraking).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeWiperStatus(const Handle &handle,
    const VehicleDataResult &wiperStatus)
{
    reply(handle).out(wiperStatus).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeHeadLampStatus(const Handle &handle,
    const VehicleDataResult &headLampStatus)
{
    reply(handle).out(headLampStatus).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeEngineTorque(const Handle &handle,
    const VehicleDataResult &engineTorque)
{
    reply(handle).out(engineTorque).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeAccPedalPosition(const Handle &handle,
    const VehicleDataResult &accPedalPosition)
{
    reply(handle).out(accPedalPosition).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeSteeringWheelAngle(const Handle &handle,
    const VehicleDataResult &steeringWheelAngle)
{
    reply(handle).out(steeringWheelAngle).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeECallInfo(const Handle &handle,
    const VehicleDataResult &eCallInfo)
{
    reply(handle).out(eCallInfo).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeAirbagStatus(const Handle &handle,
    const VehicleDataResult &airbagStatus)
{
    reply(handle).out(airbagStatus).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeEmergencyEvent(const Handle &handle,
    const VehicleDataResult &emergencyEvent)
{
    reply(handle).out(emergencyEvent).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeClusterModeStatus(const Handle &handle,
    const VehicleDataResult &clusterModeStatus)
{
    reply(handle).out(clusterModeStatus).send();
}

void VehicleInfoAdapter::ReplyUnsubscribeMyKey(const Handle &handle,
    const VehicleDataResult &myKey)
{
    reply(handle).out(myKey).send();
}

void VehicleInfo::replyIsRead(const QVariantMap &handle, bool available)
{
    adapter->ReplyIsReady(handle, available);
}

void VehicleInfo::replyGetVehicleType(const QVariantMap &handle,
    const QVariantMap &vehicleType)
{
    adapter->ReplyGetVehicleType(handle, single<VehicleType>(vehicleType));
}

void VehicleInfo::replyReadDID(const QVariantMap &handle, const QVariantList &didResult)
{
    adapter->ReplyReadDID(handle, multiple<DIDResult>(didResult));
}

void VehicleInfo::replyGetDTCs(const QVariantMap &handle, int ecuHeader, const QVariant &dtc)
{
    adapter->ReplyGetDTCs(handle, ecuHeader, dtc);
}

void VehicleInfo::replyDiagnosticMessage(const QVariantMap &handle,
    const QList<int> &messageDataResult)
{
    adapter->ReplyDiagnosticMessage(handle, messageDataResult);
}

void VehicleInfo::replyGetGpsData(const QVariantMap &handle, const QVariantMap &gps)
{
    adapter->ReplyGetGpsData(handle, single<GPSData>(gps));
}

void VehicleInfo::replyGetSpeed(const QVariantMap &handle, double speed)
{
    adapter->ReplyGetSpeed(handle, speed);
}

void VehicleInfo::replyGetRpm(const QVariantMap &handle, int rpm)
{
    adapter->ReplyGetRpm(handle, rpm);
}

void VehicleInfo::replyGetFuelLevel(const QVariantMap &handle, double fuelLevel)
{
    adapter->ReplyGetFuelLevel(handle, fuelLevel);
}

void VehicleInfo::replyGetFuelLevelState(const QVariantMap &handle, int fuelLevel_State)
{
    adapter->ReplyGetFuelLevelState(handle, fuelLevel_State);
}

void VehicleInfo::replyGetInstantFuelConsumption(const QVariantMap &handle,
    double instantFuelConsumption)
{
    adapter->ReplyGetInstantFuelConsumption(handle, instantFuelConsumption);
}

void VehicleInfo::replyGetExternalTemperature(const QVariantMap &handle,
    double externalTemperature)
{
    adapter->ReplyGetExternalTemperature(handle, externalTemperature);
}

void VehicleInfo::replyGetVin(const QVariantMap &handle, const QString &vin)
{
    adapter->ReplyGetVin(handle, vin);
}

void VehicleInfo::replyGetPrndl(const QVariantMap &handle, int prndl)
{
    adapter->ReplyGetPrndl(handle, prndl);
}

void VehicleInfo::replyGetTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    adapter->ReplyGetTirePressure(handle, single<TireStatus>(tirePressure));
}

void VehicleInfo::replyGetOdometer(const QVariantMap &handle, int odometer)
{
    adapter->ReplyGetOdometer(handle, odometer);
}

void VehicleInfo::replyGetBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    adapter->ReplyGetBeltStatus(handle, single<BeltStatus>(beltStatus));
}

void VehicleInfo::replyGetBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    adapter->ReplyGetBodyInformation(handle, single<BodyInformation>(bodyInformation));
}

void VehicleInfo::replyGetDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    adapter->ReplyGetDeviceStatus(handle, single<DeviceStatus>(deviceStatus));
}

void VehicleInfo::replyGetDriverBraking(const QVariantMap &handle, int driverBraking)
{
    adapter->ReplyGetDriverBraking(handle, driverBraking);
}

void VehicleInfo::replyGetWiperStatus(const QVariantMap &handle, int wiperStatus)
{
    adapter->ReplyGetWiperStatus(handle, wiperStatus);
}

void VehicleInfo::replyGetHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    adapter->ReplyGetHeadLampStatus(handle, single<HeadLampStatus>(headLampStatus));
}

void VehicleInfo::replyGetEngineTorque(const QVariantMap &handle, double engineTorque)
{
    adapter->ReplyGetEngineTorque(handle, engineTorque);
}

void VehicleInfo::replyGetAccPedalPosition(const QVariantMap &handle,
    double accPedalPosition)
{
    adapter->ReplyGetAccPedalPosition(handle, accPedalPosition);
}

void VehicleInfo::replyGetSteeringWheelAngle(const QVariantMap &handle,
    double steeringWheelAngle)
{
    adapter->ReplyGetSteeringWheelAngle(handle, steeringWheelAngle);
}

void VehicleInfo::replyGetECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    adapter->ReplyGetECallInfo(handle, single<ECallInfo>(eCallInfo));
}

void VehicleInfo::replyGetAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    adapter->ReplyGetAirbagStatus(handle, single<AirbagStatus>(airbagStatus));
}

void VehicleInfo::replyGetEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    adapter->ReplyGetEmergencyEvent(handle, single<EmergencyEvent>(emergencyEvent));
}

void VehicleInfo::replyGetClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    adapter->ReplyGetClusterModeStatus(handle, single<ClusterModeStatus>(clusterModeStatus));
}

void VehicleInfo::replyGetMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    adapter->ReplyGetMyKey(handle, single<MyKey>(myKey));
}

void VehicleInfo::replySubscribeGps(const QVariantMap &handle, const QVariantMap &gps)
{
    adapter->ReplySubscribeGps(handle, single<VehicleDataResult>(gps));
}

void VehicleInfo::replySubscribeSpeed(const QVariantMap &handle, const QVariantMap &speed)
{
    adapter->ReplySubscribeSpeed(handle, single<VehicleDataResult>(speed));
}

void VehicleInfo::replySubscribeRpm(const QVariantMap &handle, const QVariantMap &rpm)
{
    adapter->ReplySubscribeRpm(handle, single<VehicleDataResult>(rpm));
}

void VehicleInfo::replySubscribeFuelLevel(const QVariantMap &handle,
    const QVariantMap &fuelLevel)
{
    adapter->ReplySubscribeFuelLevel(handle, single<VehicleDataResult>(fuelLevel));
}

void VehicleInfo::replySubscribeFuelLevel_State(const QVariantMap &handle,
    const QVariantMap &fuelLevel_State)
{
    adapter->ReplySubscribeFuelLevel_State(handle, single<VehicleDataResult>(fuelLevel_State));
}

void VehicleInfo::replySubscribeInstantFuelConsumption(const QVariantMap &handle,
    const QVariantMap &instantFuelConsumption)
{
    adapter->ReplySubscribeInstantFuelConsumption(handle,
        single<VehicleDataResult>(instantFuelConsumption));
}

void VehicleInfo::replySubscribeExternalTemperature(const QVariantMap &handle,
    const QVariantMap &externalTemperature)
{
    adapter->ReplySubscribeExternalTemperature(handle,
        single<VehicleDataResult>(externalTemperature));
}

void VehicleInfo::replySubscribeVin(const QVariantMap &handle, const QString &vin)
{
    adapter->ReplySubscribeVin(handle, vin);
}

void VehicleInfo::replySubscribePrndl(const QVariantMap &handle, const QVariantMap &prndl)
{
    adapter->ReplySubscribePrndl(handle, single<VehicleDataResult>(prndl));
}

void VehicleInfo::replySubscribeTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    adapter->ReplySubscribeTirePressure(handle, single<VehicleDataResult>(tirePressure));
}

void VehicleInfo::replySubscribeOdometer(const QVariantMap &handle,
    const QVariantMap &odometer)
{
    adapter->ReplySubscribeOdometer(handle, single<VehicleDataResult>(odometer));
}

void VehicleInfo::replySubscribeBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    adapter->ReplySubscribeBeltStatus(handle, single<VehicleDataResult>(beltStatus));
}

void VehicleInfo::replySubscribeBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    adapter->ReplySubscribeBodyInformation(handle, single<VehicleDataResult>(bodyInformation));
}

void VehicleInfo::replySubscribeDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    adapter->ReplySubscribeDeviceStatus(handle, single<VehicleDataResult>(deviceStatus));
}

void VehicleInfo::replySubscribeDriverBraking(const QVariantMap &handle,
    const QVariantMap &driverBraking)
{
    adapter->ReplySubscribeDriverBraking(handle, single<VehicleDataResult>(driverBraking));
}

void VehicleInfo::replySubscribeWiperStatus(const QVariantMap &handle,
    const QVariantMap &wiperStatus)
{
    adapter->ReplySubscribeWiperStatus(handle, single<VehicleDataResult>(wiperStatus));
}

void VehicleInfo::replySubscribeHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    adapter->ReplySubscribeHeadLampStatus(handle,
        single<VehicleDataResult>(headLampStatus));
}

void VehicleInfo::replySubscribeEngineTorque(const QVariantMap &handle,
    const QVariantMap &engineTorque)
{
    adapter->ReplySubscribeEngineTorque(handle, single<VehicleDataResult>(engineTorque));
}

void VehicleInfo::replySubscribeAccPedalPosition(const QVariantMap &handle,
    const QVariantMap &accPedalPosition)
{
    adapter->ReplySubscribeAccPedalPosition(handle,
        single<VehicleDataResult>(accPedalPosition));
}

void VehicleInfo::replySubscribeSteeringWheelAngle(const QVariantMap &handle,
    const QVariantMap &steeringWheelAngle)
{
    adapter->ReplySubscribeSteeringWheelAngle(handle,
        single<VehicleDataResult>(steeringWheelAngle));
}

void VehicleInfo::replySubscribeECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    adapter->ReplySubscribeECallInfo(handle, single<VehicleDataResult>(eCallInfo));
}

void VehicleInfo::replySubscribeAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    adapter->ReplySubscribeAirbagStatus(handle, single<VehicleDataResult>(airbagStatus));
}

void VehicleInfo::replySubscribeEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    adapter->ReplySubscribeEmergencyEvent(handle, single<VehicleDataResult>(emergencyEvent));
}

void VehicleInfo::replySubscribeClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    adapter->ReplySubscribeClusterModeStatus(handle,
        single<VehicleDataResult>(clusterModeStatus));
}

void VehicleInfo::replySubscribeMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    adapter->ReplySubscribeMyKey(handle, single<VehicleDataResult>(myKey));
}

void VehicleInfo::replyUnsubscribeGps(const QVariantMap &handle, const QVariantMap &gps)
{
    adapter->ReplyUnsubscribeGps(handle, single<VehicleDataResult>(gps));
}

void VehicleInfo::replyUnsubscribeSpeed(const QVariantMap &handle, const QVariantMap &speed)
{
    adapter->ReplyUnsubscribeSpeed(handle, single<VehicleDataResult>(speed));
}

void VehicleInfo::replyUnsubscribeRpm(const QVariantMap &handle, const QVariantMap &rpm)
{
    adapter->ReplyUnsubscribeRpm(handle, single<VehicleDataResult>(rpm));
}

void VehicleInfo::replyUnsubscribeFuelLevel(const QVariantMap &handle,
    const QVariantMap &fuelLevel)
{
    adapter->ReplyUnsubscribeFuelLevel(handle, single<VehicleDataResult>(fuelLevel));
}

void VehicleInfo::replyUnsubscribeFuelLevel_State(const QVariantMap &handle,
    const QVariantMap &fuelLevel_State)
{
    adapter->ReplyUnsubscribeFuelLevel_State(handle,
        single<VehicleDataResult>(fuelLevel_State));
}

void VehicleInfo::replyUnsubscribeInstantFuelConsumption(const QVariantMap &handle,
    const QVariantMap &instantFuelConsumption)
{
    adapter->ReplyUnsubscribeInstantFuelConsumption(handle,
        single<VehicleDataResult>(instantFuelConsumption));
}

void VehicleInfo::replyUnsubscribeExternalTemperature(const QVariantMap &handle,
    const QVariantMap &externalTemperature)
{
    adapter->ReplyUnsubscribeExternalTemperature(handle,
        single<VehicleDataResult>(externalTemperature));
}

void VehicleInfo::replyUnsubscribeVin(const QVariantMap &handle, const QString &vin)
{
    adapter->ReplyUnsubscribeVin(handle, vin);
}

void VehicleInfo::replyUnsubscribePrndl(const QVariantMap &handle, const QVariantMap &prndl)
{
    adapter->ReplyUnsubscribePrndl(handle, single<VehicleDataResult>(prndl));
}

void VehicleInfo::replyUnsubscribeTirePressure(const QVariantMap &handle,
    const QVariantMap &tirePressure)
{
    adapter->ReplyUnsubscribeTirePressure(handle, single<VehicleDataResult>(tirePressure));
}

void VehicleInfo::replyUnsubscribeOdometer(const QVariantMap &handle,
    const QVariantMap &odometer)
{
    adapter->ReplyUnsubscribeOdometer(handle, single<VehicleDataResult>(odometer));
}

void VehicleInfo::replyUnsubscribeBeltStatus(const QVariantMap &handle,
    const QVariantMap &beltStatus)
{
    adapter->ReplyUnsubscribeBeltStatus(handle, single<VehicleDataResult>(beltStatus));
}

void VehicleInfo::replyUnsubscribeBodyInformation(const QVariantMap &handle,
    const QVariantMap &bodyInformation)
{
    adapter->ReplyUnsubscribeBodyInformation(handle,
        single<VehicleDataResult>(bodyInformation));
}

void VehicleInfo::replyUnsubscribeDeviceStatus(const QVariantMap &handle,
    const QVariantMap &deviceStatus)
{
    adapter->ReplyUnsubscribeDeviceStatus(handle, single<VehicleDataResult>(deviceStatus));
}

void VehicleInfo::replyUnsubscribeDriverBraking(const QVariantMap &handle,
    const QVariantMap &driverBraking)
{
    adapter->ReplyUnsubscribeDriverBraking(handle, single<VehicleDataResult>(driverBraking));
}

void VehicleInfo::replyUnsubscribeWiperStatus(const QVariantMap &handle,
    const QVariantMap &wiperStatus)
{
    adapter->ReplyUnsubscribeWiperStatus(handle, single<VehicleDataResult>(wiperStatus));
}

void VehicleInfo::replyUnsubscribeHeadLampStatus(const QVariantMap &handle,
    const QVariantMap &headLampStatus)
{
    adapter->ReplyUnsubscribeHeadLampStatus(handle,
        single<VehicleDataResult>(headLampStatus));
}

void VehicleInfo::replyUnsubscribeEngineTorque(const QVariantMap &handle,
    const QVariantMap &engineTorque)
{
    adapter->ReplyUnsubscribeEngineTorque(handle,
        single<VehicleDataResult>(engineTorque));
}

void VehicleInfo::replyUnsubscribeAccPedalPosition(const QVariantMap &handle,
    const QVariantMap &accPedalPosition)
{
    adapter->ReplyUnsubscribeAccPedalPosition(handle,
        single<VehicleDataResult>(accPedalPosition));
}

void VehicleInfo::replyUnsubscribeSteeringWheelAngle(const QVariantMap &handle,
    const QVariantMap &steeringWheelAngle)
{
    adapter->ReplyUnsubscribeSteeringWheelAngle(handle,
        single<VehicleDataResult>(steeringWheelAngle));
}

void VehicleInfo::replyUnsubscribeECallInfo(const QVariantMap &handle,
    const QVariantMap &eCallInfo)
{
    adapter->ReplyUnsubscribeECallInfo(handle, single<VehicleDataResult>(eCallInfo));
}

void VehicleInfo::replyUnsubscribeAirbagStatus(const QVariantMap &handle,
    const QVariantMap &airbagStatus)
{
    adapter->ReplyUnsubscribeAirbagStatus(handle,
        single<VehicleDataResult>(airbagStatus));
}

void VehicleInfo::replyUnsubscribeEmergencyEvent(const QVariantMap &handle,
    const QVariantMap &emergencyEvent)
{
    adapter->ReplyUnsubscribeEmergencyEvent(handle,
        single<VehicleDataResult>(emergencyEvent));
}

void VehicleInfo::replyUnsubscribeClusterModeStatus(const QVariantMap &handle,
    const QVariantMap &clusterModeStatus)
{
    adapter->ReplyUnsubscribeClusterModeStatus(handle,
        single<VehicleDataResult>(clusterModeStatus));
}

void VehicleInfo::replyUnsubscribeMyKey(const QVariantMap &handle, const QVariantMap &myKey)
{
    adapter->ReplyUnsubscribeMyKey(handle, single<VehicleDataResult>(myKey));
}

void VehicleInfo::onGpsData(const QVariantMap &gps)
{
    emit adapter->OnGpsData(single<GPSData>(gps));
}

void VehicleInfo::onSpeed(double speed)
{
    emit adapter->OnSpeed(speed);
}

void VehicleInfo::onRpm(int rpm)
{
    emit adapter->OnRpm(rpm);
}

void VehicleInfo::onFuelLevel(double fuelLevel)
{
    emit adapter->OnFuelLevel(fuelLevel);
}

void VehicleInfo::onFuelLevelState(int fuelLevel_State)
{
    emit adapter->OnFuelLevelState(fuelLevel_State);
}

void VehicleInfo::onInstantFuelConsumption(double instantFuelConsumption)
{
    emit adapter->OnInstantFuelConsumption(instantFuelConsumption);
}

void VehicleInfo::onExternalTemperature(double externalTemperature)
{
    emit adapter->OnExternalTemperature(externalTemperature);
}

void VehicleInfo::onVin(const QString &vin)
{
    emit adapter->OnVin(vin);
}

void VehicleInfo::onPrndl(int prndl)
{
    emit adapter->OnPrndl(prndl);
}

void VehicleInfo::onTirePressure(const QVariantMap &tirePressure)
{
    emit adapter->OnTirePressure(single<TireStatus>(tirePressure));
}

void VehicleInfo::onOdometer(int odometer)
{
    emit adapter->OnOdometer(odometer);
}

void VehicleInfo::onBeltStatus(const QVariantMap &beltStatus)
{
    emit adapter->OnBeltStatus(single<BeltStatus>(beltStatus));
}

void VehicleInfo::onBodyInformation(const QVariantMap &bodyInformation)
{
    emit adapter->OnBodyInformation(single<BodyInformation>(bodyInformation));
}

void VehicleInfo::onDeviceStatus(const QVariantMap &deviceStatus)
{
    emit adapter->OnDeviceStatus(single<DeviceStatus>(deviceStatus));
}

void VehicleInfo::onDriverBraking(int driverBraking)
{
    emit adapter->OnDriverBraking(driverBraking);
}

void VehicleInfo::onWiperStatus(int wiperStatus)
{
    emit adapter->OnWiperStatus(wiperStatus);
}

void VehicleInfo::onHeadLampStatus(const QVariantMap &headLampStatus)
{
    emit adapter->OnHeadLampStatus(single<HeadLampStatus>(headLampStatus));
}

void VehicleInfo::onEngineTorque(double engineTorque)
{
    emit adapter->OnEngineTorque(engineTorque);
}

void VehicleInfo::onAccPedalPosition(double accPedalPosition)
{
    emit adapter->OnAccPedalPosition(accPedalPosition);
}

void VehicleInfo::onSteeringWheelAngle(double steeringWheelAngle)
{
    emit adapter->OnSteeringWheelAngle(steeringWheelAngle);
}

void VehicleInfo::onECallInfo(const QVariantMap &eCallInfo)
{
    emit adapter->OnECallInfo(single<ECallInfo>(eCallInfo));
}

void VehicleInfo::onAirbagStatus(const QVariantMap &airbagStatus)
{
    emit adapter->OnAirbagStatus(single<AirbagStatus>(airbagStatus));
}

void VehicleInfo::onEmergencyEvent(const QVariantMap &emergencyEvent)
{
    emit adapter->OnEmergencyEvent(single<EmergencyEvent>(emergencyEvent));
}

void VehicleInfo::onClusterModeStatus(const QVariantMap &clusterModeStatus)
{
    emit adapter->OnClusterModeStatus(single<ClusterModeStatus>(clusterModeStatus));
}

void VehicleInfo::onMyKey(const QVariantMap &myKey)
{
    emit adapter->OnMyKey(single<MyKey>(myKey));
}
