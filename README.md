# Blinky Mbed OS Example

The example project contains variants of an application to blink an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

The project can be built with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli). Please install Arm Mbed CLI.

Depending on the target, the example project can be built with GCC_ARM, ARM or IAR toolchain. Run the command below after installing ARM Mbed CLI to determine which toolchain support your target.

```bash
$ mbed compile -S
```

Clone this repository on your system and change the current directory to where the project was cloned.

Modifying default Mbed OS configuration parameters can be done at application level using an application configuration file. By default ARM Mbed CLI looks for [`mbed_app.json`](https://os.mbed.com/docs/mbed-os/latest/reference/configuration.html), however the configuration file can be named anything. It can be passed to ARM Mbed CLI using the optional argument `--app-config` of the `compile` sub-command. This project comes with configuration files for the different variants and configurations of the blinky application.

Select the section for the variant of the application you wish to build:
* [Blinky Wait application](#blinky_wait)
    * [Bare metal](#blinky_wait_bare_metal)
* [Blinky multi-threaded application](#blinky_multi_threaded)

## <a name="blinky_wait"></a> Blinky Wait application

### Application functionality

The `main()` function calls `blinky_wait()`, as part of the single thread, which toggles the state of a digital output connected to an LED on the target.

### <a name="build_blinky_wait_rtos"></a> Building and Running

1. Connect a USB cable between the USB port on the target and the host computer.
2. Run the following command to build the example project and program the microcontroller flash memory:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin` and can alternatively be manually copied to the target which gets mounted on the host computer via USB.

<<<<<<< HEAD
### Application functionality

The `main()` function calls `blinky_rtos()`, as part of the main thread, which starts two threads: `thread_producer()` and `thread_consumer`. `thread_producer()` periodically send messages to `thread_consumer()` via an inter-thread queue. `thread_consumer()` verifies the message correctness and toggle the state of a digital output connected to an LED on the target.

### Optional RTOS runtime statistics
=======
### <a name="blinky_wait_bare_metal"></a> Bare metal
The variant of the application [above](#build_blinky_wait_rtos) is built with the full Mbed OS library including its RTOS components. However, for single-threaded applications running on targets with ultraconstrains, it is possible to obtain an application with an even smaller memory footprint using [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html) profile.
An application configuration file, [`config_blinky_wait_bare_metal.json`](./blinky_wait/config_blinky_wait_bare_metal.json) is provided to build a binary with Mbed OS bare metal profile.
>>>>>>> Add application variants and Mbed OS bare metal tutorial

1. Connect a USB cable between the USB port on the target and the host computer.
2. Run the following command to build the example project with runtime statistics output:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --app-config=./blinky_wait/config_blinky_bare_metal.json --flash
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin` and can alternatively be manually copied to the target which gets mounted on the host computer via USB.

`"target.default_lib" : "small"` tells the build tool to use a small implementation of the C standard library for the toolchain selected if available. That would be Newlib-nano and MicroLib for GCC_ARM and ARM toolchains respectively.


## <a name="blinky_multi_threaded"></a> Blinky multi-threaded application

This variant shows Mbed OS features suchs as threads, thread delay, and inter-thread communication to blink an LED.

### Application functionality

The `main()` function calls `blinky_multithreaded()`, as part of the main thread, which starts two threads: `thread_producer()` and `thread_consumer`. `thread_producer()` periodically send messages to `thread_consumer()` via an inter-thread queue. `thread_consumer()` verifies the message correctness and toggles the state of a digital output connected to an LED on the target.

### Building and Running

1. Connect a USB cable between the USB port on the target and the host computer.
2. Run the following command to build the example project and program the microcontroller flash memory:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash --app-config=./blinky_multithreaded/config_blinky_multithreaded.json
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin` and can alternatively be manually copied to the target which gets mounted on the host computer via USB.

### Optional RTOS runtime statistics

It is possible to take a snapshot of the device's runtime statistics and display it over serial to your PC. See how [here](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).


## Troubleshooting
If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.

## Related Links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html)
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html)
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html)
* [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html)
* [Mbed boards](https://os.mbed.com/platforms/)

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
