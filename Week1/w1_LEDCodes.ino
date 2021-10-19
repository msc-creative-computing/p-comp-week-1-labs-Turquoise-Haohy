// C++ code
//

void setup()
{
  pinMode(12, OUTPUT);
}

void loop()
{
  /*
  'DO' IN MORSE CODE
*/
  line();
  dot();
  dot();
  
  halt();
  
  line();
  line();
  line();
  
  halt();
  halt();
  
  
  /*
  'YOU' IN MORSE CODE
*/
  line();
  dot();
  line();
  line();
  
  halt();
  
  line();
  line();
  line();
  
  halt();
  
  dot();
  dot();
  line();
  
  halt();
  halt();
  
  /*
  'LOVE' IN MORSE CODE
*/
  dot();
  line();
  dot();
  dot();
  
  halt();
  
  line();
  line();
  line();
  
  halt();
  
  dot();
  dot();
  dot();
  line();
  
  halt();
  
  dot();
  
  halt();
  halt();
  
   /*
  'KIRBY' IN MORSE CODE
*/
  line();
  dot();
  line();
  
  halt();
  
  dot();
  dot();
  
  halt();
  
  dot();
  line();
  dot();
  
  halt();
  
  line();
  dot();
  dot();
  dot();
  
  halt();
  
  line();
  dot();
  line();
  line();
  
  halt();
  halt();
  
}

void dot()
{
  digitalWrite(12, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(500); // Wait for 500 millisecond(s)
}

void halt()
{
  delay(1000); 
}
  
void line()
{
  digitalWrite(12, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(12, LOW);
  delay(500); // Wait for 500 millisecond(s)
}
