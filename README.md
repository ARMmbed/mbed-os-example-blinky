# Getting started with Blinky on mbed OS

This is a very simply guide with the steps required to get Blinky working on an mbed OS platform.

## Compile and download your application

### Clone the example

From the command line, clone this repository using git

```
$ git clone https://github.com/ARMmbed/mbed-os-blinky
cd mbed-os-blinky

```
### Update the example

Download mbed OS sources to your local copy.

```
mbed update

```

### Compile the example

Invoke `mbed compile` specifying the name of the platform and the toolchain

```
mbed compile -m K64F -t GCC_ARM

```

Your PC may take a few minutes to compile your code. At the end you should get the following result:

```
[snip]
+----------------------------+-------+-------+------+
| Module                     | .text | .data | .bss |
+----------------------------+-------+-------+------+
| Fill                       |   176 |     4 | 2246 |
| Misc                       | 37291 |  2224 | 2160 |
| core/hal                   | 15448 |    16 |  568 |
| core/rtos                  |  7318 |    24 | 2662 |
| features/FEATURE_IPV4      |    96 |     0 |   48 |
| frameworks/greentea-client |  1561 |    52 |   52 |
| frameworks/utest           |  2988 |     0 |  732 |
| Subtotals                  | 64878 |  2320 | 8468 |
+----------------------------+-------+-------+------+
Allocated Heap: 65540 bytes
Allocated Stack: 32768 bytes
Total Static RAM memory (data + bss): 10788 bytes
Total RAM memory (data + bss + heap + stack): 109096 bytes
Total Flash memory (text + data + misc): 68238 bytes
Image: .\.build\K64F\GCC_ARM\mbed-os-blinky.bin                  

```

### Program your board

Copy the binary file to the mbed device and press the reset button to start the program. You should see the LED of your platform turning on and off. Congratulations if you managed to complete this test!

## Export the project to Keil MDK and debug your application

From the command line, run the following command:

```
mbed export -m K64F -i uvision
```

You should see the following output:

```
Successful exports:
  * K64F::uvision       .\projectfiles\uvision_K64F\Unnamed_Project
```

Now you can start MDK and open the project generated above.

## Troubleshooting

1. Make sure mbed-cli is working correctly and version is greater than `0.8.0`
```
mbed-cli --version
```
If not, you can update the version easily:
```
pip install mbed-cli --upgrade
```



