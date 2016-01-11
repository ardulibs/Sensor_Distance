#include <SensorDistance.h>

SensorDistance sensor;
float distance;

void setup() {
  Serial.begin(9600);
  sensor.attach(12, 11);
  sensor.turnOn();
}

void loop() {
  distance = sensor.getDistance();
  Serial.println(distance);
  delay(500);
}