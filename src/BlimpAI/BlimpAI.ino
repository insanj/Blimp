// Created by Casey Waldren and Julian Weiss
// U of R, CSC 197, Spring 2014, Blimp Bot

#define MAX_SENSORS 5
#define MAX_MOTORS 3
#define LED_PIN 13

/************************************************************************/
/****************************** Structures ******************************/
/************************************************************************/

typedef struct {
	char name[36];	// Human-assigned name (english)
	int pin;		// Hardware pin on board
	float speed;	// Speed (relative rate)
	bool analog;
} Motor;

typedef struct {
	char name[36];
	int pin;
	int value;
	bool analog;
} Sensor;

// Arrays for all installed motors and sensors
Motor motors[MAX_MOTORS];
Sensor sensors[MAX_SENSORS];

/************************************************************************/
/********************************* Setup ********************************/
/************************************************************************/

// Straightforward initialization for all sensors in array
void setup_sensors() {
	for (int i = 0; i < MAX_SENSORS; i++) {
		Sensor sensor = sensors[i];
		if (!sensor.analog) {
			pinMode(sensors[i].pin, INPUT);
		}
	}
}

// Straightforward initialization for all motors in array
void digital_setup_motors() {
	for (int i = 0; i < MAX_MOTORS; i++) {
		pinMode(motors[i].pin, OUTPUT);
	}
}

// Standard Arduino setup function
void setup() {
	pinMode(LED_PIN, OUTPUT);

	/*
	motors[0] = (Motor){"Front motor", 13, 0};
	motors[1] = (Motor){"Left-back motor", 14, 0};
	motors[2] = (Motor){"Right-back motor", 15, 0};
	setup_motors();

	sensors[0] = (Sensor){"Front ultrasonic sensor", 5, 0};
	sensors[1] = (Sensor){"Back ultrasonic sensor", 6, 0};
	sensors[2] = (Sensor){"Left ultrasonic sensor", 7, 0};
	sensors[3] = (Sensor){"Right ultrasonic sensor", 8, 0};
	*/
	
	sensors[0] = (Sensor){"Infrared", 2, 0};
	setup_sensors();
	
	test_infrared(sensors[0].pin);
}


/************************************************************************/
/******************************** Tests *********************************/
/************************************************************************/

void test_infrared(int pin) {
	int sensorValue = analogRead(pin);		// read the value from the sensor
	digitalWrite(LED_PIN, HIGH);			// turn the ledPin on
	delay(sensorValue);						// stop the program for <sensorValue> milliseconds
	digitalWrite(LED_PIN, LOW);				// turn the ledPin off
	delay(sensorValue);						// stop the program for for <sensorValue> milliseconds
}

/************************************************************************/
/******************************** Phases ********************************/
/************************************************************************/

void check_charge() {
/*
 if (current_cycle - last_cycle_checked) >= periodic_check_cycles
	 if check_charge() <= 5
		 landing_phase()
	 else if check_charge() <= 20
		 homing_phase()
	 else
		 last_cycle_checked = current_cycle
 
*/
}

// In order to assure complete operability, BlimpAI will periodically check the hardware connection for status of its battery. The results of this test will determine the next immediate phase: if the bot is in standby, launching or landing, if the bot in airborne, wandering or homing. The barebones translation of this portion goes something like:
void preflight() {
	check_charge();
}

// If the preflight phase cleared, BlimpAI will send signals to power on all of the bot’s motors and rise until it reaches a predetermined height. Once there, it will move out of launch and into wander.
void launch() {
/*
 motors_on(up_dir)
 while get_height() < ~10 feet
 do nothing...
 wandering_phase()
 */
}

// After assured that it’s at an acceptable charge level and height, BlimpAI will pick a random direction to “wander.” To sustain adequate flight patterns, the bot will periodically power on the downward and active motors to coast and remain airborne, while conserving battery life. While in pseudo-random wander, BlimpAI will check its ultrasonic sensors to check for obstacles. If it detects an imminent collision, the bot will immediately be prompted to pick a new direction and restart the phase. In addition, this phase includes the same charge-checking code from the preflight phase.
void wander() {
/*
 dir = pick_direction(specific_dir || c_random)
 motors_on(dir)
 set_timer(3 secs)
 
 if timer_fired
 if averting_collision
 motors_off()
 averting_collision = false
 motors_on(pick_direction(c_random))
 if check_collisions()
 motors_off()
 averting_collision = true
 set_timer(1.5 secs)
 motors_on(reverse_dir)
 charge_check()
 */
}

//Once given the signal to initiate the homing sequence, BlimpAI will break out of all other phases and begin finding its way to the charging dock. First, the bot will a scan the area for an IR beacon. If none can be found, it will first rotate 180 degrees to check its immediate surroundings, then continue in a random direction and check again, following its own specific wander protocol until finding a beacon. Once found, the bot will power its horizontal motors until it’s hovering above it. Once locked above, it will call for the landing phase.
void home() {
/*
  motors_off()
 ir_direction = ir_detected()
 lost = !ir_direction
 
 if current_time - started_spin_time >= 8 secs (time for 360)
 wandering_phase()
 else if lost
 started_spin_time = current_time
 set_timer(0.25 secs) // average time to spin 45°
 motors_on(right)
 else
 while distance to ir_distance() > 10
 // collision logic like in random walk
 motors_on(ir_direction)
 motors_off()
 landing_phase()
 */
}

// During this final phase, the bot is instructed by BlimpAI to descend vertically until its ultrasonic sensors detect something below it (presumably the charging station or the floor) in close proximity, at which point it will slowly power off all motors. From this point on, it will begin preflighting until able to take off again
void land() {
/*
 set_motor_speed(slow)
 motors_on(down_dir)
 while get_height() > 1 foot
 do nothing
 motors_off()
*/
}

/************************************************************************/
/******************************* Run Loop *******************************/
/************************************************************************/

void loop() {
	preflight();
}
