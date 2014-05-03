int ar = 0;
int ctrl = 5;
  
void setup() {
//  pinMode(5, INPUT);
//  pinMode(0, OUTPUT);
   Serial.begin(9600);
}

void loop() {
 analogWrite(ctrl, 175);
 delay(20);
 int sensorValue = analogRead(ar);
  delay(20);
 int sensorValue2 = analogRead(ar);

  int avg = (sensorValue + sensorValue2) / 2;
 //Serial.println(sensorValue, DEC);
 Serial.println(avg, DEC);

 delay(200);
}
