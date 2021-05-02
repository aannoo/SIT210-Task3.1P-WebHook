SYSTEM_THREAD(ENABLED);

// debugging logs
SerialLogHandler logHandler;

// This is where the phototransistor is plugged in.
const pin_t SENSOR_PIN = A0; 

//transistor value variable
int analogvalue; 


void setup() {
	// Declare a Particle.variable() to access the sensor from the cloud
	Particle.variable("analogvalue", analogvalue);
}

void loop() {
    //store transistor value in variable
	analogvalue = analogRead(SENSOR_PIN);

    //log value
	Log.info("analogvalue=%d", analogvalue);
	
	//publish value to cloud
	Particle.publish("field_1", String(analogvalue), PRIVATE);

    //30 sec delay before starting loop again
	delay(30000ms);
}