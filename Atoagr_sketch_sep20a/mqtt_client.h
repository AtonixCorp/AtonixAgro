#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

void initMQTTClient();
void sendDataToCloud(const char *topic, const char *payload);

#endif // MQTT_CLIENT_H