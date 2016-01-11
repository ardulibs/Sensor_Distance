/*
 * SensorDistance
 * Version 0.1.0 Jun, 2015 - Created.
 * Version 0.2.0 Jun, 2015 - Added turn on, turn off and is active.
 * Version 0.2.1 Jun, 2015 - Starts turned off.
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
 * @param pinTrig: pin where the trigger pin is connected.
 * @param pinEcho: pin where the echo pin is connected.
 */
void SensorDistance::attach(int inputTrig, int inputEcho)
{
	pinTrig = inputTrig;
	pinEcho = inputEcho;
	pinMode(pinTrig, OUTPUT);
  	pinMode(pinEcho, INPUT);
	this->turnOff();
}

/**
 * Gets the distance to one obstacle.
 */
float SensorDistance::getDistance()
{
	long distance = -1;

	if(this->isActive()){
		long duration;
		digitalWrite(pinTrig, LOW);  // Added this line
		delayMicroseconds(2); // Added this line
		digitalWrite(pinTrig, HIGH);
		//  delayMicroseconds(1000); - Removed this line
		delayMicroseconds(10); // Added this line
		digitalWrite(pinTrig, LOW);
		duration = pulseIn(pinEcho, HIGH);
		distance = (duration/2) / 29.1;

		if (distance >= 200 || distance <= 0){
			distance = -1;
		}

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
