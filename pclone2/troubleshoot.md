---
layout: default
---

# Troubleshooting

OK, you built it, but things aren't quite working...
 
## Disconnect power and check things

- I would say things work first time about 50% of the time, about 49% of the other 50% is down to just one or two little errors that you can find and fix pretty quickly. Double check all the wiring first, since thats where the issue is most likely to be (in my experience!). Look for broken connections, loose connections things touching that should not be etc. Check the PCB soldering. Check the components are all in place and you have not left any off. Check you didn't use the wrong terminals on the output sockets.
 
## Is the LED On ?

So you may have wondered why there is an LED on the board when it is inside a box? This is where it gets useful.. if the LED is not on, it is likely that we don't have power getting to the board

- Check your power supply and connections
- Check the polarity of your supply against the (+) and (-) terminals on the board. The board has protection which prevents power getting to it if the polarity is wrong
- Make sure there is no sign of a short circuit. Some power supplies might warn of this - but if you have a multimeter you can check the resistance directly between (+) and (-) and make sure it is a high value (it may take a while for the reading to setting due to the capacitors charging)
- It is always possible the LED isn't working. If you have a voltmeter, check the voltage on the prototyping area to the right of the board (i.e. between the row marked "+" above the "A" row, and the row maked "-" below the "I" row)

## Did you let the magic smoke out?

- When you first applied power did any smoke come out or were there any popping or crackling sounds coming from the circuit? This is bad news and is most likely due to you mixing up the transistor types for Q3-Q6. The transistors will need to be replaced. There is also a workaround that will let you get sound in the meantime - email me about it if you think you're in this bad place.

## Have you turned it up?

- Might sound dumb, but when I made my first prototype I spent several annoyed minutes before realising the sensitivity control was turned right down. Turn all the control pots up full.
- The trimmer pot (R45 on the circuit board) will kill all output if turned right down. Turn it right up full!

## Sound Never Stops

- You might find that the oscillator can still be heard as a background noise after the decay envelope has finished (i.e. a sound is always present and can be modulated with PITCH and LFO controls). In this case use trimmer R45 to attenuate the sound until it is blocked when the envelope is closed. R45 will make the output quieter, so adjust carefully to find the best position. In most cases it is not neccessary to make any adjustment and R45 can be left at the full clockwise position.

