# Tiller for flight simulation
Arduino based tiller

## assembled
![Tiller](https://github.com/hotbso/tiller/blob/master/doc/tiller.jpg)

## inside
![Inside](https://github.com/hotbso/tiller/blob/master/doc/inside.jpg)

## in windows
![In Windows](https://github.com/hotbso/tiller/blob/master/doc/tiller-calibration.jpg)

# BOM
- Arduino Micro (clone)
- hand wheel (e.g. for a lathe)
- potentiometer dual 10 kOHm linear with center detent (e.g. for stereo balance control)
- poti knob with diameter matching the hole of the hand wheel
- plastic box
- USB cable

costs total < 30 €

# build
- install library https://github.com/MHeironimus/ArduinoJoystickLibrary
- connect outer contacts of poti to GND and VCC
- of inner contacts of poti one to A0, the other to A1
- upload sketch
