#define MAX_SENSORS 5
#define MAX_MOTORS 3

/* Motors */
typedef struct {
  char name[36];
  int pin;
  int speed;
} Motor;

/* Sensors */


typedef struct {
  char name[36];
  int pin;
  int value;
} Sensor;

Motor motors[MAX_MOTORS];
Sensor sensors[MAX_SENSORS];


void setup() {

  motors[0] = (Motor){"Front motor", 13, 0};
  motors[1] = (Motor){"Left-back motor", 14, 0};
  motors[2] = (Motor){"Right-back motor", 15, 0};


  sensors[0] = (Sensor){"Front ultrasonic sensor", 5, 0};
  sensors[1] = (Sensor){"Back ultrasonic sensor", 6, 0};
  sensors[2] = (Sensor){"Left ultrasonic sensor", 7, 0};
  sensors[3] = (Sensor){"Right ultrasonic sensor", 8, 0};
  sensors[4] = (Sensor){"IR sensor", 9, 0};


}


void setup_sensors() {
  for (int i = 0; i < MAX_SENSORS; i++) {
    pinMode(sensors[i].pin, INPUT);
  }
}


void loop() {

}

