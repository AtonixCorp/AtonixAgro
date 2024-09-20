#include <Arduino.h>
#include "mqtt_client.h"
#include <DHT.h>

// Define the pins for the sensors
#define SOIL_MOISTURE_PIN A0
#define DHT_PIN 2
#define DHT_TYPE DHT22

// Initialize the DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Variables to store sensor data
float soilMoisture;
float temperature;
float humidity;

// Arduino IoT Cloud variables
String atonixAgro;

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);
    delay(1500);

    // Initialize the DHT sensor
    dht.begin();

    // Initialize the MQTT client
    initMQTTClient();
}

void loop()
{
    // Read data from the soil moisture sensor
    soilMoisture = analogRead(SOIL_MOISTURE_PIN);

    // Read data from the DHT sensor
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    // Print the sensor data to the serial monitor
    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);

    // Example data to send
    const char *topic = "sensor/data";
    String payload = "{\"soilMoisture\": " + String(soilMoisture) + ", \"temperature\": " + String(temperature) + ", \"humidity\": " + String(humidity) + "}";

    // Send data to the cloud
    sendDataToCloud(topic, payload.c_str());

    // Wait for 10 seconds before sending the next data
    delay(10000);
}

// The code above reads data from the soil moisture sensor and the DHT sensor. It then sends the data to the cloud using the MQTT protocol.
// The  setup()  function initializes the serial communication, the DHT sensor, and the MQTT client. The  loop()  function reads the sensor data, prints it to the serial monitor, and sends it to the cloud.
// The  sendDataToCloud()  function is used to send data to the cloud. It takes the topic and the payload as arguments. The payload is a JSON string that contains the sensor data.
// The  initMQTTClient()  function initializes the MQTT client and connects to the MQTT broker. It also subscribes to the topic  atonixAgro  to receive commands from the cloud.
/// The  mqtt_client.h  file contains the MQTT client code. It includes the necessary libraries and defines the MQTT broker address, port, username, and password.
// #ifndef MQTT_CLIENT_H