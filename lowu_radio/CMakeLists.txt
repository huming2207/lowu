cmake_minimum_required(VERSION 3.20.0)
if (NOT ESP_PLATFORM)
    project(lowu_radio)
endif()

if (ZEPHYR_BASE)
    zephyr_include_directories("../includes")
    zephyr_library()
    zephyr_library_sources(
            "../includes/radio_hal.hpp"
            "../zephyr_glue.c" "../zephyr_glue.h"
            "../zephyr_stm32wl.cpp" "../includes/zephyr_stm32wl.hpp"
            "../sx12xx.cpp" "../sx126x.cpp" "../sx126x_regs.hpp" "../includes/sx12xx.hpp" "../includes/sx126x.hpp"
    )

    zephyr_library_compile_options(-std=c++17 -fno-threadsafe-statics)
elseif(ESP_PLATFORM)
    # TODO
endif()