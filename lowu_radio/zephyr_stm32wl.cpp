#include <drivers/spi.h>
#include "zephyr_stm32wl.hpp"
#include "zephyr_glue.h"

#include <stm32wlxx_ll_exti.h>
#include <stm32wlxx_ll_pwr.h>
#include <stm32wlxx_ll_rcc.h>

zephyr_stm32wl::zephyr_stm32wl()
{
    spi = &lora_spi;
}

bool zephyr_stm32wl::reset()
{
    LL_RCC_RF_EnableReset();
    k_sleep(K_MSEC(20));
    LL_RCC_RF_DisableReset();
    k_sleep(K_MSEC(10));

    return true;
}

bool zephyr_stm32wl::wakeup()
{
    return true; // Does nothing???
}

int zephyr_stm32wl::write(const uint8_t *cmd, const uint16_t cmd_len, const uint8_t *data, const uint16_t data_len)
{
    const struct spi_buf tx_buf[] = {
            {
                    .buf = (void *)cmd,
                    .len = cmd_len,
            },
            {
                    .buf = (void *)data,
                    .len = data_len
            }
    };

    const struct spi_buf_set tx = {
            .buffers = tx_buf,
            .count = ARRAY_SIZE(tx_buf),
    };

    return spi_write_dt(spi, &tx);
}

int zephyr_stm32wl::read(const uint8_t *cmd, const uint16_t cmd_len, uint8_t *data, uint16_t data_len)
{
    const struct spi_buf tx_buf[] = {
            {
                    .buf = (void *)cmd,
                    .len = cmd_len,
            },
    };

    const struct spi_buf rx_buf[] = {
            {
                    .buf = (void *)data,
                    .len = data_len
            }
    };

    const struct spi_buf_set tx = {
            .buffers = tx_buf,
            .count = ARRAY_SIZE(tx_buf),
    };

    const struct spi_buf_set rx = {
            .buffers = rx_buf,
            .count = ARRAY_SIZE(rx_buf),
    };

    return spi_transceive_dt(spi, &tx, &rx);
}

bool zephyr_stm32wl::init()
{
    return true;
}
