// Define LED pins based on Arduino Uno mapping
#define LED1 11  // PB3 (Arduino Pin 11) - Blinks at 1Hz
#define LED2 13  // PB5 (Arduino Pin 13) - Blinks at 0.5Hz

volatile uint16_t counter_1Hz = 0;
volatile uint16_t counter_0_5Hz = 0;

void setup() {
    Serial.begin(9600);  // Start Serial for Debugging
    Serial.println("Starting Timer2 Interrupt for LED Blinking...");

    pinMode(LED1, OUTPUT); // Set LED1 as Output
    pinMode(LED2, OUTPUT); // Set LED2 as Output

    // Timer2 Initialization for 1Hz and 0.5Hz interrupt-based LED blinking
    cli(); // Disable global interrupts
    TCCR2A = 0; // Normal Mode
    TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20); // Prescaler 1024
    TIMSK2 = (1 << TOIE2); // Enable Overflow Interrupt
    sei(); // Enable global interrupts

    Serial.println("Timer2 Configured. LEDs should start blinking...");
}

ISR(TIMER2_OVF_vect) {
    static uint16_t timer_count = 0;
    timer_count++;

    if (timer_count >= 61) {  // Approx 1 second
        digitalWrite(LED1, !digitalRead(LED1)); // Toggle LED1 (1Hz)
        Serial.println("LED1 TOGGLED (1Hz)");

        counter_1Hz++;
        if (counter_1Hz >= 2) {  // Toggle LED2 every 2 seconds
            digitalWrite(LED2, !digitalRead(LED2)); // Toggle LED2 (0.5Hz)
            Serial.println("LED2 TOGGLED (0.5Hz)");
            counter_1Hz = 0;
        }
        timer_count = 0;
    }
}

void loop() {
    // Nothing needed in the loop, everything runs in the ISR
}
