/*
Copyright (C) AC SOFTWARE SP. Z O.O.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "rgbw_leds.h"

Supla::Control::RGBWLeds::RGBWLeds(int redPin,
                                   int greenPin,
                                   int bluePin,
                                   int colorBrightnessPin,
                                   int brightnessPin)
    : redPin(redPin),
      greenPin(greenPin),
      bluePin(bluePin),
      colorBrightnessPin(colorBrightnessPin),
      brightnessPin(brightnessPin) {
}

void Supla::Control::RGBWLeds::setRGBWValueOnDevice(uint8_t red,
                          uint8_t green,
                          uint8_t blue,
                          uint8_t colorBrightness,
                          uint8_t brightness) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  analogWrite(brightnessPin, (brightness * 255) / 100);
  analogWrite(colorBrightnessPin, (colorBrightness * 255) / 100);
}

void Supla::Control::RGBWLeds::onInit() {
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
  pinMode(colorBrightnessPin, OUTPUT); 
  pinMode(brightnessPin, OUTPUT); 

 #ifdef ARDUINO_ARCH_ESP8266
  analogWriteRange(255);
 #endif 

  Supla::Control::RGBWBase::onInit();
}
