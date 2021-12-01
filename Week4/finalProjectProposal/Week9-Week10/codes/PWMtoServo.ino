//resource: https://blog.csdn.net/wzxxtt62267018/article/details/79785690

void setup(){
pinMode(servopin,OUTPUT);

}

void loop(){
for(int i=0;i<50;i++) 
  {
       servopulse(angle);  
  }
}

void servopulse(int angle)
     {
 
         int pulsewidth=(angle*11)+500; 
 
         digitalWrite(servopin,HIGH);   
 
         delayMicroseconds(pulsewidth);  
 
         digitalWrite(servopin,LOW);     
 
         delayMicroseconds(20000-pulsewidth);   
 
     }    


