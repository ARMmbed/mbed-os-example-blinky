# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13)

# Mbed OS system root path - that probably needs to come from tools
set(MBED_OS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")

# Include standard Mbed definitions
include(${MBED_OS_ROOT}/cmake/app.cmake)

project(mbed-os-example-blinky)

# uncomment below to have a verbose build process
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Sources for main application
target_sources(app PRIVATE main.cpp)

set_target_properties(app PROPERTIES ENABLE_EXPORTS 1) # TODO: What is that?