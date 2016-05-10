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
        console.log("Received method: VehicleInfo.IsReady");
        replyIsReady(handle, dataContainer.hmiVehicleInfoAvailable);
    }

    function getVehicleType(handle) {
        console.log("Received method: VehicleInfo.GetVehicleType");
        replyGetVehicleType(handle, {
            "make": "Ford",
            "model": "Fiesta",
            "modelYear": "2013",
            "trim": "SE"
        });
    }

    function getGpsData(handle, appID) {
        console.log("Received method: VehicleInfo.GetGpsData");
        console.debug("appID =", JSON.stringify(appID));
        replyGetGpsData(handle, dataContainer.vehicleInfoModel.gps)
    }

    function getSpeed(handle, appID) {
        console.log("Received method: VehicleInfo.GetSpeed");
        console.debug("appID =", JSON.stringify(appID));
        replyGetSpeed(handle, dataContainer.vehicleInfoModel.speed)
    }

    function getRpm(handle, appID) {
        console.log("Received method: VehicleInfo.GetRpm");
        console.debug("appID =", JSON.stringify(appID));
        handle.code = Common.Result.DATA_NOT_AVAILABLE;
        replyGetRpm(handle, dataContainer.vehicleInfoModel.rpm);
    }

    function getFuelLevel(handle, appID) {
        console.log("Received method: VehicleInfo.GetFuelLevel");
        console.debug("appID =", JSON.stringify(appID));
        replyGetFuelLevel(handle, dataContainer.vehicleInfoModel.fuelLevel)
    }

    function getFuelLevelState(handle, appID) {
        console.log("Received method: VehicleInfo.GetFuelLevelState");
        console.debug("appID =", JSON.stringify(appID));
        replyGetFuelLevelState(handle, dataContainer.vehicleInfoModel.fuelLevel_State)
    }

    function getInstantFuelConsumption(handle, appID) {
        console.log("Received method: VehicleInfo.GetInstantFuelConsumption");
        console.debug("appID =", JSON.stringify(appID));
        replyGetInstantFuelConsumption(handle, dataContainer.vehicleInfoModel.instantFuelConsumption)
    }

    function getExternalTemperature(handle, appID) {
        console.log("Received method: VehicleInfo.GetExternalTemperature");
        console.debug("appID =", JSON.stringify(appID));
        replyGetExternalTemperature(handle, dataContainer.vehicleInfoModel.externalTemperature)
    }

    function getVin(handle, appID) {
        console.log("Received method: VehicleInfo.GetVin");
        console.debug("appID =", JSON.stringify(appID));
        replyGetVin(handle, dataContainer.vehicleInfoModel.vin)
    }

    function getPrndl(handle, appID) {
        console.log("Received method: VehicleInfo.GetPrndl");
        console.debug("appID =", JSON.stringify(appID));
        if (dataContainer.vehicleInfoModel.prndl === -1) { // Test value, to check response
            handle.code = Common.Result.DATA_NOT_AVAILABLE;
        }
        replyGetPrndl(handle, dataContainer.vehicleInfoModel.prndl);
    }

    function getTirePressure(handle, appID) {
        console.log("Received method: VehicleInfo.GetTirePressure");
        console.debug("appID =", JSON.stringify(appID));
        replyGetTirePressure(handle, dataContainer.vehicleInfoModel.tirePressure)
    }

    function getOdometer(handle, appID) {
        console.log("Received method: VehicleInfo.GetOdometer");
        console.debug("appID =", JSON.stringify(appID));
        handle.code = Common.Result.DATA_NOT_AVAILABLE;
        replyGetOdometer(handle, dataContainer.vehicleInfoModel.odometer);
    }

    function getBeltStatus(handle, appID) {
        console.log("Received method: VehicleInfo.GetBeltStatus");
        console.debug("appID =", JSON.stringify(appID));
        replyGetBeltStatus(handle, dataContainer.vehicleInfoModel.beltStatus)
    }

    function getBodyInformation(handle, appID) {
        console.log("Received method: VehicleInfo.GetBodyInformation");
        console.debug("appID =", JSON.stringify(appID));
        replyGetBodyInformation(handle, dataContainer.vehicleInfoModel.bodyInformation)
    }

    function getDeviceStatus(handle, appID) {
        console.log("Received method: VehicleInfo.GetDeviceStatus");
        console.debug("appID =", JSON.stringify(appID));
        replyGetDeviceStatus(handle, dataContainer.vehicleInfoModel.deviceStatus)
    }

    function getDriverBraking(handle, appID) {
        console.log("Received method: VehicleInfo.GetDriverBraking");
        console.debug("appID =", JSON.stringify(appID));
        replyGetDriverBraking(handle, dataContainer.vehicleInfoModel.driverBraking)
    }

    function getWiperStatus(handle, appID) {
        console.log("Received method: VehicleInfo.GetWiperStatus");
        console.debug("appID =", JSON.stringify(appID));
        replyGetWiperStatus(handle, dataContainer.vehicleInfoModel.wiperStatus)
    }

    function getHeadLampStatus(handle, appID) {
        console.log("Received method: VehicleInfo.GetHeadLampStatus");
        console.debug("appID =", JSON.stringify(appID));
        replyGetHeadLampStatus(handle, dataContainer.vehicleInfoModel.headLampStatus)
    }

    function getEngineTorque(handle, appID) {
        console.log("Received method: VehicleInfo.GetEngineTorque");
        console.debug("appID =", JSON.stringify(appID));
        replyGetEngineTorque(handle, dataContainer.vehicleInfoModel.engineTorque)
    }

    function getAccPedalPosition(handle, appID) {
        console.log("Received method: VehicleInfo.GetAccPedalPosition");
        console.debug("appID =", JSON.stringify(appID));
        replyGetgetAccPedalPosition(handle, dataContainer.vehicleInfoModel.accPedalPosition)
    }

    function getSteeringWheelAngle(handle, appID) {
        console.log("Received method: VehicleInfo.GetSteeringWheelAngle");
        console.debug("appID =", JSON.stringify(appID));
        replyGetSteeringWheelAngle(handle, dataContainer.vehicleInfoModel.steeringWheelAngle)
    }

    function getECallInfo(handle, appID) {
        console.log("Received method: VehicleInfo.GetECallInfo");
        console.debug("appID =", JSON.stringify(appID));
        replyGetECallInfo(handle, dataContainer.vehicleInfoModel.eCallInfo)
    }

    function getAirbagStatus(handle, appID) {
        console.log("Received method: VehicleInfo.GetAirbagStatus");
        console.debug("appID =", JSON.stringify(appID));
        replyGetAirbagStatus(handle, dataContainer.vehicleInfoModel.airbagStatus)
    }

    function getEmergencyEvent(handle, appID) {
        console.log("Received method: VehicleInfo.GetEmergencyEvent");
        console.debug("appID =", JSON.stringify(appID));
        replyGetEmergencyEvent(handle, dataContainer.vehicleInfoModel.emergencyEvent)
    }

    function getClusterModeStatus(handle, appID) {
        console.log("Received method: VehicleInfo.GetClusterModeStatus");
        console.debug("appID =", JSON.stringify(appID));
        replyGetClusterModeStatus(handle, dataContainer.vehicleInfoModel.clusterModeStatus)
    }

    function getMyKey(handle, appID) {
        console.log("Received method: VehicleInfo.GetMyKey");
        console.debug("appID =", JSON.stringify(appID));
        replyGetMyKey(handle, dataContainer.vehicleInfoModel.myKey)
    }

    function getDTCs(handle, ecuName, dtcMask, appID) {
        console.log("Received method: VehicleInfo.GetDTCs");
        console.debug("ecuName =", JSON.stringify(ecuName));
        console.debug("dtcMask =", JSON.stringify(dtcMask));
        console.debug("appID =", JSON.stringify(appID));

        var ecuHeader = 2
        var dtc = []

        for (var i = 0; i < 3; i++) {
            dtc.push("line" + i)
        }
        replyGetDTCs(handle, ecuHeader, dtc);
    }

    function readDID(handle, ecuName, didLocation, appID) {
        console.log("Received method: VehicleInfo.ReadDID");
        console.debug("ecuName =", JSON.stringify(ecuName));
        console.debug("didLocation =", JSON.stringify(didLocation));
        console.debug("appID =", JSON.stringify(appID));

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
    }

    function subscribeGps(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeGps");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onGpsChanged.disconnect(model.sendGpsChange)
        model.onGpsChanged.connect(model.sendGpsChange)
        replySubscribeGps(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_GPS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS});
    }
    function unsubscribeGps(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeGps");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onGpsChanged.disconnect(model.sendGpsChange)
        replyUnsubscribeGps(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_GPS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS});
    }

    function subscribeSpeed(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeSpeed");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onSpeedChanged.disconnect(model.sendSpeedChange)
        model.onSpeedChanged.connect(model.sendSpeedChange)
        replySubscrcibeSpeed(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_SPEED,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeSpeed(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeSpeed");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onSpeedChanged.disconnect(model.sendSpeedChange)
        replyUnsubscribeSpeed(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_SPEED,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeRpm(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeRpm");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onRpmChanged.disconnect(model.sendRpmChange)
        model.onRpmChanged.connect(model.sendRpmChange)
        replySubscribeRpm(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_RPM,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeRpm(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeRpm");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onRpmChanged.disconnect(model.sendRpmChange)
        replyUnsubscribeRpm(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_RPM,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeFuelLevel(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeFuelLevel");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevelChanged.disconnect(model.sendFuelLevelChange)
        model.onFuelLevelChanged.connect(model.sendFuelLevelChange)
        replySubscribeFuelLevel(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeFuelLevel(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeFuelLevel");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevelChanged.disconnect(model.sendFuelLevelChange)
        replyUnsubscribeFuelLevel(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeFuelLevel_State(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeFuelLevel_State");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevel_StateChanged.disconnect(model.sendFuelLevel_StateChange)
        model.onFuelLevel_StateChanged.connect(model.sendFuelLevel_StateChange)
        replySubscribeFuelLevel_State(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL_STATE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeFuelLevel_State(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeFuelLevel_State");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onFuelLevel_StateChanged.disconnect(model.sendFuelLevel_StateChange)
        replyUnsubscribeFuelLevel_State(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELLEVEL_STATE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeInstantFuelConsumption(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeInstantFuelConsumption");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onInstantFuelConsumptionChanged.disconnect(model.sendInstantFuelConsumptionChange)
        model.onInstantFuelConsumptionChanged.connect(model.sendInstantFuelConsumptionChange)
        replySubscribeInstantFuelConsumption(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELCONSUMPTION,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeInstantFuelConsumption(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeInstantFuelConsumption");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onInstantFuelConsumptionChanged.disconnect(model.sendInstantFuelConsumptionChange)
        replyUnsubscribeInstantFuelConsumption(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_FUELCONSUMPTION,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeExternalTemperature(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeExternalTemperature");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onExternalTemperatureChanged.disconnect(model.sendExternalTemperatureChange)
        model.onExternalTemperatureChanged.connect(model.sendExternalTemperatureChange)
        replySubscribeExternalTemperature(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EXTERNTEMP,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeExternalTemperature(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeExternalTemperature");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onExternalTemperatureChanged.disconnect(model.sendExternalTemperatureChange)
        replyUnsubscribeExternalTemperature(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EXTERNTEMP,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribePrndl(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribePrndl");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onPrndlChanged.disconnect(model.sendPrndlChange)
        model.onPrndlChanged.connect(model.sendPrndlChange)
        replySubscribePrndl(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_PRNDL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribePrndl(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribePrndl");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onPrndlChanged.disconnect(model.sendPrndlChange)
        replyUnsubscribePrndl(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_PRNDL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeVin(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeVin");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onVinChanged.disconnect(model.sendVinChange)
        model.onVinChanged.connect(model.sendVinChange)
        replySubscribeVin(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_VIN,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeVin(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeVin");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onVinChanged.disconnect(model.sendVinChange)
        replyUnsubscribeVin(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_VIN,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeTirePressure(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeTirePressure");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onTirePressureChanged.disconnect(model.sendTirePressureChange)
        model.onTirePressureChanged.connect(model.sendTirePressureChange)
        replySubscribeTirePressure(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_TIREPRESSURE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeTirePressure(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeTirePressure");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onTirePressureChanged.disconnect(model.sendTirePressureChange)
        replyUnsubscribeTirePressure(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_TIREPRESSURE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeOdometer(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeOdometer");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onOdometerChanged.disconnect(model.sendOdometerChange)
        model.onOdometerChanged.connect(model.sendOdometerChange)
        replySubscribeOdometer(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ODOMETER,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeOdometer(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeOdometer");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onOdometerChanged.disconnect(model.sendOdometerChange)
        replyUnsubscribeOdometer(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ODOMETER,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeBeltStatus(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeBeltStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onBeltStatusChanged.disconnect(model.sendBeltStatusChange)
        model.onBeltStatusChanged.connect(model.sendBeltStatusChange)
        replySubscribeBeltStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BELTSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeBeltStatus(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeBeltStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onBeltStatusChanged.disconnect(model.sendBeltStatusChange)
        replyUnsubscribeBeltStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BELTSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeBodyInformation(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeBodyInformation");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onBodyInformationChanged.disconnect(model.sendBodyInformationChange)
        model.onBodyInformationChanged.connect(model.sendBodyInformationChange)
        replySubscribeBodyInformation(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BODYINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeBodyInformation(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeBodyInformation");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onBodyInformationChanged.disconnect(model.sendBodyInformationChange)
        replyUnsubscribeBodyInformation(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BODYINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeDeviceStatus(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeDeviceStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onDeviceStatusChanged.disconnect(model.sendDeviceStatusChange)
        model.onDeviceStatusChanged.connect(model.sendDeviceStatusChange)
        replySubscribeDeviceStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_DEVICESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeDeviceStatus(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeDeviceStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onDeviceStatusChanged.disconnect(model.sendDeviceStatusChange)
        replyUnsubscribeDeviceStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_DEVICESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeDriverBraking(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeDriverBraking");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onDriverBrakingChanged.disconnect(model.sendDriverBrakingChange)
        model.onDriverBrakingChanged.connect(model.sendDriverBrakingChange)
        replyUnsubscribeDriverBraking(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BRAKING,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeDriverBraking(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeDriverBraking");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onDriverBrakingChanged.disconnect(model.sendDriverBrakingChange)
        replyUnsubscribeDriverBraking(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_BRAKING,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeWiperStatus(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeWiperStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onWiperStatusChanged.disconnect(model.sendWiperStatusChange)
        model.onWiperStatusChanged.connect(model.sendWiperStatusChange)
        replySubscribeWiperStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_WIPERSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeWiperStatus(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeWiperStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onWiperStatusChanged.disconnect(model.sendWiperStatusChange)
        replyUnsubscribeWiperStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_WIPERSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeHeadLampStatus(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeHeadLampStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onHeadLampStatusChanged.disconnect(model.sendHeadLampStatusChange)
        model.onHeadLampStatusChanged.connect(model.sendHeadLampStatusChange)
        replySubscribeHeadLampStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_HEADLAMPSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeHeadLampStatus(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeHeadLampStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onHeadLampStatusChanged.disconnect(model.sendHeadLampStatusChange)
        replyUnsubscribeHeadLampStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_HEADLAMPSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeEngineTorque(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeEngineTorque");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onEngineTorqueChanged.disconnect(model.sendEngineTorqueChange)
        model.onEngineTorqueChanged.connect(model.sendEngineTorqueChange)
        replySubscribeEngineTorque(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ENGINETORQUE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeEngineTorque(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeEngineTorque");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onEngineTorqueChanged.disconnect(model.sendEngineTorqueChange)
        replyUnsubscribeEngineTorque(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ENGINETORQUE,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeAccPedalPosition(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeAccPedalPosition");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onAccPedalPositionChanged.disconnect(model.sendAccPedalPositionChange)
        model.onAccPedalPositionChanged.connect(model.sendAccPedalPositionChange)
        replySubscribeAccPedalPosition(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ACCPEDAL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeAccPedalPosition(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeAccPedalPosition");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onAccPedalPositionChanged.disconnect(model.sendAccPedalPositionChange)
        replyUnsubscribeAccPedalPosition(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ACCPEDAL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeSteeringWheelAngle(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeSteeringWheelAngle");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onSteeringWheelAngleChanged.disconnect(model.sendSteeringWheelAngleChange)
        model.onSteeringWheelAngleChanged.connect(model.sendSteeringWheelAngleChange)
        replySubscribeSteeringWheelAngle(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_STEERINGWHEEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeSteeringWheelAngle(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeSteeringWheelAngle");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onSteeringWheelAngleChanged.disconnect(model.sendSteeringWheelAngleChange)
        replyUnsubscribeSteeringWheelAngle(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_STEERINGWHEEL,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeECallInfo(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeECallInfo");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onECallInfoChanged.disconnect(model.sendECallInfoChange)
        model.onECallInfoChanged.connect(model.sendECallInfoChange)
        replySubscribeECallInfo(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ECALLINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeECallInfo(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeECallInfo");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onECallInfoChanged.disconnect(model.sendECallInfoChange)
        replyUnsubscribeECallInfo(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_ECALLINFO,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeAirbagStatus(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeAirbagStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onAirbagStatusChanged.disconnect(model.sendAirbagStatusChange)
        model.onAirbagStatusChanged.connect(model.sendAirbagStatusChange)
        replySubscribeAirbagStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_AIRBAGSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeAirbagStatus(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeAirbagStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onAirbagStatusChanged.disconnect(model.sendAirbagStatusChange)
        replyUnsubscribeAirbagStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_AIRBAGSTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeEmergencyEvent(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeEmergencyEvent");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onEmergencyEventChanged.disconnect(model.sendEmergencyEventChange)
        model.onEmergencyEventChanged.connect(model.sendEmergencyEventChange)
        replySubscribeEmergencyEvent(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EMERGENCYEVENT,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeEmergencyEvent(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeEmergencyEvent");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onEmergencyEventChanged.disconnect(model.sendEmergencyEventChange)
        replyUnsubscribeEmergencyEvent(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_EMERGENCYEVENT,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeClusterModeStatus(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeClusterModeStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onClusterModeStatusChanged.disconnect(model.sendClusterModeStatusChange)
        model.onClusterModeStatusChanged.connect(model.sendClusterModeStatusChange)
        replySubscribeClusterModeStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_CLUSTERMODESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeClusterModeStatus(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeClusterModeStatus");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onClusterModeStatusChanged.disconnect(model.sendClusterModeStatusChange)
        replyUnsubscribeClusterModeStatus(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_CLUSTERMODESTATUS,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function subscribeMyKey(handle, appID) {
        console.log("Received method: VehicleInfo.SubscribeMyKey");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onMyKeyChanged.disconnect(model.sendMyKeyChange)
        model.onMyKeyChanged.connect(model.sendMyKeyChange)
        replySubscribeMyKey(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_MYKEY,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }
    function unsubscribeMyKey(handle, appID) {
        console.log("Received method: VehicleInfo.UnsubscribeMyKey");
        console.debug("appID =", JSON.stringify(appID));
        var model = dataContainer.vehicleInfoModel;
        model.onMyKeyChanged.disconnect(model.sendMyKeyChange)
        replyUnsubscribeMyKey(handle,
            { dataType: Common.VehicleDataType.VEHICLEDATA_MYKEY,
              resultCode: Common.VehicleDataResultCode.VDRC_SUCCESS });
    }

    function diagnosticMessage(handle, targetID, messageLength, messageData, appID) {
        console.log("Received method: VehicleInfo.DiagnosticMessage");
        console.debug("targetID =", JSON.stringify(targetID));
        console.debug("messageLength =", JSON.stringify(messageLength));
        console.debug("messageData =", JSON.stringify(messageData));
        console.debug("appID =", JSON.stringify(appID));
        console.warn("Not implemented");
        // TODO: it's stub, need to implement
        replyDiagnosticMessage(handle, []);
    }
}
