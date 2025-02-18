// Traffic Light Controller with Three Separate LEDs
int greenLED = 8;   // Green LED on Pin 5
int yellowLED = 9;  // Yellow LED on Pin 6
int redLED = 7;     // Red LED on Pin 7

int blinkRate = 500;   // Base blink rate for Yellow (ms)
unsigned long previousTime = 0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  // GREEN: LED ON CONSTANTLY
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  delay(6000); // Green light duration (6 seconds)

  // YELLOW: Blink at Rate_1 (500ms)
  for (int i = 0; i < 6; i++) { 
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(blinkRate / 2);
    digitalWrite(yellowLED, LOW);
    delay(blinkRate / 2);
  }

  // RED: Blink at 2 * Rate_1 (250ms)
  for (int i = 0; i < 12; i++) {
    digitalWrite(redLED, HIGH);
    delay(blinkRate / 4);
    digitalWrite(redLED, LOW);
    delay(blinkRate / 4);
  }
}
