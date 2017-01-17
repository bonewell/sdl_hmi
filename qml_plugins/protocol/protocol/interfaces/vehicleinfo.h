#ifndef VEHICLEINFO_H
#define VEHICLEINFO_H

#include "core/abstractadapter.h"
#include "core/abstractitem.h"
#include "protocol/structures.h"

#define VEHICLEINFO_INTROSPECTION \
    "<interface name=\"com.ford.sdl.hmi.VehicleInfo\">" \
    "<method name=\"IsReady\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"available\" type=\"b\" />" \
    "</method>" \
    "<method name=\"GetVehicleType\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"vehicleType\" type=\"((bs)(bs)(bs)(bs))\" />" \
    "</method>" \
    "<method name=\"ReadDID\">" \
    "<arg direction=\"in\" name=\"ecuName\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"didLocation\" type=\"ai\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"didResult\" type=\"(ba(ii(bs)))\" />" \
    "</method>" \
    "<method name=\"GetDTCs\">" \
    "<arg direction=\"in\" name=\"ecuName\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"dtcMask\" type=\"(bi)\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"ecuHeader\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"dtc\" type=\"(bas)\" />" \
    "</method>" \
    "<method name=\"DiagnosticMessage\">" \
    "<arg direction=\"in\" name=\"targetID\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"messageLength\" type=\"i\" />" \
    "<arg direction=\"in\" name=\"messageData\" type=\"ai\" />" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"messageDataResult\" type=\"ai\" />" \
    "</method>" \
    "<method name=\"GetGpsData\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"gps\" type=\"((bd)(bd)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bd)(bd)(bd)(bb)(bi)(bi)(bd)(bd)(bd))\" />" \
    "</method>" \
    "<method name=\"GetSpeed\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"speed\" type=\"d\" />" \
    "</method>" \
    "<method name=\"GetRpm\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"rpm\" type=\"i\" />" \
    "</method>" \
    "<method name=\"GetFuelLevel\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"fuelLevel\" type=\"d\" />" \
    "</method>" \
    "<method name=\"GetFuelLevelState\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"fuelLevel_State\" type=\"i\" />" \
    "</method>" \
    "<method name=\"GetInstantFuelConsumption\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"instantFuelConsumption\" type=\"d\" />" \
    "</method>" \
    "<method name=\"GetExternalTemperature\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"externalTemperature\" type=\"d\" />" \
    "</method>" \
    "<method name=\"GetVin\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"vin\" type=\"s\" />" \
    "</method>" \
    "<method name=\"GetPrndl\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"prndl\" type=\"i\" />" \
    "</method>" \
    "<method name=\"GetTirePressure\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"tirePressure\" type=\"((bi)(b(i))(b(i))(b(i))(b(i))(b(i))(b(i)))\" />" \
    "</method>" \
    "<method name=\"GetOdometer\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"odometer\" type=\"i\" />" \
    "</method>" \
    "<method name=\"GetBeltStatus\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"beltStatus\" type=\"((bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi))\" />" \
    "</method>" \
    "<method name=\"GetBodyInformation\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"bodyInformation\" type=\"(bii(bb)(bb)(bb)(bb))\" />" \
    "</method>" \
    "<method name=\"GetDeviceStatus\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"deviceStatus\" type=\"((bb)(bb)(bb)(bb)(bb)(bi)(bb)(bb)(bi)(bi)(bb))\" />" \
    "</method>" \
    "<method name=\"GetDriverBraking\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"driverBraking\" type=\"i\" />" \
    "</method>" \
    "<method name=\"GetWiperStatus\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"wiperStatus\" type=\"i\" />" \
    "</method>" \
    "<method name=\"GetHeadLampStatus\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"headLampStatus\" type=\"(bbi)\" />" \
    "</method>" \
    "<method name=\"GetEngineTorque\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"engineTorque\" type=\"d\" />" \
    "</method>" \
    "<method name=\"GetAccPedalPosition\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"accPedalPosition\" type=\"d\" />" \
    "</method>" \
    "<method name=\"GetSteeringWheelAngle\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"steeringWheelAngle\" type=\"d\" />" \
    "</method>" \
    "<method name=\"GetECallInfo\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"eCallInfo\" type=\"(iii)\" />" \
    "</method>" \
    "<method name=\"GetAirbagStatus\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"airbagStatus\" type=\"(iiiiiiii)\" />" \
    "</method>" \
    "<method name=\"GetEmergencyEvent\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"emergencyEvent\" type=\"(iiiii)\" />" \
    "</method>" \
    "<method name=\"GetClusterModeStatus\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"clusterModeStatus\" type=\"(biii)\" />" \
    "</method>" \
    "<method name=\"GetMyKey\">" \
    "<arg direction=\"in\" name=\"appID\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"myKey\" type=\"(i)\" />" \
    "</method>" \
    "<method name=\"SubscribeGps\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"gps\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeGps\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"gps\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeSpeed\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"speed\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeSpeed\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"speed\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeRpm\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"rpm\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeRpm\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"rpm\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeFuelLevel\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"fuelLevel\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeFuelLevel\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"fuelLevel\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeFuelLevel_State\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"fuelLevel_State\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeFuelLevel_State\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"fuelLevel_State\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeInstantFuelConsumption\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"instantFuelConsumption\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeInstantFuelConsumption\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"instantFuelConsumption\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeExternalTemperature\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"externalTemperature\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeExternalTemperature\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"externalTemperature\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribePrndl\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"prndl\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribePrndl\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"prndl\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeVin\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"vin\" type=\"s\" />" \
    "</method>" \
    "<method name=\"UnsubscribeVin\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"vin\" type=\"s\" />" \
    "</method>" \
    "<method name=\"SubscribeTirePressure\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"tirePressure\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeTirePressure\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"tirePressure\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeOdometer\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"odometer\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeOdometer\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"odometer\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeBeltStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"beltStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeBeltStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"beltStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeBodyInformation\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"bodyInformation\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeBodyInformation\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"bodyInformation\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeDeviceStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"deviceStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeDeviceStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"deviceStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeDriverBraking\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"driverBraking\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeDriverBraking\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"driverBraking\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeWiperStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"wiperStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeWiperStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"wiperStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeHeadLampStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"headLampStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeHeadLampStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"headLampStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeEngineTorque\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"engineTorque\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeEngineTorque\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"engineTorque\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeAccPedalPosition\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"accPedalPosition\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeAccPedalPosition\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"accPedalPosition\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeSteeringWheelAngle\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"steeringWheelAngle\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeSteeringWheelAngle\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"steeringWheelAngle\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeECallInfo\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"eCallInfo\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeECallInfo\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"eCallInfo\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeAirbagStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"airbagStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeAirbagStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"airbagStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeEmergencyEvent\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"emergencyEvent\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeEmergencyEvent\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"emergencyEvent\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeClusterModeStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"clusterModeStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeClusterModeStatus\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"clusterModeStatus\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"SubscribeMyKey\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"myKey\" type=\"(ii)\" />" \
    "</method>" \
    "<method name=\"UnsubscribeMyKey\">" \
    "<arg direction=\"out\" name=\"retCode\" type=\"i\" />" \
    "<arg direction=\"out\" name=\"retMessage\" type=\"s\" />" \
    "<arg direction=\"out\" name=\"myKey\" type=\"(ii)\" />" \
    "</method>" \
    "<signal name=\"OnGpsData\">" \
    "<arg name=\"gps\" type=\"((bd)(bd)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bd)(bd)(bd)(bb)(bi)(bi)(bd)(bd)(bd))\" />" \
    "</signal>" \
    "<signal name=\"OnSpeed\">" \
    "<arg name=\"speed\" type=\"d\" />" \
    "</signal>" \
    "<signal name=\"OnRpm\">" \
    "<arg name=\"rpm\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnFuelLevel\">" \
    "<arg name=\"fuelLevel\" type=\"d\" />" \
    "</signal>" \
    "<signal name=\"OnFuelLevelState\">" \
    "<arg name=\"fuelLevel_State\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnInstantFuelConsumption\">" \
    "<arg name=\"instantFuelConsumption\" type=\"d\" />" \
    "</signal>" \
    "<signal name=\"OnExternalTemperature\">" \
    "<arg name=\"externalTemperature\" type=\"d\" />" \
    "</signal>" \
    "<signal name=\"OnVin\">" \
    "<arg name=\"vin\" type=\"s\" />" \
    "</signal>" \
    "<signal name=\"OnPrndl\">" \
    "<arg name=\"prndl\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnTirePressure\">" \
    "<arg name=\"tirePressure\" type=\"((bi)(b(i))(b(i))(b(i))(b(i))(b(i))(b(i)))\" />" \
    "</signal>" \
    "<signal name=\"OnOdometer\">" \
    "<arg name=\"odometer\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnBeltStatus\">" \
    "<arg name=\"beltStatus\" type=\"((bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi)(bi))\" />" \
    "</signal>" \
    "<signal name=\"OnBodyInformation\">" \
    "<arg name=\"bodyInformation\" type=\"(bii(bb)(bb)(bb)(bb))\" />" \
    "</signal>" \
    "<signal name=\"OnDeviceStatus\">" \
    "<arg name=\"deviceStatus\" type=\"((bb)(bb)(bb)(bb)(bb)(bi)(bb)(bb)(bi)(bi)(bb))\" />" \
    "</signal>" \
    "<signal name=\"OnDriverBraking\">" \
    "<arg name=\"driverBraking\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnWiperStatus\">" \
    "<arg name=\"wiperStatus\" type=\"i\" />" \
    "</signal>" \
    "<signal name=\"OnHeadLampStatus\">" \
    "<arg name=\"headLampStatus\" type=\"(bbi)\" />" \
    "</signal>" \
    "<signal name=\"OnEngineTorque\">" \
    "<arg name=\"engineTorque\" type=\"d\" />" \
    "</signal>" \
    "<signal name=\"OnAccPedalPosition\">" \
    "<arg name=\"accPedalPosition\" type=\"d\" />" \
    "</signal>" \
    "<signal name=\"OnSteeringWheelAngle\">" \
    "<arg name=\"steeringWheelAngle\" type=\"d\" />" \
    "</signal>" \
    "<signal name=\"OnECallInfo\">" \
    "<arg name=\"eCallInfo\" type=\"(iii)\" />" \
    "</signal>" \
    "<signal name=\"OnAirbagStatus\">" \
    "<arg name=\"airbagStatus\" type=\"(iiiiiiii)\" />" \
    "</signal>" \
    "<signal name=\"OnEmergencyEvent\">" \
    "<arg name=\"emergencyEvent\" type=\"(iiiii)\" />" \
    "</signal>" \
    "<signal name=\"OnClusterModeStatus\">" \
    "<arg name=\"clusterModeStatus\" type=\"(biii)\" />" \
    "</signal>" \
    "<signal name=\"OnMyKey\">" \
    "<arg name=\"myKey\" type=\"(i)\" />" \
    "</signal>" \
    "</interface>" \

