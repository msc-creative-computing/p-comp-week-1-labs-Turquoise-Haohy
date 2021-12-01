// C++ code

#include <Servo.h> 

#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>


// Declare the Servo pin 
int servo1Pin = 10; 
int servo2Pin = 11; 
int servo3Pin = 12; 
Servo Servo1,Servo2,Servo3; 

boolean rotateOnce = true;

//name the sd modula
TMRpcm shot;

//set up the ultro-sonic sensor
// set threshold distance to activate the caamera-simulators
int distanceThreshold = 0;
int cm = 0;
//int inches = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int i = 0;

void setup()
{
  Serial.begin(9600);
  Servo1.attach(servo1Pin);
  Servo2.attach(servo2Pin);
  Servo3.attach(servo3Pin);
  
  
//  pinMode(servo1Pin, OUTPUT);
//  pinMode(servo2Pin, OUTPUT);
//  pinMode(servo3Pin, OUTPUT);

//set the speaker pin
  shot.speakerPin = 5; 

  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  
}  



void loop()
{
  
  distanceThreshold = 80;
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 6);
  Serial.print(cm);
  Serial.println("cm, ");

  if (cm <= distanceThreshold  && cm > (distanceThreshold - 60)) {
      if(rotateOnce){
      servoRotate();
      delay(1000);
      rotateOnce = false;
      }
      return; 
  }

  if (cm <= distanceThreshold - 60 ) {
      tone(5, 200, 30);
      delay(2000);
      shot.play("1.wav");
      delay(2000);
  }
  delay(1000);
}


  
void servoRotate(){

//to make the three servos work simultaneously       

           Servo1.write(0); 
           delay(500); 
           // Make servo go to 90 degrees 
           Servo2.write(0); 
           delay(500); 
           // Make servo go to 180 degrees 
           Servo3.write(0); 
           delay(500);  
          
          for (i = 0; i < 180; i++) { 
          Servo1.write(i);              
          Servo2.write(i);     
          Servo3.write(i);     
          delay(10);                      
          } 
          for (i = 180; i > 0; i--) { 
          Servo1.write(i);              
          Servo2.write(i);     
          Servo3.write(i);     
          delay(10);                      
         }
         
         Servo1.write(20);
         delay(1000);
         Servo3.write(7 0);
         delay(2000); 
         
         

  
}

void servopulse(int angle){
  for (i = 0; i <50;i++){
    int pulsewidth = (angle * 11) ;
    digitalWrite(servo1Pin,HIGH);
    digitalWrite(servo2Pin,HIGH);
    digitalWrite(servo3Pin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servo1Pin,LOW);
    digitalWrite(servo2Pin,LOW);
    digitalWrite(servo3Pin,LOW);
    delayMicroseconds(20000 - pulsewidth);
    }
  
  }
