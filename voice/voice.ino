#include <Adafruit_NeoPixel.h>
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 300 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels

void setup() {
  Serial.begin(115200);
  pixels.begin();
}

void loop() {
  String  str;
  String strs[3];
  int StringCount = 0;

  if (Serial.available() > 0) {    
  str=Serial.readString();
  str.trim();
    while (str.length() > 0)
  {
    int index = str.indexOf(',');
    if (index == -1) // No space found
    {
      strs[StringCount++] = str;
      break;
    }
    else
    {
      strs[StringCount++] = str.substring(0, index);
      str = str.substring(index+1);
    }
  }
          pixels.clear();
          for(int i=0; i<NUMPIXELS/20; i++) { // For each pixel...            
            pixels.setPixelColor(i, pixels.Color(strs[0].toInt(), strs[1].toInt(), strs[2].toInt()));
             // Pause before next pass through loop

          }
                      pixels.show();
          delay(DELAYVAL);

          }
  }
