
#include <Arduino.h>
#include <XBee.h>
#include "ZigBee_Driver.h"
#include "WeatherStation.h"


/* Create an instance of the XBee object to connect to network */
//XBee xbee = XBee();


ZigBee_Driver::ZigBee_Driver(void) {
  //xbee.begin(9600);

}


void ZigBee_Driver::receive_packet() {
    
    
}


void ZigBee_Driver::process_message(String mesg) {
    
    if (mesg.compareTo(String('!'))) {
      Serial.print("*");
    } else if (mesg.compareTo(String('%'))) {
      //OneWireInitialize();
    }

    
}


