import processing.serial.*;

Serial port;                         // The serial port
String message = null;               // Incomming messages
String elements[] = null;            // Message elements
int values[] = {0,0,0,0,0,0};        // Values of the analog pins       


void setup() { 
  
  size(420,150); //La taille de notre fenêtre
 
  frameRate(30);
  stroke(255);
  
  println("Opening: "+Serial.list()[0]);
  port = new Serial(this, Serial.list()[0], 115200);
  println("Opening the Serial port forces the Diecimila to reboot...");
  println("...so wait till the Arduino boots and send out a message...");
  while (port.available() == 0 ) {}; // Wait till Arduino boots
  println("Done waiting.");
  port.write(13);    // Clear messages still hanging out in th buffer;
  port.write("50");    // Send the desired sampling rate as ASCII characters: 33 milliseconds
  port.write(13);    // End the message with a carriage return;
} 


void draw() { 

  background(0); 
  fill(255);
  
  while (port.available() > 0) {
   message = port.readStringUntil(13); // Read message until a carriage return
   if (message != null) {
     println(message);
    elements = splitTokens(message);
    for (int i =0; i < elements.length && i < 6; i++ ) {
      values[i] = int(elements[i]);
    }
   }
  }
  
  
  for (int i =0; i < 6; i++ ) {
     rect(12+(i*((width-24)/6.0)),25,((width-24)/6.0)-4,map(values[i],0,1024,0,100)); //
  } 
   
} 
