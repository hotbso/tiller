/*
  MIT License

  Copyright (c) 2020 Holger Teutsch

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  Simple joystick application that presents a potentiometer as steering

*/

#include <Arduino.h>
#include <math.h>
#include <Joystick.h>

//#define DEBUG

#define TICK 20       // 50 Hz

#define MID 512
#define MID_RANGE 15  // slightly greater +- center hysterisis
#define NULL_ZONE 10  // 1% raw range, round everything in between to 0
#define DELTA 4       // only report if raw range 
#define SLOPE 1.6     // the poti has a higher angular range than the tiller, adjust so it feels natural

static double center_bias, center_act = 512;
#define CENTER_ALPHA 0.1  // exp smoother

static int jval_o;

static Joystick_ Tiller(JOYSTICK_DEFAULT_REPORT_ID,
                        JOYSTICK_TYPE_JOYSTICK, 0, 0,
                        false, false, false, false, false, false,
                        false, false, false, false, true);


static double read_poti(void) {
  int p1 = analogRead(A0);
  int p2 = analogRead(A1);
  double avg = (p1 + p2) * 0.5;

#ifdef DEBUG
  //Serial.print(String(p1) + " " + String(p2) + " " + String(avg));
  //Serial.println();
#endif

  return avg;
}

static void adjust_null(double val) {
  if (MID - MID_RANGE < val && val < MID + MID_RANGE) {
    char buff[20];
    center_act = CENTER_ALPHA * val + (1.0 - CENTER_ALPHA) * center_act;
    center_bias = MID - center_act;

#ifdef DEBUG
    //Serial.print("adjust_null: " + String(val) + "  " + dtostrf(center_act, sizeof(buff) - 1, 2, buff));
    //Serial.println();
#endif

  }
}

void setup() {
  delay(1000);

#ifdef DEBUG
  Serial.begin(57600);
  Serial.println();
#else
  Tiller.setSteeringRange(-1023, 1023);
  Tiller.begin();
#endif
}

void loop() {
  double val = read_poti();
  adjust_null(val);

  int jval = constrain(round(SLOPE * 2.0 * (val + center_bias - MID)), -1023, 1023);

  if (abs(jval) < NULL_ZONE)
    jval = 0;

  if (abs(jval - jval_o) >= DELTA) {
    jval_o = jval;
#ifdef DEBUG
    char buff[20];
    Serial.print(String(val) + "  " + String(jval)); Serial.println();
#else
    Tiller.setSteering(jval);
#endif
  }

  delay(TICK);
}
