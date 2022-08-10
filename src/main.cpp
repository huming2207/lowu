#include <zephyr/device.h>
#include <zephyr/drivers/lora.h>
#include <zephyr/drivers/spi.h>
#include <errno.h>
#include <zephyr/sys/util.h>
#include <zephyr/zephyr.h>

#define MAX_DATA_LEN 255

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(lowu);

extern "C" int main(void)
{
    LOG_INF("Lay hou");
    k_sleep(K_FOREVER);

    return 0;
}