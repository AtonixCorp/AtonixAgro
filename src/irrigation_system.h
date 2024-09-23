#ifndef IRRIGATION_SYSTEM_H
#define IRRIGATION_SYSTEM_H

#include <Arduino.h>

#define IRRIGATION_PIN 3

int readSoilMoisture();
void initIrrigationSystem();
void controlIrrigationSystem();

#endif // IRRIGATION_SYSTEM_H