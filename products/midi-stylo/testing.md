---
layout: default
---
Once you have completed the "brain" board it is useful to run some tests before proceeding (fixing faults will prove much more difficult once everything is connected together)<br>
<br>
There are some diagnostic programs provided, which can be run on the Atmega328 micro controller on the brain board. The first of these is the "led test" sketch<br>
<br>
Use the 6-pin header to upload the firmware to the board, but please note that the +5V power supply pin from the header is NOT connected. This is because otherwise problems could result when the board is also connected to the 4.5V battery supply in the Stylophone. When running the tests or reprogramming the board you will need to supply a separate 5V supply (or 4.5V if using the Stylophone batteries) to the board.<br>
<br>
The 6-pin header fits an "FTDI type" USB-TTL serial programming cable. The pins on this type of header are numbered<br>
<br>
1 - Reset (active low)<br>
2 - Microcontroller data transmit<br>
3 - Microcontroller data receive<br>
4 - +5V (pin not connected)<br>
5 - GND<br>
6 - Clear to send (Hard wired to GND)<br>
<br>
Since there is no reset switch on the board, if you are using a programming cable that does not connect to the reset pin you will need to manually reset the board at the start of the upload from the Arduino environment by either<br>
- Disconnecting the power prior to upload and connecting it only when the Arduino environment shows "Uploading"
- Briefly connecting pin 1 to GND with a wire as the upload starts.
<br>
To upload to this board from the Arduino environment you should select board type "Arduino Duemilanova w/ATMega328"<br>
<br>
The first test to try is the "check_led" sketch ([https://github.com/hotchk155/MIDI-Stylo/tree/master/check_led](https://github.com/hotchk155/MIDI-Stylo/tree/master/check_led))
. Once uploaded, the RGB LED should repeatedly show the following colour sequence: RED-OFF-RED-OFF-GREEN-OFF-BLUE-OFF<br>
<br>
The next test is to run the "check_accel" sketch ([https://github.com/hotchk155/MIDI-Stylo/tree/master/check_accel](https://github.com/hotchk155/MIDI-Stylo/tree/master/check_accel))
. Once loaded, the LED should blink red. With the programmer still attached, in the Arduino environment select Serial Monitor from the tools menu. Ensure the baud rate is 9600. You should see a list of figures rapidly being dumped out. For example<br>
<br>
391,512,502<br>
392,513,502<br>
391,512,501<br>
392,513,502<br>
<br>
When you tilt the board you should see the values changing. By tilting the board in each possible direction you should be able to get a variation in each individual value of up to 300 points (typically the value range from tilting is about 300-600). When the board is stationary the values should not vary by more than a few units (e.g. less than 3 units each way due to "noise"). With some experimentation you should be able to vary the value of a single axis at a time by learning the corresponding tilt direction.<br>
<br>
Problems with the accelerometer or connections can be seen as <br>
- One or more values does not change at all or cannot be changed by more then a few units (e.g. <10) by tilting fully
- One or more values oscillates or changes by large amounts (e.g. >10 units) without movement of the board
<br>
Next run the "check_buttons" sketch ([https://github.com/hotchk155/MIDI-Stylo/tree/master/check_buttons](https://github.com/hotchk155/MIDI-Stylo/tree/master/check_buttons)). Use the serial monitor to watch the status read from the four mode buttons. Make sure that the buttons individually register as pressed when held down.<br>
<br>
Once these basic checks are working, we will move on to the checks of the stylus pad scanning...<br>