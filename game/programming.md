---
layout: default
---
# 

## Adding a new Game Class
All games are implemented as classes that derive from CGame:

<pre>
class CGame 
{
  public:
    virtual void init() = 0;
    virtual void handleEvent(char event) = 0;
};
</pre>

If you have used C++ or Java this will be second nature... however if you are already confused what it basically means is that when you create your game you need to define it in the following way

<pre>
class CMyNewGame : public CGame 
{
  public:
    static void getGameIcon(byte *dst, byte count)
    {
       // this is where you define the menu icon for your game by 
       // loading data into the dst array. dst[0] thru dst[7] are the
       // red pixel rows and dst[8] thru dst[15] are the green pixels.
       // Each pixel row is 8 bits with bit 0 to the right side
       // The count parameter can be used for animation, blinking etc
    }
    void init()
    {
       // this function is called when your class is loaded. Use it
       // to initialise variables for the game
    }
    void handleEvent(char event)
    {
       // this function is how your game does everything else. We'll 
       // discuss this some more further on...
    }
};
</pre>

You can, of course, include other methods in your class, but the above are the minimum required by the game framework to use your class

Create your class in a header file named after the class, for example "MyNewGame.H" (In the Arduino IDE  you need to create a "new tab"). To work with the menu system you will need to add an additional line to your header file, after the class definition

<pre>
CGameFactoryImpl&lt;CMyNewGame&gt; MyNewGame;
</pre>

Obviously replace "MyNewGame" with your class name. This line is used by the framework to link your class into the Menu system so it can be selected and played.

Finally, hook your new game into the build by including your header file in AVRGame.ino. 

<pre>
// Include all game headers here
#include "InvadersGame.h"
#include "LanderGame.h"
#include "BreakoutGame.h"
<b>#include "MyNewGameGame.h"</b>
</pre>

There will be a limit (due to the constraints of the Microcontroller chip's memory) to the number of games that can be linked into the program at the same time - this is set by the MAX_GAMES definiton. 

However because the API creates the game classes dynamically (so there is only 1 class instantiated at a time) this helps optimise memory usage, allowing more games to be included in the program at a time.

## Handling Events
The most important part of your game is your handleEvent method. This gets called whenever something "interesting" happens... the rest of the time the game is considered idle and the main loop of the sketch spends its time updating the display. "Interesting" things are keypresses and timers. 

There are 4 buttons labelled A, B, C and D. For each there is a "press" and a "release" event, giving a full set of events as follows:

<pre>
  EV_PRESS_A
  EV_PRESS_B
  EV_PRESS_C
  EV_PRESS_D
  EV_RELEASE_A
  EV_RELEASE_B
  EV_RELEASE_C
  EV_RELEASE_D
</pre>

Every such event that happens is passed to your handleEvent method. You can choose to act on it or ignore it, but at least you are freed from polling the digital inputs, checking for changes and handling switch debounce... the framework does it for you and you just need to hook in your game-specific handling (such as "move left" when EV_PRESS_A happens)

Timers are used for things that your game does "by itself" (such as a missile travelling up the display or an alien moving across the screen). Since you must allow the framework to keep refreshing the display you must NOT have any long loop or delays inside your game code. The game API handles all this for you in a way that is MUCH less work for you, but can be a bit hard to understand at first.

There are five timers you can use in your game. Each one is enabled by assigning a value to the corresponding global variable from the following
<pre>
unsigned int Timer1Period;
unsigned int Timer2Period;
unsigned int Timer3Period;
unsigned int Timer4Period;
unsigned int Timer5Period;
</pre>

For example if we put the line 
<pre>
Timer1Period = 100;
</pre>
in our game's init method, this means that every 100 milliseconds (ten times a second) our handleEvent method will receive a EV_TIMER_1 event. We can use this event to run code for moving that missile etc. The beauty is that our game code does not need to do the timing, it only needs to act when the time comes up. This frees up the framework code to poll the buttons and refresh the display when no events are happening. 

Timers 2,3,4,5 work just like timer 1 described above. You can change the timer period at any time (e.g. to make a game get faster as it progresses), and you can set it to zero to stop  the timer.

## Displaying Things
The Disp8x8 class is used to address the display. You can clear the screen or set/get the value of any pixel. The rows and columns are numbered 0 to 7. You can access the data through the get/set function or through the red[] and green[] byte arrays (the latter method is more efficient for moving large blocks of data). You do not need to call the refresh() method since the framework is calling this between passing events to your class.

## Sound
call playSound(int pitch, int dur) to play a sound (Parameters in Hertz and milliseconds). The sounds are played asynchronously by the Arduino Tone library. This means that the code does not wait for the sound to finish. This is usually what you want since any delay or blocking will stop the display being updated. However, tunes or sound effects can be achieved with a delay() between each playSound() call, but the screen will not be refreshed.
The game framework allows all sound to be disabled via the menu. Always use playSound rather than calling the Tone library directly - this makes sure the sound can be turned off.

## Keeping Score
The global variable gameScore should be updated by your code, if your game has a concept of scoring. The variable is initialised to zero by the framework. In order to display the score at the end of the game call the endGame() method when the game is over. This function does not return - a reset is needed to start a new game.

## Check out the sample games to see how all the above should fit together!

## How to program the board
The board uses Arduino code (select Duemilanova with Atmega328 as board type). To physically connect your PC or Mac to the board in order to program the chip you need a special programming adaptor which includes a USB to TTL chip. The leads typically include the FTDI FT232 chip and are described as "5V USB to TTL cable". You should be able to get one for 10GBP/15EUR/20USD or so<br>
Another alternative is to use a Arduino board as a programmer, provided it uses a DIP28 AVR chip rather than surface mount... carefully remove the ATMega chip from the Arduino board and slot in the one removed from the game board you wish to program. Program the Arduino as normal, then swap the chips again. This method will damage the legs on the chip after a while even if you are very careful. Much better is to get a USB2TTL lead.