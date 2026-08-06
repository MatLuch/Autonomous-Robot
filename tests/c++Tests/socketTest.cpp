#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "YourSsid";
const char* password = "YourPassword";
WiFiUDP udp;

String getPacket(int packetSize) {
  if (packetSize) {
    char buffer[255];
    int len = udp.read(buffer, 255);
    if (len > 0) buffer[len] = 0;
    return String(buffer);
  }
  return "";
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  udp.begin(1234);
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    Serial.println(getPacket(packetSize));
  }
}