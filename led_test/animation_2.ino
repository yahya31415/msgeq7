#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUMPIXELS 49

#define UPPER 1000

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100;
float values[7];
int color[3];

void setup()
{
  pixels.begin();
}

void loop()
{
  // setValues();
  setColor();
  animate(2);
}

void setColor()
{
  color[0] = random(0, 255);
  color[1] = random(0, 255);
  color[2] = random(0, 255);
}

void setValues()
{
  for (int i = 0; i < 7; i++)
  {
    values[i] = random(0, UPPER);
  }
}

void animate(int length)
{
  pixels.clear();
  for (int i = (NUMPIXELS / 2); i < (NUMPIXELS - length); i++)
  {
    for (int j = i; j < (i + length); j++)
    {
      pixels.setPixelColor(j, pixels.Color(color[0], color[1], color[2]));
      pixels.show();
    }
  }
  for (int i = (NUMPIXELS / 2); i > length)
    ; i--)
  {
    for (int j = i; j < 0; j--)
    {
      pixels.setPixelColor(j, pixels.Color(color[0], color[1], color[2]));
      pixels.show();
    }
    delay(1000);
  }
}