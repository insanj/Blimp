// Static and recognized pin-holders:
int led = 13;

// Setup functions for the first run, should boot the LEDs
// and sensors to prepare for the main loop.
void setup() {
  int sensors[] = {led};
  setupSensors(sensors);
}

// Setup the sensors given as parameters. Should be extendable
// in case we remove or add more later on.
void setupSensors(int pins[]) {
  for(int i = 0; i < sizeof(pins); i++) {
     pinMode(pins[i], OUTPUT);    
  }
}

// Main loop and lifetime functions.
void loop() {
  blinkLED();
  
  // Here we should check for battery life, and define "land" and
  // adjust axis methods. The x and y-axis methods should be combined,
  // whereas angle rotations on the z-axis should be independant.
}

// Blinks the recognized LED pin. Comments from example
// code sketch.
void blinkLED() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
