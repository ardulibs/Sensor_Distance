/*
 * RobotDistance
 * Version 0.1.0 Jun, 2015
 * Copyright 2015 Diego de los Reyes
 *
 * Gets the distance to one obstacle.
 */

#ifndef RobotDistance_h
#define RobotDistance_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// Class RobotDistance
class RobotDistance {
 
	/** Public elements. **/
	public:
	
		/**
		 * Construct.
		 */
		RobotDistance();

		/**
		 * Attach the given pin.
		 * @param pin: pin where the ultrasound sensor is connected.
		 */
		void attach(int pin);
	
		/**
		 * Gets the distance to one obstacle.
		 */
		float getDistance();

	private:

		/** Attributes **/

		//Attached pin.
		int pinSensor;
};

#endif

