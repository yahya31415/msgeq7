#include <Adafruit_NeoPixel.h>

#define LEDLOW 8   // input pin Neopixel is attached to
#define LEDMID 9  
#define LEDHIG 10 

#define NUMPIXELS      8 // number of neopixels in strip

Adafruit_NeoPixel pixelsLow = Adafruit_NeoPixel(NUMPIXELS, LEDLOW, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsMid = Adafruit_NeoPixel(NUMPIXELS, LEDMID, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsHig = Adafruit_NeoPixel(NUMPIXELS, LEDHIG, NEO_GRB + NEO_KHZ800);

int delayval = 30; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Initialize the NeoPixel library.
  pixelsLow.begin();
}

void loop() {
  setColor();
  
  int low = random(0, NUMPIXELS);
  int mid = random(0, NUMPIXELS);
  int high = random(0, NUMPIXELS);

  for (int i=0; i < (NUMPIXELS-low); i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixelsLow.setPixelColor(i, pixelsLow.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixelsLow.show();
  }
  
  for (int i=0; i < (NUMPIXELS-mid); i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixelsMid.setPixelColor(i, pixelsMid.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixelsMid.show();
  }
  
  for (int i=0; i < (NUMPIXELS-high); i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixelsHig.setPixelColor(i, pixelsHig.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixelsHig.show();
  }
  
  // Delay for a period of time (in milliseconds).
  delay(delayval);
  
  pixelsLow.clear();
  pixelsMid.clear();
  pixelsHig.clear();
}

// setColor()
// picks random values to set for RGB
void setColor(){
  redColor = 255; //random(0, 255);
  greenColor = 0; //random(0,255);
  blueColor = 0; //random(0, 255);
}
