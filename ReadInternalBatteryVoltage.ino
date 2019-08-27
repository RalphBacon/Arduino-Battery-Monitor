void setup() {
  Serial.begin(9600);

  // 1.1V internal reference voltage. Measure it on pin 21.
  analogReference(INTERNAL);

  // Force interal ref voltage to be applied
  analogRead(A0);

  // Above can be done with a single statement:
  // ADMUX = bit (REFS0) | bit(REFS1);
   Serial.print("ADMUX: ");
   Serial.println(ADMUX,BIN);
  /*
   * This means, set the bits:
   * 1UL << 6 | 1UL << 7
   * 
   * so we set two bits at position 6 & 7
   * 000000--(32 bits)----011000000
   */

  Serial.println("Read the voltage with a multimeter\non physical pin 21, AREF");
}

// Nothing to do here
void loop() {
}
