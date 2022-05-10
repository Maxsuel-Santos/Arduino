// Circuito com 3 leds, 1 display 7 seg. e um RGB

int counter;

int counter2;

int counter3;

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  for (counter = 0; counter < 7; ++counter) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  for (counter2 = 0; counter2 < 7; ++counter2) {
    analogWrite(3, 255);
    analogWrite(5, 0);
    analogWrite(6, 0);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  for (counter3 = 0; counter3 < 7; ++counter3) {
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(1500); // Wait for 1500 millisecond(s)
  }
  analogWrite(3, 51);
  analogWrite(5, 255);
  analogWrite(6, 51);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 51);
  analogWrite(5, 51);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 0);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 51);
  analogWrite(5, 0);
  analogWrite(6, 51);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 51);
  analogWrite(6, 255);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 102);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 153);
  analogWrite(5, 51);
  analogWrite(6, 153);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 204);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(1250); // Wait for 1250 millisecond(s)
  analogWrite(3, 102);
  analogWrite(5, 51);
  analogWrite(6, 51);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 0);
  analogWrite(5, 51);
  analogWrite(6, 51);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 51);
  analogWrite(5, 204);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 153);
  analogWrite(5, 153);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 102);
  analogWrite(5, 102);
  analogWrite(6, 102);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 204);
  analogWrite(5, 204);
  analogWrite(6, 204);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 153);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 153);
  analogWrite(5, 153);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 0);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 51);
  analogWrite(5, 255);
  analogWrite(6, 51);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 51);
  analogWrite(5, 51);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 204);
  analogWrite(5, 51);
  analogWrite(6, 204);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 102);
  analogWrite(5, 102);
  analogWrite(6, 102);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 204);
  analogWrite(6, 102);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 51);
  analogWrite(5, 102);
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 255);
  analogWrite(5, 204);
  analogWrite(6, 204);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(3, 102);
  analogWrite(5, 51);
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
}
