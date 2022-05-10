/*
  sistema de segurança da MAX ONE
*/

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  Serial.println(0.01723 * readUltrasonicDistance(4, 5));
  if (0.01723 * readUltrasonicDistance(4, 5) < 200) {
    digitalWrite(9, HIGH);
    digitalWrite(11, LOW);
  } else {
    digitalWrite(9, LOW);
    digitalWrite(11, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
