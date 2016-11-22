#ifndef INBOX_H
#define INBOX_H

#include <QObject>

class QByteArray;

class Inbox : public QObject
{
    Q_OBJECT
public:
    explicit Inbox(QObject *parent = 0);

public slots:
    void received(const QByteArray& data);
};

#endif // INBOX_H
