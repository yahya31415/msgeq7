#include <Adafruit_NeoPixel.h>

#define PIN 9	

#define NUMPIXELS 60

#define UPPER 1500

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200;
float values[7];
int color[3];

int strobePin  = 7;    // Strobe Pin on the MSGEQ7
int resetPin   = 8;    // Reset Pin on the MSGEQ7
int outPin     = A1;   // Output Pin on the MSGEQ7

void setup() {
  pixels.begin();

  // put your setup code here, to run once:
  Serial.begin (9600);
 
  // Define our pin modes
  pinMode      (strobePin, OUTPUT);
  pinMode      (resetPin,  OUTPUT);
  pinMode      (outPin,    INPUT);
 
  // Create an initial state for our pins
  digitalWrite (resetPin,  LOW);
  digitalWrite (strobePin, LOW);
  delay        (1);
 
  // Reset the MSGEQ7 as per the datasheet timing diagram
  digitalWrite (resetPin,  HIGH);
  delay        (1);
  digitalWrite (resetPin,  LOW);
  digitalWrite (strobePin, HIGH); 
  delay        (1);
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
      pixels.show();
      // delay(30);
    }
  }
  
  // delay(delayval);
  pixels.clear();
}

void setColor(){
  color[0] = random(0, 255);
  color[1] = random(0,255);
  color[2] = random(0, 255);
}

void setValues() {
  for (int i = 0; i < 7; i++) {
    digitalWrite       (strobePin, LOW);
    delayMicroseconds  (100);                  // Delay necessary due to timing diagram
    values[i] =         analogRead (outPin);
    digitalWrite       (strobePin, HIGH);
    delayMicroseconds  (1);                    // Delay necessary due to timing diagram  
  }
}