class VehicleInfo;

class VehicleInfoAdapter : public AbstractAdapter
{
    Q_OBJECT
    ADAPTER_INFO(100, VehicleInfo, VEHICLEINFO_INTROSPECTION)
    REGISTER_ADAPTER(VehicleInfoAdapter, VehicleInfo)
    CONNECT_SERVICE("com.ford.sdl.core", "com.ford.sdl.core.VehicleInfo")

// Incoming requests
public slots:
    void IsReady(const Message& message);
    void GetVehicleType(const Message& message);
    void ReadDID(int ecuName, const QList<int>& didLocation, int appID,
        const Message& message);
    void GetDTCs(int ecuName, const Optional<int>& dtcMask, int appID,
        const Message& message);
    void DiagnosticMessage(int targetID, int messageLength,
        const QList<int>& messageData, int appID, const Message& message);
    void GetGpsData(int appID, const Message& message);
    void GetSpeed(int appID, const Message& message);
    void GetRpm(int appID, const Message& message);
    void GetFuelLevel(int appID, const Message& message);
    void GetFuelLevelState(int appID, const Message& message);
    void GetInstantFuelConsumption(int appID, const Message& message);
    void GetExternalTemperature(int appID, const Message& message);
    void GetVin(int appID, const Message& message);
    void GetPrndl(int appID, const Message& message);
    void GetTirePressure(int appID, const Message& message);
    void GetOdometer(int appID, const Message& message);
    void GetBeltStatus(int appID, const Message& message);
    void GetBodyInformation(int appID, const Message& message);
    void GetDeviceStatus(int appID, const Message& message);
    void GetDriverBraking(int appID, const Message& message);
    void GetWiperStatus(int appID, const Message& message);
    void GetHeadLampStatus(int appID, const Message& message);
    void GetEngineTorque(int appID, const Message& message);
    void GetAccPedalPosition(int appID, const Message& message);
    void GetSteeringWheelAngle(int appID, const Message& message);
    void GetECallInfo(int appID, const Message& message);
    void GetAirbagStatus(int appID, const Message& message);
    void GetEmergencyEvent(int appID, const Message& message);
    void GetClusterModeStatus(int appID, const Message& message);
    void GetMyKey(int appID, const Message& message);
    void SubscribeGps(const Message& message);
    void SubscribeSpeed(const Message& message);
    void SubscribeRpm(const Message& message);
    void SubscribeFuelLevel(const Message& message);
    void SubscribeFuelLevel_State(const Message& message);
    void SubscribeInstantFuelConsumption(const Message& message);
    void SubscribeExternalTemperature(const Message& message);
    void SubscribeVin(const Message& message);
    void SubscribePrndl(const Message& message);
    void SubscribeTirePressure(const Message& message);
    void SubscribeOdometer(const Message& message);
    void SubscribeBeltStatus(const Message& message);
    void SubscribeBodyInformation(const Message& message);
    void SubscribeDeviceStatus(const Message& message);
    void SubscribeDriverBraking(const Message& message);
    void SubscribeWiperStatus(const Message& message);
    void SubscribeHeadLampStatus(const Message& message);
    void SubscribeEngineTorque(const Message& message);
    void SubscribeAccPedalPosition(const Message& message);
    void SubscribeSteeringWheelAngle(const Message& message);
    void SubscribeECallInfo(const Message& message);
    void SubscribeAirbagStatus(const Message& message);
    void SubscribeEmergencyEvent(const Message& message);
    void SubscribeClusterModeStatus(const Message& message);
    void SubscribeMyKey(const Message& message);
    void UnsubscribeGps(const Message& message);
    void UnsubscribeSpeed(const Message& message);
    void UnsubscribeRpm(const Message& message);
    void UnsubscribeFuelLevel(const Message& message);
    void UnsubscribeFuelLevel_State(const Message& message);
    void UnsubscribeInstantFuelConsumption(const Message& message);
    void UnsubscribeExternalTemperature(const Message& message);
    void UnsubscribeVin(const Message& message);
    void UnsubscribePrndl(const Message& message);
    void UnsubscribeTirePressure(const Message& message);
    void UnsubscribeOdometer(const Message& message);
    void UnsubscribeBeltStatus(const Message& message);
    void UnsubscribeBodyInformation(const Message& message);
    void UnsubscribeDeviceStatus(const Message& message);
    void UnsubscribeDriverBraking(const Message& message);
    void UnsubscribeWiperStatus(const Message& message);
    void UnsubscribeHeadLampStatus(const Message& message);
    void UnsubscribeEngineTorque(const Message& message);
    void UnsubscribeAccPedalPosition(const Message& message);
    void UnsubscribeSteeringWheelAngle(const Message& message);
    void UnsubscribeECallInfo(const Message& message);
    void UnsubscribeAirbagStatus(const Message& message);
    void UnsubscribeEmergencyEvent(const Message& message);
    void UnsubscribeClusterModeStatus(const Message& message);
    void UnsubscribeMyKey(const Message& message);
};

