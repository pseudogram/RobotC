#pragma config(Sensor, S1,     lightSensorL,   sensorEV3_Color, modeEV3Color_Ambient)

task main()
{
	/*
// Calibrate light level
	int i = 0;
  float ambientLight = 0;
	while (i<5000)
	{
		float lightlevel = getColorAmbient( lightSensorL );
		motor[motorA] = 100;
		ambientLight = ((ambientLight*i)+lightlevel)/(i+1);
		i = i + 1;
		displayBigTextLine( 5, "Ambient Lvl: %d", ambientLight );
	}*/

float ambientLight = 10;
// Start
	while (true)
	{
			// level of light detected
		float lightlevel = getColorAmbient( lightSensorL );
		float leftMotor = 100;

		// algorithm for right motor
		float z = lightlevel-ambientLight;
		float rightMotor = 100*1/(1+exp(-(z/(ambientLight/3))));

		motor[motorA] = leftMotor;
		motor[motorD] = rightMotor;

		displayBigTextLine( 1, "Left: %d", leftMotor );
		displayBigTextLine( 3, "Right: %d", rightMotor );
		displayBigTextLine( 5, "Light Lvl: %d", lightlevel );
		displayBigTextLine( 7, "Ambient Lvl: %d", ambientLight );
	}
}