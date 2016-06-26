// defines pins numbers
const int vibrationMotorLeftSignalPin = 7;
const int vibrationMotorRightSignalPin = 6;
const int ultraSonicCenterTrigPin = 9;
const int ultraSonicCenterEchoPin = 10;
const int ultraSonicRightTrigPin = 11;
const int ultraSonicRightEchoPin = 12;
const int ultraSonicLeftTrigPin = 3;
const int ultraSonicLeftEchoPin = 4;

// defines variables
long durationForCenter, durationForRight, durationForLeft;
float distanceFromCenter, distanceFromRight, distanceFromLeft;

void setup() {
  pinMode(ultraSonicCenterTrigPin, OUTPUT); // Sets the ultraSonicCenterTrigPin as an Output
  pinMode(ultraSonicCenterEchoPin, INPUT); // Sets the ultraSonicCenterEchoPin as an Input
  pinMode(ultraSonicRightTrigPin, OUTPUT); // Sets the ultraSonicRightTrigPin as an Output
  pinMode(ultraSonicRightEchoPin, INPUT); // Sets the ultraSonicRightEchoPin as an Input
  pinMode(ultraSonicLeftTrigPin, OUTPUT); // Sets the ultraSonicLeftTrigPin as an Output
  pinMode(ultraSonicLeftEchoPin, INPUT); // Sets the ultraSonicLeftEchoPin as an Input
  pinMode(vibrationMotorLeftSignalPin, OUTPUT); // Sets the vibrationMotorLeftSignalPin as an Output
  pinMode(vibrationMotorRightSignalPin, OUTPUT); // Sets the vibrationMotorRightSignalPin as an Output
  Serial.begin(9600); // Starts the serial communication
}

void loop(){

  distanceFromCenter = getDistanceFromCenterUltrasonicSensor();
  distanceFromRight = getDistanceFromRightUltrasonicSensor();
  distanceFromLeft = getDistanceFromLeftUltrasonicSensor();

  //------- Clear Vibration Motor -------
  // Clears the vibrationMotorLeftSignalPin
  digitalWrite(vibrationMotorLeftSignalPin, LOW);

  // Clears the vibrationMotorRightSignalPin
  digitalWrite(vibrationMotorRightSignalPin, LOW);

  if (distanceFromCenter < 2.00) {
    digitalWrite(vibrationMotorRightSignalPin, HIGH);
    digitalWrite(vibrationMotorLeftSignalPin, HIGH);
    // Prints the distance on the Serial Monitor
    Serial.print("Distance Feet from Center : ");
    Serial.println(distanceFromCenter);
  } else if (distanceFromRight < 2.00) {
    digitalWrite(vibrationMotorRightSignalPin, HIGH);
    digitalWrite(vibrationMotorLeftSignalPin, LOW);
    // Prints the distance on the Serial Monitor
    Serial.print("Distance Feet from Right : ");
    Serial.println(distanceFromRight);
  } else if (distanceFromLeft < 2.00) {
    digitalWrite(vibrationMotorRightSignalPin, LOW);
    digitalWrite(vibrationMotorLeftSignalPin, HIGH);
    // Prints the distance on the Serial Monitor
    Serial.print("Distance Feet from LEFT : ");
    Serial.println(distanceFromLeft);
  }
}

float getDistanceFromCenterUltrasonicSensor(){
  // Clears the ultraSonicCenterTrigPin
  digitalWrite(ultraSonicCenterTrigPin, LOW);
  delayMicroseconds(2);
  // Sets the ultraSonicCenterTrigPin on HIGH state for 10 micro seconds
  digitalWrite(ultraSonicCenterTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonicCenterTrigPin, LOW);
  // Reads the ultraSonicCenterEchoPin, returns the sound wave travel time in microseconds
  durationForCenter = pulseIn(ultraSonicCenterEchoPin, HIGH);
  // Calculating the distance in feet
  return durationForCenter * 0.00112533/2;
}

float getDistanceFromRightUltrasonicSensor(){
  // Clears the ultraSonicRightTrigPin
  digitalWrite(ultraSonicRightTrigPin, LOW);
  delayMicroseconds(2);
  // Sets the ultraSonicRightTrigPin on HIGH state for 10 micro seconds
  digitalWrite(ultraSonicRightTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonicRightTrigPin, LOW);
  // Reads the ultraSonicRightEchoPin, returns the sound wave travel time in microseconds
  durationForRight = pulseIn(ultraSonicRightEchoPin, HIGH);
  // Calculating the distance in feet
  return durationForRight * 0.00112533/2;
}

float getDistanceFromLeftUltrasonicSensor(){
  // Clears the ultraSonicLeftTrigPin
  digitalWrite(ultraSonicLeftTrigPin, LOW);
  delayMicroseconds(2);
  // Sets the ultraSonicLeftTrigPin on HIGH state for 10 micro seconds
  digitalWrite(ultraSonicLeftTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonicLeftTrigPin, LOW);
  // Reads the ultraSonicLeftEchoPin, returns the sound wave travel time in microseconds
  durationForLeft = pulseIn(ultraSonicLeftEchoPin, HIGH);
  // Calculating the distance in feet
  return durationForLeft * 0.00112533/2;
}
