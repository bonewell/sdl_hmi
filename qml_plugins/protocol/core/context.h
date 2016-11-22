#ifndef CONTEXT_H
#define CONTEXT_H

#ifdef DBUS
#  include <QtDBus/QDBusContext>
typedef QDBusContext Context;
#elif WEBSOCKET
struct Context {};
#elif MQUEUE
struct Context {};
#endif

#endif // CONTEXT_H
