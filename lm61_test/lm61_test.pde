/*
 * AnalogInput
 * by DojoDave <http://www.0j0.org>
 *
 * Turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead(). In the easiest case we connect
 * a potentiometer to analog pin 2.
 *
 * http://www.arduino.cc/en/Tutorial/AnalogInput
 */
 
#include <stdio.h>
#include <stdlib.h>

#define SAMPLES 6

int sample[SAMPLES];


int potPin = 0;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
float cel = 0;
float deg = 0;
float milliv = 0;

void setup() {
  for (int i=0; i<SAMPLES; i++) 
    sample[i] = 0;
    
  Serial.begin(9600);
  Serial.println("Temperature:\n");
  delay(100);
}

void loop() {
  val = readAnalog(potPin);    // read the value from the sensor
  
  Serial.print("temp = ");
  
  milliv = (val / 1024.0 ) * 5000;
  cel = (milliv - 600) / 10;
  deg = ((cel * 9.0) / 5.0) + 32.0;
  Serial.print(float2str(cel));
  Serial.print("/");
  Serial.println(float2str(deg));
  delay(1000);                  // stop the program for some time
}


char* float2str(float val) {
  int whole = int(val);
  int fract = int( (val - whole) * 100);
  char strval[10] = "";
  char intval[5];
  
  //Serial.print("whole=");
  //Serial.println(whole);
  //Serial.print("fract=");
  //Serial.print(fract);
  
  //sprintf (strval, "%f", val);
  itoa(whole, intval, 10);
  strcat(strval, intval);
  strcat(strval, ".");
  itoa(fract, intval, 10);
  strcat(strval, intval);
  return strval;
}


int readAnalog(int pin) {
  static int index = 0;
  static int total = 0;
  
  total -= sample[index];
  sample[index] = analogRead(pin);
  total += sample[index];
  index++;
  
  if (index >= SAMPLES)
    index = 0;
    
  return (total / SAMPLES);
}
