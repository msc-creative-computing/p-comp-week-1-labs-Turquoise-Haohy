#include <Adafruit_NeoPixel.h>
#define LED_PIN   6
#define LED_COUNT 5
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int switchPin = 9;
int switchValue;

int switch2Pin= 10;
int switch2Value;

int switch3Pin= 12;
int switch3Value;


void setup() {

  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(switch2Pin, INPUT);
  pinMode(switch3Pin, INPUT);
  digitalWrite(switchPin, HIGH);
  digitalWrite(switch2Pin, HIGH);
  digitalWrite(switch3Pin, HIGH);

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(100); //

}

void loop() {
  
switchValue = digitalRead(switchPin);
switch2Value = digitalRead(switch2Pin);
switch3Value = digitalRead(switch3Pin);

if (switchValue == LOW && switch2Value == HIGH && switch3Value == HIGH ){
  rainbow(2); 
  colorWipe(strip.Color(  0,   0, 0), 50);
} else if (switch2Value == LOW && switchValue == HIGH && switch3Value == HIGH){
  theaterChase(strip.Color(127, 127, 127), 30); // White, half brightness
  theaterChase(strip.Color(127,   0,   0), 30); // Red, half brightness
  theaterChase(strip.Color(  0,   0, 127), 30); // Blue, half brightness
  colorWipe(strip.Color(  0,   0, 0), 50);
  } else if (switch3Value == LOW && switchValue == HIGH && switch2Value == HIGH){

  colorWipe(strip.Color(255,   0,   0), 50); // Red
  colorWipe(strip.Color(  0, 255,   0), 50); // Green
  colorWipe(strip.Color(  0,   0, 255), 50); // Blue
  
  colorWipe(strip.Color(  0,   0, 0), 50);
  } else {
    digitalWrite(6, LOW);
  }

}


void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}
