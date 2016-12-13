/**
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

TTS
{
    function ttsChunksToString(ttsChunks){
        return ttsChunks.map(function(str) { return str.text }).join('\n')
    }

    function isReady(handle) {
        console.log("Received method: TTS.IsReady");
        replyIsReady(handle, dataContainer.hmiTTSAvailable);
    }

    function speak(handle, ttsChunks, appID, speakType, playTone) {
        console.log("Received method: TTS.Speak");
        console.debug("ttsChunks =", JSON.stringify(ttsChunks));
        console.debug("appID =", JSON.stringify(appID));
        console.debug("speakType =", JSON.stringify(speakType));
        console.debug("playTone =", JSON.stringify(playTone));

        if (ttsPopUp.async) {
            console.warn('speak send abort');
            fail(handle, Common.Result.ABORTED);
        }
        var message = ttsChunksToString(ttsChunks);
        ttsPopUp.activate(message);
        ttsPopUp.async = handle;
    }

    function stopSpeaking() {
        console.log("Received method: TTS.StopSpeaking");
        ttsPopUp.deactivate();
    }

    function getLanguage(handle) {
        console.log("Received method: TTS.GetLanguage");
        replyGetLanguage(handle, dataContainer.hmiTTSVRLanguage);
    }

    function getSupportedLanguages(handle) {
        console.log("Received method: TTS.GetSupportedLanguages");
        replyGetSupportedLanguages(handle, settingsContainer.sdlLanguagesList);
    }

    function getCapabilities(handle) {
        console.log("Received method: TTS.GetCapabilities");
        replyGetCapabilities(handle,
            [
                Common.SpeechCapabilities.SC_TEXT,
                Common.SpeechCapabilities.PRE_RECORDED
            ],
            [
                Common.PrerecordedSpeech.HELP_JINGLE,
                Common.PrerecordedSpeech.INITIAL_JINGLE,
                Common.PrerecordedSpeech.LISTEN_JINGLE,
                Common.PrerecordedSpeech.POSITIVE_JINGLE,
                Common.PrerecordedSpeech.NEGATIVE_JINGLE
            ]
        )
    }

    function performInteraction(helpPrompt, initialPrompt, timeoutPrompt, timeout) {
        console.log("Received method: TTS.PerformInteraction");
        console.debug("helpPrompt =", JSON.stringify(helpttsChunks));
        console.debug("initialPrompt =", JSON.stringify(initialPrompt));
        console.debug("timeoutPrompt =", JSON.stringify(timeoutPrompt));
        console.debug("timeout =", JSON.stringify(timeout));

        ttsPopUp.performInteraction(ttsChunksToString(helpPrompt),
                                    ttsChunksToString(initialPrompt),
                                    ttsChunksToString(timeoutPrompt),
                                    timeout)
    }

    function changeRegistration(ttsName, language, appID) {
        console.log("Received method: TTS.ChangeRegistration");
        console.debug("ttsName =", JSON.stringify(ttsName));
        console.debug("language =", JSON.stringify(language));
        console.debug("appID =", JSON.stringify(appID));

        dataContainer.changeRegistrationTTSVR(language, appID);
    }

    function setGlobalProperties(helpPrompt, timeoutPrompt, appID) {
        console.log("Received method: TTS.SetGlobalProperties");
        console.debug("helpPrompt =", JSON.stringify(helpPrompt));
        console.debug("timeoutPrompt =", JSON.stringify(timeoutPrompt));
        console.debug("appID =", JSON.stringify(appID));

        var newHelpPropmt = helpPrompt ?
                    helpPrompt.map(
                        function (structure) {
                            return structure.text
                        }
                     ).join(", ") :
                    dataContainer.currentApplication.helpPrompt

        var newTimeoutPrompt = timeoutPrompt ?
                    timeoutPrompt.map(
                        function (structure) {
                            return structure.text
                        }
                     ).join(", ") :
                    dataContainer.currentApplication.timeoutPrompt

        dataContainer.setApplicationProperties(dataContainer.currentApplication.appId, {
                                                   helpPrompt: newHelpPropmt,
                                                   timeoutPrompt: newTimeoutPrompt
                                               })
    }
}

