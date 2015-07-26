#ifndef OneWire_Driver_h
#define OneWire_Driver_h

#include <inttypes.h>
#include "OneWire.h"

#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif



class OneWire_Driver {
private:
    OneWire ds;
    device_enum devices[7];
        
public:
    OneWire_Driver();
    uint8_t enumerate_onewire(void);
    void send_command(uint8_t id, uint8_t cmd);
    uint8_t read_byte(void);
    device_type get_device_type(uint8_t id);
    float getTemp(uint8_t id);
    void DS1820_readTemps(void);
};
    
#endif
