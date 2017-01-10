# Copyright (c) 2013, Ford Motor Company
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following
# disclaimer in the documentation and/or other materials provided with the
# distribution.
#
# Neither the name of the Ford Motor Company nor the names of its contributors
# may be used to endorse or promote products derived from this software
# without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

cmake_minimum_required(VERSION 2.8.11)

set(target Protocol)
set(destination com/ford/sdl/hmi/protocol)
set(install_destination bin/plugins/${destination})
set(library_name ${CMAKE_SHARED_LIBRARY_PREFIX}${target}${CMAKE_SHARED_LIBRARY_SUFFIX})

set(CMAKE_AUTOMOC ON)
set(SOURCES
  protocol_plugin.cc
  core/service.cpp
  core/coremessage.cpp
#  core/abstractmessage.cpp
  core/abstractadapter.cpp
  core/abstractitem.cpp
  core/optional.cpp
  core/procedure.cpp
  core/signal.cpp
  core/method.cpp
  protocol/interfaces/buttons.cpp
  protocol/interfaces/tts.cpp
  protocol/interfaces/vr.cpp
  protocol/interfaces/navigation.cpp
  protocol/interfaces/basiccommunication.cpp
  protocol/interfaces/ui.cpp
  protocol/interfaces/vehicleinfo.cpp
  protocol/interfaces/sdl.cpp
  moc_watcher.cpp
)

if(${TRANSPORT} STREQUAL "dbus")
  list(APPEND SOURCES
    dbus/dbusconnector.cpp
    dbus/dbuswatcher.cpp
    dbus/dbusmessage.cpp
  )
  add_definitions(-DDBUS)
elseif(${TRANSPORT} STREQUAL "websocket")
  list(APPEND SOURCES
    websocket/websocketconnector.cpp
    websocket/websocketwatcher.cpp
    websocket/websocketmessage.cpp
  )
  add_definitions(-DWEBSOCKET)
endif()

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(${target} SHARED ${SOURCES})

qt5_generate_moc(${CMAKE_CURRENT_SOURCE_DIR}/core/watcher.h moc_watcher.cpp)
set(QT_MODULES Core Qml)
if (TRANSPORT STREQUAL "dbus")
  list(APPEND QT_MODULES DBus)
elseif (TRANSPORT STREQUAL "websocket")
  list(APPEND QT_MODULES WebSockets)
endif()
qt5_use_modules(${target} ${QT_MODULES})
set(model_dir ${CMAKE_CURRENT_BINARY_DIR}/../../qml_model_qt5/)
set(copy_destination ${CMAKE_CURRENT_BINARY_DIR}/../../qml_model_qt5/${destination})

target_link_libraries(${target} log4cxx)

add_custom_target(copy_library_${target} ALL
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/${library_name}
    ${copy_destination}
    DEPENDS ${target}
    COMMENT "Copying library ${library_name}")
file(COPY qmldir DESTINATION ${copy_destination})

install(TARGETS ${target}
  DESTINATION ${install_destination}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
    GROUP_READ GROUP_EXECUTE
    WORLD_READ WORLD_EXECUTE
)
install(FILES qmldir DESTINATION ${install_destination})

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  add_custom_target(qmltypes_${target} ALL
    COMMAND ${qmlplugindump_binary} -nonrelocatable com.ford.sdl.hmi.dbus_adapter 1.0 ${model_dir} > ${CMAKE_CURRENT_BINARY_DIR}/plugins.qmltypes 2>/dev/null || true
    DEPENDS copy_library_${target}
  )
  add_custom_target(copy_qmltypes_${target} ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${CMAKE_CURRENT_BINARY_DIR}/plugins.qmltypes
      ${copy_destination}
    DEPENDS qmltypes_${target}
  )
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/plugins.qmltypes DESTINATION ${install_destination})
endif ()
