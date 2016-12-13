#include "signal.h"

#include "core/connector.h"

Signal::Signal(const QString &name, const QList<QByteArray>& params,
               PrivateInterface &impl)
    : impl_(impl), message_()
{
    message_.setName(name);
    message_.setParams(params);
}

void Signal::send()
{
    impl_.sendSignal(message_);
}
