#include "method.h"

#include "core/watcher.h"
#include "core/connector.h"

Method::Method(const QString& name, const QList<QByteArray>& parameters,
               MethodCallback *callback, PrivateInterface &impl)
    : impl_(impl), callback_(callback),
      request_(), response_(), output_(),
      watcher_(0)
{
    request_.setName(name);
    QList<QByteArray> params(parameters);
    params.removeAll("callback");
    request_.setParams(params);
}

Method::~Method()
{
    delete watcher_;
    delete callback_;
}

void Method::send()
{
    watcher_ = impl_.sendRequest(request_);
    connect(watcher_, &Watcher::finished, this, &Method::call);
}

void Method::call()
{
    response_ = watcher_->response();
    callback_->call(*this);
}

void Method::run()
{
    callback_->run(output_);
    this->deleteLater();
}
