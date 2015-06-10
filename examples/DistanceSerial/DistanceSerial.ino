#include <SensorDistance.h>

SensorDistance sensor;

void setup() {
  Serial.begin(9600);
  sensor.attach(A0);
}

void loop() {
  int distance = sensor.getDistance();
  Serial.println(distance);
  delay(500);
}