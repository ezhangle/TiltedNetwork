#pragma once

#include <Allocator.h>
#include <Buffer.h>

class Channel : public AllocatorCompatible
{
public:

    enum Type
    {
        kReliable,
        kUnreliable,
        kSequenced
    };

    Channel(Type aType, std::function<void()> aMessageReceivedCallback);
    ~Channel();

    void ProcessPacket(Buffer::Reader* apReader);

protected:

    void ProcessUnreliablePacket(Buffer::Reader* apReader);
    void ProcessReliablePacket(Buffer::Reader* apReader);
    void ProcessSequencedPacket(Buffer::Reader* apReader);

private:

    Type m_type;
    std::function<void()> m_messageReceivedCallback;
};