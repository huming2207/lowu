board_runner_args(pyocd "--target=STM32WLE5CCUx" "--frequency=40000000")
board_runner_args(pyocd "--flash-opt=-O reset_type=hw")
board_runner_args(pyocd "--flash-opt=-O connect_mode=under-reset")
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)