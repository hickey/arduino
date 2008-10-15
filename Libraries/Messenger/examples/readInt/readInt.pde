#include <Messenger.h>
Messenger message = Messenger(); // Instantiate Messenger object with the default separator (the space character)

void setup() {
  Serial.begin(115200); // Initiate Serial Communication
}


void loop() {
  // The following two lines is the most effective way of using Serial and Messenger
  while ( Serial.available() ) {
    if ( message.process(Serial.read() ) ){
      
      Serial. println(message.readInt()); // This command simpy echoes the first integer of a message
      
    }
  }
}
