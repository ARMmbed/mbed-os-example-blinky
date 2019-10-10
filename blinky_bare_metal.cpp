/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
#ifdef MBED_BARE_METAL
#include "mbed.h"
#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    500

// Initialise the digital pin LED1 as an output
DigitalOut led(LED1);

void blinky_bare_metal()
{
    while (true) {
        led = !led;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
#endif // MBED_BARE_METAL
