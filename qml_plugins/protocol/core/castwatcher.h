#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CASTWATCHER_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CASTWATCHER_H_

#ifdef DBUS
#  include "dbus/dbuscastwatcher.h"
#elif WEBSOCKET
#  include "websocket/websocketcastwatcher.h"
#elif MQUEUE
#  include "mqueue/mqueuecastwatcher.h"
#endif

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CASTWATCHER_H_
