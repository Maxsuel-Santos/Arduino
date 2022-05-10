/*
  Semáfaro com leds e servo motor
*/

#include <Servo.h>

int brightness = 0;

Servo servo_3;

void setup()
{
  servo_3.attach(3);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  servo_3.write(90);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(35000); // Wait for 35000 millisecond(s)
  servo_3.write(0);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(5000); // Wait for 5000 millisecond(s)
  servo_3.write(0);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(20000); // Wait for 20000 millisecond(s)
}
