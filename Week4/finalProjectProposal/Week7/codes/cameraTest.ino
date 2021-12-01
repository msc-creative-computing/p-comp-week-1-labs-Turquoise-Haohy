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

//name the sd modula
TMRpcm shot;

//set up the ultro-sonic sensor
// set threshold distance to activate the caamera-simulators
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

boolean rotateOnce = true;


void setup()
{
  Serial.begin(9600);
  Servo1.attach(servo1Pin);
  Servo2.attach(servo2Pin);
  Servo3.attach(servo3Pin);

//set the flash LED
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);

//set the speaker pin
  shot.speakerPin = 9; 

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
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  if (cm > distanceThreshold) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
        } 
      if (cm <= distanceThreshold  && cm > distanceThreshold - 60) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(5, HIGH);
        delay(50);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        //digitalWrite(4, LOW);
        Servo1.write(0); 
        delay(500); 
        Servo2.write(0); 
        delay(500); 
        Servo3.write(0); 
        delay(500); 
  }
      if (cm <= distanceThreshold - 60) {
        
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        //digitalWrite(4, HIGH);

        
//        if (rotateOnce){
//          rotateOnce = false;
//          servoRotate();
//          }
//             
        for(int j=0; j<10; j++){
        flash();
        }
        
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        //digitalWrite(4, HIGH);
        delay(1000);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        //digitalWrite(4, LOW);
        shot.play("1.wma");
        delay(2000);
    
  }
}

void flash(){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    //digitalWrite(4, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    //digitalWrite(4, LOW);
    delay(100);
  }
void servoRotate(){


  for (int i = 0; i < 180; i++) { 
    Servo1.write(i);              
    Servo2.write(i);     
    Servo3.write(i);
     
    delay(10);                      
    }
  for (int i = 90; i > 0; i--) { 
    Servo1.write(i);                
    Servo2.write(i);     
    Servo3.write(i);
   
    delay(10);                      
  }   
 }
