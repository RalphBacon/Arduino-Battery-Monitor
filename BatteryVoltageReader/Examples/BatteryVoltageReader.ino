#include "Arduino.h"
#include <BatteryVoltageReader.h>
BatteryVoltageReader BVR;
#define ledPin 10

void setup() {
  Serial.begin(9600);

  // 1.1V internal reference voltage. Measure it on pin 21.
  BVR.begin();

  Serial.println("Setup completed.");
}


void loop() {

  // If the battery is below 3.29v (329) beep a longer series of beeps
  Serial.print("Battery (VCC) voltage: ");
  uint16_t batVolts = BVR.readVCC();
  Serial.println(batVolts);

  if (batVolts < 329) {
    Serial.println("Battery low");
    doFastBeep();
  }
}

// Low battery warning
void doFastBeep() {
  for (auto cnt = 1; cnt < 10; cnt++) {
    digitalWrite(ledPin, HIGH);
    delay(20);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
  delay(250);
}