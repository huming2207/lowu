#pragma once

#include <zephyr/zephyr.h>
#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include "radio_hal.hpp"

class zephyr_stm32wl : public radio_hal
{
public:
    static zephyr_stm32wl *instance()
    {
        static zephyr_stm32wl _instance;
        return &_instance;
    }

    void operator=(zephyr_stm32wl const&) = delete;
    zephyr_stm32wl(zephyr_stm32wl const&) = delete;

    radio::ret init() override;
    radio::ret reset() override;
    radio::ret wakeup() override;
    radio::ret write(const uint8_t* cmd, uint16_t cmd_len, const uint8_t* data, uint16_t data_len) override;
    radio::ret read(const uint8_t* cmd, uint16_t cmd_len, uint8_t* data, uint16_t data_len) override;

private:
    zephyr_stm32wl();
    spi_dt_spec *spi = nullptr;
    gpio_dt_spec *tx_enable = nullptr;
    gpio_dt_spec *rx_enable = nullptr;
};
