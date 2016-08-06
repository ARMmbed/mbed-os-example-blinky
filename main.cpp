#include "mbed.h"

DigitalOut led1(LED1);

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for delays)
int main() {
    while (true) {
        led1 = !led1;
        Thread::wait(500);
    }
}

