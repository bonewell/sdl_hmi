#include "signal.h"

#include <QDebug>

#include "core/connector.h"

Signal::Signal(const QString &name, const QMetaMethod &meta, PrivateInterface &impl)
    : name_(name), meta_(meta), impl_(impl), names_(meta.parameterNames()),
      index_(0)
{
    qDebug() << names_;
}

void Signal::send()
{
    impl_.sendSignal(name_, arguments_);
}
