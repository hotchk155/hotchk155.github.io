---
layout: default
---
# BANANA SPLIT

## Overview

Banana Split is a six-way MIDI thru box. MIDI information that comes in through the input is sent to all six outputs in parallel. 

Using a central "hub" to send MIDI to multiple devices, rather than chaining them together through their MIDI thru ports, has the advantage you can disconnect or remove power from one device without affecting the others. It also helps to reduce latency issues.

## Power

Banana Split has a 2.1mm power socket, such as those used with the wall wart adaptors for guitar pedals. Typically these adaptors are 9V DC with a positive outer barrel. Banana Split has a bridge rectifier and voltage regulator which mean it can also run with an adaptor that has a plug with a negative outer barrel, and can run from any voltage from about 7 volts up to about 15 volts (9V - 12V recommended, never exceed 15 volts).

## MIDI Input

Banana split has two separate MIDI inputs:

- A standard 5-pin DIN socket (the circular connector found on most music gear)
- A 3.5mm jack socket

Some newer equipment uses a 3.5mm jack output for MIDI. Some examples are the Novation Circuit and Arturia Beatstep Pro. These devices usually require an adaptor to break out a 3.5mm plug to a 5-pin DIN socket, however you can use a 3.5mm stereo jack to jack cable to connect these devices directly to the Banana Split. However please note

- You must use a STEREO jack cable. The plugs will have three connectors (Tip, Ring and Sleeve) rather than the two connectors (Tip and Sleeve) of a mono jack.
- **Do not try to use both the jack socket and the 5-pin DIN input at the same time**. You **cannot** merge MIDI inputs in this way. In the best case it simply won't work. In the worst cast you may cause damage to your MIDI sending equipment.
- Unfortunately the 3.5mm socket will not work with KORG equipment (or other equipment that uses the same wiring scheme as KORG) because KORG use a different wiring standard, as I'll describe below. Of course you can still use the 5-pin MIDI socket with KORG equipment, since that us an established standard. You could also make a cross-over cable to allow a KORG sequencer (such as SQ-1) to be used with the 3.5mm socket.

The 3.5mm socket is wired as follows

- TIP - MIDI signal current source. Equivalent to pin 4 of the MIDI socket. This signal is held at +5V by the sending device so is also called the "hot" connection.
- RING - MIDI signal current sink. Equivalent to pin 5 of the MIDI socket. The sending device switches between connecting this to ground (so a current can flow) and holding it at +5V or disconnecting it (so no current can flow)
- SLEEVE - Ground

The KORG wiring standard switches the functions of TIP and RING. If you want to make a cross-over cable you can simply switch the signals over on one of the connectors.

## MIDI Outputs

Banana split has six MIDI outputs, which are identical and hard-wired to share the same MIDI signal. There is no firmware processing of the signal, just electrical buffering (i.e. signal amplification). This means that latency between the input and output is kept to a bare minimum.

Since there is no firmware processing of the signal, it is **not** possible to apply any kind of filtering or conditional routing of the MIDI information (e.g. split different MIDI channels to different sockets). However most MIDI devices are designed to ignore all MIDI data not on their configured channel, meaning this is not an issue.

## Indicators

Banana Split has three LED indicators

- The BLUE LED blinks when there is any kind of MIDI activity detected (notes, clock, CC, sysex etc)
- The YELLOW LED blinks when a MIDI clock is present. MIDI clock is sent by the master device at a rate of 24 ticks per quarter note. For example if the clock is at 120bpm there will be two beats (quarter notes) per second, or 48 ticks. The LED blinks at the rate of once every 24 ticks, so indicates both the presence and the rate of the MIDI clock. However although the blink rate will be locked to the tempo, the flashes might be out of sync with the beat count. To make sure that the blinks are in sync you need to send a MIDI "start" message to Banana Split. This is usually a simply matter of stopping and restarting the master device.
- The RED LED is lit when power is present

## Microprocessor

While Banana Split does not apply any processing to the MIDI data that is passing through, it does contain a microprocessor (a small PIC microcontroller) which is used to control the activity and beat indicator LEDs. This chip listens in on the MIDI traffic passing through the box.

There are two unused output signals on the chip that you can make use of if you want to mod your box:

- A "divide by 2" beat clock is present on the pad marked "RA4" on the PCB. This signal can be used to sync devices that use a 1/8th beat voltage pulse for sync (such as KORG volca devices). You can take this to the tip of a 3.5mm jack, with the sleeve grounded (use the cathode of of C5 or C6 as a ground). You should use a series resistor (e.g. 1k) for short circuit protection.
- A "running" signal is present on the pad marked "RA2" on the PCB. This is held high (+5V) when a MIDI clock "start" or "continue" has been received, until a "stop" is received. If you take this signal outside the box you should use a 1k series resistor for short circuit protection.
