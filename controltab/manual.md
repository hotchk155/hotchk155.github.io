---
layout: default
---

#Using synchtab

synchtab requires your ARPIE to have the following:

- The "hack header" socket which was added to mainboard version 3 and above
- Firmware version 4 or later

The firmware can be <a href="../arpie/update.html">upgraded</a> for free. However if you have an older ARPIE without the hack header socket you have a bit more of a problem. It IS possible to connect controltab to an older ARPIE by soldering on some extra wires, but the result will not quite so neat. Let me know if you need information on this - I may also add it to FAQ.

When you connect controltab, you need to tell the ARPIE to use it. This is done by changing the "hack header" settings (see the <a href="..\arpie\manual.html#hh">ARPIE manual</a>)

For example to assign the switch to MUTE and the 3 pots to Gate Length, Velocity, Mod Wheel:

* Press and hold the PLEN button until the LEDs change to show the system preferences menu 
* Change the state of LEDs 1-8 to show:
* OFF-OFF-ON-OFF-OFF-ON-OFF-ON

You will need to reset the ARPIE after making changes to these settings.

*NOTE: If you disconnect the controltab with the settings still enabled, you will have "random" stuff happening (this is because the ARPIE is still trying to reading values from the pots, but is instead receiving garbage values)*

To prevent this you need to disable the controltab inputs by going back to the PLEN menu and set the state of LED's 1-8 to
OFF-OFF-OFF-OFF-OFF-OFF-OFF-OFF
You will need to reset the ARPIE 

Several other parameters can be assigned... check in the <a href="..\arpie\manual.html#hh">ARPIE manual<a> for the full list.



