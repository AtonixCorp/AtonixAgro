#include "temperature_sensor.h"
#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void initTemperatureSensor()
{
    dht.begin();
}

float readTemperature()
{
    return dht.readTemperature();
}