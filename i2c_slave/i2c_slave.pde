
#include <Wire.h>
#include <stdio.h>

int count; 

void setup() {
    count = 0;
    
    Serial.begin(9600);
    Serial.println("I2C Slave initialized.");
    Wire.begin((9 << 3) | 1);
    //Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);
}


void loop() {
    delay (1000);
    Serial.println("Loop");
}


void receiveEvent(int howMany) {
    char msg[40];
    
    sprintf (msg, "Received %d bytes", howMany);
    Serial.println(msg);
    
    while (Wire.available()) {
        Serial.print(Wire.receive());
    }
}

void requestEvent() {
    Serial.print("Received request:  ");
    Serial.println(count);
    Wire.send(count);
    count++;
}    
