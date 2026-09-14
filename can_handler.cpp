#include "can_handler.h"
#include <stdexcept>
#include <iostream>

CANHandler::CANHandler(BaudRate baudRate)
    : baudRate_(baudRate),
      initialized_(false),
      txCount_(0),
      rxCount_(0) {}

CANHandler::~CANHandler() {
    // Release hardware resources
}

bool CANHandler::initialize() {
    // Hardware CAN controller init (MCP2515 / STM32 bxCAN)
    initialized_ = true;
    return initialized_;
}

bool CANHandler::sendMessage(const CANMessage& msg) {
    if (!initialized_) return false;
    if (!validateMessage(msg)) return false;
    // Hardware: load into TX mailbox and trigger send
    ++txCount_;
    return true;
}

bool CANHandler::receiveMessage(CANMessage& msg) {
    if (rxQueue_.empty()) return false;
    msg = rxQueue_.front();
    rxQueue_.pop();
    ++rxCount_;
    return true;
}

void CANHandler::registerCallback(uint32_t messageId,
                                   MessageCallback cb) {
    callbacks_[messageId] = std::move(cb);
}

void CANHandler::processRxQueue() {
    CANMessage msg;
    while (receiveMessage(msg)) {
        auto it = callbacks_.find(msg.id);
        if (it != callbacks_.end()) {
            it->second(msg);
        }
    }
}

bool CANHandler::validateMessage(const CANMessage& msg) const {
    if (msg.dlc > 8) return false;
    if (!msg.isExtendedId && msg.id > 0x7FF) return false;
    return true;
}
