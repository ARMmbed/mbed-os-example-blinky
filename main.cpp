#include <inttypes.h>
#include "mbed.h"

DigitalOut led1(LED1);

// main() runs in its own thread in the OS
int main() {
    uint32_t ctr = 0;

    printf("Starting mbed-os-example-blinky\n");
    while (true) {
        ctr++;
        if (ctr % 10 == 0) {
            printf("%" PRIu32 " blinks\n", ctr);
        }
        led1 = !led1;
        wait(0.5);
    }
}

