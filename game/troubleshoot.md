---
layout: default
---
## No Display, LED is not blinking
* Check that you have soldered the capacitors in the correct positions. If you accidentally solder the 100nF capacitors beside the crystal the device cannot boot up.
* Check battery polarity 
* Check orientation of all ICs
* Check solder joints
* Try to follow instructions in the following section in case there is a problem with the LED but the system has actually booted..

## No Display, LED is blinking
* The first revision of the firmware had an issue where where the menu code was confused by an out of range value of "last game played" which it read from uninitialised EEPROM on first bootup. The solution is to press buttons B and D immediately after startup. This should then display the menu. Select a game (e.g. Invaders) by pressing C then press reset. When the device reboots it should operate normally.
* Check you have the LED matrix fitted correctly (the top left corner should be indicated with a label). It is only possible to fit it correctly or rotated through 180 degrees. The latter case will not produce a display. You will need to desolder and refit the matrix. You are in for some fun. Sorry.
* Follow instructions for "partial display" below

## Partial display
* Check the orientation and fitting of the ICs and the solder joints on the resistors on the back of the board. Typically "missing rows" will be caused by misfitted shift register IC's (either side of LED matrix) or broken/bent IC pins on them. "Missing colums" would point to an issue with the resistors on the back of the board or badly fitted/bent or broken pins on the microcontroller chip (below the display)
* Try pressing firmly down on the LED display, the resistors and ICs in turn to see if any change results in the display. This can help track down the problem.
* If a single pixel seems to be at fault, the LED matrix may be faulty. Entire missing rows or columns would more likely indicate an issue with solder joints or with other components 

## LED does not work
* Check LED is soldered with correct polarity
* Check the soldering on the 1K resistor beside the speaker
* Check the LED directly with a voltmeter on "diode check" setting. 
* Replace the LED.

## No Sound
* Make sure sound is turned on via the menu
* Turn sound off and back on via menu
* Check the soldering of the piezo buzzer and the lower right 100nF capacitor
* Check the piezo buzzer has been soldered to the board the correct way round (anode at bottom)

## Cannot compile the firmware (Error: "Tone does not name a type")
* Download the Arduino Tone library from http://code.google.com/p/rogue-code/downloads/list. At the time of writing the link to the current version is [http://code.google.com/p/rogue-code/downloads/detail?name=Arduino-Library-Tone.zip&can=2&q=&sort=-uploaded](http://code.google.com/p/rogue-code/downloads/detail?name=Arduino-Library-Tone.zip&can=2&q=&sort=-uploaded). Copy the contents of the zip file to your /libraries/ subfolder of your Arduino installation folder. Restart the Arduino environment.<br><br>
If you are using a recent version of the Arduino library you may also find you encounter "Error Compiling" after installing the Tone library. There is an incompatibility between the current (at time of writing) Tone library and recent versions of the Arduino environment. This can be fixed by changing the file Tone.cpp as follows:
<br>
<pre>
//#include &lt;avr/interrupt.h>
//#include &lt;avr/pgmspace.h>
//#include &lt;wiring.h>
//#include &lt;pins_arduino.h>
**#include &lt;Arduino.h>**
#include "Tone.h"
</pre>
Comment out the first four #include lines and add a new one for Arduino.h

## Cannot upload new sketches from Arduino environment
* Make sure you have selected board type "Arduino Duemilanova w/ATMega 328"
* Make sure you have the correct COM port selected
* Make sure you have the correct drivers for your USB-TTL device
* Try closing and re-opening the Arduino environment (especially if you have just connected USB-TTL device while Arduino environment is running)
* Try rebooting your computer (especially if you have just installed drivers for a new USB-TTL device)
* Check wiring between the USB-TTL device and the header on the board
* Depending on the type of USB-TTL device you may need to reset the board when the Arduino environment shows "Uploading"
* Locate and open boards.txt (within your Arduino installation in a hardware/arduino folder) 
<pre>
##############################################################
atmega328.name=Arduino Duemilanove w/ ATmega328
atmega328.upload.protocol=stk500
atmega328.upload.maximum_size=30720
atmega328.upload.speed=57600
atmega328.bootloader.low_fuses=0xFF
atmega328.bootloader.high_fuses=0xDA
atmega328.bootloader.extended_fuses=0x05
atmega328.bootloader.path=atmega
atmega328.bootloader.file=ATmegaBOOT_168_atmega328.hex
atmega328.bootloader.unlock_bits=0x3F
atmega328.bootloader.lock_bits=0x0F
atmega328.build.mcu=atmega328p
atmega328.build.f_cpu=16000000L
atmega328.build.core=arduino
atmega328.build.variant=standard
</pre>

In this block, if your setting of **atmega328.upload.protocol** is set to **arduino** try changing to **stk500**. Save the file and restarted the Arduino environment.