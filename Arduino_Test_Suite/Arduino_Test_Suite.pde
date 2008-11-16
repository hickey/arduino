

#define LED_PIN  13

int count = 0;
    
    
void setup() {
    Serial.begin(9600);
    Serial.println("Initialized...");

    pinMode(LED_PIN, OUTPUT);
}


void loop() {
     Serial.print("count = ");
    Serial.println(count);
    count++;
    
    if (digitalRead(LED_PIN) == 0) {
        digitalWrite(LED_PIN, 1);
    } else {
        digitalWrite(LED_PIN, 0);
    }
    
    delay(1000);
}
