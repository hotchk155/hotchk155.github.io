---
layout: default
---

# Which Switcher?

There are two different MIDI switchers available. They both have the same essential soul (i.e. they share firmware) but differ in the way  switching is implemented. There are some pretty specific reasons to favour one over the other for a given application, so I will try to guide you...

## Transistor Based

The transistor-based solid state MIDI-Switcher is the original. It is smaller and slicker. It is probably the default choice if you are looking at something like MIDI driven electric percussion.

### PROS

- Efficient, transistor based switching
- Compact and simple design
- Supports PWM-based "switching intensity" which can be modulated via MIDI velocity, CC etc.
- Up to 5A per channel current handling in rev 5 board (1A per channel in earlier revisions)

### CONS

- Common ground, low side switch: Means that this is really an eight channel power switch, and cannot be used for isolated signal switching (as you may need for something line a guitar channel switch). 
- Switching action is "single pole single throw". The outputs are on or off - there is no "normally closed" path.
- All the switched current is routed through the PCB. This is fine for most transient loads like solenoids, but is not good for heavy continuous current loads. Recommendation is to limit total combined continuous current loading to 5A.
- DC only switching, cannot switch AC power or signals

## Relay Based

### PROS

- High (10A) current capacity per output 
- Output terminals are per relay, so there is no "total current" limitation imposed by PCB
- Switches are electrically isolated from each other (this is probably the greatest advantage of using relays, as it allows a relay to arbitrarily replace any mechanical switch)
- "Single pole, double throw" switching. Each relay has a "normally closed" switch path which opens additional applications (e.g. a MIDI controlled, switch based H-bridge for reversible control over motors)
- Can switch AC power and signals
- The relays are 110V/220V rated and could be used to switch mains

**Disclaimer**: Given the potentially lethal danger with working with mains, I advise against this unless you are qualified to work with mains voltages. You do so at your own risk.

### CONS

- Relays are clunky, inefficient devices. They waste much more power than transistors (although it is unlikely you will care very much)
- Relays are electro-mechanical devices and correspondingly suffer from wear and tear. They will wear out eventually.
- Relays are slow (Although they are still faster than humans can notice). The main drawback here is that the "switching intensity" of the MIDI switcher is NOT SUPPORTED FOR RELAYS since it relies on modulating very rapid switching sequences that cannot be support by mechanical relays.

## MY ADVICE

Q: I want to make a small/medium sized solenoid-based physical drum machine?<br>
A: Transistors!<br>
<br>
Q: I want to drive switch pedals (like guitar amp channel select) via MIDI<br>
A: Relays!<br>
<br>
Q: I want to drive some really big continuous loads with this thing (say a big motor)<br>
A: Relays!<br>
<br>
Q: I want to switch 12VDC light bulbs and dim them and stuff<br>
A: Transistors!<br>
<br>
Q: I want to control a set of mains lamps by MIDI<br>
A: Relays... but see disclaimer above.<br>
<br>
I made those questions up. If you have some genuine ones I'll answer and feature them!<br>
<br>
