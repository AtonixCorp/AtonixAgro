#include "MQTTClient.h"
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char *ssid = "your_SSID";
const char *password = "your_PASSWORD";

// MQTT broker details
const char *mqtt_server = "your_mqtt_broker_address";
const int mqtt_port = 1883;
const char *mqtt_user = "your_mqtt_username";
const char *mqtt_password = "your_mqtt_password";

// Create WiFi and MQTT client instances
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi()
{
    delay(10);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP32Client", mqtt_user, mqtt_password))
        {
            Serial.println("connected");
            // Once connected, publish an announcement...
            client.publish("outTopic", "hello world");
            // ... and resubscribe
            client.subscribe("inTopic");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void initMQTTClient()
{
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
}

void sendDataToCloud(const char *topic, const char *payload)
{
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();
    client.publish(topic, payload);
}