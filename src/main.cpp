#include <Arduino.h>
#include "sensors/soil_moisture_sensor.h"
#include "sensors/temperature_sensor.h"
#include "actuators/irrigation_system.h"
#include "actuators/robotic_arm.h"
#include "utils/mqtt_client.h"
#include "utils/http_client.h"

void setup()
{
    // Initialize sensors and actuators
    initSoilMoistureSensor();
    initTemperatureSensor();
    initIrrigationSystem();
    initRoboticArm();

    // Initialize communication
    initMQTTClient();
    initHTTPClient();
}

void loop()
{
    // Main logic for your project
    monitorSoilMoisture();
    monitorTemperature();
    controlIrrigationSystem();
    controlRoboticArm();
    sendDataToCloud();
}