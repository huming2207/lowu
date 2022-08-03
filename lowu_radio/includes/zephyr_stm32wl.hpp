#pragma once

#include <zephyr/zephyr.h>
#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include "radio_hal.hpp"

class zephyr_stm32wl : public radio_hal
{
public:
    zephyr_stm32wl();
    bool init() override;
    bool reset() override;
    bool wakeup() override;
    int write(const uint8_t* cmd, uint16_t cmd_len, const uint8_t* data, uint16_t data_len) override;
    int read(const uint8_t* cmd, uint16_t cmd_len, uint8_t* data, uint16_t data_len) override;

private:
    spi_dt_spec *spi = nullptr;
    gpio_dt_spec *tx_enable = nullptr;
    gpio_dt_spec *rx_enable = nullptr;
};
