#include "zephyr_glue.h"

#include <devicetree_unfixed.h>

struct spi_dt_spec lora_spi = SPI_DT_SPEC_GET(DT_NODELABEL(lora), SPI_WORD_SET(8) | SPI_TRANSFER_MSB, 0);