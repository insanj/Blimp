#define MAX_SENSORS 5
#define MAX_MOTORS 3

typedef struct {
  char name[36];
  int pin;
  int speed;
} Motor;

typedef struct {
  char name[36];
  int pin;
  int value;
} Sensor;

Motor motors[MAX_MOTORS];
Sensor sensors[MAX_SENSORS];


void setup_sensors() {
  for (int i = 0; i < MAX_SENSORS; i++) {
    pinMode(sensors[i].pin, INPUT);
  }
}

void setup_motors() {
  for (int i = 0; i < MAX_MOTORS; i++) {
    pinMode(motors[i].pin, OUTPUT);
  }
}

void setup() {

  motors[0] = (Motor){"Front motor", 13, 0};
  motors[1] = (Motor){"Left-back motor", 14, 0};
  motors[2] = (Motor){"Right-back motor", 15, 0};


  sensors[0] = (Sensor){"Front ultrasonic sensor", 5, 0};
  sensors[1] = (Sensor){"Back ultrasonic sensor", 6, 0};
  sensors[2] = (Sensor){"Left ultrasonic sensor", 7, 0};
  sensors[3] = (Sensor){"Right ultrasonic sensor", 8, 0};
  sensors[4] = (Sensor){"IR sensor", 9, 0};
  
  setup_sensors();
  setup_motors();

}

void check_charge() {
  //return battery charge
}


void preflight() {
 //while check_charge() < 100
    //do nothing
}

void launch() {
  //all motors full power
    //while height < 10ft
      //do nothing
  //all motors halt
}

void wander() {
  //pick random direction
  //while checking sensor input:
    //burn motors for ~3 sec
    //coast for a bit
    //if check_charge() < 20 
      //break
}

void find_home() {
  //while 360 spin:
    //observe IR sensor
  //set direction to IR sensor
  //go to it
}

void land() {
  //motors reverse 

}

void loop() {
  preflight();
  launch();
  wander();
  find_home();
  land();
}

