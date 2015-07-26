/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int secs = 60;
int milli = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(" Detonation in:");
}

String zeroPad (int val) {
  if (val < 10) {
    return String("0" + String(val));
  } else {
    return String(val);
  }
}


void displayTime (int numsecs) {
  String display_time, mins, secs;
  
  mins = zeroPad(numsecs / 60);
  secs = zeroPad(numsecs % 60);
  display_time = String(String(mins) + ":" + String(secs));
  lcd.setCursor(6, 1);
  lcd.print(display_time);
}


void loop() {

  displayTime(secs);
  if (secs < 0) {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("BOOM");
    lcd.setCursor(6,1);
    lcd.print("BOOM");
    delay(5000);

    lcd.clear();
    lcd.print(" Detonation in:");
    secs = 60;
  } else if (secs < 5) {
    lcd.noDisplay();
    delay(150);
    lcd.display();
    delay(350);
    
    milli += 500;
    if (milli >= 1000) {
      secs -= 1;
    }
  } else if (secs < 15) {
    lcd.noDisplay();
    delay(250);
    lcd.display();
    delay(750);
    secs -= 1; 
  } else {
    secs -= 1;
    delay(1000);
  }
}

