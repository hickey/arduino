/*



*/


/*

    Signal        40 pin        Mega8       Arduino
  ====================================================
    I0              31           PC0         A0(14)
    I1              32           PC1         A1(15)
    I2              33           PC2         A2(16)
    I3              34           PC3         A3(17)
    OUT1            27           PD5         D5
    OUT2            28           PD6         D6
    OUT3            29           PD7         D7
    OUT4            30           PD8         D8
    CNT             39           PC4         A5(18)  // Not currently connected
    RST             4            RESET       RESET
    RUN             1      // Running a wire from pin 1 to pin 5 would activate
    HLT             6            PD2         D2





*/


#include <Ethernet.h>
#include <TextString.h>


const int WebServer = 1;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 0, 0, 177 };
Server server(80);
TextString webHeader = TextString(80);


// 4 channel inputs from MicroMaster
const int input1 = 14;
const int input2 = 15;
const int input3 = 16;
const int input4 = 17;

// 4 channel ouputs to relays of MicroMaster
const int relay1 = 5;
const int relay2 = 6;
const int relay3 = 7;
const int relay4 = 8;

const int count = 18;  // not currently connected
const int irq   = 2;

const int testMode = 1;
const int runMode  = 2;


// Relay states
int relay1state = LOW;
int relay2state = LOW;
int relay3state = LOW;
int relay4state = LOW;

int mode = 0;



void setup() {
    if (WebServer) {
        Ethernet.begin(mac, ip);
        server.begin();
    }
    
    // initialize outputs
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    
    // Turn off all relays
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    
    // initialize inputs
    pinMode(input1, INPUT);
    pinMode(input2, INPUT);
    pinMode(input3, INPUT);
    pinMode(input4, INPUT);
    pinMode(irq, INPUT);
    
    // Determine if we should run in test mode or not. 
    int test = digitalRead(irq);
    if (test == 0) {
        mode = testMode;
    } else {
        mode = runMode;
    }
}


void loop() {
    if (mode == testMode) {
        performTest();
        if (digitalRead(irq) == 1) {
            // If halt signal is removed, stop test mode and enter run mode.
            mode = runMode;
        }
    } else {
        // regular run mode
        relay1state = digitalRead(input1);
        relay2state = digitalRead(input2);
        relay3state = digitalRead(input3);
        relay4state = digitalRead(input4);
        
        if (WebServer) {
            Client client = server.available();
            if (client) {
                // an http request ends with a blank line
                boolean current_line_is_blank = true;
                while (client.connected()) {
                    if (client.available()) {
                        char c = client.read();
                        // if we've gotten to the end of the line (received a newline
                        // character) and the line is blank, the http request has ended,
                        // so we can send a reply
                                                
                        if (c == '\n' && current_line_is_blank) {
                            // send a standard http response header
                            client.println("HTTP/1.1 200 OK");
                            client.println("Content-Type: text/html");
                            client.println();
          
                            // output the value of each analog input pin
                            for (int i = 0; i < 6; i++) {
                                client.print("analog input ");
                                client.print(i);
                                client.print(" is ");
                                client.print(analogRead(i));
                                client.println("<br />");
                            }
                            break;
                        }
                        if (c == '\n') {
                            // we're starting a new line
                            current_line_is_blank = true;
                        } else if (c != '\r') {
                            // we've gotten a character on the current line
                            current_line_is_blank = false;
                            
                            if (webHeader.length() <= 79) {
                                webHeader.setCharAt(webHeader.length(), c);
                            }
                        }
                    }
                }
                // give the web browser time to receive the data
                delay(1);
                client.stop();
            }
        }    
        
        digitalWrite(relay1, relay1state);
        digitalWrite(relay2, relay2state);
        digitalWrite(relay3, relay3state);
        digitalWrite(relay4, relay4state);

        
        delay(100);
    }
    
}


void performTest() {
    digitalWrite(relay1, HIGH);
    delay(100);
    digitalWrite(relay2, HIGH);
    delay(100);
    digitalWrite(relay3, HIGH);
    delay(100);
    digitalWrite(relay4, HIGH);
    delay(100);
    digitalWrite(relay4, LOW);
    delay(100);
    digitalWrite(relay3, LOW);
    delay(100);
    digitalWrite(relay2, LOW);
    delay(100);
    digitalWrite(relay1, LOW);
    delay(100);
}

