# Getting started example for Mbed OS

This guide reviews the steps required to get Blinky with the addition of dynamic OS statistics working on an Mbed OS platform. (Note: To see a rendered example you can import into the Arm Online Compiler, please see our [quick start](https://os.mbed.com/docs/mbed-os/latest/quick-start/online-with-the-online-compiler.html#importing-the-code).)

Please install [Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

## Import the example application

From the command-line, import the example:

```
mbed import mbed-os-example-blinky
cd mbed-os-example-blinky
```

### Now compile

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_ARM`, `ARM`, `IAR`). For example, for the ARM Compiler:

```
mbed compile -m K64F -t ARM
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

```
...
Image: ./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin
```

**Note** By default, this example is built with the Mbed OS `bare-metal` build profile which only includes the `drivers` and `platform` libraries and contains no RTOS. As a result, the thread and stack information will not be displayed and the CPU stats with the RTOS-less wait simply run at 100% usage.

To disable the `bare-metal` profile, remove the following line from `mbed_app.json`

```
    "requires": ["bare-metal"],
```

### Program your board

1. Connect your Mbed device to the computer over USB.
1. Copy the binary file to the Mbed device.
1. Press the reset button to start the program.

The LED on your platform turns on and off. The main thread will additionally take a snapshot of the device's runtime statistics and display it over serial to your PC. The snapshot includes:

* System Information:
    * Mbed OS Version: Will currently default to 999999
    * Compiler ID
        * ARM = 1
        * GCC_ARM = 2
        * IAR = 3
    * [CPUID Register Information](#cpuid-register-information)
    * [Compiler Version](#compiler-version)
* CPU Statistics
    * Percentage of runtime that the device has spent awake versus in sleep
* Heap Statistics
    * Current heap size
    * Max heap size which refers to the largest the heap has grown to
* Thread Statistics [Disabled in bare-metal]
    * Provides information on all running threads in the OS including
        * Thread ID
        * Thread Name
        * Thread State
        * Thread Priority
        * Thread Stack Size
        * Thread Stack Space

#### Compiler Version

| Compiler | Version Layout |
| -------- | -------------- |
| ARM      | PVVbbbb (P = Major; VV = Minor; bbbb = build number) |
| GCC      | VVRRPP  (VV = Version; RR = Revision; PP = Patch)    |
| IAR      | VRRRPPP (V = Version; RRR = Revision; PPP = Patch)   |

#### CPUID Register Information

| Bit Field | Field Description | Values |
| --------- | ----------------- | ------ |
|[31:24]    | Implementer       | 0x41 = ARM |
|[23:20]    | Variant           | Major revision 0x0  =  Revision 0 |
|[19:16]    | Architecture      | 0xC  = Baseline Architecture |
|           |                   | 0xF  = Constant (Mainline Architecture) |
|[15:4]     | Part Number       | 0xC20 =  Cortex-M0 |
|           |                   | 0xC60 = Cortex-M0+ |
|           |                   | 0xC23 = Cortex-M3  |
|           |                   | 0xC24 = Cortex-M4  |
|           |                   | 0xC27 = Cortex-M7  |
|           |                   | 0xD20 = Cortex-M23 |
|           |                   | 0xD21 = Cortex-M33 |
|[3:0]      | Revision          | Minor revision: 0x1 = Patch 1 |


You can view individual examples and additional API information of the statistics collection tools at the bottom of the page in the [related links section](#related-links).


### Output

To view the serial output you can use any terminal client of your choosing such as [PuTTY](http://www.putty.org/) or [CoolTerm](http://freeware.the-meiers.org/). Unless otherwise specified, printf defaults to a baud rate of 9600 on Mbed OS.

You can find more information on the Mbed OS configuration tools and serial communication in Mbed OS in the related [related links section](#related-links).

The output should contain system information transmitted periodically over UART.

## Troubleshooting

If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.

## Related Links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html)
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html)
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html)

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
