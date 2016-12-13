#ifndef SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_SLAVE_H_
#define SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_SLAVE_H_

#include <QObject>
#include <QList>
#include <QByteArray>
#include <QMetaMethod>
#include <QVector>
#include <QArgument>

#include "core/message.h"
#include "core/handle.h"
#include "core/convert.h"

class AbstractItem;

/**
 * @brief The Procedure class
 * instance of this class is used to transmit request to QML and
 * to send response in the bus
 */
class Procedure : public QObject
{
    Q_OBJECT

public:
    Procedure(AbstractItem* item, const QString& name, const QList<QByteArray>& input,
              const QList<QByteArray>& output, const Handle& handle,
              const Message& message);

    template<typename T>
    Procedure& in(const T& value) {
//        QVariant var;
//        var << value;
//        input_[names_[index_++]] = var;
        return *this;
    }

    template<typename T>
    Procedure& out(const T& value) {
//        response_.setArgument<T>(value);
        return *this;
    }

    template<typename T>
    Procedure& out(const QVariantMap& value) {
        return out(single<T>(value));
    }

    template<typename T>
    Procedure& out(const QVariantList& value) {
        return out(multiple<typename T::value_type>(value));
    }

#ifdef WEBSOCKET
    void execute();
#endif  // WEBSOCKET
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
    inline bool canSplit(int max) const;
    bool invoke();
    AbstractItem* item_;
    const QString name_;
    const Handle handle_;
    Message request_;
    Message response_;
//    int index_;
    QList<QByteArray> input_;
    QList<QByteArray> output_;
    QVariantMap params_;
    static const int kMaxArgs = 10;
    QVector<QGenericArgument> args_;
};

#endif  // SRC_COMPONENTS_QT_HMI_QML_PLUGINS_PROTOCOL_CORE_SLAVE_H_
