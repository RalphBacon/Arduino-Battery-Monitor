void setup() {
  Serial.begin(9600);
  Serial.println("Setup completed.");
}

void loop() {

  // Read external battery VCC voltage
  Serial.print("Bat: ");
  uint16_t batVolts = getBatteryVolts();
  Serial.print(batVolts);
  Serial.print(" - ");
  Serial.println(getBatteryVolts2());

  delay(500);
}

// One way of getting the battery voltate without any double or float calculations
unsigned int getBatteryVolts() {
  //http://www.gammon.com.au/adc

  // Adjust this value to your boards specific internal BG voltage x1000
  const long InternalReferenceVoltage = 1087L; // <-- change this for your ATMEga328P pin 21 AREF value

  // REFS1 REFS0          --> 0 1, AVcc internal ref. -Selects AVcc external reference
  // MUX3 MUX2 MUX1 MUX0  --> 1110 1.1V (VBG)         -Selects channel 14, bandgap voltage, to measure
  ADMUX = (0 << REFS1) | (1 << REFS0) | (0 << ADLAR) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (0 << MUX0);

  // Let mux settle a little to get a more stable A/D conversion
  delay(50);

  // Start a conversion
  ADCSRA |= _BV( ADSC );

  // Wait for conversion to complete
  while ( ( (ADCSRA & (1 << ADSC)) != 0 ) );

  // Scale the value - calculates for straight line value
  unsigned int results = (((InternalReferenceVoltage * 1024L) / ADC) + 5L) / 10L;
  return results;
}

// A different way using float to determine the VCC voltage
float getBatteryVolts2() {
  // You MUST measure the voltage at pin 21 (AREF) using just a simple one line sketch consisting
  // of:  analogReference(INTERNAL);
  //      analogRead(A0);
  // Then use the measured value here.

  const float InternalReferenceVoltage = 1.087; // <- as measured (or 1v1 by default)

  // turn ADC on
  ADCSRA =  bit (ADEN);

  // Prescaler of 128
  ADCSRA |= bit (ADPS0) |  bit (ADPS1) | bit (ADPS2);

  // MUX3 MUX2 MUX1 MUX0  --> 1110 1.1V (VBG) - Selects channel 14, bandgap voltage, to measure
  ADMUX = bit (REFS0) | bit (MUX3) | bit (MUX2) | bit (MUX1);

  // let it stabilize
  delay (10);

  // start a conversion
  bitSet (ADCSRA, ADSC);

  // Wait for the conversion to finish
  while (bit_is_set(ADCSRA, ADSC))
  {
    ;
  }

  // Float normally reduces precion but works OK here. Add 0.5 for rounding not truncating.
  float results = InternalReferenceVoltage / float (ADC + 0.5) * 1024.0;
  return results;
}