class VehicleInfo : public AbstractItem
{
    Q_OBJECT
    CONNECT_ADAPTER(VehicleInfo, VehicleInfoAdapter)

public:
// Outcoming notifications
    Q_INVOKABLE void onGpsData(const QVariantMap& gps);
    Q_INVOKABLE void onSpeed(double speed);
    Q_INVOKABLE void onRpm(int rpm);
    Q_INVOKABLE void onFuelLevel(double fuelLevel);
    Q_INVOKABLE void onFuelLevelState(int fuelLevel_State);
    Q_INVOKABLE void onInstantFuelConsumption(double instantFuelConsumption);
    Q_INVOKABLE void onExternalTemperature(double externalTemperature);
    Q_INVOKABLE void onVin(const QString& vin);
    Q_INVOKABLE void onPrndl(int prndl);
    Q_INVOKABLE void onTirePressure(const QVariantMap& tirePressure);
    Q_INVOKABLE void onOdometer(int odometer);
    Q_INVOKABLE void onBeltStatus(const QVariantMap& beltStatus);
    Q_INVOKABLE void onBodyInformation(const QVariantMap& bodyInformation);
    Q_INVOKABLE void onDeviceStatus(const QVariantMap& deviceStatus);
    Q_INVOKABLE void onDriverBraking(int driverBraking);
    Q_INVOKABLE void onWiperStatus(int wiperStatus);
    Q_INVOKABLE void onHeadLampStatus(const QVariantMap& headLampStatus);
    Q_INVOKABLE void onEngineTorque(double engineTorque);
    Q_INVOKABLE void onAccPedalPosition(double accPedalPosition);
    Q_INVOKABLE void onSteeringWheelAngle(double steeringWheelAngle);
    Q_INVOKABLE void onECallInfo(const QVariantMap& eCallInfo);
    Q_INVOKABLE void onAirbagStatus(const QVariantMap& airbagStatus);
    Q_INVOKABLE void onEmergencyEvent(const QVariantMap& emergencyEvent);
    Q_INVOKABLE void onClusterModeStatus(const QVariantMap& clusterModeStatus);
    Q_INVOKABLE void onMyKey(const QVariantMap& myKey);

// Outcoming responses
    Q_INVOKABLE void replyIsReady(const QVariantMap& handle, bool available);
    Q_INVOKABLE void replyGetVehicleType(const QVariantMap& handle,
        const QVariantMap& vehicleType);
    Q_INVOKABLE void replyReadDID(const QVariantMap& handle,
        const QVariantList& didResult);
    Q_INVOKABLE void replyGetDTCs(const QVariantMap& handle, int ecuHeader,
        const QVariant& dtc = QVariant());
    Q_INVOKABLE void replyDiagnosticMessage(const QVariantMap& handle,
        const QList<int>& messageDataResult);
    Q_INVOKABLE void replyGetGpsData(const QVariantMap& handle, const QVariantMap& gps);
    Q_INVOKABLE void replyGetSpeed(const QVariantMap& handle, double speed);
    Q_INVOKABLE void replyGetRpm(const QVariantMap& handle, int rpm);
    Q_INVOKABLE void replyGetFuelLevel(const QVariantMap& handle, double fuelLevel);
    Q_INVOKABLE void replyGetFuelLevelState(const QVariantMap& handle, int fuelLevel_State);
    Q_INVOKABLE void replyGetInstantFuelConsumption(const QVariantMap& handle, double instantFuelConsumption);
    Q_INVOKABLE void replyGetExternalTemperature(const QVariantMap& handle, double externalTemperature);
    Q_INVOKABLE void replyGetVin(const QVariantMap& handle, const QString& vin);
    Q_INVOKABLE void replyGetPrndl(const QVariantMap& handle, int prndl);
    Q_INVOKABLE void replyGetTirePressure(const QVariantMap& handle, const QVariantMap& tirePressure);
    Q_INVOKABLE void replyGetOdometer(const QVariantMap& handle, int odometer);
    Q_INVOKABLE void replyGetBeltStatus(const QVariantMap& handle, const QVariantMap& beltStatus);
    Q_INVOKABLE void replyGetBodyInformation(const QVariantMap& handle, const QVariantMap& bodyInformation);
    Q_INVOKABLE void replyGetDeviceStatus(const QVariantMap& handle, const QVariantMap& deviceStatus);
    Q_INVOKABLE void replyGetDriverBraking(const QVariantMap& handle, int driverBraking);
    Q_INVOKABLE void replyGetWiperStatus(const QVariantMap& handle, int wiperStatus);
    Q_INVOKABLE void replyGetHeadLampStatus(const QVariantMap& handle, const QVariantMap& headLampStatus);
    Q_INVOKABLE void replyGetEngineTorque(const QVariantMap& handle, double engineTorque);
    Q_INVOKABLE void replyGetAccPedalPosition(const QVariantMap& handle, double accPedalPosition);
    Q_INVOKABLE void replyGetSteeringWheelAngle(const QVariantMap& handle, double steeringWheelAngle);
    Q_INVOKABLE void replyGetECallInfo(const QVariantMap& handle, const QVariantMap& eCallInfo);
    Q_INVOKABLE void replyGetAirbagStatus(const QVariantMap& handle, const QVariantMap& airbagStatus);
    Q_INVOKABLE void replyGetEmergencyEvent(const QVariantMap& handle, const QVariantMap& emergencyEvent);
    Q_INVOKABLE void replyGetClusterModeStatus(const QVariantMap& handle, const QVariantMap& clusterModeStatus);
    Q_INVOKABLE void replyGetMyKey(const QVariantMap& handle, const QVariantMap& myKey);
    Q_INVOKABLE void replySubscribeGps(const QVariantMap& handle, const QVariantMap& gps);
    Q_INVOKABLE void replySubscribeSpeed(const QVariantMap& handle, const QVariantMap& speed);
    Q_INVOKABLE void replySubscribeRpm(const QVariantMap& handle, const QVariantMap& rpm);
    Q_INVOKABLE void replySubscribeFuelLevel(const QVariantMap& handle, const QVariantMap& fuelLevel);
    Q_INVOKABLE void replySubscribeFuelLevel_State(const QVariantMap& handle, const QVariantMap& fuelLevel_State);
    Q_INVOKABLE void replySubscribeInstantFuelConsumption(const QVariantMap& handle, const QVariantMap& instantFuelConsumption);
    Q_INVOKABLE void replySubscribeExternalTemperature(const QVariantMap& handle, const QVariantMap& externalTemperature);
    Q_INVOKABLE void replySubscribeVin(const QVariantMap& handle, const QString& vin);
    Q_INVOKABLE void replySubscribePrndl(const QVariantMap& handle, const QVariantMap& prndl);
    Q_INVOKABLE void replySubscribeTirePressure(const QVariantMap& handle, const QVariantMap& tirePressure);
    Q_INVOKABLE void replySubscribeOdometer(const QVariantMap& handle, const QVariantMap& odometer);
    Q_INVOKABLE void replySubscribeBeltStatus(const QVariantMap& handle, const QVariantMap& beltStatus);
    Q_INVOKABLE void replySubscribeBodyInformation(const QVariantMap& handle, const QVariantMap& bodyInformation);
    Q_INVOKABLE void replySubscribeDeviceStatus(const QVariantMap& handle, const QVariantMap& deviceStatus);
    Q_INVOKABLE void replySubscribeDriverBraking(const QVariantMap& handle, const QVariantMap& driverBraking);
    Q_INVOKABLE void replySubscribeWiperStatus(const QVariantMap& handle, const QVariantMap& wiperStatus);
    Q_INVOKABLE void replySubscribeHeadLampStatus(const QVariantMap& handle, const QVariantMap& headLampStatus);
    Q_INVOKABLE void replySubscribeEngineTorque(const QVariantMap& handle, const QVariantMap& engineTorque);
    Q_INVOKABLE void replySubscribeAccPedalPosition(const QVariantMap& handle, const QVariantMap& accPedalPosition);
    Q_INVOKABLE void replySubscribeSteeringWheelAngle(const QVariantMap& handle, const QVariantMap& steeringWheelAngle);
    Q_INVOKABLE void replySubscribeECallInfo(const QVariantMap& handle, const QVariantMap& eCallInfo);
    Q_INVOKABLE void replySubscribeAirbagStatus(const QVariantMap& handle, const QVariantMap& airbagStatus);
    Q_INVOKABLE void replySubscribeEmergencyEvent(const QVariantMap& handle, const QVariantMap& emergencyEvent);
    Q_INVOKABLE void replySubscribeClusterModeStatus(const QVariantMap& handle, const QVariantMap& clusterModeStatus);
    Q_INVOKABLE void replySubscribeMyKey(const QVariantMap& handle, const QVariantMap& myKey);
    Q_INVOKABLE void replyUnsubscribeGps(const QVariantMap& handle, const QVariantMap& gps);
    Q_INVOKABLE void replyUnsubscribeSpeed(const QVariantMap& handle, const QVariantMap& speed);
    Q_INVOKABLE void replyUnsubscribeRpm(const QVariantMap& handle, const QVariantMap& rpm);
    Q_INVOKABLE void replyUnsubscribeFuelLevel(const QVariantMap& handle, const QVariantMap& fuelLevel);
    Q_INVOKABLE void replyUnsubscribeFuelLevel_State(const QVariantMap& handle, const QVariantMap& fuelLevel_State);
    Q_INVOKABLE void replyUnsubscribeInstantFuelConsumption(const QVariantMap& handle, const QVariantMap& instantFuelConsumption);
    Q_INVOKABLE void replyUnsubscribeExternalTemperature(const QVariantMap& handle, const QVariantMap& externalTemperature);
    Q_INVOKABLE void replyUnsubscribeVin(const QVariantMap& handle, const QString& vin);
    Q_INVOKABLE void replyUnsubscribePrndl(const QVariantMap& handle, const QVariantMap& prndl);
    Q_INVOKABLE void replyUnsubscribeTirePressure(const QVariantMap& handle, const QVariantMap& tirePressure);
    Q_INVOKABLE void replyUnsubscribeOdometer(const QVariantMap& handle, const QVariantMap& odometer);
    Q_INVOKABLE void replyUnsubscribeBeltStatus(const QVariantMap& handle, const QVariantMap& beltStatus);
    Q_INVOKABLE void replyUnsubscribeBodyInformation(const QVariantMap& handle, const QVariantMap& bodyInformation);
    Q_INVOKABLE void replyUnsubscribeDeviceStatus(const QVariantMap& handle, const QVariantMap& deviceStatus);
    Q_INVOKABLE void replyUnsubscribeDriverBraking(const QVariantMap& handle, const QVariantMap& driverBraking);
    Q_INVOKABLE void replyUnsubscribeWiperStatus(const QVariantMap& handle, const QVariantMap& wiperStatus);
    Q_INVOKABLE void replyUnsubscribeHeadLampStatus(const QVariantMap& handle, const QVariantMap& headLampStatus);
    Q_INVOKABLE void replyUnsubscribeEngineTorque(const QVariantMap& handle, const QVariantMap& engineTorque);
    Q_INVOKABLE void replyUnsubscribeAccPedalPosition(const QVariantMap& handle, const QVariantMap& accPedalPosition);
    Q_INVOKABLE void replyUnsubscribeSteeringWheelAngle(const QVariantMap& handle, const QVariantMap& steeringWheelAngle);
    Q_INVOKABLE void replyUnsubscribeECallInfo(const QVariantMap& handle, const QVariantMap& eCallInfo);
    Q_INVOKABLE void replyUnsubscribeAirbagStatus(const QVariantMap& handle, const QVariantMap& airbagStatus);
    Q_INVOKABLE void replyUnsubscribeEmergencyEvent(const QVariantMap& handle, const QVariantMap& emergencyEvent);
    Q_INVOKABLE void replyUnsubscribeClusterModeStatus(const QVariantMap& handle, const QVariantMap& clusterModeStatus);
    Q_INVOKABLE void replyUnsubscribeMyKey(const QVariantMap& handle, const QVariantMap& myKey);
};

#endif // VEHICLEINFO_H
