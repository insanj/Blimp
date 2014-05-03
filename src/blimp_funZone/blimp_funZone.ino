#define MAX_POWER 255
#define MIN_POWER 0
#define WAIT_DELAY 750

int ar = 1; // analog
int ctrl = 7; // analog
int fmotor = 2; // digital
int bmotor = 3; // digital

int lastavg;

// prepare serial for debug writing
void setup() {
  Serial.begin(9600);
//  pinMode(fmotor, OUTPUT);
  //pinMode(bmotor, OUTPUT);
}

// self-looping function for powering the motors for delay amount
// works by checking direction, then fully powering the motor,
// waiting 5ms, then powering it again until delay amount is negligible
void motor_power(boolean dir, int delayAmount) {
  if (dir) {
    Serial.println("moving forwards");
    analogWrite(fmotor, HIGH);
    analogWrite(bmotor, LOW);
  }
  
  else {
    Serial.println("moving backwards");
    analogWrite(fmotor, LOW);
    analogWrite(bmotor, HIGH);
  }
  
 /* int smallDelay = 5;
  delay(smallDelay);
  delayAmount -= smallDelay;
  
  if (delayAmount > smallDelay) {
    motor_power(dir, delayAmount);
  }*/
}

// basic loop that pings the distance sensor, averages two measurements
// (as per data sheet), and checks the final result to see if its within
// the forwards range (0-25) or backwards range (25-inf). then, powers
// the motor for 5 seconds in the specified direction, waits, and does
// it again.
void loop() {
  Serial.println("getting measurement data");
  analogWrite(ctrl, MAX_POWER); 
  
  delay(20); // 16.5ms ± 3.7ms
  int sensorValue = analogRead(ar); // first measurement
  
  delay(20);
  int sensorValue2 = analogRead(ar); // second measurement

  int avg = (sensorValue + sensorValue2) / 2; // average measurement
  Serial.println(avg, DEC);
  
  int delayAmount = WAIT_DELAY;
  
  // forwards
  if (lastavg - avg > 3) {
    Serial.println("moving forwards");
    analogWrite(fmotor, MAX_POWER);
    analogWrite(bmotor, MIN_POWER);
  }
  
  // backwards
  else {
    Serial.println("moving backwards");
    analogWrite(fmotor, MIN_POWER);
    analogWrite(bmotor, MAX_POWER);
  }  
  
  lastavg = avg;
  delay(delayAmount);
}
