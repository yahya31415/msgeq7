#include <Adafruit_NeoPixel.h>

#define PIN 8	

#define NUMPIXELS 60

#define UPPER 1000

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 30;
float values[7];
int color[3];

void setup() {
  pixels.begin();
}

void loop() {
  setValues();

  for (int i=0; i < 7; i++) {
    setColor();
    float percentage = (values[i]/UPPER);
    float upf = percentage * (NUMPIXELS/7);
    int up = upf/1;
    for(int j=0; j < up; j++){
      pixels.setPixelColor(((NUMPIXELS/7)*i)+j, pixels.Color(color[0], color[1], color[2]));
    }
  }
  
  pixels.show();
  delay(delayval);
  pixels.clear();
}

void setColor(){
  color[0] = random(0, 255);
  color[1] = random(0,255);
  color[2] = random(0, 255);
}

void setValues() {
  for(int i=0; i<7; i++) {
  	values[i] = random(0,UPPER);
  }
}