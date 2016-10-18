#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_MESSAGE_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_MESSAGE_H_

#ifdef DBUS
#  include "dbus/dbusmessage.h"
#elif WEBSOCKET
#  include "websocket/websocketmessage.h"
#elif MQUEUE
#  include "mqueue/mqueuemessage.h"
#endif

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_MESSAGE_H_
