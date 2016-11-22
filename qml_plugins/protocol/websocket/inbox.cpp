#include "inbox.h"

#include <QByteArray>
#include <QDebug>

Inbox::Inbox(QObject *parent) : QObject(parent)
{

}

void Inbox::received(const QByteArray &data) {
    qDebug() << data;
}
