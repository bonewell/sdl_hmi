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
    QString name = QString::fromLatin1(meta_.name());
    name[0] = name[0].toUpper();
    return name;
}
