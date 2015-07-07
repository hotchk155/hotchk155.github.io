---
layout: default
---

# ARPIE Build

When soldering a PCB, it generally helps to solder lower height components first. This stops the taller components getting in the way while we are working, and it lets us hold components in place for soldering by turning the board upside down on a flat surface and letting gravity be our third hand!

We will start with the base PCB (Printed Circuit Board), as shown below
<img src="img/B300.JPG">

Lets solder resistors R1, R2, R3 and R4. These are 220 ohm resistors which have a colour code of red-red-brown. In your kit the tape holding each set of resistors has been labelled with the resistor value.
Lets start by separating the four resistors from their tape and bending the legs as shown
<img src="img/Dsc01830.jpg">

Take a 220 ohm resistor and pass the legs through the holes in the board for resistor R1 (Resistors do not have a specific polarity and can be soldered "either way round"). 
<img src="img/B301.JPG">

Push the resistor flush to the board and bend the legs out slightly to hold it in place while you turn the board over to solder them.
<img src="img/B302.JPG">

Before you start soldering, make sure the tip of your iron is clean and up to temperature. Melt a little solder on to the tip to "tin" it. Use a soldering sponge or wire wool tip cleaner to remove excess solder leaving a thin bright silvery coating on the tip. 

Bring the tip of the iron to where the leg of the resistor emerges from the hole and, at the same time, bring the end of your solder wire to where the iron tip,resistor leg, and PCB hole all meet each other. Don't melt the solder directly on to the tip of the iron but rather melt it at the point where the iron tip touches the component leg. This should not longer than about 2-3 seconds. After applying the solder, remove the solder wire and continue to apply heat to the joint for about 1 second. You should see that the molten solder gets "sucked" into the plated PCB hole, forming a good  connection. Now remove heat and allow the joint to cool naturally for a few seconds (don't blow on it). The final joint should be bright and shiny, not dull or grey.

Use your wire wool tip cleaner or sponge to keep the tip of the iron clean. Clean excess solder from the tip every time you make a solder joint and re-tin it frequently. A clean, well tinned tip is the key to making good consistent solder joints.
<img src="img/B303.JPG">

Lets continue solder all the resistors that are fitted flat to the board. These are 

* R1, R2, R3, R4 - 220 Ohm (red-red-brown code) resistor
* R5, R6, R7, R8 - 1.5 kOhm (brown-green-red code) resistor
* R9, R10 - 10 kOhm (brown-black-orange code ) resistor
* R11, R12, R19, R20 - 1 kOhm (brown-black-red code) resistor

Your board should now look like this
<img src="img/B304.JPG">

Now lets add the 1N4148 small signal diodes, D1 and D2. These have tiny orange and black glass packages. There is a black stripe on the cathode end which aligns with the stripe shown on the diode symbol on the board.

Unlike resistors, diodes DO have a polarity and need to be soldered a specific way around. Both the diode and the symbol representing its location on the PCB show a thick line marking one end of the diode (the Cathode)

Solder the diodes as you have resistors. Please note that diodes are a bit more heat sensitive than resistors - so don't cook them too long with the iron!
<img src="img/B305.JPG">

Next we will add the crystal (X1) and the two 33pF ceramic capacitors C5 and C6 (These are marked with the code "33")
<img src="img/B306.JPG">

Solder the four 100nF ceramic capacitors (C1, C2, C3, C4). These have a "104" code. 
<img src="img/B307.JPG">

**NOTE:** An additional 100nF capacitor is provided that can optionally be soldered into position C9. This capacitor allows certain types of programmer to automatically reset the microcontroller for firmware uploads (so the RESET button does not need to be pressed manually). However not all programmers implement auto-reset and those that do can reset the microcontroller at inopportune times (such as when another USB device is plugged in to the computer). If in doubt, leave C9 off the board... you can always add it later.

Next we'll solder the power switch. I recommend placing it in the holes and turning the board upside down on a flat surface so that the weight of the board holds the switch in place. Solder just the middle pin, turn the board back over and ensure the switch is flush to the board and parallel to the edge (if not, re-heat the joint while pressing the switch down to the board). Finally solder the remaining 2 pins.<br>
<img src="img/B308.JPG">

Now we will solder the diagnostic LEDs (LED1, LED2, LED3) to the board. I used green LEDs on the base board  and red LEDs on the control surface but feel free to mix and match the red and green LEDs as you like (but I advise against mixing them with the blue LEDs since those have quite different characteristics).

LEDs have two legs, one of which is longer than the other. The longer leg is the anode (+) terminal. 
<img src="img/Dsc01852.jpg">

