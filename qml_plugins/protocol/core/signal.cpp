#include "signal.h"

#include "core/connector.h"

Signal::Signal(const QMetaMethod &meta, PrivateInterface &impl)
    : meta_(meta), impl_(impl), names_(meta.parameterNames()), message_(),
      index_(0)
{
}

void Signal::send()
{
    impl_.sendSignal(name(), message_);
}

QString Signal::name() const
{
    return QString::fromLatin1(meta_.name());
}
