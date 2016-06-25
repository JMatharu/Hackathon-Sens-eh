// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
float distanceInch, distanceFoot;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  // distanceInch = duration*0.0133/2;
  distanceFoot = duration * 0.00112533/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance Feet : ");
  Serial.println(distanceFoot);
}
