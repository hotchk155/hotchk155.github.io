---
layout: default
---

# FIRMWARES

This page lists versions of the CV.OCD firmware which can be downloaded as SYSEX files and programmed
on to the device using a SYSEX librarian or MIDI tool (See the CV.OCD manual for information)

BETA releases are new and have been tested but are not yet pre-installed in new devices. However
feel free to try them out and let me know if you see any issues.

After loading any new firmware, **please reload your current CV.OCD patch via SYSEX** since some firmware updates 
will invalidate the patch stored in the CV.OCD memory.

## CURRENT RELEASE Version 3 (1 Oct 2017) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Archive/cvocd_rev3.0.syx)

- Same as 2.2 Beta - Renamed for general release

## Version 2.2 BETA (20 May 2017) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Archive/cvocd_rev2.2beta.syx)

- Added 1.2V/OCT support

## Version 2.1 BETA (20 May 2017) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Archive/cvocd_rev2.1beta.syx)

- Fixed a bug where negative pitch transpose did not work (could cause output at maximum CV instead)

## Version 2 (1 Apr 2017) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Archive/cvocd_rev2.0.syx)

- Same as 1.3 Beta - Renamed for general release

## Version 1.3 BETA (12 Feb 2017) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Archive/cvocd_rev1.3beta.syx)

- Fixes a bug where a CC assigned to a CV output would always listen on the global default MIDI channel rather than the specific channel defined for the CV output.

## Version 1.2 BETA (28 January 2017) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Archive/cvocd_rev1.2beta.syx)

- Adds Hz per Volt handling, up to maximum of 8 volts (for C5, MIDI note 72). Pitch bend is handled, but fractional (bent) note CV is interpolated linearly, so resulting pitch glide between whole notes will not be quite linear in Hz/V mode.

- Adds Transport Start/Stop gate trigger to drive sequencers that have a single gate input to toggle their running status on and off. MIDI clock START, STOP or CONTINUE will trigger the gate output in this mode.

## Version 1 (17 October 2016) [download](https://github.com/hotchk155/cvocd.a/raw/master/firmware/Release/Archive/cvocd_rev1.0.syx)

This is the original release version of the CV.OCD firmware!
