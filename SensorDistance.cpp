/*
 * SensorDistance
 * Version 0.1.0 Jun, 2015
 * Copyright 2015 Diego de los Reyes
 *
 * Gets the distance to one obstacle.
 */

#include "SensorDistance.h"

   
/** CONSTRUCTORES **/

/**
 * Construct.
 */
SensorDistance::SensorDistance()
{
}

/** PUBLIC METHODS **/

/**
 * Attach the given pin.
 * @param pin: pin where the ultrasound sensor is connected.
 */
void SensorDistance::attach(int pin)
{
	pinSensor = pin;
}

/**
 * Gets the distance to one obstacle.
 */
float SensorDistance::getDistance()
{
	unsigned long pulse;
	float distance;

	pinMode(pinSensor, OUTPUT);
	digitalWrite(pinSensor, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinSensor, LOW);
	pinMode(pinSensor, INPUT);
	pulse = pulseIn(pinSensor, HIGH);
	distance = ((float(pulse/1000.0))*34.32)/2;
	delay(100);

	return distance;
}