#include "FastLED.h"

#define NUM_LEDS 1
#define DATA_PIN 5       // Clock and data pins for LED data
#define CLOCK_PIN 4

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:}
  Serial.begin(9600);
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN>(leds, NUM_LEDS);  // initialize LED control object
}

void loop() {
  //TODO driver
  leds[0].red   = 200;
  leds[0].green = 0;
  leds[0].blue  = 0;
  FastLED.show();
  delay(2000);

  leds[0].red   = 0;
  leds[0].green = 200;
  leds[0].blue  = 0;
  FastLED.show();
  delay(2000);

  leds[0].red   = 0;
  leds[0].green = 0;
  leds[0].blue  = 200;
  FastLED.show();
  delay(2000);
}

