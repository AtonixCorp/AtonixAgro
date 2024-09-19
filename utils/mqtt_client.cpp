#include "mqtt_client.h"
#include <PubSubClient.h>
#include <WiFi.h>

const char *ssid = "your_SSID";
const char *password = "your_PASSWORD";
const char *mqtt_server = "your_MQTT_SERVER";

WiFiClient espClient;
PubSubClient client(espClient);

void initMQTTClient()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    client.setServer(mqtt_server, 1883);
}

void sendDataToCloud()
{
    if (!client.connected())
    {
        while (!client.connected())
        {
            client.connect("ESP32Client");
        }
    }
    int soilMoisture = readSoilMoisture();
    float temperature = readTemperature();
    String payload = "{\"soilMoisture\":" + String(soilMoisture) + ",\"temperature\":" + String(temperature) + "}";
    client.publish("farm/data", payload.c_str());
}