#pragma once
#include <cstdint>
#include <array>

/**
 * @brief CAN Bus message structure
 * Based on automotive CAN communication experience (HEERO Motors BMS/TCU)
 */
struct CANMessage {
    uint32_t id;
    uint8_t dlc;                   // Data Length Code (0-8)
    std::array<uint8_t, 8> data;
    bool isExtendedId;
    bool isRemoteFrame;

    CANMessage() : id(0), dlc(0), data{}, 
                   isExtendedId(false), isRemoteFrame(false) {}

    CANMessage(uint32_t id, uint8_t dlc,
               std::array<uint8_t, 8> data)
        : id(id), dlc(dlc), data(data),
          isExtendedId(false), isRemoteFrame(false) {}
};
