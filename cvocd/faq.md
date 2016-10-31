---
layout: default
---

# FAQ

This page is under construction


* **Is Hz/Volt Supported?** Currently CV.OCD supports only 1V/Octave scaling, however Hz/V support is in development.
* **What is the gate voltage level** CV.OCD twelve gates are 5V (On) and 0V (Off) similar to Eurorack.
* **What is the CV voltage range** CV.OCD's four CV outputs can output from 0 to around 8 Volts.
* **What is the CV voltage accuracy** CV.OCD's four CV outputs have 12-bit DACs (Digital to Analog converters). The 12 bits are scaled over output range 0 - 8.192V giving a mininum voltage step of 0.002V. At 1V/Octave this corresponds to 2.4 cents.
* **Can the CV voltage scaling be "tweaked" to compensate for inaccurate volt to pitch scaling on a synth** Currently no, but I am looking to see if it can be supported.

# Sysex Patch Issues

Sysex transmission can be interrupted by any MIDI "status message" such as note on/note off/CC etc. Usually a single sending device or piece of software (e.g. a DAW) will synchronise MIDI output to avoid interruption to Sysex transmissions. However if you are using multiple pieces of software (e.g. a Sysex manager running outside of a DAW) then no synchronisation is likely taking place between the programs and Sysex transmissions might get interrupted by other MIDI activity. Avoid this by stopping playback from a DAW while uploading Sysex to CV.OCD.











