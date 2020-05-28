#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define RX 3
#define TX 4

TinyGPS gps;
SoftwareSerial ss (TX, RX);

float lat;
float lon;

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
}

void loop() {
  while(ss.available()){
     char b = ss.read();
     if(gps.encode(b)){
       monitor();
      }
  }
}

void monitor(){
    gps.f_get_position(&lat, &lon);
    Serial.print("latitude:");
    Serial.println(lat, 6);
    Serial.print("longitude:");
    Serial.println(lon, 6);
}
