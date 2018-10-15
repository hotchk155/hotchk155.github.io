---
layout: default
---

# PCLONE2 Mods

Here are some mods I have used on the PCLONE2. I am not an expert on analog electronics so these were mainly found by educated guesswork, trial and error. I am always grateful for new ideas or ways these mods might be improved.

## Pitch CV

This is a very simple mod where we apply the CV directly to the point where the LFO modulates the VCO pitch. We use a resistor (I used 100k) so the CV is mixed with the signal from the LFO and voltage from the pitch control/sweep circuit. This is NOT a tuned CV (no 1V/octave or anything!) and you may find that you need to use CV's within a narrow part of the full voltage range for the pitch to be affected usefully. However, for just a resistor and a bit of wire, this is a nice mod. I may try to refine it at a later time (in particular to expand the useful voltage range)

Solder a 100k resistor to the top pin of an unused CV socket. Solder a wire to the other end of the resistor
<img src="img/D70.JPG">

Connect the other end of the wire to the left tab of the DEPTH pot. Done!
<img src="img/D71.JPG">

## Decay CV

Calling this a "Decay CV" might be overstating it a bit, but this is a quick mod that can give some nice rhythmic variations when used in a sequence. Basically the CV is used directly to charge the capacitor (C8) that controls the VCA decay and the pitch sweep. We use a diode to prevent any current being sunk by the CV connection when the voltage is lower than the output of the trigger circuit. This relies on your sequencer having a fairly low impedance CV output and you should experiment with different pulse lengths and voltage levels, and also with interactions with gate pulses to the main trigger input.

Solder a piece of wire to the anode (stripe) of a 1N4148 small signal diode
<img src="img/D72.JPG">

Solder the other side of the diode to the top pin of an unused CV socket
<img src="img/D73.JPG">

Connect the other end of the wire to the hole above the SENS and DECAY terminals
<img src="img/D74.JPG">

Solder it from the back and trim the solder joint. Done!
<img src="img/D75.JPG">

