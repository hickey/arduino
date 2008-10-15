/*
  x10.cpp - X10 transmission library for Arduino version 0.1
  
  Original library		(0.1) by Tom Igoe.
  Timing bug fixes		(0.2) "   "   "
  
  Zero crossing algorithms borrowed from David Mellis' shiftOut command
  for Arduino.
  
  The circuits can be found at 
 
http://www.arduino.cc/en/Tutorial/x10
 
 
 */


#include "WProgram.h"
#include "x10.h"
#include "x10constants.h"

/*
 Constructor.
 
 Sets the pins and sets their I/O modes.
 
 */
x10::x10(int zeroCrossingPin, int dataPin)
{
  this->zeroCrossingPin = zeroCrossingPin;      // the zero crossing pin
  this->dataPin = dataPin;        				// the output data pin
  
  // Set I/O modes:
  pinMode(this->zeroCrossingPin, INPUT);
  pinMode(this->dataPin, OUTPUT);
}



/*
	Writes an X10 command out to the X10 modem
*/
void x10::write(byte houseCode, byte numberCode, int numRepeats) {
  byte startCode = B1110; 		// every X10 command starts with this

	// repeat as many times as requested:
 	for (int i = 0; i < numRepeats; i++) {
		// send the three parts of the command:
 		sendBits(startCode, 4, true);	
  		sendBits(houseCode, 4, false);
  		sendBits(numberCode, 5, false);
  	}
  	// if this isn't a bright or dim command, it should be followed by
  	// a delay of 3 power cycles (or 6 zero crossings):
  	if ((numberCode != BRIGHT) && (numberCode != DIM)) {
  		waitForZeroCross(this->zeroCrossingPin, 6);
  	}
}
/*
	Writes a sequence of bits out.  If the sequence is not a start code,
	it repeats the bits, inverting them.
*/

void x10::sendBits(byte cmd, byte numBits, byte isStartCode) {
  byte thisBit;		// copy of command so we can shift bits
  
	// iterate the number of bits to be shifted:
	for(int i=1; i<=numBits; i++) {
		// wait for a zero crossing change:
		waitForZeroCross(this->zeroCrossingPin, 1);
		// shift off the last bit of the command:
		thisBit = !!(cmd & (1 << (numBits - i)));
		
		// repeat once for each phase:
		for (int phase = 0; phase < 3; phase++) {
			// set the data Pin:
			digitalWrite(this->dataPin, thisBit);
			delayMicroseconds(BIT_LENGTH);
			// clear the data pin:
			digitalWrite(this->dataPin, LOW);
			delayMicroseconds(BIT_DELAY);
		}
		
		// if this command is a start code, don't
		// send its complement.  Otherwise do:
		if(!isStartCode) {
			// wait for zero crossing:
			waitForZeroCross(zeroCrossingPin, 1);
			for (int phase = 0; phase < 3; phase++) {
				// set the data pin:
				digitalWrite(this->dataPin, !thisBit);
				delayMicroseconds(BIT_LENGTH);
				// clear the data pin:
				digitalWrite(dataPin, LOW);
				delayMicroseconds(BIT_DELAY);
			}
		}
	}
}


/*
  waits for a the zero crossing pin to cross zero

*/
void x10::waitForZeroCross(int pin, int howManyTimes) {
	unsigned long cycleTime = 0;
	
  	// cache the port and bit of the pin in order to speed up the
  	// pulse width measuring loop and achieve finer resolution.  calling
  	// digitalRead() instead yields much coarser resolution.
  	uint8_t bit = digitalPinToBitMask(pin);
  	uint8_t port = digitalPinToPort(pin);

  	for (int i = 0; i < howManyTimes; i++) {
		// wait for pin to change:
    	if((*portInputRegister(port) & bit))
    	 	while((*portInputRegister(port) & bit)) 
        		cycleTime++;
    	else
      		while(!(*portInputRegister(port) & bit)) 
        		cycleTime++;
  		}
}


/*
  version() returns the version of the library:
*/
int x10::version(void)
{
  return 2;
}
