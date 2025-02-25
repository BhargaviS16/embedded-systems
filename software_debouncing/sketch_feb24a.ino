#define BUTTON_PIN 2  // External Interrupt Pin (D2)
#define LED_PIN 13    // LED Indicator (D13)

volatile bool button_pressed = false;
volatile unsigned long last_interrupt_time = 0;
const unsigned long debounce_delay = 50;  // 50ms debounce delay
volatile int toggle_count = 0;  // Counter for toggles

void handleInterrupt() {
    unsigned long current_time = millis();  // Get the current time

    if ((current_time - last_interrupt_time) > debounce_delay) {
        last_interrupt_time = current_time;  // Update last valid interrupt time
        button_pressed = true;  // Mark button as pressed
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Enable internal pull-up resistor

    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleInterrupt, FALLING);

    Serial.println("Software debounce interrupt initialized!");
}

void loop() {
    if (button_pressed) {
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));  // Toggle LED
        toggle_count++;  // Increment toggle count
        Serial.print("Button Press Detected! LED Toggled. Count: ");
        Serial.println(toggle_count);
        button_pressed = false;
    }
}
