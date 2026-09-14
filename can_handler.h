#pragma once
#include "can_message.h"
#include <queue>
#include <functional>
#include <cstdint>

/**
 * @brief CAN Bus handler with message queuing and callback support
 * Reflects real-world CAN implementation from automotive EV work
 */
class CANHandler {
public:
    using MessageCallback = std::function<void(const CANMessage&)>;

    enum class BaudRate : uint32_t {
        CAN_125K  = 125000,
        CAN_250K  = 250000,
        CAN_500K  = 500000,
        CAN_1M    = 1000000
    };

    explicit CANHandler(BaudRate baudRate = BaudRate::CAN_500K);
    ~CANHandler();

    bool initialize();
    bool sendMessage(const CANMessage& msg);
    bool receiveMessage(CANMessage& msg);
    void registerCallback(uint32_t messageId, MessageCallback cb);
    void processRxQueue();
    bool isInitialized() const { return initialized_; }
    uint32_t getTxCount() const { return txCount_; }
    uint32_t getRxCount() const { return rxCount_; }

private:
    BaudRate baudRate_;
    bool initialized_;
    uint32_t txCount_;
    uint32_t rxCount_;
    std::queue<CANMessage> rxQueue_;
    std::unordered_map<uint32_t, MessageCallback> callbacks_;

    bool validateMessage(const CANMessage& msg) const;
};
