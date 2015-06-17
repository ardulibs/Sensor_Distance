/*
 * SensorDistance
 * Version 0.1.0 Jun, 2015 - Created.
 * Version 0.2.0 Jun, 2015 - Added turn on, turn off and is active.
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
	this->turnOn();
}

/**
 * Gets the distance to one obstacle.
 */
float SensorDistance::getDistance()
{
	float distance = -1;

	if(this->isActive()){
		unsigned long pulse;

		pinMode(pinSensor, OUTPUT);
		digitalWrite(pinSensor, HIGH);
		delayMicroseconds(10);
		digitalWrite(pinSensor, LOW);
		pinMode(pinSensor, INPUT);
		pulse = pulseIn(pinSensor, HIGH);
		distance = ((float(pulse/1000.0))*34.32)/2;
		delay(100);
	}

	return distance;
}

/**
 * Turns on the sensor.
 */
void SensorDistance::turnOn()
{
	this->active = true;
}

/**
 * Turns off the sensor.
 */
void SensorDistance::turnOff()
{
	this->active = false;
}

/**
 * Returns true if the sensor is active and false in other case.
 */
bool SensorDistance::isActive()
{
	return this->active;
}
