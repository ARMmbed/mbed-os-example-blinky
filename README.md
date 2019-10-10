# Blinky Mbed OS Example

## Introduction
The example shows Mbed OS features suchs as threads, thread delay, and inter-thread communication to blink an LED on supported [Mbed boards](https://os.mbed.com/platforms/). It also comes with configuration files to enable RTOS statistic and to build with [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/v5.14/reference/mbed-os-bare-metal.html) profile.

The project can be built with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/v5.14/tools/index.html). However, this example project specifically refers to the command line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

Depending on the target, the example project can be built with GCC_ARM, ARM or IAR toolchain. Run the command below after installing ARM Mbed CLI to determine which toolchain support your target.

```bash
$ mbed compile -S
```

Clone this repository on your system and change the current directory to where the project was cloned.

Select the section for the version of the application you wish to build:
* [Building and Running the RTOS application](#blinky_rtos)
* [Building and Running the bare metal application](#blinky_bare_metal)

## <a name="blinky_rtos"></a> Building and Running the RTOS application

1. Connect a USB cable between the USB port on the target and the host computer.
2. Run the following command to build the example project and program the microcontroller flash memory:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin` and can alternatively be manually copied to the target which gets mounted on the host computer via USB.

### Application functionality

The `main()` function calls `blinky_rtos()`, as part of the main thread, which starts two threads: `thread_producer()` and `thread_consumer`. `thread_producer()` periodically send messages to `thread_consumer()` via an inter-thread queue. `thread_consumer()` verifies the message correctness and toggle the state of a digital output connected to an LED on the target.

### Optional RTOS runtime statistics

`blinky_rtos()` can optionally take a snapshot of the device's runtime statistics and display it over serial to your PC. The example project has to be re-built with modified Mbed OS configuration parameters. Modifying default Mbed OS configuration parameters can be done at application level using an application configuration file. By default ARM Mbed CLI looks for `mbed_app.json`, however the configuration file can be named anything. It can be passed to ARM Mbed CLI using the optional argument `--app-config` of the `compile` sub-command. The application configuration file `config_rtos_stats.json` has been provided to enable runtime statistics to be printed.

Run the following command to build the example project with runtime statistics output:
```bash
$ mbed compile -m <TARGET> -t <TOOLCHAIN> --app-config=config_rtos_stats.json --flash
```

### View the serial output

To view the serial output you can use any terminal client of your choosing such as [PuTTY](http://www.putty.org/) or [CoolTerm](http://freeware.the-meiers.org/). Unless otherwise specified, printf defaults to a baud rate of 9600 on Mbed OS.

You can find more information on the Mbed OS configuration tools and serial communication in Mbed OS in the related [related links section](#related-links).

The output should contain the following block transmitted at the blinking LED frequency (actual values may vary depending on your target, build profile, and toolchain):

```bash
=============================== SYSTEM INFO  ================================
Mbed OS Version: 999999
CPU ID: 0x410fc241
Compiler ID: 2
Compiler Version: 60300
RAM0: Start 0x20000000 Size: 0x30000
RAM1: Start 0x1fff0000 Size: 0x10000
ROM0: Start 0x0 Size: 0x100000
================= CPU STATS =================
Idle: 98% Usage: 2%
================ HEAP STATS =================
Current heap: 1096
Max heap size: 1096
================ THREAD STATS ===============
ID: 0x20001eac
Name: main_thread
State: 2
Priority: 24
Stack Size: 4096
Stack Space: 3296

ID: 0x20000f5c
Name: idle_thread
State: 1
Priority: 1
Stack Size: 512
Stack Space: 352

ID: 0x20000f18
Name: timer_thread
State: 3
Priority: 40
Stack Size: 768
Stack Space: 664
```

The snapshot includes:
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
* Thread Statistics
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


## <a name="blinky_bare_metal"></a> Building and Running the bare metal application

An application configuration file, `config_bare_metal.json` is provided to build a version that uses [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/v5.14/reference/mbed-os-bare-metal.html) profile to create a single threaded application.

1. Connect a USB cable between the USB port on the target and the host computer.
2. Run the following command to build the example project with runtime statistics output:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --app-config=config_bare_metal.json --flash
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin` and can alternatively be manually copied to the target which gets mounted on the host computer via USB.

`"target.default_lib" : "small"` tells the build tool to use a small version of the C standard library for the toolchain selected if available. That would be Newlib-nano and MicroLib for GCC_ARM and ARM toolchains respectively.

### Application functionality

The `main()` function calls `blinky_bare_metal()`, as part of the single thread, which toggles the state of a digital output connected to an LED on the target.


## Troubleshooting
If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.

## Related Links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html)
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html)
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html)
* [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/v5.14/reference/mbed-os-bare-metal.html)
* [Mbed boards](https://os.mbed.com/platforms/)

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
