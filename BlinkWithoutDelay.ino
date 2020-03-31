/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

//https://www.arduino.cc/en/tutorial/fading
//https://www.arduino.cc/en/tutorial/BlinkWithoutDelay

#include <analogWrite.h>

const int red = 12;// the number of the LED pin
const int green = 27;// the number of the LED pin
const int blue = 33;// the number of the LED pin


int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int interval = 10;
long previousMillis = 0; //will store last time LED was updated

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  // declare pin 12 to be an output:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);  
  pinMode(blue, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 12:
  analogWrite(green, brightness);
  
  Serial.println("!!! - Check SENSOR - !!!");

   unsigned long currentMillis = millis();

   if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    analogWrite(blue, brightness);
   }
   }
}
