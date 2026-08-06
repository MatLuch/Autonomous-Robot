#include <WiFi.h>
#include <WiFiUdp.h>

// Declaring the motors variables
const int M1A = 12;
const int M1B = 13;

const int M2A = 27;
const int M2B = 14;

const int M3A = 25;
const int M3B = 33;

const int M4A = 2;
const int M4B = 4;

// Declaring the Wifi variables and making the needed wifi reading stuff
const char* ssid = "SSID";
const char* password = "PASSWORD";
WiFiUDP udp;

String getPacket(int packetSize){
    if (packetSize){
        char buffer[255];
        int len = udp.read(buffer, 255);
        if (len > 0) buffer[len] = 0; 
        return String(buffer);
    }
    return "";
}

// this is the setup where i declare the state of the motors and start reading the wifi for data
void setup() {
  
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  pinMode(M3A, OUTPUT);
  pinMode(M3B, OUTPUT);
  pinMode(M4A, OUTPUT);
  pinMode(M4B, OUTPUT);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  udp.begin(1234);
}

void loop() {
String message = read();
if(message != ""){
  Serial.println(message);
}
delay(10);
}

String read(){
    int packetSize = udp.parsePacket(); 
     if(packetSize) {
      return getPacket(packetSize);
  }
  return "";
}

void Forward(){
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);

  digitalWrite(M3A, HIGH);
  digitalWrite(M3B, LOW);
  digitalWrite(M4A, HIGH);
  digitalWrite(M4B, LOW);
}

void Backward(){
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);

  digitalWrite(M3A, LOW);
  digitalWrite(M3B, HIGH);
  digitalWrite(M4A, LOW);
  digitalWrite(M4B, HIGH);
}

void Right(){
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);

  digitalWrite(M3A, HIGH);
  digitalWrite(M3B, LOW);
  digitalWrite(M4A, LOW);
  digitalWrite(M4B, HIGH);
  delay(1200);
}

void Left(){
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);

  digitalWrite(M3A, LOW);
  digitalWrite(M3B, HIGH);
  digitalWrite(M4A, HIGH);
  digitalWrite(M4B, LOW);
  delay(1200);
}