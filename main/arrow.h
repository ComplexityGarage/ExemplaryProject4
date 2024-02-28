// This file contains code that applies EMG_Counts into a real arrow
// attached to a servomechanism rotating by a constant angle at each
// detected muscle contraction

#ifndef ARROW_H
#define ARROW_H

#include "Servo.h"

#define ANGLE 45
Servo servo;
int pos = 0;

void initServo(int pin) {
	servo.attach(pin);
}

void rotate() {
	servo.write((pos+=ANGLE) % 180);
}

void resetServo() {
	pos=0;
	servo.write(0);
}

#endif
