/* 
   I2C Master node
   
 */


#include <Wire.h>
#include <stdio.h>


#define SLAVE_ADDR  (9 << 3) | 1


void setup() {
    Wire.begin();
    Serial.begin(9600);
    Serial.println("I2C Master initialized.");  
}



void loop() {
    char str[40];
    int val = 0;
    
    while (1) {
        val = 0;
        
        Serial.println("Sending request");
        
        //Wire.beginTransmission(SLAVE_ADDR);
        //Wire.send("This is just a test....");
        //Wire.send(0);
        //Wire.endTransmission();
      
        Wire.beginTransmission(SLAVE_ADDR);
        Wire.requestFrom(SLAVE_ADDR, 2);
  
        while(Wire.available()) {
            Serial.print(".");
            if (val != 0) {
                val = val<<8 | Wire.receive();
            } else {
                val = Wire.receive();
            }
        }
        sprintf (str, "Received 0x%x from slave", val);
        Serial.println(str); 
        Wire.endTransmission();
        
      
    
        delay(1000);
    }
}
