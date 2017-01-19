
// MOTOR DEFINITIONS -----------------------------------------------------------------------------

int leftMotor = 3; // right throttle motor pin
int rightMotor = 5; // right throttle motor pin

int maxSpeed = 255;
int turnSpeed = 64;
int minSpeed = 0;


// BUTTON STEERING DEFINITIONS -----------------------------------------------------------------------------

// MOVE FORWARD ----------
int forward = 2;
int forwardState = 0;

// RIGHT TURN ----------
int right = 4;
int rightState = 0;

// LEFT TURN ----------
int left = 7;
int leftState = 0;



  // FOR DEBUGGING -----------------------------------------------------------------------------

int led = 13;


void setup() {
  Serial.begin(9600);
  
// MOTOR PINMODES -----------------------------------------------------------------------------

  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  
  
// BUTTON PINMODES -----------------------------------------------------------------------------

  pinMode(forward, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);



  // FOR DEBUGGING -----------------------------------------------------------------------------
  pinMode(led, OUTPUT);

}

void loop() {

  int forwardState = digitalRead(forward);
  int rightState = digitalRead(right);
  int leftState = digitalRead(left);


  if (forwardState == LOW) {
    Serial.println("Drive Forward");
    analogWrite(leftMotor, maxSpeed);
    analogWrite(rightMotor, maxSpeed);

    digitalWrite(led, HIGH);
  }

  if (rightState == LOW) {
    Serial.println("Right Turn");
    analogWrite(leftMotor, turnSpeed);
    analogWrite(rightMotor, maxSpeed);

    digitalWrite(led, HIGH);
  }

  if (leftState == LOW) {
    Serial.println("Left Turn");
    analogWrite(leftMotor, maxSpeed);
    analogWrite(rightMotor, turnSpeed);

    digitalWrite(led, HIGH);
  }
  
  else {
    Serial.println("Stopped");
    analogWrite(leftMotor, minSpeed);
    analogWrite(rightMotor, minSpeed);

    digitalWrite(led, LOW);
  }
  delay(10);
}











