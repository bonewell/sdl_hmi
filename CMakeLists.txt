# Copyright (c) 2014-2016, Ford Motor Company
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

option(BUILD_TESTS "Possibility to build and run tests" OFF)
option(ENABLE_LOG "Logging feature" ON)

set(OS_TYPE_OPTION "$ENV{OS_TYPE}")
set(ARCH_TYPE_OPTION "$ENV{ARCH_TYPE}")

if (ARCH_TYPE_OPTION)
  if (NOT (${ARCH_TYPE_OPTION} STREQUAL "x86") AND NOT (${ARCH_TYPE_OPTION} STREQUAL "armv7"))
    message(AUTHOR_WARNING "HW architecture is not defined, using x86. Allowed values are x86/armv7 (case sensitive)")
    set(ARCH_TYPE_OPTION "x86")
  endif ()
else ()
    set(ARCH_TYPE_OPTION "x86")
endif ()

set(objcopy "objcopy")
if (OS_TYPE_OPTION)
  if (${OS_TYPE_OPTION} STREQUAL "QNX")
    message(STATUS "Set build process for QNX")
    #do not use include after project() command.
    #Such usecase results in infinite cycle of reinitialization of compiler and other variables
    INCLUDE("./qnx_6.5.0_linux_x86.cmake")
    set(objcopy "nto${ARCH_TYPE_OPTION}-objcopy")
  endif()
endif()

project(QtHmi)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_FLAGS "-fPIC -std=gnu++0x -Wall -Werror -Wuninitialized -Wvla")
set(CMAKE_CXX_FLAGS_RELEASE " -DNDEBUG -s -O2")
set(CMAKE_CXX_FLAGS_DEBUG   " -DDEBUG -g3 -ggdb3")

if (ENABLE_LOG)
  message(STATUS "Log is turned on")
  add_definitions(-DENABLE_LOG)
endif()

set(qt_version "5.1.0")

execute_process(
    COMMAND ${CMAKE_SOURCE_DIR}/FindQt.sh -v ${qt_version}
        OUTPUT_VARIABLE qt_bin_dir
)
message(STATUS "Binary directory Qt ${qt_version} is ${qt_bin_dir}")
set(ENV{PATH} ${qt_bin_dir}:$ENV{PATH})

find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)
set(qmlplugindump_binary ${qt_bin_dir}/qmlplugindump)

set(RTLIB rt)
if(CMAKE_SYSTEM_NAME STREQUAL "QNX")
  set(RTLIB )
endif()

set(main_qml "MainWindow.qml")
set(plugins_dir "plugins")

if (CMAKE_SYSTEM_NAME STREQUAL "QNX")
  set(start_command "./start-qml.sh")
  set(command_arguments "${main_qml} ${plugins_dir}")
else ()
  execute_process(
    COMMAND ${CMAKE_SOURCE_DIR}/FindQt.sh -v ${qt_version} -b qmlscene
    OUTPUT_VARIABLE start_command
  )
  set(command_arguments "${main_qml} -I ${plugins_dir}")
endif ()

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/start_hmi.sh
  "#!/bin/sh\n${start_command} ${command_arguments}\n")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/start_hmi.sh
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE OWNER_EXECUTE
  DESTINATION bin)
install(FILES ${CMAKE_SOURCE_DIR}/log4cxx.properties
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
  DESTINATION bin)

add_subdirectory(./qml_plugins)
add_subdirectory(./qml_model_qt5)

if(BUILD_TESTS)
  add_subdirectory(test)
endif()
