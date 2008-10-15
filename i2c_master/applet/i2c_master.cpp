/* 
   I2C Master node
   
 */


#include <Wire.h>
#include <stdio.h>


#include "WProgram.h"
void setup();
void loop();
void setup() {
    Wire.begin();
    Serial.begin(9600);
    Serial.println("I2C Master initialized.");  
}



void loop() {
    char str[40];
    int val;
    
    while (1) {
        
        Serial.println("Sending request");
        Wire.requestFrom(0x49, 4);
  
        while(Wire.available()) {
            val = Wire.receive();
            Serial.println(val);
            sprintf (str, "Received 0x%x from slave", val);
          
            Serial.println(str); 
        }
    
        delay(1000);
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

