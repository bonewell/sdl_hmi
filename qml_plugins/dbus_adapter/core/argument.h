#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QString>
#include <QDBusArgument>
#include <QVariantMap>
#include <QJSValue>

template<class T>
class Argument {};

template<>
class Argument<QDBusArgument>
{
public:
    explicit Argument(QDBusArgument& argument) : argument_(argument) {}
    template<typename T>
    Argument& set(const QString& name, const T &value) {
        Q_UNUSED(name);
        argument_ << value;
        return *this;
    }
private:
    QDBusArgument& argument_;
};

template<>
class Argument<const QDBusArgument>
{
public:
    explicit Argument(const QDBusArgument& argument) : argument_(argument) {}
    template<typename T>
    const Argument& get(const QString& name, T& value) const {
        Q_UNUSED(name);
        argument_ >> value;
        return *this;
    }
private:
    const QDBusArgument& argument_;
};

template<>
class Argument<QVariantMap>
{
public:
    explicit Argument(QVariantMap& argument) : argument_(argument) {}
    template<typename T>
    Argument& set(const QString& name, const T &value) {
        argument_[name] << value;
        return *this;
    }
private:
    QVariantMap& argument_;
};

template<>
class Argument<const QVariantMap>
{
public:
    explicit Argument(const QVariantMap& argument) : argument_(argument) {}
    template<typename T>
    const Argument& get(const QString& name, T& value) const {
        argument_.value(name) >> value;
        return *this;
    }
private:
    const QVariantMap& argument_;
};

template<>
class Argument<QJSValue>
{
public:
    explicit Argument(QJSValue& argument) : argument_(argument) {}
    template<typename T>
    Argument& set(const QString& name, const T &value) {
        QJSValue var(argument_);
        var << value;
        argument_.setProperty(name, var);
        return *this;
    }
private:
    QJSValue& argument_;
};

#endif // ARGUMENT_H
