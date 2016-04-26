/**
  * Copyright (c) 2014, Ford Motor Company
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

SDL
{
    onOnAppPermissionChanged: {
        console.log("enter onStatusUpdate");
        console.log("appID = ", JSON.stringify(appID));
        console.log("appID = ", JSON.stringify(isAppPermissionsRevoked));
        console.log("appID = ", JSON.stringify(appRevokedPermissions));
        console.log("appID = ", JSON.stringify(appRevoked));
        console.log("appID = ", JSON.stringify(appPermissionsConsentNeeded));
        console.log("appID = ", JSON.stringify(appUnauthorized));
        console.log("appID = ", JSON.stringify(priority));
        console.log("appID = ", JSON.stringify(requestType));
    }

    onOnSDLConsentNeeded: {
        console.log("enter onStatusUpdate: ", JSON.stringify(device));
    }

    onOnStatusUpdate: {
        console.log("enter onStatusUpdate")
        settingsContainer.updateStatus(status);
    }
}
