cmake_minimum_required(VERSION 3.20.0)

list(APPEND ZEPHYR_EXTRA_MODULES
        ${CMAKE_CURRENT_SOURCE_DIR}/lowu_radio
)

set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR})

# This sample is only compatible with nrf52840dk_nrf52840 because it has
# re-directed the 'boards' directory to a directory that only contains
# this board.
set(BOARD laojie)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(lowu)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