Note the symbol printed on the PCB clearly marks which hole is for the anode (+) leg. Like other diodes, LEDs do have a polarity and will not work if they are soldered in the wrong way around. They will also be a bitch to desolder, so make sure you get them right first time :) Once again avoid cooking LEDs for too long as they can be damaged by excessive heating.
<img src="img/Dsc01853.jpg">

Solder the LEDs nice and flush to the board as shown.
<img src="img/B309.JPG">

Now we will add the IC (integrated circuit) sockets. These have a little notch at one end which indicates "this way up". You will also see the IC symbol on the board show a similar notch marking. Place the socket in the holes, aligning the notches. Strictly speaking a socket will work either way round, but the notch is a convention, there to help you when you come to insert the IC's into the sockets.
<img src="img/B310.JPG">

I recommend fitting the IC sockets one at a time. Turn the board over and solder two opposite corner pins of the socket. Now check the socket is flush against the board (you can re-heat the solder and press down if you need to adjust it). Once the socket is flush on the board, solder the remaining pins.
<img src="img/Dsc01859.jpg">

Solder the three 8 pin sockets and the large 28 pin socket. Note that sockets are not strictly essential since we could solder the ICs directly to the board. However sockets allow us to easily replace an IC and also save them from the soldering heat (IC's can be heat sensitive). Since IC's tend to be the most expensive and sensitive components of a circuit, it is always a good idea to invest in sockets for them.
<img src="img/B311.JPG">

We still have some resistors to solder. We have left them until now because we will solder them in a vertical arrangement. The remaining resistors are

* R18 - 220 Ohm (red-red-brown code) resistor
* R13 - 10 kOhm (brown-black-orange code ) resistor
* R14, R15, R16, R17 - 1 kOhm (brown-black-red code) resistor

We prepare them by bending one leg as shown below
<img src="img/Dsc01861.jpg">

Use the outlines printed on the board as a guideline to put the longer leg through the hole marked for the body of the resistor as shown below.
<img src="img/B312.JPG">

The component outlines alternate the orientation of each vertical resistor. This helps prevent the legs of the resistors touching each other.
<img src="img/B313.JPG">

Now we'll solder the transistor TR1. This is a small black component with three legs, and a D-shaped case, which helps us to correctly orient the legs. Start by slightly bending out the centre leg as shown.
<img src="img/Dsc01867.jpg">

The symbol on the PCB aligns with the D-shape package. Make sure you align it correctly - a transistor has a polarity and won't work if soldered in the wrong way around.
<img src="img/Dsc01868.jpg">

The transistor will stand a few mm above the board when soldered. Avoid overheating the transistor when soldering it.
<img src="img/B314.JPG">

Add the 6 pin programming header. Again it helps to invert the board and let its weight hold the strip in place while you solder one pin, ensure it is straight, then solder the others.
<img src="img/B315.JPG">


Now solder the reset switch making sure it is flush to the board (once again it helps to start by soldering just 2 opposite corner legs then checking position and adjusting if needed before soldering the other legs)
<img src="img/B316.JPG">

Next up, its the two electrolytic capacitors (C7 and C8). These have a specific polarity to observe. The anode (+) is the longer leg and also the capacitor package has a white band marking the cathode. 
<img src="img/B317.JPG">

The symbol on the board indicates the anode hole with a + symbol.
<img src="img/Dsc01878.jpg">

Next we'll solder the 20 way and 6 way sockets. Again it helps to use gravity to hold the parts in place while soldering. 
<img src="img/B318.JPG">

Now solder the four 1N4001 rectifier diodes D3, D4, D5, D6. Bend these like we did with the vertically mounted resistors. To match the photograph, locate the silver anode stripe on the body of the diode, then bend the leg on the opposite end, so we can mount the stripe flush against the board as shown below. All four diodes have the same orientation and they **must** be soldered the correct way around. **WARNING: You can damage your kit and/or DC power supply if you solder any of these four diodes the wrong way around!**<br>
<img src="img/B319.JPG">

Now solder the DC power socket, starting by soldering just one pin then checking and adjusting the position before soldering the remaining two pins
<img src="img/B320.JPG">

Place the 3 MIDI sockets in their holes and turn the board over. Start by soldering just the pins that are closest to the edge of the board, so you can ensure it is flush to the board (Its important the the sockets are flat to the board to reduce strain on the solder connections when plugging/unplugging cables). When you are happy the sockets are flush, solder all remaining pins.
<img src="img/B321.JPG">

Now add the voltage regulator. This part must be soldered the right way around. The metal tab lines up with the marking on the board as shown in the photo below.
<img src="img/B322.JPG">

Fit the battery holder, passing the M2.5 bolts through the holes in the battery holder and corresponding holes in the board.
<img src="img/B323.JPG">

Fit nuts to the bolts and tighten before soldering the battery connections and trimming the legs
<img src="img/B324.JPG">

Now the fun starts! Our first sanity check is to insert a battery and ensure the power LED lights when we turn the slide switch on
<img src="img/B325.JPG">

Before we insert the ICs it is good to check the supply voltage to each. If you have a voltmeter, check the voltage between each pair of points shown below. Red is positive, Green is ground. In each case the voltage should be 5V when the battery power is on. You may see a small variation (e.g 5.02V) which is not a concern.
<img src="img/Dsc01901.jpg">

Turn off the power and carefully insert the PIC microcontroller (IC2) into its socket. Pay special attention to the notch on the end of the package, which should align with the corresponding notch on the board and socket. Switch on the power. LED2 next to the IC should blink rapidly 3 times, then settle into a cycle of one blink every 2-3 seconds.
<img src="img/B326.JPG">

Turn off power and insert the ATMega microcontroller (IC1) and the two 6N138 opto-isolators (IC3, IC4). The opto-isolators may have a "dimple" on their case in place of the the notch. Align the dimpled end of the IC with the notched end of the socket.
<img src="img/B327.JPG">

Turn on the power. LED1 should start a steady blinking. LED2 should blink as before.
<img src="img/B328.JPG">

Now use four M3 bolts to attach the four 25mm threaded pillars to the four corners of the board
<img src="img/B329.JPG">

Attach the rubber feet to the underneath of the board as shown. These are important to stop ARPIE scratching surfaces on which it is placed.
<img src="img/B330.JPG">
<br>
And so, on to the control surface! You will notice the the underside of the control surface board contains two pre-soldered surface-mount ICs and two small surface-mount capacitors. If these are missing or damaged let me know!
<img src="img/Dsc01920.jpg?raw=true">

Turn the board over and start by inserting the sixteen 6x3mm tactile switches 
<img src="img/Dsc01921.jpg?raw=true">

Turn over the board and solder a single pin of each switch. Ensure that each switch is completely flat against the board before soldering the second pin. Re-heat and press down with a thumb if you need to re-seat a crooked switch.
<img src="img/Dsc01922.jpg?raw=true">

Now insert the 6x6mm tactile switches in their holes
<img src="img/Dsc01924.jpg?raw=true">

Turn the board over and solder two opposite corners of each switch. Again the idea is to hold the component to the board while still giving us an opportunity to adjust it before we solder the other two pins and commit ourselves. Getting components totally flat to the board gives them mechanical stability and just looks a hell of a lot better!
<img src="img/Dsc01925.jpg?raw=true">

After switches are completely soldered, use side cutters to trim the legs nice and short
<img src="img/Dsc01928.jpg?raw=true">

Now insert the blue LEDs in the holes. PLEASE remember to check the polarity carefully. The longer LED leg is the (+) terminal and should pass through the hole in the board labelled +
<img src="img/Dsc01929.jpg?raw=true">

I suggest that you bend the cathode LED flat to the back of the board while you solder the anode
<img src="img/Dsc01931.jpg?raw=true">

Then trim the anode leg. Before you solder the cathode leg check the LEDs are flat to the board. WARNING: Getting the blue LEDs aligned consistently and flush to the board is probably the most important thing for making your ARPIE look cool vs it looking a bit of a mess! It is really worth spending time on this part. Believe me I speak from experience :-\
<img src="img/Dsc01932.jpg?raw=true">

When the blue LEDs are soldered, add the four red indicator LEDs (or green if you took that road) 
<img src="img/Dsc01934.jpg?raw=true">

Now the exciting bit.. start the drum roll... insert the 20 way long pin header strip into the socket on the base board. Orient it so the plastic support strip is at the bottom and push it down as far as it will go.
<img src="img/Dsc01936.jpg?raw=true">

Place the control surface board on top of the standoff pillars so that the 20 way pin header emerges through the set of holes in the lower right of the control surface
<img src="img/Dsc01938.jpg?raw=true">

Insert two of the M3 bolts to hold the board in the correct orientation
<img src="img/Dsc01939.jpg?raw=true">

Solder the pins from the top and trim the excess legs with side-cutters (Wear eye protection - those bits of legs fly off like bullets!) 
<img src="img/Dsc01941.jpg?raw=true">

Turn on the power - after a couple of seconds boot-up time, the blue LEDs should light up. This is a good time to ensure the LEDs are straight. If not you might still be able to reseat them with patience and care, but be careful of overheating the LEDs.
<img src="img/Dsc01943.jpg?raw=true">

And finally - we are done. Get some MIDI gear plugged in an make some sounds!
<img src="img/Dsc01945.jpg?raw=true">
