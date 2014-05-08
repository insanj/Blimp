#define MAX_POWER 255
#define MIN_POWER 0
#define WAIT_DELAY 3500
#define TOLERANCE 10
#define lol true

int ar = 1; // analog
int ctrl = 7; // analog

int fmotor1 = 2; // digital->analog
int bmotor1 = 3; // digital->analog
int fmotor2 = 4; // digital->analog
int bmotor2 = 5; // digital->analog
int fmotor3 = 6; // digital->analog
int bmotor3 = 7; // digital->analog

int range = 20;

// prepare serial for debug writing
void setup() {
  Serial.begin(9600);
}

// basic loop that pings the distance sensor, averages two measurements
// (as per data sheet), and checks the final result to see if the difference
// is within a certain tolerance range, then powers the motor accordingly
// for the WAIT_DELAY ms, then does it again.
void loop() {
  if (lol) {
    engage(lol);
  }
  
  else {
    Serial.println("getting measurement data");
    analogWrite(ctrl, MAX_POWER); 
    
    delay(20); // 16.5ms ± 3.7ms
    int sensorValue = analogRead(ar); // first measurement
    
    delay(20);
    int sensorValue2 = analogRead(ar); // second measurement
  
    int avg = (sensorValue + sensorValue2) / 2; // average measurement
    Serial.println(avg, DEC);
    
    int delayAmount = WAIT_DELAY;
    if (range > (avg + TOLERANCE) || range < (avg - TOLERANCE)) {
      range = avg;
    }
    
    // forwards
    if (avg < range) {
      Serial.println("moving forwards");
       engage(true);
    }
    
    // backwards
    else {
      Serial.println("moving backwards");
      engage(false);
    }
    
    delay(delayAmount);
  }
}

void engage (boolean forward) {
  int on_power = MAX_POWER, off_power = 0;
  if (!forward) {
    on_power = 0;
    off_power = MAX_POWER;
  }
  
  analogWrite(fmotor1, on_power);
  analogWrite(bmotor1, off_power);
  
  analogWrite(fmotor2, on_power);
  analogWrite(bmotor2, off_power);
  
  analogWrite(fmotor3, on_power);
  analogWrite(bmotor3, off_power);
}
