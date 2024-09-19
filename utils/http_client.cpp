#include "http_client.h"
#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "your_SSID";
const char *password = "your_PASSWORD";
const char *serverName = "http://your_server.com/api/data";

void initHTTPClient()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
}

void sendDataToServer()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.begin(serverName);
        http.addHeader("Content-Type", "application/json");

        int soilMoisture = readSoilMoisture();
        float temperature = readTemperature();
        String payload = "{\"soilMoisture\":" + String(soilMoisture) + ",\"temperature\":" + String(temperature) + "}";

        int httpResponseCode = http.POST(payload);
        http.end();
    }
}