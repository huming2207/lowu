#pragma once

#include <stdint.h>

class radio_hal
{
public:
    virtual bool reset() = 0;
    virtual bool wakeup() = 0;
    virtual int write(const uint8_t* cmd, const uint16_t cmd_len, const uint8_t* data, const uint16_t data_len) = 0;
    virtual int read(const uint8_t* cmd, const uint16_t cmd_len, uint8_t* data, uint16_t data_len) = 0;
};