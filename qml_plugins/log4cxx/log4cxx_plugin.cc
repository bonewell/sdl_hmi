/*
 * @file log4cxx_plugin.cpp
 * @brief Log4cxxPlugin class header file.
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

#include "log4cxx_plugin.h"

#ifdef ENABLE_LOG
#  include <log4cxx/log4cxx.h>
#  include <log4cxx/propertyconfigurator.h>
#endif  // ENABLE_LOG

#ifdef ENABLE_LOG
log4cxx::LoggerPtr logger_ = log4cxx::LoggerPtr(
                              log4cxx::Logger::getLogger("Log4cxxPlugin"));
#endif  // ENABLE_LOG

#ifdef ENABLE_LOG
void saveLog(QtMsgType type, log4cxx::spi::LocationInfo &location, const std::string &msg) {
  switch (type) {
  case QtDebugMsg:
    (*logger_).debug(msg, location);
    break;
  case QtWarningMsg:
    (*logger_).warn(msg, location);
    break;
  case QtCriticalMsg:
    (*logger_).error(msg, location);
    break;
  case QtFatalMsg:
    (*logger_).fatal(msg, location);
    break;
  default:
    (*logger_).info(msg, location);
    break;
  }
}
#endif  // ENABLE_LOG

void smartLogger(QtMsgType type, const QMessageLogContext &context,
                 const QString &msg) {
#ifdef ENABLE_LOG
  log4cxx::spi::LocationInfo location(context.file,
                                      context.function ? context.function : "",
                                      context.line);
  saveLog(type, location, msg.toStdString());
#endif  // ENABLE_LOG
}

void Log4cxxPlugin::registerTypes(const char *uri) {
#ifdef ENABLE_LOG
  log4cxx::PropertyConfigurator::configure("log4cxx.properties");
#endif  // ENABLE_LOG

  qInstallMessageHandler(smartLogger);

  // @uri com.ford.sdl.hmi.log4cxx
  qmlRegisterType<Logger>(uri, 1, 0, "Logger");
  // Use standart console API Javascript
  // See Debugging QML Applications in Qt documentation
}
