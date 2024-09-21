
#include <Arduino.h>
#include <WiFiNINA.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <107-Arduino-BoostUnits.h>

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

// WiFi credentials
const char* ssid = "your_SSID"; // Replace with your Wi-Fi SSID
const char* password = "your_PASSWORD"; // Replace with your Wi-Fi password

// Sentinel Hub API credentials
const char* apiKey = "your_sentinel_hub_api_key";

// Sentinel Hub API URL
String sentinelHubUrl = "https://services.sentinel-hub.com/api/v1/process";

// Arduino IoT Cloud variables
String atonixAgro;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(1500);

  // Initialize the DHT sensor
  dht.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
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

  // Fetch data from Sentinel Hub API
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(sentinelHubUrl);
    http.addHeader("Authorization", "Bearer " + String(apiKey));
    http.addHeader("Content-Type", "application/json");

    // Example payload for Sentinel Hub API
    String payload = "{\"input\": {\"bounds\": {\"bbox\": [13.822174072265625, 45.85080395917834, 14.55963134765625, 46.29191774991382]}, \"data\": [{\"type\": \"sentinel-2-l1c\"}]}, \"output\": {\"width\": 512, \"height\": 512, \"responses\": [{\"identifier\": \"default\", \"format\": {\"type\": \"image/jpeg\"}}]}}";

    int httpCode = http.POST(payload);

    if (httpCode > 0) {
      String response = http.getString();
      Serial.println(response);

      // Parse JSON response
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, response);

      // Process the response as needed
      // Example: Extracting a specific value from the JSON response
      // float someValue = doc["someKey"].as<float>();
      // Serial.print("Some Value: ");
      // Serial.println(someValue);
    } else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }

  // Wait for 10 seconds before sending the next data
  delay(10000);
}