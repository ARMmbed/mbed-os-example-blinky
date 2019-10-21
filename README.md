![](./resources/official_armmbed_example_badge.png)
# Blinky Mbed OS Example

The example project is part of the [Arm Mbed OS quick start guide](https://os.mbed.com/docs/mbed-os/v5.14/quick-start/index.html). It contains an application to repeatedly blink an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

The project can be built with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli). Please install Arm Mbed CLI.

Depending on the target, the example project can be built with `GCC_ARM`, `ARM` or `IAR` toolchain. Run the command below after installing ARM Mbed CLI to determine which toolchain supports your target.

```bash
$ mbed compile -S
```

Clone this repository on your system and change the current directory to where the project was cloned.


## Application functionality

The `main()` function is the single thread in the application, it toggles the state of a digital output connected to an LED on the target.

## Building and Running

1. Connect a USB cable between the USB port on the target and the host computer.
2. <a name="build_cmd"></a> Run the following command to build the example project and program the microcontroller flash memory:
    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```
The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin` and can alternatively be manually copied to the target which gets mounted on the host computer via USB.


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
