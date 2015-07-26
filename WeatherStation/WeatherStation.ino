
#include "WeatherStation.h"
#include "OneWire_Driver.h"
#include "ZigBee_Driver.h"
#include <Timer.h>


Timer ticker;
OneWire_Driver  oww;
ZigBee_Driver zgb;


int i = 0;

void readTemps() {
    oww.DS1820_readTemps();
}


void setup(void) {


  
  ticker.every(10000L, &readTemps);
  
  
}

void loop(void) {
  
  ticker.update();
  delay(200);
  
  if ((i++ % 80) == 0) {
    Serial.print("\n");
  }
  Serial.print('.');
}


void serialEvent(void) {
  char buffer[30];
  uint8_t num_read = 0;

  while (Serial.available()) {
    if (num_read <10) {
      buffer[num_read++] = Serial.read();
    } else {
      break;
    }
  };
  
  zgb.process_message(String(buffer));
  
}
