#include "mbed.h"

// Port A0: 0x40004000 GPIO0 to GPIO7
// Port A1: 0x40005000 GPIO8 to GPIO15 Use GPIO13 (SW2) as input, GPIO9(D10 Red) as output
// Port A2: 0x40006000 GPIO16 to GPIO23
// Port A3: 0x40007000 GPIO24 to GPIO31

#define WAIT_CYCLES_LONG  10000000
#define WAIT_CYCLES_SHORT 1000000
#define INPUT_PIN_PORTA1  5
#define OUTPUT_PIN_PORTA1 1
#define GPIO_PORTA1_ADDRESS 0x40005000
#define OFFSET_DIR  0x400
#define OFFSET_DATA 0

static void set_gpio_dir()
{
    // Configure direction Bit 7:0 DIR, 0 = input, 1 = output
    *((volatile unsigned long*)(GPIO_PORTA1_ADDRESS + OFFSET_DIR)) &= ~0x20; // Configure SW2 as input
    *((volatile unsigned long*)(GPIO_PORTA1_ADDRESS + OFFSET_DIR)) |= 0x2;   // Configure D10 as output

}
//DigitalOut led1(LED1);
// main() runs in its own thread in the OS
int main()
{
    unsigned long wait_cycles_in_use = WAIT_CYCLES_SHORT;
    volatile unsigned long delay = 0;
    set_gpio_dir();
    while (true)
    {

        //led1 = !led1;
        //wait(0.5);
        // Check if SW2 is pressed
        if (*(volatile unsigned long *)(GPIO_PORTA1_ADDRESS + OFFSET_DATA + ((1 << INPUT_PIN_PORTA1) << 2)))
        {
            wait_cycles_in_use = WAIT_CYCLES_LONG;
        }

        *(volatile unsigned long *)(GPIO_PORTA1_ADDRESS + OFFSET_DATA + ((1 << OUTPUT_PIN_PORTA1) << 2)) = (OUTPUT_PIN_PORTA1 << 1);
        delay = wait_cycles_in_use;
        while (delay--);
        *(volatile unsigned long *)(GPIO_PORTA1_ADDRESS + OFFSET_DATA + ((1 << OUTPUT_PIN_PORTA1) << 2)) = 0;
        delay = wait_cycles_in_use;
        while (delay--);
    }
}

