#include "soil_moisture_sensor.h"
#include <Arduino.h>

#define SOIL_MOISTURE_PIN A0

void initSoilMoistureSensor()
{
    pinMode(SOIL_MOISTURE_PIN, INPUT);
}

int readSoilMoisture()
{
    return analogRead(SOIL_MOISTURE_PIN);
}