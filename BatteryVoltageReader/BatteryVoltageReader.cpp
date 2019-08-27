/*
	Simple, in-progress library to allow easy reading of current battery (VCC) voltage
	so that a timely warning can be given to user that it's time to get new batteries
	before these ones expire!
		
	See https://github.com/RalphBacon/Arduino-Battery-Monitor
	See https://www.youtube.com/ralphbacon video #160
	
*/

#include "Arduino.h"
#include "BatteryVoltageReader.h"

void BatteryVoltageReader::begin() {
	this->startInternal1V1VoltageReference();
}

void BatteryVoltageReader::startInternal1V1VoltageReference() {
	// Internal 1.1V reference, works instantly (compare to below)
	ADMUX = bit (REFS0) | bit(REFS1);

	// Above is the equivalent of:

	/*
	 // Request INTERNAL 1v1 reference voltage (for ATMega328P)
	 analogReference (INTERNAL);

	 // That request is not honoured until we read the analog pin
	 // so force voltage reference to be turned on
	 analogRead (A0);
	 */
}

uint16_t BatteryVoltageReader::readVCC() {
	//Partly adapted from http://www.gammon.com.au/adc (Nick Gammon)

	// Adjust this value to your boards specific internal BandGap voltage x1000
	const long InternalReferenceVoltage = 1095L; // Here I measured 1.095 volts on pin 21
	
	//Taken from https://forum.arduino.cc/index.php?topic=331178.msg2285210#msg2285210
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
     // For mega boards
        // REFS1 REFS0          --> 0 1, AVcc internal ref. -Selects AVcc reference
        // MUX4 MUX3 MUX2 MUX1 MUX0  --> 11110 1.1V (VBG)         -Selects channel 30, bandgap voltage, to measure
     ADMUX = (0<<REFS1) | (1<<REFS0) | (0<<ADLAR)| (0<<MUX5) | (1<<MUX4) | (1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (0<<MUX0);  
#else
     // For 168/328 boards
        // REFS1 REFS0          --> 0 1, AVcc internal ref. -Selects AVcc external reference
        // MUX3 MUX2 MUX1 MUX0  --> 1110 1.1V (VBG)         -Selects channel 14, bandgap voltage, to measure
     ADMUX = (0<<REFS1) | (1<<REFS0) | (0<<ADLAR) | (1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (0<<MUX0);
#endif

	// Let mux settle a little to get a more stable A/D conversion
	delay(50);

	// Start a conversion
	ADCSRA |= _BV(ADSC);

	// Wait for conversion to complete
	while (((ADCSRA & (1 << ADSC)) != 0)) {
		;
	}

	// Scale the value - calculates for straight line value. +5L gives us the fractional rounding.
	unsigned int results = (((InternalReferenceVoltage * 1024L) / ADC) + 5L) / 10L;
	return results;
}

