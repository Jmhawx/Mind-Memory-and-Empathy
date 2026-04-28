#include <Adafruit_NeoPixel.h>

//neopixel strips (5 count)
int neoAmt1 = 20;
int neoPin1 = 7;
Adafruit_NeoPixel strip1(neoAmt1, neoPin1);

int neoAmt2 = 8;
int neoPin2 = 6;
Adafruit_NeoPixel strip2(neoAmt2, neoPin2);

int neoAmt3 = 8;
int neoPin3 = 5;
Adafruit_NeoPixel strip3(neoAmt3, neoPin3);

int neoAmt4 = 8;
int neoPin4 = 4;
Adafruit_NeoPixel strip4(neoAmt4, neoPin4);

int neoAmt5 = 8;
int neoPin5 = 3;
Adafruit_NeoPixel strip5(neoAmt5, neoPin5);

//buttons and states (5)
const int buttonPin1 = 12;
const int buttonPin2 = 11;
const int buttonPin3 = 10;
const int buttonPin4 = 9;
const int buttonPin5 = 8;

boolean button1State = false;
boolean prevButton1State = false;

boolean button2State = false;
boolean prevButton2State = false;

boolean button3State = false;
boolean prevButton3State = false;

boolean button4State = false;
boolean prevButton4State = false;

boolean button5State = false;
boolean prevButton5State = false;

uint32_t red1 = strip1.Color(0, 255, 0);   //GRB
uint32_t orange2 = strip2.Color(85, 255, 0);
uint32_t yellow3 = strip3.Color(215, 255, 0);
uint32_t green4 = strip4.Color(255, 0, 0);
uint32_t blue5 = strip5.Color(0, 255, 20);


void setup()
{

pinMode(buttonPin1, INPUT_PULLUP);
pinMode(buttonPin2, INPUT_PULLUP);
pinMode(buttonPin3, INPUT_PULLUP);
pinMode(buttonPin4, INPUT_PULLUP);
pinMode(buttonPin5, INPUT_PULLUP);

  Serial.begin(9600);
  strip1.begin();  
  strip2.begin();  
  strip3.begin();  
  strip4.begin();  
  strip5.begin();

  strip1.setBrightness(100);
  strip1.clear();
  strip1.show();
  
  strip2.setBrightness(100);
  strip2.clear();
  strip2.show();
  
  strip3.setBrightness(100);
  strip3.clear();
  strip3.show();
  
  strip4.setBrightness(100);
  strip4.clear();
  strip4.show();
  
  strip5.setBrightness(100);
  strip5.clear();
  strip5.show();
}

void loop()
{
  handleButtons();
}


void handleButtons(){
  prevButton1State = button1State;
  button1State = digitalRead(buttonPin1);
 	 if(button1State == LOW && prevButton1State == HIGH) {
    smoothTravel(red1, 100, 1);
      
   }
  
  prevButton2State = button2State;
  button2State = digitalRead(buttonPin2);
    if(button2State == LOW && prevButton2State == HIGH) {
      smoothTravel(orange2, 25, 2);
    }

  
  prevButton3State = button3State;
  button3State = digitalRead(buttonPin3);
    if(button3State == LOW && prevButton3State == HIGH) {
    	smoothTravel(yellow3, 25, 3);
    }

  
  prevButton4State = button4State;
  button4State = digitalRead(buttonPin4);
    if(button4State == true && prevButton4State == false) {
      smoothTravel(green4, 25, 4);
    }
  
  prevButton5State = button5State;
  button5State = digitalRead(buttonPin5);
    if(button5State == true && prevButton5State == false) {
      smoothTravel(blue5, 25, 5);
    }

  
  delay(15);
}

void smoothTravel(uint32_t color, int delayTime, int stripNum) {
  const int trailLength = 8;

  Adafruit_NeoPixel* strip;

  // Pick correct strip
  if (stripNum == 1) strip = &strip1;
  else if (stripNum == 2) strip = &strip2;
  else if (stripNum == 3) strip = &strip3;
  else if (stripNum == 4) strip = &strip4;
  else if (stripNum == 5) strip = &strip5;
  else return;

  int totalPixels = strip->numPixels();

  for (int head = 0; head < totalPixels + trailLength; head++) {

    strip->clear();

    for (int t = 0; t < trailLength; t++) {
      int pixelIndex = head - t;

      if (pixelIndex >= 0 && pixelIndex < totalPixels) {

        float fade = 1.0 - ((float)t / trailLength);

        // Extract RGB from color
        uint8_t r = (color >> 16) & 0xFF;
        uint8_t g = (color >> 8) & 0xFF;
        uint8_t b = color & 0xFF;

        // Apply fade
        r *= fade;
        g *= fade;
        b *= fade;

        strip->setPixelColor(pixelIndex, strip->Color(r, g, b));
      }
    }

    strip->show();
    delay(delayTime);
  }
}

//older animation
// void travelLight(uint32_t c, int delayTime, int stripNum) {

//    if(stripNum == 1) {
//     for(int i = 0; i <= strip1.numPixels(); i++) {
//       strip1.setPixelColor(i, c); 
//       strip1.show(); 
//       delay(delayTime); 
//     }
//      delay(3000); 
//      Serial.println("lol");
//      strip1.clear(); 
//      strip1.show(); 
//    }
  
//    if(stripNum == 2) {
//     for(int i = 0; i <= strip2.numPixels(); i++) {
//       strip2.setPixelColor(i, c); 
//       strip2.show(); 
//       delay(delayTime); 
//     }
//      delay(3000); 
//      Serial.println("lol");
//      strip2.clear(); 
//      strip2.show(); 
//    }
  
//      if(stripNum == 3) {
//     for(int i = 0; i <= strip3.numPixels(); i++) {
//       strip3.setPixelColor(i, c); 
//       strip3.show(); 
//       delay(delayTime); 
//     }
//      delay(3000); 
//      Serial.println("lol");
//      strip3.clear(); 
//      strip3.show(); 
//    }
  
//     if(stripNum == 4) {
//     for(int i = 0; i <= strip4.numPixels(); i++) {
//       strip4.setPixelColor(i, c); 
//       strip4.show(); 
//       delay(delayTime); 
//     }
//       delay(3000); 
//      Serial.println("lol");
//      strip4.clear(); 
//      strip4.show(); 
//    }
//     if(stripNum == 5) {
//     for(int i = 0; i <= strip5.numPixels(); i++) {
//       strip5.setPixelColor(i, c); 
//       strip5.show(); 
//       delay(delayTime); 
//     }
//       delay(3000); 
//      Serial.println("lol");
//      strip5.clear(); 
//      strip5.show(); 
//    }

// }
