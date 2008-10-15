#include "WProgram.h"
void init_one_wire();

int one_wire_bus = 2;


void setup () {
  Serial.begin (9600);
  Serial.println ("Initialized....");
  
  pinMode (one_wire_bus, OUTPUT);
  digitalWrite (one_wire_bus, 1);
}


void loop () {
  int i = 0;
  int width = 0;
  
  delay (3000);
  Serial.print ("Init 1-wire");
  
  init_one_wire();
  
  pinMode (one_wire_bus, INPUT);
  width = pulseIn (one_wire_bus, LOW);
  
  Serial.print ("Device found: ");
  Serial.println (width);
  
}


void init_one_wire () {
  digitalWrite (one_wire_bus, 0);
  delayMicroseconds (500);
  digitalWrite (one_wire_bus, 1);
}
