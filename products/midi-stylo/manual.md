---
layout: default
---
## General
This is the user documentation for the Midi Stylophone II project (using "reissue" stylophone with rather than the original analog model). This stylophone is pimped up with <br><br>
**BUTTONS!** - Four tactile switches for controlling the mode of the stylophone. These are placed along the left rear edge of the body and I'll refer to them as A, B, C and D. Button A is the one closest to the left as you face the front of the Stylophone.<br><br>
**FLASHING LIGHTS!** - An RGB LED located on the front right edge indicates the current mode.<br><br>
**TILT SENSOR!** - An accelerometer detects tilt left to right and front to back and uses these to control MIDI pitch-bend and modulation wheel respectively. This can be enabled and disabled while playing.<br><br>
**SOCKET!** - All that MIDI magic has to get out somewhere<br><br>
## Basic Operation
When the Stylophone is powered up (using the regular power switch on the front panel) the MIDI circuit is in standby mode and the LED on the front panel lights in dim red. The MIDI circuit takes a second or two to boot, so there is a delay before the LED comes on. The Stylophone can be played normally through the speaker (don't forget to turn up the volume so you can hear it).<br><br>
Pressing any of the buttons A,B,C or D wakes the MIDI circuit up. The LED on the front panel changes colour from dim red, and touching the Stylus to the keypad will send out MIDI notes.<br><br>
The MIDI circuit can work in parallel with the normal Stylophone sound, so sounds can be coming from the Stylophone speaker while MIDI is being sent. You will probably want to tune the Stylophone to your synth module (using the normal tuning control on the underneath) if you'll hearing both at the same time.<br><br>
When the MIDI circuit is out of standby mode, it regularly "polls" the Stylophone keypad and this sound might be audible as "static" on the Stylophone sound (Sorry, not sure what to do about this). Typically you might turn the Stylophone volume control all the way down when playing MIDI and just use your synth sounds.<br><br>
MIDI notes are always sent on channel #1. Ensure your synth is set up to listen on this channel.<br><br>
MIDI notes are always sent with a full scale velocity (127). You can mess with the mod wheel settings to get some dynamics via the tilt sensor.<br><br>
The Stylophone keyboard has 20 notes (1.5 octaves from A to E) so there is an overlap in the note ranges of shifted octaves. The MIDI note ranges are as follows:<br><br>
* Octave shift -2 maps MIDI notes 21 (A0) through 40 (E2)<br>
* Octave shift -1 maps MIDI notes 33 (A1) through 52 (E3)<br>
* Octave shift 0 maps MIDI notes 45 (A2) through 64 (E4)<br>
* Octave shift +1 maps MIDI notes 57 (A3) through 76 (E5)<br>
* Octave shift +2 maps MIDI notes 69 (A4) through 88 (E6)<br>

## Button Functions
The basic function of each of the four buttons on the back is as follows:<br><br>

* A. **NOTE HOLD** - Hold button "A" down (by itself) while playing notes on the Stylophone keypad and they will "ring on" after you stop touching the note, even after you release the button. In MIDI terms, the NOTE ON message for the note is sent but no NOTE OFF is sent. You can have any number of notes "held" at the same time (up to the polyphony of your synth) even across different octave shift ranges. To cancel the note hold you need to press and then release button "A" without touching the stylus to the keyboard (i.e. press and release the hold button without holding any new notes). The held notes are cancelled by sending out individual NOTE OFF messages for all previously held notes.<br><br>

* B. **TILT SENSOR** - While button "B" is held down (by itself), the Stylophone will send out both MIDI pitch bend messages (when tilted from left to right) and MIDI modulation wheel messages (when tilted backwards and forwards). When the button is released the controller messages are stopped, the pitch bend controller is restored to center position (no pitch bend) but the mod wheel stays at its last position.<br><br>

* C. **OCTAVE SHIFT DOWN** - Press and release button "C" to transpose the keyboard range down by one octave. If a note is currently playing, it will stop playing at the previous note pitch, and will immediately start playing at the new note pitch. A shift range of five octaves is supported.<br><br>

* D. **OCTAVE SHIFT UP** - Press and release button "D" to transpose the keyboard range up by one octave. If a note is currently playing, it will stop playing at the previous note pitch, and will immediately start playing at the new note pitch.<br><br>

## Special Button Combinations

* A + B. **TILT MODE** - Press and hold button "A" then (while still holding it) press and release button "B". This puts the Stylophone in "tilt mode" so you do not need to keep holding button "B" to send the controller messages. Tilt mode lasts until you press and release button "B" again.<br><br>

* A + D. **STANDBY** - Press and hold button "A" then (while still holding it) press and release button "D". This puts the Stylophone back into standby without powering it of and off. This can be useful to kill the "static" interference that might be heard in the sound output while playing the Stylophone normally.<br><br>

* B + C + D. **TILT RECALIBRATION** - Press and hold buttons "B", "C" and "D" together to calibrate the accelerometer (tilt sensor) so that the "at rest" position is stored. As soon as the buttons are pressed the LED will flash PURPLE for a few seconds delay. Ensure Stylophone is resting on a still, level surface. While the calibration takes place the LED flickers at a rapid rate for a couple of seconds then returns to normal operation. It should not be neccessary to do this very often (perhaps only if you find the pitch bend is "off center" when not tilted)<br><br>

## The LED
There is method in the madness.. the wild flashing colours of the LED do actually indicate something sensible!<br><br>
First off...<br><br>

* **DIM RED** - MIDI circuit is in standby mode but Stylophone is playable via internal speaker<br><br>

Other steady colours indicate the following:<br><br>

* **DIM BLUE** - Octave shift is +2.<br><br>

* **BLUE** - Octave shift is +1.<br><br>

* **WHITE** (Bluey white) - Octave shift is at centre.<br><br>

* **GREEN** - Octave shift is -1.<br><br>

* **DIM GREEN** - Octave shift is -2.<br><br>

The LED may also flash, alternating between one of the above colours (for octave shift) and one of the following<br><br>

* **YELLOW/OTHER** - Notes are held<br><br>

* **PURPLE/OTHER** - Tilt is active<br><br>

* **YELLOW/PURPLE** - Notes are held and tilt is active<br><br>

There are also flash patterns associated with tilt calibration as described in the previous section.