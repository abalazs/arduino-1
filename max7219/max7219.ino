#include "LedControl.h"

// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
static LedControl *lc = NULL;
static byte frames[] = {
  B10000000,
  B01000000,
  B00100000,
  B00010000,
  B00001000,
  B00000100,
  B00000010,
  B00000001,
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000,
  B11111111
};

static int8_t number_of_frames = sizeof(frames) / sizeof(byte);
static int8_t frame = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");

  lc = new LedControl(12, 11, 10, 1);
  lc->shutdown(0, false);
  lc->setIntensity(0, 15);
  lc->clearDisplay(0);
}

void loop() {
  lc->setColumn(0, 0, frames[frame]);
  frame++;
  if (frame == number_of_frames) {
    frame = 0;
  }
  delay(25);
}
