#include "WProgram.h"


void setup () {
  Serial.begin (9600);
  Serial.println ('Initializing....');
}


void loop () {
  int i = 0;
  
  Serial.println (i);
  delay(1000);
}
