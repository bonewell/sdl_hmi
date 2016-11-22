#ifndef SIGNAL_H
#define SIGNAL_H

#include <QString>
#include <QVariant>

class PrivateInterface;

class Signal
{
public:
    Signal(const QString& name, PrivateInterface& impl);
    void send();

    template<typename T>
    Signal& arg(const T& value) {
        QVariant var = QVariant::fromValue(value);
        arguments_ << var;
        return *this;
    }

private:
    QString name_;
    PrivateInterface& impl_;
    QVariantList arguments_;
};

#endif // SIGNAL_H
