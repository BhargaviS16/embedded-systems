Study the instructions given in the USK Guide Manual for “Circuit #7: Temperature sensor” (pp. 44-47).
Also study the LCD display module operation from these web resources:
http://arduino.cc/en/Reference/LiquidCrystalConstructor
https://code.google.com/p/arduino/source/browse/trunk/libraries/LiquidCrystal/LiquidCrystal.h?r=1037
A Tutorial Procedure to help in setup of the sensor and display:
1) Follow the instructions given in the SIK Guide Manual for “Circuit #7: Temperature sensor” (pp. 44-
47).
2) Setup the hardware as shown in the Manual. Double check to ensure the circuit is connected properly
before plugging in the USB cable of the Arduino Uno (i.e. before powering the circuit).
3) As instructed in the Manual, use the serial monitor to display the temperature of the sensor in the
computer monitor.
Note: Divide and Conquer strategy!!! This step is to ensure the sensor connection and input data
collection is working as per expectation.
4) Perform some basic functionality test (functional verification), e.g. if the sensor is working properly,
you should see the temperature value is increasing (temperature of fingers is higher than ambient)
when you pinch the sensor tightly. Another quick check is to exhale on the sensor.
5) What is the ambient temperature reading? Validate it with any other temperature sensor if you have.
For example, Android phones have a temperature sensor, which can display current ambient
temperature using an app such as “Data Monitor”. You can also check the temperature setting of the
lab room (usually around 73 ̊F).
6) Now we will connect the LCD display module to show the temperature on the display. In order to
display the measured temperature values that you will have to wire the 16x2 LCD display to 6
Digital Output pins of the Arduino board.
Wire the pins according to the following assignments:
LCD 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
Arduino
Board GND +5V GND
(Contrast) 12 GND 11 - - - - 5 4 3 2 +5V GND
7) You might need to connect a Potentiometer (Pot) to Pin 3 to adjust the contrast. To do this, connect
two end terminals of the Pot to +5V and Gnd. Then connect the middle terminal to Pin 3 of the LCD
EECE4712/6712: Embedded Systems EECE, UoM Page 2 of 3
module (instead of connecting it to Gnd as given in the table). This will allow you to change the
contrast of the LCD by turning the Pot.
8) Using a simple program, verify if the LCD connection is done properly. LCD Display library
functions are used to interface the Digital I/O pins of the Arduino board with the LCD Display.
‘lcd.print(“xxxxx”)’ function is used to display the measured values. You should refer to the code
from Arduino.cc as needed.
http://arduino.cc/en/Reference/LiquidCrystalConstructor
https://code.google.com/p/arduino/source/browse/trunk/libraries/LiquidCrystal/LiquidCrystal.h?r=1037


You will need to modify the codes to perform the given task.

Task (100%):

Integrate the LCD display as the output of temperature program and display the temperature of the
sensor on the LCD display. Functionally verify proper operation.
Provide the followings in the report:

a) Describe the process you used to develop the custom code for the given task.

b) Provide the complete (final) software code with sufficient comments.

c) Provide snapshots confirming successful download of the code.

d) Provide pictures with labels showing your setup and properly working display.

e) Develop a strategy to verify proper functionality of the system.

f) Provide details of how you have verified the functionality of the system.

Appendix:

// A sample program to display temperature on the LCD display


// include the library code:

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(12, 11, 5,4,3,2);

float tempVal;

float sensorVal;

int sensorPin = 0;

void setup() {

// set up the LCD's number of rows and columns:

EECE4712/6712: Embedded Systems EECE, UoM Page 3 of 3

lcd.begin(16, 2);

// Print a message to the LCD.

lcd.print("Temp (deg. F)");

// initialize serial communication:

Serial.begin(9600);

}

void loop() {

lcd.clear();

// get temperature

sensorVal = (analogRead(sensorPin)/1023.0)*5.0;

tempVal = sensorVal*100.0;

delay(100);

// set the cursor to column 0, line 1

// (note: line 1 is the second row, since counting begins with 0):

lcd.print("Temp (deg. F):");

lcd.setCursor(0, 1);

lcd.print(tempVal);

delay(500); //0.5sec

