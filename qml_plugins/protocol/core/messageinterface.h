#ifndef MESSAGEINTERFACE_H
#define MESSAGEINTERFACE_H

class MessageInterface
{
public:
    virtual ~MessageInterface() {}
    virtual void setDelayedReply() const = 0;
};

#endif // MESSAGEINTERFACE_H
