#ifndef ABSTRACT_MESSAGE_H
#define ABSTRACT_MESSAGE_H

#include <QString>
#include <QList>
#include <QByteArray>

class AbstractMessage
{
public:
    AbstractMessage();
    virtual ~AbstractMessage();
    virtual void setDelayedReply() const = 0;
    void setName(const QString& name);
    const QString& name() const;
    void setParams(const QList<QByteArray>& params);
protected:
    const QByteArray& nextParam();
private:
    QString name_;
    QList<QByteArray> params_;
    QListIterator<QByteArray> i_;
};

#endif // ABSTRACT_MESSAGE_H
