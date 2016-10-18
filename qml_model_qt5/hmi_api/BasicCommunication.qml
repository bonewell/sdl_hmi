/**
 * @file BasicCommunication.qml
 * @brief Implement of interface Basic Communication.
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

import com.ford.sdl.hmi.protocol 1.0
import "../hmi_api/Common.js" as Common
import "../models/Internal.js" as Internal

BasicCommunication
{
    onOnResumeAudioSource: {
        console.log("Received signal: BasicCommunication.OnResumeAudioSource");
        console.debug("appID =", JSON.stringify(appID));
        console.warn("Not implemented");
    }

    onOnSDLPersistenceComplete: {
        console.log("Received signal: BasicCommunication.OnSDLPersistenceComplete");
        console.warn("Not implemented");
    }

    onOnFileRemoved: {
        console.log("Received signal: BasicCommunication.OnFileRemoved");
        console.debug("fileName =", JSON.stringify(fileName));
        console.debug("fileType =", JSON.stringify(fileType));
        console.debug("appID =", JSON.stringify(appID));
        console.warn("Not implemented");
    }

    onOnAppRegistered: {
        console.log("Received signal: BasicCommunicaiont.OnAppRegistered")
        console.debug("application =", JSON.stringify(application));
        console.debug("ttsName =", JSON.stringify(ttsName));
        console.debug("vrSynonyms =", JSON.stringify(vrSynonyms));
        console.debug("resumeVrGrammars =", JSON.stringify(resumeVrGrammars));
        console.debug("priority =", JSON.stringify(priority));

        var appTypeToAdd = 0
        if (application.appType !== undefined) {
            for (var index in application.appType) {
                if (application.appType[index] > 31) {
                    // TODO(KKolodiy): notification don't have response, so that is strange code
                    return { __retCode: Common.Result.GENERIC_ERROR, __message: "Apptype value > 31" }
                }
                appTypeToAdd |= 1 << application.appType[index]
            }
        }

        dataContainer.addApplication({
            appName: application.appName,
            ngnMediaScreenAppName: application.ngnMediaScreenAppName,
            icon: application.icon,
            deviceName: application.deviceInfo.name,
            appId: application.appID,
            hmiDisplayLanguageDesired: application.hmiDisplayLanguageDesired,
            isMediaApplication: application.isMediaApplication,
            appType: appTypeToAdd,
            hmiUIText: { },
            mediaClock: {
                "updateMode": Internal.MediaClockUpdateMode.MCU_COUNTUP,
                "runningMode": Internal.MediaClockRunningMode.MCR_STOPPED,
                "startTime": -1,
                "endTime": -1,
                "startTimeForProgress": -1
            }
        });
    }

    onOnAppUnregistered: {
        console.log("Received signal: BasicCommunication.OnAppUnregistered");
        console.debug("unexpectedDisconnect =", JSON.stringify(unexpectedDisconnect));
        console.debug("appID =", JSON.stringify(appID));
        if ((dataContainer.currentApplication.appId === appID)) {
            if (dataContainer.applicationContext) {
                contentLoader.go("views/ApplicationListView.qml");
            }
            if (contentLoader.viewTransitionStack.filter(function(x) { return x.applicationContext })) {
                contentLoader.reset();
            }
            dataContainer.currentApplication.reset()
        }
        dataContainer.removeApplication(appID);
    }

    onOnSDLClose: {
        console.log("Received signal: BasicCommunication.OnSDLClose");
        console.warn("Not implemented");
    }

    onOnPutFile: {
        console.log("Received signal: BasicCommunication.OnPutFile");
        console.debug("offset =", JSON.stringify(offset));
        console.debug("length =", JSON.stringify(length));
        console.debug("fileSize =", JSON.stringify(fileSize));
        console.debug("FileName =", JSON.stringify(FileName));
        console.debug("syncFileName =", JSON.stringify(syncFileName));
        console.debug("fileType =", JSON.stringify(fileType));
        console.debug("persistentFile =", JSON.stringify(persistentFile));
        console.warn("Not implemented");
    }

    function updateDeviceList(deviceList) {
        console.log("Received method: BasicCommunication.UpdateDeviceList");
        console.debug("deviceList =", JSON.stringify(deviceList));

        deviceList.forEach(function (device) {
            var exist = false;
            for (var i = 0; i < dataContainer.deviceList.count; ++i) {
                exist = device.id === dataContainer.deviceList.get(i).devid;
            }
            if (!exist) {
                dataContainer.deviceList.append({ name: device.name,
                                                  devid: device.id,
                                                  allowed: false})
            }
        });

        for (var i = 0; i < dataContainer.deviceList.count; ++i) {
            var exist = false;
            deviceList.forEach(function (device) {
                exist = exist || dataContainer.deviceList.get(i).devid === device.id;
            });
            if (!exist) {
                dataContainer.deviceList.remove(i);
            }
        }
    }

    function updateAppList(applications) {
        console.log("Received method: BasicCommunication.UpdateAppList");
        console.debug("applications =", JSON.stringify(applications));

        dataContainer.applicationList.clear();
        for(var i = 0; i < applications.length; i++) {
            dataContainer.applicationList.append({
                 appName: applications[i].appName,
                 ngnMediaScreenAppName: applications[i].ngnMediaScreenAppName,
                 icon: applications[i].icon,
                 deviceName: applications[i].deviceInfo.name,
                 appId: applications[i].appID,
                 hmiDisplayLanguageDesired: applications[i].hmiDisplayLanguageDesired,
                 isMediaApplication: applications[i].isMediaApplication,
                 appType: applications[i].appType
            });
        }
    }

    function allowDeviceToConnect(handle, device) {
        console.log("Received method: BasicCommunication.AllowDeviceToConnect");
        console.debug("device =", JSON.stringify(device));
        replyAllowDeviceToConnect(handle, true)
    }

    function mixingAudioSupported(handle) {
        console.log("Received method: BasicCommunication.MixingAudioSupported");
        replyMixingAudioSupported(handle, true)
    }

    function dialNumber(number, appID) {
        console.log("Received method: BasicCommunication.DialNumber");
        console.debug("number =", JSON.stringify(number));
        console.debug("appID =", JSON.stringify(appID));
        console.warn("Not implemented");
    }

    function activateApp(appID, priority, level) {
        console.log("Received method: BasicCommunication.ActivateApp");
        console.debug("appID =", JSON.stringify(appID));
        console.debug("priority =", JSON.stringify(priority));
        console.debug("level =", JSON.stringify(level));
        contentLoader.go("views/SDLPlayerView.qml", appID);
    }

    function policyUpdate(file, timeout, retry) {
        console.log("Received method: BasicCommunication.PolicyUpdate");
        console.debug("file =", JSON.stringify(file));
        console.debug("timeout =", JSON.stringify(timeout));
        console.debug("retry =", JSON.stringify(retry));
        settingsContainer.filePTSnapshot = file;
        settingsContainer.timeoutPTExchange = timeout;
        settingsContainer.retriesPTExchange = retry;
        var service = 7; // service type for Ford specific policy
        sdlSDL.getURLS(service, settingsContainer.startPTExchange);
    }

    function systemRequest(requestType, fileName, appID) {
        console.log("Received method: BasicCommunication.SystemRequest");
        console.debug("requestType =", JSON.stringify(requestType));
        console.debug("fileName =", JSON.stringify(fileName));
        console.debug("appID =", JSON.stringify(appID));

        switch (requestType) {
            case Common.RequestType.PROPRIETARY: {
                settingsContainer.stopPTExchange(fileName);
                break;
            }
            case Common.RequestType.HTTP: {
                if (fileName === "IVSU") {
                    settingsContainer.updateIVSU(appID);
                } else {
                    settingsContainer.decrypt(fileName, appID);
                }
                break;
            }
        }
    }

    function getSystemInfo(handle) {
        console.log("Received method: BasicCommunication.GetSystemInfo");
        console.warn("Not implemented");
        // TODO: it's stub, you need to implement
        replyGetSystemInfo(handle, "1.1.1", 1, "ru");
    }
}
