/**
 * @file UI.qml
 * @brief UI interface implementation.
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
import "../models/Internal.js" as Internal

UI
{
    onOnRecordStart: {
        console.log("Received signal: UI.OnRecordStart");
        console.debug("appID =", JSON.stringify(appID));
        console.warn("Not implemented");
    }

    function filter (strings, fields) {
        console.debug("enter")
// substrings for each allowed field
        var fieldSubstrings = {}
// this cycle concatenates allowed lines sorting them by field
        for (var stringIndex = 0; stringIndex < strings.length; ++stringIndex) {
            for (var fieldIndex = 0; fieldIndex < fields.length; ++fieldIndex) {
                var fieldName = strings[stringIndex].fieldName
                if (fieldName === fields[fieldIndex]) {
                    if (fieldSubstrings[fieldName] !== undefined) {
                        fieldSubstrings[fieldName] += "\n";
                        fieldSubstrings[fieldName] += strings[stringIndex].fieldText
                    }
                    else {
                        fieldSubstrings[fieldName] = strings[stringIndex].fieldText
                    }
                }
            }
        }
        console.debug("exit")
        return fieldSubstrings
    }

    function alert(handle, alertStrings, duration, softButtons, progressIndicator,
        alertType, appID) {
        console.log("Received method: UI.Alert");
        console.debug("alertStrings =", JSON.stringify(alertStrings));
        console.debug("duration =", JSON.stringify(duration));
        console.debug("softButtons =", JSON.stringify(softButtons));
        console.debug("progressIndicator =", JSON.stringify(progressIndicator));
        console.debug("alertType =", JSON.stringify(alertType));
        console.debug("appID =", JSON.stringify(appID));

        var fieldSubstrings = alertStrings
            .sort(function(a, b) { return a.fieldName - b.fieldName }) // sorting by fieldName
            .map(function(val) { return val.fieldText });              // mapping to array of strings

        var tryAgainTime = alertWindow.alert(fieldSubstrings, duration, softButtons, progressIndicator, alertType, appID)
        if (tryAgainTime === undefined) {
            alertWindow.async = handle;
        } else {
            handle.code = Common.Result.REJECTED;
            replyAlert(handle, tryAgainTime);
        }
    }

    function show(showStrings, alignment, graphic, secondaryGraphic,
        softButtons, customPresets, appID) {
        console.log("Received method: UI.Show");
        console.debug( "showStrings =", JSON.stringify(showStrings));
        console.debug("alignment =", JSON.stringify(alignment));
        console.debug("graphic = ", JSON.stringify(graphic));
        console.debug("secondaryGraphic =", JSON.stringify(secondaryGraphic));
        console.debug("softButtons =", JSON.stringify(softButtons));
        console.debug("customPresets =", JSON.stringify(customPresets));
        console.debug("appID =", JSON.stringify(appID));

        var app = dataContainer.getApplication(appID);

        if (app.softButtons) {
            app.softButtons.clear();
        }
        if (softButtons) {
            softButtons.forEach(function(x) { app.softButtons.append(x); });
        }

        app.customPresets.clear()
        if (customPresets) {
            customPresets.forEach( function(x) { app.customPresets.append( {text: x} ); } )
        }

        var textAlignment
        switch (alignment) {
            case Common.TextAlignment.LEFT_ALIGNED:
                textAlignment = Text.AlignLeft
                break;
            case Common.TextAlignment.RIGHT_ALIGNED:
                textAlignment = Text.AlignRight
                break;
            case Common.TextAlignment.CENTERED:
                textAlignment = Text.AlignHCenter
                break;
            default:
                textAlignment = Text.AlignHCenter
                break;
        }

        // with this array we grab only the lines we need
        var showFields = [
            Common.TextFieldName.mainField1,
            Common.TextFieldName.mainField2,
            Common.TextFieldName.mainField3,
            Common.TextFieldName.mainField4,
            Common.TextFieldName.statusBar,
            Common.TextFieldName.mediaClock,
            Common.TextFieldName.mediaTrack
        ]
        var fieldSubstrings = filter(showStrings, showFields)
        var showData = { hmiUIText: {} }
        if (fieldSubstrings[Common.TextFieldName.mainField1] !== undefined) { showData.hmiUIText.mainField1 = fieldSubstrings[Common.TextFieldName.mainField1]; }
        if (fieldSubstrings[Common.TextFieldName.mainField2] !== undefined) { showData.hmiUIText.mainField2 = fieldSubstrings[Common.TextFieldName.mainField2]; }
        if (fieldSubstrings[Common.TextFieldName.mainField3] !== undefined) { showData.hmiUIText.mainField3 = fieldSubstrings[Common.TextFieldName.mainField3]; }
        if (fieldSubstrings[Common.TextFieldName.mainField4] !== undefined) { showData.hmiUIText.mainField4 = fieldSubstrings[Common.TextFieldName.mainField4]; }
        if (fieldSubstrings[Common.TextFieldName.statusBar] !== undefined) { showData.hmiUIText.statusBar = fieldSubstrings[Common.TextFieldName.statusBar]; }
        if (fieldSubstrings[Common.TextFieldName.mediaTrack] !== undefined) { showData.hmiUIText.mediaTrack = fieldSubstrings[Common.TextFieldName.mediaTrack]; }
        if (graphic) { showData.hmiUIText.image = graphic.value; }
        if (secondaryGraphic) { showData.hmiUIText.secondaryImage = secondaryGraphic.value; }
        if (textAlignment) { showData.hmiUITextAlignment = textAlignment; }
        if (fieldSubstrings[Common.TextFieldName.mediaClock]) {
            showData.mediaClock = {
                "updateMode": Internal.MediaClockUpdateMode.MCU_COUNTUP,
                "runningMode": Internal.MediaClockRunningMode.MCR_STOPPED,
                "magic": Internal.stringToHmsTime(fieldSubstrings[Common.TextFieldName.mediaClock]),
                "startTime": Internal.stringToHmsTime(fieldSubstrings[Common.TextFieldName.mediaClock]),
                "startTimeForProgress": -1
            }
        }

        dataContainer.setApplicationProperties(appID, showData);
    }

    function addCommand(cmdID, menuParams, cmdIcon, appID) {
        console.log("Received method: UI.AddCommand");
        console.debug("cmdID =", JSON.stringify(cmdID));
        console.debug("menuParams =", JSON.stringify(menuParams));
        console.debug("cmdIcon =", JSON.stringify(cmdIcon));
        console.debug("appID =", JSON.stringify(appID));
        dataContainer.addCommand(cmdID, menuParams, cmdIcon, appID)
    }

    function deleteCommand(cmdID, appID) {
        console.log("Received method: UI.DeleteCommand");
        console.debug("cmdID =", JSON.stringify(cmdID));
        console.debug("appID =", JSON.stringify(appID));
        dataContainer.deleteCommand(cmdID, appID)
    }

    function addSubMenu(menuID, menuParams, appID) {
        console.log("Received method: UI.AddSubMenu");
        console.debug("menuID =", JSON.stringify(menuID));
        console.debug("menuParams =", JSON.stringify(menuParams));
        console.debug("appID =", JSON.stringify(appID));
        dataContainer.addSubMenu(menuID, menuParams, appID)
    }

    function deleteSubMenu(menuID, appID) {
        console.log("Received method: UI.DeleteSubMenu");
        console.debug("menuID =", JSON.stringify(menuID));
        console.debug("appID =", JSON.stringify(appID));
        dataContainer.deleteSubMenu(menuID, appID)
    }

    function performInteraction(handle, initialText, choiceSet, vrHelpTitle, vrHelp,
        timeout, interactionLayout, appID) {
        console.log("Received method: UI.PerformInteraction");
        console.debug("appID:", JSON.stringify(appID));
        console.debug("initialText =", JSON.stringify(initialText));
        console.debug("choiceSet =", JSON.stringify(choiceSet));
        console.debug("vrHelpTitle: '", JSON.stringify(vrHelpTitle));
        console.debug("vrHelp =", JSON.stringify(vrHelp));
        console.debug("timeout =", JSON.stringify(timeout));
        console.debug("interactionLayout =", JSON.stringify(interactionLayout));

        interactionPopup.async = handle;
        interactionPopup.performInteraction(initialText, choiceSet, vrHelpTitle,
                                            vrHelp, timeout, interactionLayout, appID);
    }

    function setMediaClockTimer(handle, startTime, endTime, updateMode, appID) {
        console.log("Received method: UI.SetMediaClockTimer");
        console.debug("startTime =", JSON.stringify(startTime));
        console.debug("endTime =", JSON.stringify(endTime));
        console.debug("updateMode =", JSON.stringify(updateMode));
        console.debug("appID =", JSON.stringify(appID));

        var app = dataContainer.getApplication(appID)
        var newStartTime
        var newEndTime
        var newUpdateMode
        var newRunningMode
        var newStartTimeForProgress
        var resultCode
        var sendErrorResponce = false

        switch (updateMode) {
            case Common.ClockUpdateMode.COUNTUP:
                if (startTime === undefined) {
                    resultCode = Common.Result.INVALID_DATA
                    sendErrorResponce = true
                    break
                }
                newStartTime = Internal.hmsTime(startTime.hours, startTime.minutes, startTime.seconds)
                newEndTime = endTime ? Internal.hmsTime(endTime.hours,
                                                        endTime.minutes,
                                                        endTime.seconds)
                          : dataContainer.currentApplication.mediaClock.upperTimeLimit

                newUpdateMode = Internal.MediaClockUpdateMode.MCU_COUNTUP
                newRunningMode = Internal.MediaClockRunningMode.MCR_RUNNING
                newStartTimeForProgress = Internal.hmsTime(startTime.hours, startTime.minutes, startTime.seconds)
                resultCode = Common.Result.SUCCESS
                break

            case Common.ClockUpdateMode.COUNTDOWN:
                if (startTime === undefined) {
                    resultCode = Common.Result.INVALID_DATA
                    sendErrorResponce = true
                    break
                }
                newStartTime = Internal.hmsTime(startTime.hours, startTime.minutes, startTime.seconds)
                newEndTime = endTime ? Internal.hmsTime(endTime.hours, endTime.minutes, endTime.seconds) : 0
                newUpdateMode = Internal.MediaClockUpdateMode.MCU_COUNTDOWN
                newRunningMode = Internal.MediaClockRunningMode.MCR_RUNNING
                newStartTimeForProgress = Internal.hmsTime(startTime.hours, startTime.minutes, startTime.seconds)
                resultCode = Common.Result.SUCCESS
                break

            case Common.ClockUpdateMode.PAUSE:
                // Already paused or cleared
                if ((app.mediaClock.runningMode === Internal.MediaClockRunningMode.MCR_STOPPED)
                        || (app.mediaClock.startTime === -1 && app.mediaClock.endTime === -1)) {
                    resultCode = Common.Result.IGNORED
                    sendErrorResponce = true
                    break
                }
                newStartTime = app.mediaClock.startTime
                newEndTime = app.mediaClock.endTime
                newRunningMode = Internal.MediaClockRunningMode.MCR_STOPPED
                newUpdateMode = app.mediaClock.updateMode
                newStartTimeForProgress = app.mediaClock.startTimeForProgress
                resultCode = Common.Result.SUCCESS
                break

            case Common.ClockUpdateMode.RESUME:
                // Already resumed or cleared
                if ((app.mediaClock.runningMode === Internal.MediaClockRunningMode.MCR_RUNNING)
                        || (app.mediaClock.startTime === app.mediaClock.endTime)) {
                    resultCode = Common.Result.IGNORED
                    sendErrorResponce = true
                    break
                }
                newStartTime = app.mediaClock.startTime
                newEndTime = app.mediaClock.endTime
                newRunningMode = Internal.MediaClockRunningMode.MCR_RUNNING
                newStartTimeForProgress = app.mediaClock.startTimeForProgress
                newUpdateMode = app.mediaClock.updateMode
                resultCode = Common.Result.SUCCESS
                break

            case Common.ClockUpdateMode.CLEAR:
                newStartTime = -1
                newEndTime = -1
                newRunningMode = Internal.MediaClockRunningMode.MCR_STOPPED
                newUpdateMode = app.mediaClock.updateMode
                newStartTimeForProgress = -1
                resultCode = Common.Result.SUCCESS
                break
        }

        if (sendErrorResponce) {
            console.debug("exit with result code: ", resultCode)
            handle.code = resultCode;
            reply(handle);
            return;
        }

        dataContainer.setApplicationProperties(appID, {
            "mediaClock": {
                "updateMode": newUpdateMode,
                "runningMode": newRunningMode,
                "startTime": newStartTime,
                "endTime": newEndTime,
                "startTimeForProgress": newStartTimeForProgress
            }
        })

        handle.code = resultCode;
        reply(handle);
    }

    function setGlobalProperties (vrHelpTitle, vrHelp, menuTitle, menuIcon,
        keyboardProperties, appID) {
        console.log("Received method: UI.SetGlobalProperties");
        console.debug("vrHelpTitle =", JSON.stringify(vrHelpTitle));
        console.debug("vrHelp =", JSON.stringify(vrHelp));
        console.debug("menuTitle =", JSON.stringify(menuTitle));
        console.debug("menuIcon =", JSON.stringify(menuIcon));
        console.debug("keyboardProperties =", JSON.stringify(keyboardProperties));
        console.debug("appID =", JSON.stringify(appID));

        var app = dataContainer.getApplication(appID)
        var dataToUpdate = {}

        if (vrHelpTitle !== undefined) {
            dataToUpdate.vrHelpTitle = vrHelpTitle
        } else if ( (vrHelp !== undefined) && (vrHelp.length >= 1) ) {
            return { __retCode: Common.Result.REJECTED, __message: "vrHelpTitle - undefined, vrHelpItem - provided" }
        }

        if (vrHelp !== undefined) {
            var checkSequentialPosition = vrHelp[0].position
            for (var index = 0; index < vrHelp.length; index++) {
                if (vrHelp[index].position !== checkSequentialPosition) {
                    return { __retCode: Common.Result.REJECTED, __message: "Nonsequential positions of VrHelpItems" }
                }
                checkSequentialPosition++
            }

            if (app.vrHelpItems.count !== 0) {
                app.vrHelpItems.clear()
            }
            vrHelp.forEach( Internal.appendVrHelpItem, app.vrHelpItems )
        } else {
            if (vrHelpTitle !== undefined) {
                return { __retCode: Common.Result.REJECTED, __message: "vrHelpItems - undefined, vrHelpTitle - provided" }
            }
        }
        if (menuTitle !== undefined) {
            dataToUpdate.menuTitle = menuTitle
        }
        if (menuIcon !== undefined) {
            dataToUpdate.menuIcon = menuIcon
        }
        dataContainer.setApplicationProperties(appID, dataToUpdate)
    }

    function isReady(handle) {
        console.log("Received method: UI.IsReady");
        replyIsReady(handle, dataContainer.hmiUIAvailable);
    }

    function getLanguage(handle) {
        console.log("Received method: UI.GetLanguage");
        replyGetLanguage(handle, dataContainer.hmiUILanguage);
    }

    function getSupportedLanguages(handle) {
        console.log("Received method: UI.GetSupportedLanguages");
        replyGetSupportedLanguages(handle, settingsContainer.sdlLanguagesList);
    }

    function changeRegistration(appName, ngnMediaScreenAppName, language,
        appHMIType, appID) {
        console.log("Received method: UI.ChangeRegistration");
        console.debug("appName =", JSON.stringify(appName));
        console.debug("ngnMediaScreenAppName =", JSON.stringify(ngnMediaScreenAppName));
        console.debug("language =", JSON.stringify(language));
        console.debug("appID =", JSON.stringify(appID));
        dataContainer.changeRegistrationUI(language, appID)
    }

    function setAppIcon(syncFileName, appID) {
        console.log("Received method: UI.SetAppIcon");
        console.debug("syncFileName =", JSON.stringify(syncFileName));
        console.debug("appID =", JSON.stringify(appID));
        dataContainer.setApplicationProperties(appID, { icon: syncFileName.value })
    }

    function slider(handle, numTicks, position, sliderHeader, sliderFooter, timeout, appID) {
        console.log("Received method: UI.Slider");
        console.debug("numTicks =", JSON.stringify(numTicks));
        console.debug("position =", JSON.stringify(position));
        console.debug("sliderHeader =", JSON.stringify(sliderHeader));
        console.debug("sliderFooter =", JSON.stringify(sliderFooter));
        console.debug("timeout =", JSON.stringify(timeout));
        console.debug("appID =", JSON.stringify(appID));

        if (dataContainer.uiSlider.running) {
            console.debug("aborted")
            handle.code = Common.Result.ABORTED;
            replySlider(handle, position);
            return;
        }

        dataContainer.uiSlider.appName = dataContainer.getApplication(appID).appName
        dataContainer.uiSlider.header = sliderHeader
        dataContainer.uiSlider.footer = sliderFooter
        dataContainer.uiSlider.numTicks = numTicks
        dataContainer.uiSlider.position = position
        dataContainer.uiSlider.timeout = timeout

        if (timeout !== 0) {
            sliderPopup.showSlider()
            sliderPopup.async = handle;
        } else {
            replySlider(handle, position);
        }
    }

    function scrollableMessage(handle, messageText, timeout, softButtons, appID) {
        console.log("Received method: UI.ScrollableMessage");
        console.debug("messageText =", JSON.stringify(messageText));
        console.debug("timeout =", JSON.stringify(timeout));
        console.debug("softButtons =", JSON.stringify(softButtons));
        console.debug("appID =", JSON.stringify(appID));

        // TODO{ALeshin}: Also check HMILevel, when it will be available. It should be FULL otherwise - REJECTED
        if (contentLoader.item.systemContext !== Common.SystemContext.SYSCTXT_MAIN) {
            handle.code = Common.Result.REJECTED;
            handle.message = "System Context isn't MAIN";
            reply(handle);
            return;
        }
        if(dataContainer.scrollableMessageModel.running){
            //send error response if scrollable message already running
            handle.code = Common.Result.ABORTED;
            handle.message = "ScrollableMessage already running";
            reply(handle);
            return;
        }

        dataContainer.scrollableMessageModel.longMessageText = messageText.fieldText
        if (timeout === 0) {
            handle.message = "Timeout = 0";
            reply(handle);
            return;
        } else {
            dataContainer.scrollableMessageModel.timeout = timeout
        }

        dataContainer.scrollableMessageModel.softButtons.clear();
        if (softButtons !== undefined) {
            softButtons.forEach(fillSoftButtons, dataContainer.scrollableMessageModel.softButtons);
        }
        dataContainer.scrollableMessageModel.appId = appID
        dataContainer.scrollableMessageModel.async = handle
        contentLoader.go("./views/ScrollableMessageView.qml")
    }

    function getCapabilities(handle) {
        console.log("Received method: UI.GetCapabilities");
        replyGetCapabilities(handle, settingsContainer.displayCapabilities,
            {
                "samplingRate": Common.SamplingRate.RATE_44KHZ,
                "bitsPerSample": Common.BitsPerSample.RATE_8_BIT,
                "audioType": Common.AudioType.PCM
            },
            Common.HmiZoneCapabilities.FRONT,
            settingsContainer.softButtonCapabilities
        );
    }

    function performAudioPassThru(handle, appID, audioPassThruDisplayTexts, timeout) {
        console.log("Received method: UI.PerformAudioPassThru");
        console.debug("appID =", JSON.stringify(appID));
        console.debug("audioPassThruDisplayTexts =", JSON.stringify(displayTexts));
        console.debug("timeout =", JSON.stringify(timeout));

        if (dataContainer.uiAudioPassThru.running) {
            console.debug("aborted")
            fail(handle, Common.Result.ABORTED);
            return;
        }

        dataContainer.uiAudioPassThru.appName = dataContainer.getApplication(appID).appName
        dataContainer.uiAudioPassThru.timeout = timeout
        if (audioPassThruDisplayTexts.length === 2) {
            dataContainer.uiAudioPassThru.firstLine = audioPassThruDisplayTexts[0].fieldText
            dataContainer.uiAudioPassThru.secondLine = audioPassThruDisplayTexts[1].fieldText
        }
        performAudioPassThruPopup.async = handle;
        performAudioPassThruPopup.showAudioPassThru()
    }

    function endAudioPassThru(handle) {
        console.log("Received method: UI.EndAudioPassThru");

        if (!dataContainer.uiAudioPassThru.running) {
            console.debug("rejected")
            fail(handle, Common.Result.REJECTED);
            return;
        }
        performAudioPassThruPopup.complete(Common.Result.SUCCESS)
        reply(handle);
    }

    function closePopUp(handle, methodName) {
        console.log("Received method: UI.ClosePopUp");
        console.debug("methodName =", JSON.stringify(methodName));

        var popUpToClose

        if (dataContainer.activePopup.length === 0) {
            handle.code = Common.Result.ABORT;
            handle.message = "No active PopUps";
            reply(handle);
            return;
        }

        if (methodName !== undefined) {
            popUpToClose = methodName
        } else {
            popUpToClose = dataContainer.activePopup[dataContain.activePopUp.length - 1]
        }

        switch (popUpToClose) {
            case "UI.PerformInteraction":
                interactionPopup.complete(Common.Result.SUCCESS)
                break
            case "UI.Slider":
                sliderPopup.complete(Common.Result.SUCCESS)
                break
            case "UI.PerformAudioPassThru":
                performAudioPassThruPopup.complete(Common.Result.SUCCESS)
                break
            case "UI.Alert":
                alertWindow.complete(Common.Result.SUCCESS)
                break
            case "UI.VrHelp":
                vrHelpPopup.complete(Common.Result.SUCCESS)
                break
        }
    }

    function fillSoftButtons(element, index, array) {
        this.append({
                        type: element.type,
                        text: element.text,
                        image: element.image,
                        isHighlighted: element.isHighlighted,
                        softButtonID: element.softButtonID,
                        systemAction: element.systemAction
                    });
    }

    function setDisplayLayout(displayLayout, appID) {
        console.log("Received method: UI.SetDisplayLayout");
        console.debug("displayLayout =", JSON.stringify(displayLayout));
        console.warn("Not implemented");
    }

    function showCustomForm(handle, customFormID, parentFormID) {
        console.log("Received method: UI.ShowCustomForm");
        console.debug("customFormID =", JSON.stringify(customFormID));
        console.debug("parentFormID =", JSON.stringify(parentFormID));
        console.warn("Not implemented");
        // TODO: it's stub. Need to implement
        replyShowCustomForm(handle, "info");
    }
}
