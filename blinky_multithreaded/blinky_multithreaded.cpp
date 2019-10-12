/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
#ifdef BLINKY_MULTITHREADED

#include "mbed.h"
#include "platform/mbed_thread.h"
#include "rtos/Queue.h"
#include "rtos/Thread.h"
#include "rtos/MemoryPool.h"


// Maximum number of item in the inter-thread communication queue
#define MAX_QUEUE_SIZE                                                        1

// Thread priorities
#define THREAD_PRIORITY_PRODUCER                          osPriorityAboveNormal
#define THREAD_PRIORITY_CONSUMER                                 osPriorityHigh

// Delay between sending messages in milliseconds
#define THREAD_SLEEP_TIME_MS_PRODUCER                                       500

// Message to be sent from producer thread to consumer thread
#define THREAD_PRODUCER_MSG                                          0xDEADBEEF


// Fixed size memory pool to hold messages
MemoryPool<unsigned long, MAX_QUEUE_SIZE> mem_pool;

// Queue used for inter-thread communications
Queue<unsigned long, MAX_QUEUE_SIZE> queue;

// Producer thread handle
Thread thread_producer_handle(
    THREAD_PRIORITY_PRODUCER,
    OS_STACK_SIZE,
    nullptr,
    "PRODUCER"
);

// Consumer thread handle
Thread thread_consumer_handle(
    THREAD_PRIORITY_CONSUMER,
    OS_STACK_SIZE,
    nullptr,
    "CONSUMER"
);


static void thread_consumer();
static void thread_producer();


// The function `blinky_multithreaded()` runs in the main thread in the OS
void blinky_multithreaded()
{
    // Start execution of the functions in the threads
    thread_consumer_handle.start(callback(thread_consumer));
    thread_producer_handle.start(callback(thread_producer));
}


static void thread_consumer()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        osEvent evt = queue.get();

        if (evt.status == osEventMessage) {
            unsigned long *msg = (unsigned long *)evt.value.p;

            if (*msg == THREAD_PRODUCER_MSG) {
                led = !led;
            }

            mem_pool.free(msg);
        }
    }
}

static void thread_producer()
{
    while (true) {
        unsigned long *msg = mem_pool.alloc();
        *msg = THREAD_PRODUCER_MSG;

        queue.put(msg);

        thread_sleep_for(THREAD_SLEEP_TIME_MS_PRODUCER);
    }
}

#endif // BLINKY_MULTITHREADED
