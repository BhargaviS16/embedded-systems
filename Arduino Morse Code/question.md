This Assignment will require you to have an Arduino Uno board. If you do not have your own board, you
can borrow a board for the semester from the instructor. A tutorial is provided in this document to assist
you understanding basic coding of Arduino to blink an LED with a specific time delay.
Task (100%):
Program an Arduino Uno board to show the Morse Code of "SOS" by blinking an external LED on a
breadboard. In the report, provide the followings:
a) Describe the process you used to develop this custom code for this task.
b) What was the duration of each blink for "Dots" and "Dashes"?
c) Provide the complete software code with sufficient comments to ensure the code is understandable.
d) Provide snapshots confirming successful download of the code from computer to Arduino board.
e) Provide a few pictures as evidence of successful operation of the code.
f) Determine the memory size used by the downloaded code.
g) How your code can be generalized to transmit any Morse code?


A Tutorial to make an external LED blink with a specific time delay (source: uskcode.zip):
1) Connect the Arduino Uno board to the USB cable. Read the manual from uskcode.zip file from page
2 to page 5 (steps 1 to 5).
2) Install and open Arduino Sketch software. You should see the GUI window (Integrated Development
Environment or IDE). Match it with the manual pages and identify different menu and buttons.
3) Plug in the USB connector of the board to the computer (there is USB port beside the monitors).
4) Open the Blink example sketch by going to: File > Examples > 1.Basics > Blink
5) Select the type of Arduino board you are using: Tools > Board > Arduino Uno.
2
6) Select the serial/COM port that your Arduino is attached to: Tools > Port > COMxx (where xx stands
for the numeric port number).
7) If you’re not sure which serial device is your Arduino, take a look at the available ports, then unplug
your Arduino and look again. The one that disappeared is your Arduino.
8) With your Arduino board connected, and the Blink sketch open, press the ‘Upload’ button
9) 9) If properly done, you should see some LEDs flashing on your Arduino, followed by the message
‘Done Uploading’ in the status bar of the Blink sketch.
10) If the microcontroller is programmed, the onboard LED on your Arduino should now be blinking!
11) Now, we will follow the instructions given in Circuit 1 of the manual (page 20). For this purpose,
you will need the “USK Guide Code” from Canva or www.vilros.com/uskcode. You can download
this code from Canvas, and keep a copy on your USB stick for other labs.
12) Copy the USK Guide Code to the installation folder “C:\Program Files\Arduino\Examples”.
13) Open the Arduino software and check the Open button to see if you can find USK Guide Code. If
not, check if the files (Step 12) are copied properly.
14) Read the manual for Circuit # 1. (Titled: Your first circuit).
15) Execute the program. Determine the blinking rate of the LED by observing the number of blinks in
30 seconds, and averaging the blink duration. Change the duration to 0.5 seconds by changing delay.
Which port the LED is connected? Reprogram to use port 12 for external LED.
You will need to modify this code to perform the given task.

