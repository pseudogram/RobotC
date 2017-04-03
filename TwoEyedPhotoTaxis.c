#pragma config(Sensor, S1,     lightSensorL,   sensorEV3_Color, modeEV3Color_Ambient)
#pragma config(Sensor, S1,     lightSensorL,   sensorEV3_Color, modeEV3Color_Ambient)

// Set up bot with one light sensor front and center.
task main()
{
	//int i = 0;					//used to determine avg speed
	//float avgRPM = 0;		//used to determine avg speed
	int i = 0;
	while (true)
	{
			// level of light detected
			float centerAmbient = getColorAmbient( lightSensorL );

//		float leftMotor = (centerAmbient - 10 ) + centerAmbient * 9;
//		float rightMotor = (centerAmbient - 10 ) + centerAmbient * 10;
			//float leftMotor = 100;
			//float rightMotor = 100 * (1/(1+exp(centerAmbient));

		float leftMotor = 100;

		float z = centerAmbient-10;
		// algorithm for right motor
		float rightMotor = 80/(1+exp(-(z/20)));

		motor[motorA] = leftMotor;
		motor[motorD] = rightMotor;

		// determine average speed
		//float RPM = getMotorRPM(motorA);				//used to determine avg speed
		//float avgRPM = (avgRPM*i+RPM)/(i+1);		//used to determine avg speed
		//i += 1;																	//used to determine avg speed

		displayBigTextLine( 1, "Left: %d", leftMotor );
		displayBigTextLine( 3, "Right: %d", rightMotor );
		displayBigTextLine( 5, "Light Lvl: %d", centerAmbient );
		//displayBigTextLine( 7, "MotorA RPM: %d", RPM );					//used to determine avg speed
		//displayBigTextLine( 9, "avg RPM: %d", avgRPM );					//used to determine avg speed
		i += 1;
	}
}
