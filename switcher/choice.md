---
layout: default
---

# Which Switcher?

There are two different MIDI switchers available. They both have the same essential soul (i.e. they share firmware) but differ in the way  switching is implemented. There are some pretty specific reasons to favour one over the other for a given application, so I will try to guide you...

# Transistor Based

The transistor-based MIDI-Switcher is the original. It is smaller and slicker. It is probably the default choice if you are looking at something like MIDI driven electric percussion.

## PROS

- Efficient, transistor based switching
- Compact and simple design
- Supports PWM-based "switching intensity" which can be modulated via MIDI velocity, CC etc.
- Up to 5A per channel current handling in rev 5 board (1A per channel in earlier revisions)

## CONS

- Common ground, low side switch: Means that this is really an eight channel power switch, and cannot be used for isolated signal switching (as you may need for something line a guitar channel switch). 
- Switching action is "single pole single throw". The outputs are on or off - there is no "normally closed" path.
- All the switched current is routed through the PCB. This is fine for most transient loads like solenoids, but is not good for heavy continuous current loads. Recommendation is to limit total combined continuous current loading to 5A.
- DC only switching, cannot switch AC power or signals

# Relay Based

## PROS

- High (10A) current capacity per output 
- Output terminals are per relay, so there is no "total current" limitation imposed by PCB
- Switches are electrically isolated from each other (this is probably the greatest advantage of using relays, as it allows a relay to arbitrarily replace any mechanical switch)
- "Single pole, double throw" switching. Each relay has a "normally closed" switch path which opens additional applications (e.g. a MIDI controlled, switch based H-bridge for reversible control over motors)
- Can switch AC power and signals
- Possiblity to switch mains power, although you are on your own with this! The relays are 110V/220V mains-rated, but given the potentially lethal danger here I can only say I DO NOT RECOMMEND ATTACHING ANY MAINS POWER SUPPLY TO THIS PRODUCT UNLESS YOU ARE A QUALIFIED ELECTRICIAN!!! IF YOU DO SO IT IS AT YOUR OWN RISK!!! NOTHING TO DO WITH ME, MATE!!!


## CONS

- Relays are clunky, inefficient devices. They waste much more power than transistors (although it is unlikely you will care very much)
- Relays are electro-mechanical devices and correspondingly suffer from wear and tear. They will wear out eventually.
- Relays are slow (Although they are still faster than humans can notice). The main drawback here is that the "switching intensity" of the MIDI switcher is NOT SUPPORTED FOR RELAYS since it relies on modulating very rapid switching sequences that cannot be support by mechanical relays.

# MY ADVICE

Q: I want to make a small/medium sized solenoid-based physical drum machine?
A: Transistors!

Q: I want to drive switch pedals (like guitar amp channel select) via MIDI
A: Relays!

Q: I want to drive some really big continuous loads with this thing (say a big motor)
A: Relays!

Q: I want to switch 12VDC light bulbs and dim them and stuff
A: Transistors!

Q: I want to control a set of mains lamps by MIDI
A: Be gone and don't darken my doorstep again!! (or contact me by email)

I made those questions up. If you have some genuine ones I'll answer and feature them!

# FAQ:
Q: Why can't you give a more specific maximum continuous DC current rating for the board?
A: I do not have, neither can afford, the facilities needed to safely test a PCB to destruction through over-current. The MIDI-Switcher PCB uses 2oz copper pour (i.e. double the standard copper track thickness) and load current is routed through both the top and bottom layer in parallel to increase handling. The maximum continuous current handling of the board is therefore probably greater than the 5A I quote, but I will not vouch for it and leave it up to you to find out for yourself - if you need to!