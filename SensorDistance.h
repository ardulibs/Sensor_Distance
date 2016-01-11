/*
 * SensorDistance
 * Version 0.1.0 Jun, 2015 - Created.
 * Version 0.2.0 Jun, 2015 - Added turn on, turn off and is active.
 * Version 0.2.1 Jun, 2015 - Starts turned off.
 * Copyright 2015 Diego de los Reyes
 *
 * Gets the distance to one obstacle.
 */

#ifndef SensorDistance_h
#define SensorDistance_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// Class SensorDistance
class SensorDistance {
 
	/** Public elements. **/
	public:
	
		/**
		 * Construct.
		 */
		SensorDistance();

		/**
		 * Attach the given pin.
		 * @param pin: pin where the ultrasound sensor is connected.
		 */
		void attach(int pinTrig, int pinEcho);
	
		/**
		 * Gets the distance to one obstacle.
		 */
		float getDistance();

		/**
		 * Turns on the sensor.
		 */
		void turnOn();

		/**
		 * Turns off the sensor.
		 */
		void turnOff();

		/**
		 * Returns true if the sensor is active and false in other case.
		 */
		bool isActive();

	private:

		/** Attributes **/

		//Attached trigger pin.
		int pinTrig;

		//Attached echo pin.
		int pinEcho;

		//Active
		bool active;
};

#endif

