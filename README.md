# Tiller for flight simulation
Arduino based tiller

## assembled
![Tiller](https://github.com/hotbso/tiller/blob/master/doc/tiller.jpg)

## inside
![Inside](https://github.com/hotbso/tiller/blob/master/doc/inside.jpg)

## in windows
![In Windows](https://github.com/hotbso/tiller/blob/master/doc/tiller-calibration.jpg)

# BOM
- Arduino Micro (clone) https://smile.amazon.de/gp/product/B07FQJW2KN/ref=ppx_yo_dt_b_asin_title_o00_s01?ie=UTF8&psc=1
- hand wheel (e.g. for a lathe) https://smile.amazon.de/gp/product/B07QS43KJL/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1
- potentiometer dual 10 kOHm linear with center detent (e.g. for stereo balance control) (e.g. google for `ALPS RK09L1220 10KBX2CC`)
- poti knob with diameter matching the hole of the hand wheel 
- plastic box https://smile.amazon.de/gp/product/B072M2JKGW/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1
- USB cable

costs total < 30 €

# build
- install library https://github.com/MHeironimus/ArduinoJoystickLibrary
- connect outer contacts of poti to GND and VCC
- of inner contacts of poti one to A0, the other to A1
- upload sketch
