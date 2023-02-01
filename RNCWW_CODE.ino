// C++ code
//
#include <Servo.h>

int sensor_1 = 0;

int sensor_2 = 0;

int modo = 0;

Servo servo_0;

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
  servo_0.attach(0, 500, 2500);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop()
{
  if (modo == 0) {
    servo_0.write(90);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    if (0.01723 * readUltrasonicDistance(12, 13) <= 25) {
      tone(1, 932, 250)
      delay(250);
      noTone(1);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(500);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
      servo_0.write(45);
      delay(1000); 
      sensor_1 = 0.01723 * readUltrasonicDistance(12, 13);
      servo_0.write(135);
      delay(1000);
      sensor_2 = 0.01723 * readUltrasonicDistance(12, 13);
      servo_0.write(90);
      if (sensor_1 >= sensor_2) {
        digitalWrite(8, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        delay(500);
      }
      if (sensor_2 > sensor_1) {
        digitalWrite(4, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(11, HIGH);
        delay(500);
      }
    }
  }
}