cmake_minimum_required(VERSION 3.20.0)
if (NOT ESP_PLATFORM)
    project(lowu_radio)
endif()

if (ZEPHYR_BASE)
    zephyr_include_directories("../includes")
    zephyr_library()
    zephyr_library_sources(
            "../includes/radio_hal.hpp"
            "../sx12xx.cpp" "../sx126x.cpp" "../includes/sx12xx.hpp" "../includes/sx126x.hpp"
    )
elseif(ESP_PLATFORM)
    # TODO
endif()