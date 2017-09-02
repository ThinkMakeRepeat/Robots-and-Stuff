int motor1 = 9;
int motor2 = 10;

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(motor1, 100);   // turn the LED on (HIGH is the voltage level)
  analogWrite(motor2, 100);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  
  analogWrite(motor1, 100);    // turn the LED off by making the voltage LOW
  analogWrite(motor2, 100);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
}
