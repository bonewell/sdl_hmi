#include "courier.h"

#include "core/watcher.h"
#include "core/connector.h"

Courier::Courier(const QString &name, const QJSValue &callback,
                 CourierCallback func, PrivateInterface &impl)
    : name_(name), impl_(impl), callback_(callback),
      input_(), watcher_(0), func_(func), index_(0)
{
}

void Courier::call()
{
    watcher_ = impl_.call(name_, input_);
    connect(watcher_, SIGNAL(finished()), this, SLOT(response()));
}

void Courier::response()
{
    response_ = watcher_->output();
    func_(*this);
}

void Courier::invoke()
{
    callback_.call(output_);
    watcher_->deleteLater();
    this->deleteLater();
}
