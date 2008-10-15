/*
 	Stepper.h - - Stepper library for Wiring/Arduino - Version 0.4
  
  Original library		(0.1) by Tom Igoe.
  Timing bug fixes		(0.2) "   "   "

	Sends X10 commands.

*/

// ensure this library description is only included once
#ifndef x10_h
#define x10_h

// include types & constants of Wiring core API
#include "WConstants.h"
#include "pins_arduino.h"

// library interface description
class x10 {
  public:
    // constructors:
    x10(int zeroCrossingPin, int dataPin);

    // write command method:
	void write(byte houseCode, byte numberCode, int numRepeats);
    // returns the version number:
    int version(void);

  private:
  	int zeroCrossingPin;	// AC zero crossing pin
  	int dataPin;			// data out pin
  	// sends the individual bits of the commands:
    void sendBits(byte cmd, byte numBits, byte isStartCode);
    // checks for AC zero crossing
    void waitForZeroCross(int pin, int howManyTimes);

};

#endif

