/**
 * @file Navigation.qml
 * @brief Navigation.
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
import "Common.js" as Common

Navigation
{
    onOnAudioDataStreaming: {
        console.log("Received signal: Navigation.OnAudioDataStreaming")
        console.log("available =", JSON.stringify(available));
        console.warn("Not implemented");
    }

    onOnVideoDataStreaming: {
        console.log("Received signal: Navigation.OnVideoDataStreaming")
        console.log("available =", JSON.stringify(available));
        console.warn("Not implemented");
    }

    function isReady(handle) {
        console.log("Received method: Navigation.IsReady")
        replyIsReady(handle, dataContainer.hmiNavigationAvailable)
    }

    function sendLocation(appID, longitudeDegrees, latitudeDegrees, locationName,
        locationDescription, addressLines, phoneNumber, locationImage, timeStamp, address) {
        console.log("Received method: Navigation.SendLocation");
        console.log("appID =", JSON.stringify(appID));
        console.log("longitudeDegrees =", JSON.stringify(longitudeDegrees));
        console.log("latitudeDegrees =", JSON.stringify(latitudeDegrees));
        console.log("locationName =", JSON.stringify(locationName));
        console.log("locationDescription =", JSON.stringify(locationDescription));
        console.log("addressLines =", JSON.stringify(addressLines));
        console.log("phoneNumber =", JSON.stringify(phoneNumber));
        console.log("locationImage =", JSON.stringify(locationImage));
        console.log("timeStamp =", JSON.stringify(timeStamp));
        console.log("address =", JSON.stringify(address));
        console.warn("Not implemented");
    }

    function showConstantTBT(handle, navigationTexts, turnIcon, nextTurnIcon,
        distanceToManeuver, distanceToManeuverScale, maneuverComplete,
        softButtons, appID) {
        console.log("Received method: Navigation.ShowConstantTBT");
        console.debug("navigationTexts =", JSON.stringify(navigationTexts));
        console.debug("turnIcon =", JSON.stringify(turnIcon));
        console.debug("nextTurnIcon =", JSON.stringify(nextTurnIcon));
        console.debug("distanceToManeuver =", JSON.stringify(distanceToManeuver));
        console.debug("distanceToManeuverScale =", JSON.stringify(distanceToManeuverScale));
        console.debug("maneuverComplete =", JSON.stringify(maneuverComplete));
        console.debug("softButtons =", JSON.stringify(softButtons));
        console.debug("appID =", JSON.stringify(appID));

        var app = dataContainer.getApplication(appID)
        var dataToUpdate = {}

        navigationTexts.forEach(fillTexts, dataToUpdate)
        if (turnIcon !== undefined) { dataToUpdate.turnIcon = turnIcon }
        if (nextTurnIcon !== undefined) { dataToUpdate.nextTurnIcon = nextTurnIcon }
        if (distanceToManeuver !== undefined) {
            dataToUpdate.distanceToManeuver = distanceToManeuver
        } else {
            handle.code = Common.Result.INVALID_DATA;
            handle.message = "distanceToManeuver absence";
            sendResult(handle);
            return;
        }
        if (distanceToManeuverScale !== undefined) {
            dataToUpdate.distanceToManeuverScale = distanceToManeuverScale
        } else {
            handle.code = Common.Result.INVALID_DATA;
            handle.message = "distanceToManeuverScale absence";
            sendResult(handle);
            return;
        }
        if (maneuverComplete !== undefined) {
            dataToUpdate.maneuverComplete = maneuverComplete
        }
        if (softButtons !== undefined) {
            app.navigationSoftButtons.clear()
            softButtons.forEach(function(x) { app.navigationSoftButtons.append(x); });
        }
        if (appID !== undefined) {
            dataToUpdate.appID = appID
        } else {
            handle.code = Common.Result.INVALID_DATA;
            handle.message = "appID absence";
            sendResult(handle);
            return;
        }

        dataContainer.setApplicationProperties(appID, { navigationModel : dataToUpdate } )
        sendResult(handle);
        contentLoader.go("./views/TurnByTurnView.qml", appID)
    }

    function alertManeuver(softButtons, appID) {
        console.log("Received method: Navigation.AlertManeuver");
        console.debug("softButtons =", JSON.stringify(softButtons));
        console.debug("appID =", JSON.stringify(appID));
        console.warn("Not implemented");
    }

    function updateTurnList(turnList, softButtons, appID) {
        console.log("Received method: Navigation.UpdateTurnList");
        console.debug("turnList =", JSON.stringify(turnList));
        console.debug("softButtons =", JSON.stringify(softButtons));
        console.debug("appID =", JSON.stringify(appID));

        if (turnList !== undefined) {
            dataContainer.getApplication(appID).turnList.clear();
            turnList.forEach(fillTurnList, dataContainer.getApplication(appID).turnList);
        }
        if (softButtons !== undefined) {
            dataContainer.getApplication(appID).turnListSoftButtons.clear();
            softButtons.forEach(fillSoftButtons, dataContainer.getApplication(appID).turnListSoftButtons);
        }
        dataContainer.navigationModel.appId = appID;
    }

    function fillTexts(element, index, array) {
        switch (element.fieldName) {
        case Common.TextFieldName.navigationText1:
            this.text1 = element.fieldText;
            break;
        case Common.TextFieldName.navigationText2:
            this.text2 = element.fieldText;
            break;
        case Common.TextFieldName.ETA:
            this.eta = element.fieldText;
            break;
        case Common.TextFieldName.totalDistance:
            this.totalDistance = element.fieldText;
            break;
        case Common.TextFieldName.timeToDestination:
            this.timeToDestination = element.fieldText;
            break;
        }
    }

    function startStream(url, appID) {
        console.log("Received method: Navigation.StartStream");
        console.debug("url =", JSON.stringify(url));
        console.debug("appID =", JSON.stringify(appID));
        player.startStream(url)
    }

    function stopStream(appID) {
        console.log("Received method: Navigation.StopStream");
        console.debug("appID =", JSON.stringify(appID));
        player.stop()
    }

    function startAudioStream(url, appID) {
        console.log("Received method: Navigation.StartAudioStream");
        console.debug("url =", JSON.stringify(url));
        console.debug("appID =", JSON.stringify(appID));
        stream.source = url;
        stream.play();
    }

    function stopAudioStream(appID) {
        console.log("Received method: Navigation.StopAudioStream");
        console.debug("appID =", JSON.stringify(appID));
        stream.stop();
    }

    function fillSoftButtons(element, index, array) {
        this.append({
                        type: element.type,
                        text: element.text,
                        image: element.image,
                        isHighlighted: element.isHighlighted,
                        buttonId: element.softButtonID,
                        systemAction: element.systemAction
                    });
    }

    function fillTurnList(element, index, array) {
        this.append({                        
                        navigationText: element.navigationText,
                        turnIcon: element.turnIcon
                    });
    }

    function getWayPoints(handle, wayPointType) {
        console.log("Received method: Navigation.GetWayPoints");
        console.debug("wayPointType=", JSON.stringify(wayPointType));
        console.warn("Not implemented");
        // TODO: it's stub, you need to implement
        replyGetWayPoints(handle, []);
    }

    function subscribeWayPoints() {
        console.log("Received method: Navigation.SubscribeWayPoints");
        console.warn("Not implemented");
    }

    function unsubscribeWayPoints() {
        console.log("Received method: Navigation.UnsubscribeWayPoints");
        console.warn("Not implemented");
    }
}
