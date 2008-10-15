
#define ledPin     13
#define lightSensor   0


void setup () {
   pinMode (ledPin, OUTPUT);
   Serial.begin (9600);
   
}


void loop () {
  int light;

  light = analogRead (lightSensor);
  Serial.print ('A');
  Serial.print (light);
  Serial.println ();
  
  toggleLed ();
  delay (500);

  
   
}


void toggleLed () {
  int state;
 
 state = digitalRead (ledPin);
 digitalWrite (ledPin, !state); 
}
