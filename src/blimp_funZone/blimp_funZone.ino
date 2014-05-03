int ar = 0; // analog
int ctrl = 5; // analog
int motor = 9; // analog

// prepare serial for debug writing
void setup() {
  Serial.begin(9600);
}

// self-looping function for powering the motors for delay amount
// works by checking direction, then fully powering the motor,
// waiting 5ms, then powering it again until delay amount is negligible
void motor_power(boolean dir, int delayAmount) {
  if (dir) {
    Serial.println("moving forwards");
    analogWrite(9, 255);
  }
  
  else {
    Serial.println("moving backwards");
    analogWrite(9, -255);
  }
  
  delay(5);
  delayAmount -= 5;
  if (delayAmount > 5) {
    motor_power(dir, delayAmount);
  }
}

// basic loop that pings the distance sensor, averages two measurements
// (as per data sheet), and checks the final result to see if its within
// the forwards range (0-25) or backwards range (25-inf). then, powers
// the motor for 5 seconds in the specified direction, waits, and does
// it again.
void loop() {
  analogWrite(ctrl, 255); 
  
  delay(20); // 16.5ms ± 3.7ms
  int sensorValue = analogRead(ar); // first measurement
  
  delay(20);
  int sensorValue2 = analogRead(ar); // second measurement

  int avg = (sensorValue + sensorValue2) / 2; // average measurement
  Serial.println(avg, DEC);
  
  int delayAmount = 500;
  
  // forwards
  if (avg < 25) {
    motor_power(true, delayAmount);
  }
  
  // backwards
  else {
    motor_power(false, delayAmount);
  }  

  delay(delayAmount + 5);
}
