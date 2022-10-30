#pragma once
#include <string>
#include <string_view>
namespace rtc{

enum class HandlerDir{
  kIn,
  kOut,
  kBoth,
};

class HandlerInterface {
public:
    virtual ~HandlerInterface() = default;

    virtual void Enable() = 0;

    virtual void Disable() = 0;

    virtual std::string_view Name() = 0;

    virtual void NotifyUpdate() = 0;

    virtual void NotifyEvent() = 0;
};

class InboundInterface{
public:
    virtual ~InboundInterface() = default;

    virtual void Read() = 0;

    virtual void ReadEOF() = 0;

    virtual void TransportActive() = 0;
    
    virtual void TransportInActive() = 0;
};

class OutboundInterface{
public:
    virtual ~OutboundInterface() = 0;

    virtual void Write() = 0;
    
    virtual void Close() = 0;
};

class Handler : public HandlerInterface, InboundInterface, OutboundInterface {
public:
    static constexpr HandlerDir dir = HandlerDir::kBoth;

    virtual ~Handler() = default;
};

class InboundHandler : public HandlerInterface, InboundInterface {
public:
    static constexpr HandlerDir dir = HandlerDir::kIn;

    virtual ~InboundHandler() = default;
};

class OutboundHandler : public HandlerInterface, OutboundInterface {
public:
    static constexpr HandlerDir dir = HandlerDir::kOut;

    virtual ~OutboundHandler() = default;
};
};
