#include <DisplayManager.cpp>
#include <LEDMatrix.cpp>
#include <TemperatureManager.cpp>
#include <TimeManager.cpp>
#include <TiltManager.cpp>
#include <Pangodream_18650_CL.h>
#include <vector>

//#include <Wire.h>
//#include <Adafruit_GFX.h>

//pins
const int PIN_buttonStart = 32;//2
const int PIN_buttonRepeats = 33;//3

const int PIN_tilt = 37;//7

const int PIN_dht = 26;//5

const int PIN_rgbRed = 12;//11
const int PIN_rgbGreen = 13;//10
const int PIN_rgbBlue = 15;//9

const int PIN_speaker = 17;

Pangodream_18650_CL Battery;

    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

void setup() {

  pinMode(PIN_buttonStart, INPUT);
  pinMode(PIN_buttonRepeats, INPUT);
  pinMode(PIN_tilt, INPUT);

  pinMode(PIN_rgbRed, OUTPUT);
  pinMode(PIN_rgbGreen, OUTPUT);
  pinMode(PIN_rgbBlue, OUTPUT);
  
  Serial.begin(9600);

  matrix.begin(0x70);  
  matrix.setRotation(3);

  while (! rtc.begin()) {
    Serial.println("RTC is NOT running!");
    delay(1000);
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  lcd.init();
  lcd.backlight();

  dht.begin();

}

//Setup Getters for returning the PIN values 

int GetTiltPin() {
  return PIN_tilt;
}

int GetDHTPin() {
  return PIN_dht;
}

int GetSpeakerPin(){
  return PIN_speaker;
}

int GetRGB(int val) {
  switch (val)
  {
  case 0:
    return PIN_rgbRed;
  case 1:
    return PIN_rgbGreen;
  case 2:
    return PIN_rgbBlue;
  default:
    return PIN_rgbRed;
  }
}