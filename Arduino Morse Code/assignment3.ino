// Define the pin where the LED is connected
int ledPin = 9;  // Pin 9 is used for the external LED

// Setup function 
void setup() {
    pinMode(ledPin, OUTPUT);  // Set ledPin as an output
}

// Function to flash the LED 
void flash(int duration) {
    digitalWrite(ledPin, HIGH);  // Turn the LED on
    delay(duration);             // Wait for 'duration' milliseconds
    digitalWrite(ledPin, LOW);  // Turn the LED off
    delay(duration);             
}

// Loop function 
void loop() {
    // S: dot dot dot
    flash(200); 
    flash(200);
    flash(200);
    delay(300); 
    // O: dash dash dash
    flash(500);
    flash(500);
    flash(500);
    delay(300); 
    // S: dot dot dot
    flash(200);
    flash(200);
    flash(200);
    delay(1000); // Wait before repeating the SOS signal
}

