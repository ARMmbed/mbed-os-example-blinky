![](./resources/official_armmbed_example_badge.png)
# Blinky Mbed OS Example

The example project is part of the [Arm Mbed OS quick start guide](https://os.mbed.com/docs/mbed-os/v5.14/quick-start/index.html). It contains an application to repeatedly blink an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

The project can be built with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli). Please install Arm Mbed CLI.

Depending on the target, the example project can be built with GCC_ARM, ARM or IAR toolchain. Run the command below after installing ARM Mbed CLI to determine which toolchain supports your target.

```bash
$ mbed compile -S
```

Clone this repository on your system and change the current directory to where the project was cloned.

Modifying default Mbed OS configuration parameters can be done at application level using an application configuration file. By default ARM Mbed CLI looks for [`mbed_app.json`](https://os.mbed.com/docs/mbed-os/latest/reference/configuration.html), however the configuration file can be named anything. It can be passed to ARM Mbed CLI using the optional argument `--app-config` of the `compile` sub-command. This project comes with a configuration a file to modify default parameters of Mbed OS later on in the tutorial.

## Application functionality

The `main()` function is the single thread in the application, it toggles the state of a digital output connected to an LED on the target.

## Building and Running

1. Connect a USB cable between the USB port on the target and the host computer.
2. <a name="build_cmd"></a> Run the following command to build the example project and program the microcontroller flash memory:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin` and can alternatively be manually copied to the target which gets mounted on the host computer via USB.

## Bare metal
The binary above is built with the full Mbed OS library including its RTOS components. However, for single-threaded applications running on ultra-constrained targets, it is possible to obtain an application with an even smaller memory footprint using [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html) profile.
An application configuration file, [`config_bare_metal.json`](./config_bare_metal.json) is provided to build a binary with Mbed OS bare metal profile.

Run the following command instead of the one [above](#build_cmd) to build with Mbed OS bare metal profile:
```bash
$ mbed compile -m <TARGET> -t <TOOLCHAIN> --app-config config_bare_metal.json --flash
```

## Optional RTOS runtime statistics

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
