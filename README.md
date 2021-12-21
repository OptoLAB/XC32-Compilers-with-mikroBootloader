# XC32 Compilers with mikroBootloader
 Using MPLAB X IDE and XC32 Compilers with preloaded USB-HID bootloader from Mikroelektronika 
## About project
These are test project (simple LED blink examples) for [MINI-32 for PIC32MX](https://www.mikroe.com/mini-pic32mx) and [MINI-32 for PIC32MZ](https://www.mikroe.com/mini-32-for-pic32mz) built using MPLAB development tools to be used with mikroBootloader. In these examples default assembly  startup code (crt0.S) is replaced with new (modified) startup code (startup.S) in order to avoid issues with program not executing or MCU resetting when using mikroBootloader.

Demo project is built using following ecosystem:
 - [MINI-32 For PIC32MX](https://www.mikroe.com/mini-pic32mx) and [MINI-32 For PIC32MZ]( https://www.mikroe.com/mini-pic32mx) starter boards by Mikroelektronika with a preloaded USB-HID bootloader.
 - [MPLAB X IDE v5.15](https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem) Integrated Development Environment by Microchip.
 - [XC32 v2.15](https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem) free compiler version for 32-bit MCUs by Microchip.
 - [mikroBootloader v2.8.0.0](https://libstock.mikroe.com/projects/view/1862/mikrobootloader) free and simple application by Mikroelektronika for programing MCUs with a preloaded USB-HID bootloade

More info can be found [here](https://www.optolab.ftn.uns.ac.rs/index.php/education/project-base/280-using-mplab-x-ide-and-xc32-compilers-with-mikrobootloader)
