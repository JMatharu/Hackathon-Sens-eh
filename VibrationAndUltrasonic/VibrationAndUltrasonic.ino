// defines pins numbers
const int vibrationMotorSignalPin = 7;
const int ultraSonicTrigPin = 9;
const int ultraSonicEchoPin = 10;

// defines variables
long duration;
float distanceInFeets;

void setup() {
  pinMode(ultraSonicTrigPin, OUTPUT); // Sets the ultraSonicTrigPin as an Output
  pinMode(ultraSonicEchoPin, INPUT); // Sets the ultraSonicEchoPin as an Input
  pinMode(vibrationMotorSignalPin, OUTPUT); // Sets the vibrationMotorSignalPin as an Output
  Serial.begin(9600); // Starts the serial communication
}

void loop(){
  // Clears the ultraSonicTrigPin
  digitalWrite(ultraSonicTrigPin, LOW);
  delayMicroseconds(2);
  // Sets the ultraSonicTrigPin on HIGH state for 10 micro seconds
  digitalWrite(ultraSonicTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonicTrigPin, LOW);
  // Reads the ultraSonicEchoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ultraSonicEchoPin, HIGH);
  // Calculating the distance
  distanceInFeets = duration * 0.00112533/2;

  // Clears the VibrationMotorSignalPin
  digitalWrite(vibrationMotorSignalPin, LOW);

  if (distanceInFeets < 1.00) {
    digitalWrite(vibrationMotorSignalPin, HIGH);
    // Prints the distance on the Serial Monitor
    Serial.print("Distance Feet : ");
    Serial.println(distanceInFeets);
  }
}
