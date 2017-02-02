---
layout: default
---

# FAQ

This page is under construction

## Usage Questions

* **Output triggers on wrong MIDI note (For example you program CV.OCD to trip a gate in response to a D1 but you find it responds to D0 instead)** Octave numbering of notes is not actually standard, for example middle C (MIDI note number 60) can be named C3 or C4 in different devices/programs. CV.OCD uses C4 for middle C - most notably, Ableton Live uses C3. In Live you'll need to remember to sequence notes an octave higher. The actual MIDI note numbers however are always reliable, so think in terms of them if you can.
* **Yellow LED is not in sync with the beat** MIDI clock signals are just "ticks" and do not contain any count information. Since there are 24 MIDI clock ticks for every beat, a reference point is needed so that a slave can be put in "phase" with the master (they should always be running at the same "rate"). CV.OCD needs to see a MIDI "clock start" message to get its phase synched up. Usually just stopping and starting the transport on the master is enough (as long as the master is sending MIDI transport messages). In many cases it does not actually matter if the phase is out - the exception would be if you are sending clock outputs from the CV.OCD.

## Hardware Questions

* **Is Hz/Volt Supported?** Yes - but you may need to [upgrade your firmware](firmwares.html)
* **What is the gate voltage level** CV.OCD twelve gates are 5V (On) and 0V (Off) similar to Eurorack.
* **What is the CV voltage range** CV.OCD's four CV outputs can output from 0 to around 8 Volts.
* **What is the CV voltage accuracy** CV.OCD's four CV outputs have 12-bit DACs (Digital to Analog converters). The 12 bits are scaled over output range 0 - 8.192V giving a mininum voltage step of 0.002V. At 1V/Octave this corresponds to 2.4 cents.
* **Can the CV voltage scaling be "tweaked" to compensate for inaccurate volt to pitch scaling on a synth** Currently no, but I am looking to see if it can be supported.
* **Can I use one of the gates to get another CV output?** No, only the four CV outputs have DACs (digital to analog converters), the gates are logic (ON/OFF) outputs - this is a hardware limitation. If you do connect a gate output to a CV input on a synth you'll just get 2 levels (0V and 5V) - use it this way if you want to!
* **Can I use CV.OCD gates  with an S-Trig inputs?** A V-Trig to S-Trig converter would be needed. There are ways to [make one yourself](http://www.doepfer.de/faq/gen_faq.htm) quite simply just using a transistor and a resistor.

## Sysex Issues

* **Sysex load of patch fails** Sysex transmission can be interrupted by any MIDI "status message" such as note on/note off/CC etc. Usually a single sending device or piece of software (e.g. a DAW) will synchronise MIDI output to avoid interruption to Sysex transmissions. However if you are using multiple pieces of software (e.g. a Sysex manager running outside of a DAW) then no synchronisation is likely taking place between the programs and Sysex transmissions might get interrupted by other MIDI activity. Avoid this by stopping playback from a DAW while uploading Sysex to CV.OCD.

Also make sure you are not trying to use the firmware update mode! When you load a patch you DO NOT need to use the button. Powering up with the button held is only for firmware uploads. You send a patch to the CV.OCD in the normal play mode. 










