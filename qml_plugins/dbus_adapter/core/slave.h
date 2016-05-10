#ifndef SLAVE_H
#define SLAVE_H

#include <QObject>
#include <QList>
#include <QByteArray>
#include <QMetaMethod>

#include "core/message.h"
#include "core/handle.h"

class PrivateInterface;

class Slave : public QObject
{
    Q_OBJECT

public:
    Slave(const Handle& handle, const Message& message,
          const QMetaMethod& meta, PrivateInterface &impl);

    template<typename T>
    Slave& in(const T& value) {
        QVariant var;
        var << value;
        input_[names_[index_++]] = var;
        return *this;
    }

    template<typename T>
    Slave& out(const T& value) {
        QVariant var = QVariant::fromValue(value);
        output_ << var;
        return *this;
    }
    void run();
    void send();
    void error(const QString& name, const QString& text);
    bool hasHandle() const;

signals:
    void pass();
    void fail(const QString& name, const QString& text);

private slots:
    void sendReply();
    void sendError(const QString& name, const QString& text);

private:
    inline std::string name() const;
    inline bool canSplit(int max) const;
    bool invoke();
    const Handle handle_;
    const QMetaMethod meta_;
    Message request_;
    PrivateInterface& impl_;
    int index_;
    const QList<QByteArray> names_;
    QVariantMap input_;
    QVariantList output_;
};

#endif // SLAVE_H
