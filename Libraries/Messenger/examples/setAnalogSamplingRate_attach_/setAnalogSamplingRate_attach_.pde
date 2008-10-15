//This example demonstrates Messenger's callback  & attach methods


#include <Messenger.h>

// Define a metronome
unsigned long previousMillis = 0;
//Set the default interval to 2 seconds
unsigned long interval = 1000;

// Instantiate Messenger object with the message function and the default separator (the space character)
Messenger message = Messenger(); 


// Define messenger function
void messageArrived() {
                  // Set the interval
                  interval = message.readInt();
}

void setup() {
  // Initiate Serial Communication
  Serial.begin(115200); 
  message.attach(messageArrived);
}

void loop() {
  // The following two lines is the most effective way of using Serial and Messenger
  while ( Serial.available( )  ) message.process(Serial.read( ) );

// Output the analog values
  if ( millis() - previousMillis > interval ) {
    previousMillis = millis();
    for ( byte i = 0; i < 6; i++) {
      Serial.print( analogRead(i) );
      Serial.print(' ');
    }
    Serial.println();
  }

}
