
// This example sets all the values of the digital pins with a list

#include <Messenger.h>
// Instantiate Messenger object with the default separator (the space character)
Messenger message = Messenger(); 
void setup() {
  // Initiate Serial Communication
  Serial.begin(115200); 
}


void loop() {
  // The following two lines is the most effective way of using Serial and Messenger
  while ( Serial.available() ) { // Check if there is Serial data
    if ( message.process(Serial.read() ) ){  // Process the Serial data and continue if there is a message
      int pin = 0;
       // Loop through all the available elements of the message
       while ( message.available() ) {
	// Set the pin as determined by the message
         digitalWrite( pin,message.readInt() );
         pin=pin+1;
      }
    }
  }
}
