#pragma config(Sensor, S1, lightSensorL, sensorEV3_Color, modeEV3Color_Ambient)
#pragma config(Sensor, S4, lightSensorR, sensorEV3_Color, modeEV3Color_Ambient)
task main()
{
	while (true)
	{
		displayBigTextLine( 1, "Left: %d", getColorAmbient( lightSensorL ) );
		displayBigTextLine( 3, "Right: %d", getColorAmbient( lightSensorR ) );
		float photoLeft;
		float photoRight;
		float distLeft;
		float distRight;
		//Photo layer
		{
			float leftAmbient = getColorAmbient( lightSensorL );
			float rightAmbient = getColorAmbient( lightSensorR );
			photoLeft = (rightAmbient - 0) * 30; //Scale the inputs
			photoRight = (leftAmbient - 0) * 30;
		}

		motor[motorA] = photoLeft;
		motor[motorD] = photoLeft;
	}
}
