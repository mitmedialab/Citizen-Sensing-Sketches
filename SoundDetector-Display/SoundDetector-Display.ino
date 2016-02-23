#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#define PIN_ANALOG_IN A0

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  matrix.begin(0x70);  // pass in the address
  
  // Display status
  Serial.println("Initialized");
}

int readings[8] =
  {0,0,0,0,0,0,0,0};

static const uint8_t PROGMEM

void loop() {
  // put your main code here, to run repeatedly:
  int y;
  int value = analogRead(PIN_ANALOG_IN);
  

//  Display Marquee based on sound value
    if (value < 10){
        y=0;
    } else if (value < 20){
        y=1;
    } else if (value < 30){
        y=2;
    } else if (value < 50){
        y=3;
    } else if (value < 90){
        y=4;
    } else if (value < 130){
        y=5;
    } else if (value < 200){
        y=6;
    } else {
        y=7;
    }  

    for(int i=0; i <= 6; i++){
      readings[i] = readings[i+1];
    };
    readings[7] = y;
    
  
    matrix.clear();  
    for (int i = 0; i <= 7; i++){
      matrix.drawLine(7-i,0, 7-i,readings[i], LED_ON);
      matrix.writeDisplay();
    }
    
  // pause
  delay(500);
}
