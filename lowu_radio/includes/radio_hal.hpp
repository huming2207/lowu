#pragma once

#include <cstdint>

namespace radio
{
    enum ret : uint8_t
    {
        OK = 0,
        UNSUPPORTED_FEATURE,
        UNKNOWN_VALUE,
        ERROR,
    };
}

class radio_hal
{
public:
    virtual radio::ret init() = 0;
    virtual radio::ret reset() = 0;
    virtual radio::ret wakeup() = 0;
    virtual radio::ret write(const uint8_t* cmd, uint16_t cmd_len, const uint8_t* data, uint16_t data_len) = 0;
    virtual radio::ret read(const uint8_t* cmd, uint16_t cmd_len, uint8_t* data, uint16_t data_len) = 0;
};