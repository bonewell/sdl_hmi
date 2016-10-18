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

set(qml_dirs hmi_api controls models popups views)
set(qml_files MainWindow.qml)

add_custom_target(qml_copy_resources ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../res ${CMAKE_CURRENT_BINARY_DIR}/res
  COMMENT "Copying resources")

if(NOT "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  foreach(qml_dir ${qml_dirs})
    add_custom_target(qml_copy_${qml_dir} ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/${qml_dir} ${CMAKE_CURRENT_BINARY_DIR}/${qml_dir}
    COMMENT "Copying directory ${qml_dir}")
  endforeach(qml_dir)

  foreach(qml_file ${qml_files})
    add_custom_target(qml_copy_${qml_file} ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/${qml_file} ${CMAKE_CURRENT_BINARY_DIR}/${qml_file}
    COMMENT "Copying file ${qml_file}")
  endforeach(qml_file)
endif()

install(DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}/controls
    ${CMAKE_CURRENT_BINARY_DIR}/hmi_api
    ${CMAKE_CURRENT_BINARY_DIR}/models
    ${CMAKE_CURRENT_BINARY_DIR}/popups
    ${CMAKE_CURRENT_BINARY_DIR}/res
    ${CMAKE_CURRENT_BINARY_DIR}/views
  DESTINATION bin)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MainWindow.qml DESTINATION bin)
