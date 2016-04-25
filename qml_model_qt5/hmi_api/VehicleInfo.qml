/**
 * @file VehicleInfo.qml
 * @brief Vehicle information interface realisation.
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

import com.ford.sdl.hmi.dbus_adapter 1.0
import "Common.js" as Common

VehicleInfo
{
    function isReady(handle) {
        console.log("Message Received - {method: 'VehicleInfo.IsReady'}")
        replyIsReady(handle, dataContainer.hmiVehicleInfoAvailable)
    }

    function getVehicleType(handle) {
        console.log("Message Received - {method: 'VehicleInfo.GetVehicleType'}")
        replyGetVehicleType(handle, {
            "make": "Ford",
            "model": "Fiesta",
            "modelYear": "2013",
            "trim": "SE"
        });
    }

    function getGpsData(handle, appID) {
        console.debug("enter")
        replyGetGpsData(handle, dataContainer.vehicleInfoModel.gps)
        console.debug("exit")
    }

    function getSpeed(handle, appID) {
        console.debug("enter")
        replyGetSpeed(handle, dataContainer.vehicleInfoModel.speed)
        console.debug("exit")
    }

    function getRpm(handle, appID) {
        console.debug("enter")
        handle.code = Common.Result.DATA_NOT_AVAILABLE;
        replyGetRpm(handle, dataContainer.vehicleInfoModel.rpm);
        console.debug("exit")
    }

    function getFuelLevel(handle, appID) {
        console.debug("enter")
        replyGetFuelLevel(handle, dataContainer.vehicleInfoModel.fuelLevel)
        console.debug("exit")
    }

    function getFuelLevelState(handle, appID) {
        console.debug("enter")
        replyGetFuelLevelState(handle, dataContainer.vehicleInfoModel.fuelLevel_State)
        console.debug("exit")
    }

    function getInstantFuelConsumption(handle, appID) {
        console.debug("enter")
        replyGetInstantFuelConsumption(handle, dataContainer.vehicleInfoModel.instantFuelConsumption)
        console.debug("exit")
    }

    function getExternalTemperature(handle, appID) {
        console.debug("enter")
        replyGetExternalTemperature(handle, dataContainer.vehicleInfoModel.externalTemperature)
        console.debug("exit")
    }

    function getVin(handle, appID) {
        console.debug("enter")
        replyGetVin(handle, dataContainer.vehicleInfoModel.vin)
        console.debug("exit")
    }

    function getPrndl(handle, appID) {
        console.debug("enter")
        if (dataContainer.vehicleInfoModel.prndl === -1) { // Test value, to check response
            handle.code = Common.Result.DATA_NOT_AVAILABLE;
        }
        replyGetPrndl(handle, dataContainer.vehicleInfoModel.prndl);
        console.debug("exit")
    }

    function getTirePressure(handle, appID) {
        console.debug("enter")
        replyGetTirePressure(handle, dataContainer.vehicleInfoModel.tirePressure)
        console.debug("exit")
    }

    function getOdometer(handle, appID) {
        console.debug("enter")
        handle.code = Common.Result.DATA_NOT_AVAILABLE;
        replyGetOdometer(handle, dataContainer.vehicleInfoModel.odometer);
        console.debug("exit")
    }

    function getBeltStatus(handle, appID) {
        console.debug("enter")
        replyGetBeltStatus(handle, dataContainer.vehicleInfoModel.beltStatus)
        console.debug("exit")
    }

    function getBodyInformation(handle, appID) {
        console.debug("enter")
        replyGetBodyInformation(handle, dataContainer.vehicleInfoModel.bodyInformation)
        console.debug("exit")
    }

    function getDeviceStatus(handle, appID) {
        console.debug("enter")
        replyGetDeviceStatus(handle, dataContainer.vehicleInfoModel.deviceStatus)
        console.debug("exit")
    }

    function getDriverBraking(handle, appID) {
        console.debug("enter")
        replyGetDriverBraking(handle, dataContainer.vehicleInfoModel.driverBraking)
        console.debug("exit")
    }

    function getWiperStatus(handle, appID) {
        console.debug("enter")
        replyGetWiperStatus(handle, dataContainer.vehicleInfoModel.wiperStatus)
        console.debug("exit")
    }

    function getHeadLampStatus(handle, appID) {
        console.debug("enter")
        replyGetHeadLampStatus(handle, dataContainer.vehicleInfoModel.headLampStatus)
        console.debug("exit")
    }

    function getEngineTorque(handle, appID) {
        console.debug("enter")
        replyGetEngineTorque(handle, dataContainer.vehicleInfoModel.engineTorque)
        console.debug("exit")
    }

    function getAccPedalPosition(handle, appID) {
        console.debug("enter")
        replyGetgetAccPedalPosition(handle, dataContainer.vehicleInfoModel.accPedalPosition)
        console.debug("exit")
    }

    function getSteeringWheelAngle(handle, appID) {
        console.debug("enter")
        replyGetSteeringWheelAngle(handle, dataContainer.vehicleInfoModel.steeringWheelAngle)
        console.debug("exit")
    }

    function getECallInfo(handle, appID) {
        console.debug("enter")
        replyGetECallInfo(handle, dataContainer.vehicleInfoModel.eCallInfo)
        console.debug("exit")
    }

    function getAirbagStatus(handle, appID) {
        console.debug("enter")
        replyGetAirbagStatus(handle, dataContainer.vehicleInfoModel.airbagStatus)
        console.debug("exit")
    }

    function getEmergencyEvent(handle, appID) {
        console.debug("enter")
        replyGetEmergencyEvent(handle, dataContainer.vehicleInfoModel.emergencyEvent)
        console.debug("exit")
    }

    function getClusterModeStatus(handle, appID) {
        console.debug("enter")
        replyGetClusterModeStatus(handle, dataContainer.vehicleInfoModel.clusterModeStatus)
        console.debug("exit")
    }

    function getMyKey(handle, appID) {
        console.debug("enter")
        replyGetMyKey(handle, dataContainer.vehicleInfoModel.myKey)
        console.debug("exit")
    }

    function getDTCs(handle, ecuName, dtcMask, appID) {
        console.log("Message Received - {method: 'VehicleInfo.GetDTCs', params:{ " +
                    "ecuName: " + ecuName + ", " +
                    "dtcMask: " + dtcMask + ", " +
                    "appID: " + appID +
                    "}}")
        var ecuHeader = 2
        var dtc = []

        for (var i = 0; i < 3; i++) {
            dtc.push("line" + i)
        }
        replyGetDTCs(handle, ecuHeader, dtc);
    }

    function readDID(handle, ecuName, didLocation, appID) {
        console.debug("Enter")
        console.log("Message Received - {method: 'VehicleInfo.ReadDID', params:{ " +
                    "ecuName: " + ecuName + ", " +
                    "didLocation: " + didLocation + ", " +
                    "appID: " + appID +
                    "}}")
        //TODO{ALeshin}: refactoring of this function, when we'll have Vehicle Info module
        var didResult = []

        for (var i = 0; i < didLocation.length; i++) {
            if (i < 10) {
                didResult[i] = {}
                didResult[i].resultCode = Common.VehicleDataResultCode.VDRC_SUCCESS
                didResult[i].didLocation = didLocation[i]
                didResult[i].data = '0'
            }
            else {
                didResult[i] = {}
                didResult[i].resultCode = Common.VehicleDataResultCode.VDRC_DATA_NOT_AVAILABLE
                didResult[i].didLocation = didLocation[i]
                didResult[i].data = '0'
            }
        }
        replyReadDID(handle, didResult);
        console.debug("Exit")
    }

    function subscribeGps(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onGpsChanged.disconnect(model.sendGpsChange)
        model.onGpsChanged.connect(model.sendGpsChange)
        replySubscribeGps(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_GPS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS});
        console.debug("exit")
    }
    function unsubscribeGps(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onGpsChanged.disconnect(model.sendGpsChange)
        replyUnsubscribeGps(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_GPS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS});
        console.debug("exit")
    }

    function subscribeSpeed(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onSpeedChanged.disconnect(model.sendSpeedChange)
        model.onSpeedChanged.connect(model.sendSpeedChange)
        replySubscrcibeSpeed(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_SPEED,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeSpeed(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onSpeedChanged.disconnect(model.sendSpeedChange)
        replyUnsubscribeSpeed(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_SPEED,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeRpm(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onRpmChanged.disconnect(model.sendRpmChange)
        model.onRpmChanged.connect(model.sendRpmChange)
        replySubscribeRpm(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_RPM,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeRpm(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onRpmChanged.disconnect(model.sendRpmChange)
        replyUnsubscribeRpm(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_RPM,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeFuelLevel(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevelChanged.disconnect(model.sendFuelLevelChange)
        model.onFuelLevelChanged.connect(model.sendFuelLevelChange)
        replySubscribeFuelLevel(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeFuelLevel(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevelChanged.disconnect(model.sendFuelLevelChange)
        replyUnsubscribeFuelLevel(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeFuelLevel_State(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevel_StateChanged.disconnect(model.sendFuelLevel_StateChange)
        model.onFuelLevel_StateChanged.connect(model.sendFuelLevel_StateChange)
        replySubscribeFuelLevel_State(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL_STATE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeFuelLevel_State(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevel_StateChanged.disconnect(model.sendFuelLevel_StateChange)
        replyUnsubscribeFuelLevel_State(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL_STATE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeInstantFuelConsumption(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onInstantFuelConsumptionChanged.disconnect(model.sendInstantFuelConsumptionChange)
        model.onInstantFuelConsumptionChanged.connect(model.sendInstantFuelConsumptionChange)
        replySubscribeInstantFuelConsumption(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELCONSUMPTION,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeInstantFuelConsumption(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onInstantFuelConsumptionChanged.disconnect(model.sendInstantFuelConsumptionChange)
        replyUnsubscribeInstantFuelConsumption(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELCONSUMPTION,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeExternalTemperature(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onExternalTemperatureChanged.disconnect(model.sendExternalTemperatureChange)
        model.onExternalTemperatureChanged.connect(model.sendExternalTemperatureChange)
        replySubscribeExternalTemperature(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EXTERNTEMP,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeExternalTemperature(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onExternalTemperatureChanged.disconnect(model.sendExternalTemperatureChange)
        replyUnsubscribeExternalTemperature(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EXTERNTEMP,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribePrndl(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onPrndlChanged.disconnect(model.sendPrndlChange)
        model.onPrndlChanged.connect(model.sendPrndlChange)
        replySubscribePrndl(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_PRNDL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribePrndl(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onPrndlChanged.disconnect(model.sendPrndlChange)
        replyUnsubscribePrndl(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_PRNDL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeVin(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onVinChanged.disconnect(model.sendVinChange)
        model.onVinChanged.connect(model.sendVinChange)
        replySubscribeVin(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_VIN,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeVin(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onVinChanged.disconnect(model.sendVinChange)
        replyUnsubscribeVin(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_VIN,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeTirePressure(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onTirePressureChanged.disconnect(model.sendTirePressureChange)
        model.onTirePressureChanged.connect(model.sendTirePressureChange)
        replySubscribeTirePressure(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_TIREPRESSURE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeTirePressure(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onTirePressureChanged.disconnect(model.sendTirePressureChange)
        replyUnsubscribeTirePressure(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_TIREPRESSURE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeOdometer(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onOdometerChanged.disconnect(model.sendOdometerChange)
        model.onOdometerChanged.connect(model.sendOdometerChange)
        replySubscribeOdometer(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ODOMETER,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeOdometer(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onOdometerChanged.disconnect(model.sendOdometerChange)
        replyUnsubscribeOdometer(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ODOMETER,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeBeltStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onBeltStatusChanged.disconnect(model.sendBeltStatusChange)
        model.onBeltStatusChanged.connect(model.sendBeltStatusChange)
        replySubscribeBeltStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BELTSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeBeltStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onBeltStatusChanged.disconnect(model.sendBeltStatusChange)
        replyUnsubscribeBeltStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BELTSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeBodyInformation(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onBodyInformationChanged.disconnect(model.sendBodyInformationChange)
        model.onBodyInformationChanged.connect(model.sendBodyInformationChange)
        replySubscribeBodyInformation(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BODYINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeBodyInformation(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onBodyInformationChanged.disconnect(model.sendBodyInformationChange)
        replyUnsubscribeBodyInformation(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BODYINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeDeviceStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onDeviceStatusChanged.disconnect(model.sendDeviceStatusChange)
        model.onDeviceStatusChanged.connect(model.sendDeviceStatusChange)
        replySubscribeDeviceStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_DEVICESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeDeviceStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onDeviceStatusChanged.disconnect(model.sendDeviceStatusChange)
        replyUnsubscribeDeviceStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_DEVICESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeDriverBraking(handle, appID) {
        console.debug("enter")
        replySubscribe
        var model = dataContainer.vehicleInfoModel;
        model.onDriverBrakingChanged.disconnect(model.sendDriverBrakingChange)
        model.onDriverBrakingChanged.connect(model.sendDriverBrakingChange)
        replyUnsubscribeDriverBraking(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BRAKING,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeDriverBraking(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onDriverBrakingChanged.disconnect(model.sendDriverBrakingChange)
        replyUnsubscribeDriverBraking(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BRAKING,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeWiperStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onWiperStatusChanged.disconnect(model.sendWiperStatusChange)
        model.onWiperStatusChanged.connect(model.sendWiperStatusChange)
        replySubscribeWiperStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_WIPERSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeWiperStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onWiperStatusChanged.disconnect(model.sendWiperStatusChange)
        replyUnsubscribeWiperStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_WIPERSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeHeadLampStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onHeadLampStatusChanged.disconnect(model.sendHeadLampStatusChange)
        model.onHeadLampStatusChanged.connect(model.sendHeadLampStatusChange)
        replySubscribeHeadLampStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_HEADLAMPSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeHeadLampStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onHeadLampStatusChanged.disconnect(model.sendHeadLampStatusChange)
        replyUnsubscribeHeadLampStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_HEADLAMPSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeEngineTorque(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onEngineTorqueChanged.disconnect(model.sendEngineTorqueChange)
        model.onEngineTorqueChanged.connect(model.sendEngineTorqueChange)
        replySubscribeEngineTorque(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ENGINETORQUE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeEngineTorque(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onEngineTorqueChanged.disconnect(model.sendEngineTorqueChange)
        replyUnsubscribeEngineTorque(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ENGINETORQUE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeAccPedalPosition(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onAccPedalPositionChanged.disconnect(model.sendAccPedalPositionChange)
        model.onAccPedalPositionChanged.connect(model.sendAccPedalPositionChange)
        replySubscribeAccPedalPosition(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ACCPEDAL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeAccPedalPosition(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onAccPedalPositionChanged.disconnect(model.sendAccPedalPositionChange)
        replyUnsubscribeAccPedalPosition(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ACCPEDAL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeSteeringWheelAngle(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onSteeringWheelAngleChanged.disconnect(model.sendSteeringWheelAngleChange)
        model.onSteeringWheelAngleChanged.connect(model.sendSteeringWheelAngleChange)
        replySubscribeSteeringWheelAngle(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_STEERINGWHEEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeSteeringWheelAngle(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onSteeringWheelAngleChanged.disconnect(model.sendSteeringWheelAngleChange)
        replyUnsubscribeSteeringWheelAngle(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_STEERINGWHEEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeECallInfo(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onECallInfoChanged.disconnect(model.sendECallInfoChange)
        model.onECallInfoChanged.connect(model.sendECallInfoChange)
        replySubscribeECallInfo(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ECALLINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeECallInfo(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onECallInfoChanged.disconnect(model.sendECallInfoChange)
        replyUnsubscribeECallInfo(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ECALLINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeAirbagStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onAirbagStatusChanged.disconnect(model.sendAirbagStatusChange)
        model.onAirbagStatusChanged.connect(model.sendAirbagStatusChange)
        replySubscribeAirbagStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_AIRBAGSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeAirbagStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onAirbagStatusChanged.disconnect(model.sendAirbagStatusChange)
        replyUnsubscribeAirbagStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_AIRBAGSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeEmergencyEvent(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onEmergencyEventChanged.disconnect(model.sendEmergencyEventChange)
        model.onEmergencyEventChanged.connect(model.sendEmergencyEventChange)
        replySubscribeEmergencyEvent(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EMERGENCYEVENT,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeEmergencyEvent(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onEmergencyEventChanged.disconnect(model.sendEmergencyEventChange)
        replyUnsubscribeEmergencyEvent(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EMERGENCYEVENT,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeClusterModeStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onClusterModeStatusChanged.disconnect(model.sendClusterModeStatusChange)
        model.onClusterModeStatusChanged.connect(model.sendClusterModeStatusChange)
        replySubscribeClusterModeStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_CLUSTERMODESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeClusterModeStatus(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onClusterModeStatusChanged.disconnect(model.sendClusterModeStatusChange)
        replyUnsubscribeClusterModeStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_CLUSTERMODESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function subscribeMyKey(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onMyKeyChanged.disconnect(model.sendMyKeyChange)
        model.onMyKeyChanged.connect(model.sendMyKeyChange)
        replySubscribeMyKey(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_MYKEY,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }
    function unsubscribeMyKey(handle, appID) {
        console.debug("enter")
        var model = dataContainer.vehicleInfoModel;
        model.onMyKeyChanged.disconnect(model.sendMyKeyChange)
        replyUnsubscribeMyKey(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_MYKEY,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
        console.debug("exit")
    }

    function diagnosticMessage(handle, targetID, messageLength, messageData, appID) {
        console.log("Message Received - {method: 'VehicleInfo.DiagnosticMessage'}");
        // TODO: it's stub, need to implement
        replyDiagnosticMessage(handle, []);
    }
}
