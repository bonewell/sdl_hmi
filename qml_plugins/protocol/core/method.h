#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_COURIER_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_COURIER_H_

#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QVariant>
#include <QMetaMethod>

#include "core/coremessage.h"
#include "core/convert.h"

class Method;
class PrivateInterface;
class Watcher;

/**
 * @brief The MethodCallback class is base class for callbacks
 */
class MethodCallback
{
public:
    explicit MethodCallback(const QJSValue& callback) : callback_(callback) {}
    virtual ~MethodCallback() {}
    virtual void call(Method& response) = 0;
    void run(const QJSValueList& output) { callback_.call(output); }
    QJSValue createValue() { return QJSValue(callback_); }
private:
    QJSValue callback_;
};

#define InitResponse(Name) \
class Name : public MethodCallback \
{ \
public: \
    explicit Name(const QJSValue& callback) : MethodCallback(callback) {} \
    virtual void call(Method& response); \
}; \
void Name::call(Method& response)

/**
 * @brief The Method class
 * instance of this class is used to send request in the bus and
 * to call callback to transmit response to QML
 */
class Method : public QObject
{
    Q_OBJECT

public:
    Method(const QString& name, const QList<QByteArray>& parameters,
           MethodCallback *callback, PrivateInterface &impl);
    ~Method();
    void send();
    void run();

    template<typename T>
    Method& in(const T& value) {
        request_.setArgument(value);
        return *this;
    }

    template<typename T>
    Method& in(const QVariantList& value) {
        return in(multiple<typename T::value_type>(value));
    }

    template<typename T>
    Method& out(const QString& name) {
        T value = response_.argument<T>(name);
        QJSValue var = callback_->createValue();
        var << value;
        output_ << var;
        return *this;
    }

private slots:
    void call();

private:
    PrivateInterface &impl_;
    MethodCallback* callback_;
    CoreMessage request_;
    CoreMessage response_;
    QJSValueList output_;
    Watcher* watcher_;
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_COURIER_H_
