#include "irrigation_system.h"
#include <Arduino.h>

#define IRRIGATION_PIN 3

int readSoilMoisture()
{
    // Example logic to read soil moisture
    return analogRead(A0);
}

void initIrrigationSystem()
{
    pinMode(IRRIGATION_PIN, OUTPUT);
    digitalWrite(IRRIGATION_PIN, LOW);
}

void controlIrrigationSystem()
{
    // Example logic to control irrigation
    int soilMoisture = readSoilMoisture();
    if (soilMoisture < 300)
    {
        digitalWrite(IRRIGATION_PIN, HIGH); // Turn on irrigation
    }
    else
    {
        digitalWrite(IRRIGATION_PIN, LOW); // Turn off irrigation
    }
}