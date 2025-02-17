// Define the pins for the LEDs
const int blueLedPin = 13;  // Blue LED connected to digital pin 13
const int greenLedPin = 12; // Green LED connected to digital pin 12

void setup() {
  // Set the LED pins as output
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // Blink the blue LED every 1 second
  digitalWrite(blueLedPin, HIGH);  // Turn on blue LED
  delay(1000);                      // Wait for 500ms
  digitalWrite(blueLedPin, LOW);   // Turn off blue LED
  delay(1000);                      // Wait for 500ms

  // Blink the green LED every 2 seconds
  digitalWrite(greenLedPin, HIGH); // Turn on green LED
  delay(2000);                     // Wait for 1000ms
  digitalWrite(greenLedPin, LOW);  // Turn off green LED
  delay(2000);                     // Wait for 1000ms
}