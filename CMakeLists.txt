# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13)

# Include other generated CMake files
include(toolchain.cmake)
include(target.cmake)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CROSSCOMPILING TRUE)

# if the environment does not specify build type, set to Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo"
        CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
endif()

enable_language(C CXX ASM)

# here starts the project
project(mbed-os-example-blinky C CXX ASM)

# uncomment below to have a verbose build process
#set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(mbed-os)
add_subdirectory(gen_config)

# This is the main application
add_executable(mbed-os-example-blinky main.cpp)

set_target_properties(mbed-os-example-blinky PROPERTIES ENABLE_EXPORTS 1)

# add syslibs dependencies to create the correct linker order
target_link_libraries(mbed-os-example-blinky mbed_os gen_config -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys)

add_custom_command(TARGET mbed-os-example-blinky PRE_LINK
                   COMMAND "arm-none-eabi-cpp" -E -P -Wl,--gc-sections -Wl,--wrap,main -Wl,--wrap,_malloc_r -Wl,--wrap,_free_r -Wl,--wrap,_realloc_r -Wl,--wrap,_memalign_r -Wl,--wrap,_calloc_r -Wl,--wrap,exit -Wl,--wrap,atexit -Wl,-n -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -DMBED_ROM_START=0x0 -DMBED_ROM_SIZE=0x100000 -DMBED_RAM_START=0x20000000 -DMBED_RAM_SIZE=0x30000 -DMBED_RAM1_START=0x1fff0000 -DMBED_RAM1_SIZE=0x10000 -DMBED_BOOT_STACK_SIZE=1024 -DXIP_ENABLE=0 ./mbed-os/targets/TARGET_Freescale/TARGET_MCUXpresso_MCUS/TARGET_MCU_K64F/device/TOOLCHAIN_GCC_ARM/MK64FN1M0xxx12.ld -o ${CMAKE_CURRENT_BINARY_DIR}/mbed-os-example-blinky_pp.link_script.ld
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                   BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/mbed-os-example-blinky_pp.link_script.ld"
                   )

add_custom_command(TARGET mbed-os-example-blinky POST_BUILD
                   COMMAND ${ELF2BIN} -O binary $<TARGET_FILE:mbed-os-example-blinky> $<TARGET_FILE:mbed-os-example-blinky>.bin
                   COMMAND ${CMAKE_COMMAND} -E echo "-- built: $<TARGET_FILE:mbed-os-example-blinky>.bin"
                  )
