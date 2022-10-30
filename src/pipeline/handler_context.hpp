#pragma once

namespace rtc {

class DataPacket;

class PipelineBase;

class ContextInterface {
public:
    virtual ~ContextInterface() = default;

    virtual PipelineBase* Pipeline() = 0;
};

class InboundHandlerContextInterface {
public:
    virtual ~InboundHandlerContextInterface() = default;

    virtual void FireRead(DataPacket* pkt) = 0;

    virtual void FireReadEOF() = 0;

    virtual void FireTransportActive() = 0;

    virtual void FireTransportInActive() = 0;
};

class OutboundHandlerContextInterface {
public:
    virtual ~OutboundHandlerContextInterface() = default;

    virtual void FireWrite(DataPacket* pkt) = 0;

    virtual void FireClose() = 0;
};

}
