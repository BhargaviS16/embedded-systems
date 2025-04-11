#include <LiquidCrystal.h>

// LCD Setup (Parallel, 4-bit mode)
// LCD connections: RS -> D7, E -> D8, D4 -> D9, D5 -> D10, D6 -> D11, D7 -> D12
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Pin Definitions
const int ANALOG_PIN = A0;        // Analog input from potentiometer via RC filter
const int INTERRUPT_PIN = 2;      // External interrupt input push button

// Shift Register (MC74HC595A) pins:
const int SR_DATA_PIN   = 3;      // DS
const int SR_CLOCK_PIN  = 4;      // SH_CP
const int SR_LATCH_PIN  = 5;      // ST_CP
const int SR_OE_PIN     = 6;      // OE (active low)

// Global Variables
const int BUFFER_SIZE = 250;      // Circular buffer size for analog samples
int sampleBuffer[BUFFER_SIZE];    // Array for storing analog samples
int bufferIndex = 0;              // Next index for storing a sample

volatile uint8_t incomingData = 0xAA;  // Example 8-bit data word for shift register
volatile bool interruptFlag = false;   // Flag to indicate an interrupt was processed

// Setup Function
void setup() {
  Serial.begin(9600);
  Serial.println("System Initialization...");

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("System Init...");

  // Setup analog input from potentiometer via RC filter
  pinMode(ANALOG_PIN, INPUT);

  // Setup shift register control pins as outputs
  pinMode(SR_DATA_PIN, OUTPUT);
  pinMode(SR_CLOCK_PIN, OUTPUT);
  pinMode(SR_LATCH_PIN, OUTPUT);
  pinMode(SR_OE_PIN, OUTPUT);
  
  // Disable shift register outputs initially (OE is active low; HIGH disables)
  digitalWrite(SR_OE_PIN, HIGH);
  digitalWrite(SR_LATCH_PIN, LOW);

  // Setup external interrupt on INTERRUPT_PIN (trigger on rising edge)
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), handleInterrupt, RISING);

  Serial.println("Setup Complete.");
}


// Main Loop Function
void loop() {
  // 1. Analog Sampling Section
  // Read the analog value from A0 (voltage from the potentiometer, filtered by RC network)
  int sample = analogRead(ANALOG_PIN);
  sampleBuffer[bufferIndex] = sample;
  bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
  
  // When the circular buffer wraps around (i.e., buffer is full), print and display samples
  if (bufferIndex == 0) {
    Serial.println("Circular Buffer Full:");
    for (int i = 0; i < BUFFER_SIZE; i++) {
      Serial.print(sampleBuffer[i]);
      Serial.print(" ");
    }
    Serial.println();

    // Display first 8 samples on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Samples:");
    lcd.setCursor(0, 1);
    for (int i = 0; i < 8; i++) {
      lcd.print(sampleBuffer[i]);
      lcd.print(" ");
    }
  }
  
  //Check if an interrupt has occurred 
  if (interruptFlag) {
    Serial.println("Interrupt processed; shift register updated.");
    interruptFlag = false;
  }
  
  // Delay to set sampling rate 
  delay(1);
}


// Interrupt Service Routine (ISR)
// This ISR is triggered by the external event (push button on D2)
// It shifts an 8-bit word (incomingData) into the MC74HC595A shift register.
void handleInterrupt() {
  // Disable shift register outputs during shifting
  digitalWrite(SR_OE_PIN, HIGH);
  
  // Shift out 8 bits (MSB first)
  for (int i = 7; i >= 0; i--) {
    digitalWrite(SR_CLOCK_PIN, LOW);
    // Set DATA pin according to the current bit of incomingData
    digitalWrite(SR_DATA_PIN, (incomingData & (1 << i)) ? HIGH : LOW);
    digitalWrite(SR_CLOCK_PIN, HIGH);
  }
  
  // Pulse the latch pin to update the shift register outputs
  digitalWrite(SR_LATCH_PIN, LOW);
  digitalWrite(SR_LATCH_PIN, HIGH);
  
  // Re-enable the shift register outputs (active low: LOW enables)
  digitalWrite(SR_OE_PIN, LOW);
  
  // Set flag to indicate the interrupt was processed
  interruptFlag = true;
}
