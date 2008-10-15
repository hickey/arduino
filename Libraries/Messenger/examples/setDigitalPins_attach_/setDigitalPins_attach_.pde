
// This example sets all the values of the digital pins with a list through a callback function 

#include <Messenger.h>
// Instantiate Messenger object with the default separator (the space character)
Messenger message = Messenger(); 

// Create the callback function
void messageReady() {
    int pin = 0;
       // Loop through all the available elements of the message
       while ( message.available() ) {
	// Set the pin as determined by the message
         digitalWrite( pin, message.readInt() );
         pin=pin+1;
      }
}


void setup() {
  // Initiate Serial Communication
  Serial.begin(115200); 
  // Attach the callback function to the Messenger
  message.attach(messageReady);
}


void loop() {
  // The following line is the most effective way of using Serial and Messenger's callback
  while ( Serial.available() )  message.process(Serial.read () );
}
