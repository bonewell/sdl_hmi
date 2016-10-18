#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CONNECTOR_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CONNECTOR_H_

#ifdef DBUS
#  include "dbus/dbusconnector.h"
#elif WEBSOCKET
#  include "websocket/websocketconnector.h"
#elif MQUEUE
#  include "mqueue/mqueueconnector.h"
#endif

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_CONNECTOR_H_
