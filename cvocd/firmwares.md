---
layout: default
---

# FIRMWARES

This page lists versions of the CV.OCD firmware which can be downloaded as SYSEX files and programmed
on to the device using a SYSEX librarian or MIDI tool (See the CV.OCD manual for information)

BETA releases are new and have been tested but are not yet pre-installed in new devices. However
feel free to try them out and let me know if you see any issues.

## Version 1.2 BETA (28 January 2017) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Current/cvocd_rev1.2beta.syx)

- Adds Hz per Volt handling, up to maximum of 8 volts (for C5, MIDI note 72). Pitch bend is handled, but fractional (bent) note CV is interpolated linearly, so resulting pitch glide between whole notes will not be quite linear in Hz/V mode.

- Adds Transport Start/Stop gate trigger to drive sequencers that have a single gate input to toggle their running status on and off. MIDI clock START, STOP or CONTINUE will trigger the gate output in this mode.

## Version 1 (17 October 2016) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Current/cvocd_rev1.0.syx)

This is the original release version of the CV.OCD firmware!