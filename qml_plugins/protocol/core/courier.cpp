#include "courier.h"

#include "core/watcher.h"
#include "core/connector.h"

Courier::Courier(const QMetaMethod &meta, const QJSValue &callback,
                 CourierCallback func, PrivateInterface &impl)
    : meta_(meta), impl_(impl), callback_(callback),
      request_(), names_(meta_.parameterNames()), watcher_(0), func_(func), index_(0)
{
    names_.removeAll("callback");
}

void Courier::call()
{
    watcher_ = impl_.call(name(), request_);
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

QString Courier::name() const
{
    QString name = QString::fromLatin1(meta_.name());
    name[0] = name[0].toUpper();
    return name;
}
