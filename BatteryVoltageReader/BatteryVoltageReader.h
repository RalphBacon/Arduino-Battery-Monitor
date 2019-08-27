#ifndef BatteryVoltageReader_h_
#define BatteryVoltageReader_h_

#include "Arduino.h"
class BatteryVoltageReader {
public:
	void begin();
	uint16_t readVCC();

private:
	void startInternal1V1VoltageReference();

protected:


};
#endif
