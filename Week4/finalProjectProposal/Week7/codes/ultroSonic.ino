// C++ code
//

// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 9; 
Servo Servo1; 

int distanceThreshold = 0;

int cm = 0;

int inches = 0;

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
  Servo1.attach(servoPin); 

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  // set threshold distance to activate LEDs
  distanceThreshold = 50;
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 6);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  if (cm > distanceThreshold) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
//  if (cm <= distanceThreshold && cm > distanceThreshold - 10) {
//    digitalWrite(2, HIGH);
//    digitalWrite(3, LOW);
//    digitalWrite(4, LOW);
//
//  }
//  if (cm <= distanceThreshold - 10 && cm > distanceThreshold - 20) {
//    digitalWrite(2, HIGH);
//    digitalWrite(3, HIGH);
//    digitalWrite(4, LOW);
//  }
//  if (cm <= distanceThreshold - 20 && cm > distanceThreshold - 30) {
//    digitalWrite(2, HIGH);
//    digitalWrite(3, HIGH);
//    digitalWrite(4, HIGH);
//  }
 if (cm <= distanceThreshold - 40) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    servoRotate();
  }
  delay(100); // Wait for 100 millisecond(s)
  while(1);
}

void servoRotate(){
    Servo1.write(0); 
   delay(500); 
   // Make servo go to 90 degrees 
   Servo1.write(180); 
   delay(500); 
   // Make servo go to 180 degrees 
   Servo1.write(90); 
   delay(1000);   
  }
