#include "WProgram.h"

// This example sets the speed of the sampling of an analog input

#include <Messenger.h>

// Instantiate Messenger object with the default separator (the space character)
void setup();
void loop();
Messenger message = Messenger(); 

// Metronome
unsigned long previousMillis = 0;
//Set the default interval to 2 seconds
unsigned long interval = 50;

void setup() {
  // Initiate Serial Communication
  Serial.begin(115200); 
}


void loop() {
  // The following two lines is the most effective way of using Serial and Messenger
  while ( Serial.available() ) { // Check if there is Serial data
    if ( message.process(Serial.read() ) ){  // Process the Serial data and continue if there is a message
      // Set the interval
      interval = message.readInt();
    }
  }

  if ( millis() - previousMillis > interval ) {
    previousMillis = millis();
   
    for ( byte i = 0; i < 6; i++) {
      Serial.print( analogRead(i) );
      Serial.print(' ');
    }
    Serial.println();
  }

}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

