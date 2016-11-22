#include "signal.h"

#include "core/connector.h"

Signal::Signal(const QString &name, PrivateInterface &impl)
    : name_(name), impl_(impl)
{

}

void Signal::send()
{
    impl_.sendSignal(name_, arguments_);
}
