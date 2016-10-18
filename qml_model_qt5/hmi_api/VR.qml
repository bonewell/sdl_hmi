/**
 * @file VR.qml
 * @brief Implement of interface VR.
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

VR
{
    function isReady(handle) {
        console.log("Received method: VR.IsReady");
        replyIsReady(handle, dataContainer.hmiVRAvailable);
    }

    function addCommand(cmdID, vrCommands, type, grammarID, appID) {
        console.log("Received method: VR.AddCommand");
        console.debug("cmdID =", JSON.stringify(cmdID));
        console.debug("vrCommands =", JSON.stringify(vrCommands));
        console.debug("type =", JSON.stringify(type));
        console.debug("grammarID =", JSON.stringify(grammarID));
        console.debug("appID =", JSON.stringify(appID));

        for (var i = 0; i < vrCommands.length; ++i) {
            if (type === Common.VRCommandType.Command) {
                dataContainer.vrCommands.append({
                                               cmdID: cmdID,
                                               command: vrCommands[i],
                                               appID: appID === undefined ? 0 : appID,
                                               type: type,
                                               grammarID: grammarID,
                                           });
            }
            else {
                dataContainer.choicesVrCommands.append({
                                                   cmdID: cmdID,
                                                   command: vrCommands[i],
                                                   appID: appID === undefined ? 0 : appID,
                                                   type: type,
                                                   grammarID: grammarID,
                                               });
            }
        }
    }

    function deleteCommand(cmdID, type, grammarID, appID) {
        console.log("Received method: VR.DeleteCommand");
        console.debug("cmdID =", JSON.stringify(cmdID));
        console.debug("type =", JSON.stringify(type));
        console.debug("grammarID =", JSON.stringify(grammarID));
        console.debug("appID =", JSON.stringify(appID));

        for (var i = 0; i < dataContainer.vrCommands.count; ) {
            if ((dataContainer.vrCommands.get(i).cmdID === cmdID) &&
                    ((appID === undefined) || (dataContainer.vrCommands.get(i).appID === appID))) {
                dataContainer.vrCommands.remove(i);
                continue;
            }
            ++i;
        }
    }

    function getLanguage(handle) {
        console.log("Received method: VR.GetLanguage");
        replyGetLanguage(handle, dataContainer.hmiTTSVRLanguage);
    }

    function getSupportedLanguages(handle) {
        console.log("Received method: VR.GetSupportedLanguages");
        replyGetSupportedLanguages(handle, settingsContainer.sdlLanguagesList);
    }

    function getCapabilities(handle) {
        console.log("Received method: UI.GetCapabilities");
        replyGetCapabilities(handle, [ Common.VrCapabilities.VR_TEXT ]);
    }

    function changeRegistration(vrSynonyms, language, appID) {
        console.log("Received method: VR.ChangeRegistration");
        console.debug("vrSynonyms =", JSON.stringify(vrSynonyms));
        console.debug("language =", JSON.stringify(language));
        console.debug("appID =", JSON.stringify(appID));
        dataContainer.changeRegistrationTTSVR(language, appID);
    }

    function ttsChunksToString(ttsChunks){
        return ttsChunks.map(function(str) { return str.text }).join('\n')
    }

    function performInteraction(helpPrompt, initialPrompt, timeoutPrompt,
        timeout, grammarID, appID) {
        console.log("Received method: TTS.PerformInteraction");
        console.debug("helpPrompt =", JSON.stringify(helpPrompt));
        console.debug("initialPrompt =", JSON.stringify(initialPrompt));
        console.debug("timeoutPrompt =", JSON.stringify(timeoutPrompt));
        console.debug("timeout =", JSON.stringify(timeout));
        console.debug("grammarID =", JSON.stringify(grammarID));
        console.debug("appID =", JSON.stringify(appID));

        ttsPopUp.performInteraction(ttsChunksToString(helpPrompt),
                                    ttsChunksToString(initialPrompt),
                                    ttsChunksToString(timeoutPrompt),
                                    timeout)
        interactionPopup.grammarID = grammarID
    }
}
