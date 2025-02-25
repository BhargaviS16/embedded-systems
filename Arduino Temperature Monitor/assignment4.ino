#include <LiquidCrystal.h>

// Initialize LCD with (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int potPin = A0;        // Potentiometer connected to A0
float potValue = 0.0;   // Store potentiometer reading
float tempValue = 0.0;  // Simulated temperature

void setup() {
  lcd.begin(16, 2);  // Initialize LCD (16x2)
  lcd.print("Temp (deg. F):"); // Static text
  Serial.begin(9600); // Start Serial Monitor
  delay(1000); // Allow LCD to initialize
}

void loop() {
  potValue = analogRead(potPin);  // Read potentiometer value (0 - 1023)
  float voltage = (potValue / 1023.0) * 5.0;  // Convert reading to voltage (0V - 5V)
  
  // Map voltage to temperature range (Simulating 32°F to 100°F)
  tempValue = map(potValue, 0, 1023, 32, 100);

  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print("V | Simulated Temp: ");
  Serial.print(tempValue);
  Serial.println(" F");

  lcd.setCursor(0, 1);  // Move cursor to second row
  lcd.print("          "); // Erase old value (overwrite)
  lcd.setCursor(0, 1);  // Move cursor again
  lcd.print(tempValue);  // Display updated temperature

  delay(1000); // Update every second
}
