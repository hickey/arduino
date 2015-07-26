#ifndef ZigBee_Driver_h
#define ZigBee_Driver_h

#include <inttypes.h>
#include "XBee.h"

#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif



class ZigBee_Driver {
private:

        
public:
    ZigBee_Driver();
    void receive_packet(void);
    void process_message(String);
    
};
    
#endif
