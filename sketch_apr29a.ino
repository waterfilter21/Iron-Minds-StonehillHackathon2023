#include <Servo.h>

const int triggerPin = 2;
const int echoPin = A0;
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
  long duration, inches, cm;
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop()
{
  int distance = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);
  Serial.println(distance);
  
  if (distance <= 3) {
    // Create a Servo object
    Servo myservo;
    // Attach the servo to pin 3
    myservo.attach(3);
    // Rotate the servo 90 degrees clockwise
    myservo.write(90);
    delay(500); // wait for the servo to reach the position
    // Detach the servo to save power
    myservo.detach();
  }

  delay(10); // Delay a little bit to improve simulation performance
}
