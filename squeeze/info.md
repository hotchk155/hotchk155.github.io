---
layout: default
---

# How It Works

Orange Squeeze actually contains four microcontrollers (MCUs) working together 

Three of these run a simple firmware program that act as a "bridge", receiving MIDI input from a serial port (UART) and passing it out over a fast IIC (Inter-integrated circuit) bus to the master MCU. The slaves just transfer the MIDI bytes "blindly" and do not really need to understand it... they just need to get it over to the master as soon as they can! 

The master MCU runs the fourth MIDI input and the merged MIDI output. It is responsible for getting MIDI information from the three slaves and merging the MIDI information to the output. To do this, the master needs to "understand" MIDI so that it can combine the four streams of messages in a way that will make sense to the receiver.

All of Orange Squeeze's MIDI inputs and outputs are implemented in hardware, giving more robustness than software emulation of serial ports.

## Slave Functions

Each slave is implemented in a PIC12F1822 microntroller, which has a maximum of six I/O (input and output) pins. Two of the pins are inputs that are either tied to 5V or GND. the combination of voltages on these two pins determines the "sequence number" of the slave chip, so that they can establish an unique ID even when identical firmware can be loaded on each.

The unique ID is needed to set up an I2C slave address for each of them. The three slaves use their sequence numbers to establish the following I2C slave addresses:

Slave #A :  0x70
Slave #B :  0x71
Slave #C :  0x72

Now the each slave has an unique address, the master can talk to them individually (more of this later)

The other pins on the slave are used for the MIDI input (one pin), the I2C bus (two pins), and the indicator LED (one pin).

The first thing the master does is send a special "Slave Start" command to each slave in turn. When the slave receives this command it causes the slave to reset its buffers, enable MIDI reception, and turn on the indicator LED for a short period (at start-up the LEDs for inputs A, B, C should light as the master establishes communication with them). The slave start command will also be sent to each slave if the master should reset for any reason (e.g. a partial power recycle), which then sets each slave to a known initial state. This helps get everything back in line should the master reset without all the slaves resetting!

Since I2C includes an "acknowledge" status, the master knows if any slave did not receive the "Slave Start" command and assumes the slave is not present and thereafter does not address it at all (this allows for hardware setups with only 2 or 3 inputs)

Otherwise the master will start periodically polling each slave for data. This poll is simply an I2C read transaction without any preceding command write. The first byte returned by the slave is the number of available data bytes and the master will then simply read each byte in turn.

Each slave uses a "double buffering" scheme where at any given time one buffer is being filled from incoming MIDI data from the serial port, and the other is being transmitted to the I2C port. Every time the master starts a new I2C read transaction, the buffers are swapped around so that the current receive buffer becomes the new transmit buffer and the old transmit buffer is cleared and set to be the new receive buffer.  

Each buffer has a capacity of 50 bytes. Should a MIDI character be received when the receive buffer is already full, that MIDI byte will be dropped and an "overflow" is reported to the master. The overflow is indicated by setting bit 7 of the count byte (the first byte returned to the master on each read transaction) and also by lighting the indicator LED solidly for a short period. 

The master has a special "overflow" signal LED so that it is obvious when any data has been lost from a slave. In practice data loss should only be expected if communication to the master is blocked (e.g. by an extended sysex message on a different input port) while large amounts of MIDI data are being received at the client.

## Master Functions



