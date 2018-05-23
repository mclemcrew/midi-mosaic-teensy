#include <i2c_t3.h>
#include <Bounce.h>  // Bounce library makes button change detection easy
#include "Adafruit_MPR121.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 11
#define PIN2 12
#define PIN3 24
#define PIN4 25
#define PIN5 9
#define PIN6 10
#define PIN7 36 
#define PIN8 35  

// 7 is the number of pixels on the strip
// Have to change this for 16 columns rather than rows
Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(7, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(7, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(7, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(7, PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(7, PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(7, PIN7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(7, PIN8, NEO_GRB + NEO_KHZ800);

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap1 = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();
Adafruit_MPR121 cap3 = Adafruit_MPR121();
Adafruit_MPR121 cap4 = Adafruit_MPR121();
Adafruit_MPR121 cap5 = Adafruit_MPR121();
Adafruit_MPR121 cap6 = Adafruit_MPR121();
Adafruit_MPR121 cap7 = Adafruit_MPR121();
Adafruit_MPR121 cap8 = Adafruit_MPR121();
Adafruit_MPR121 cap9 = Adafruit_MPR121();
Adafruit_MPR121 cap10 = Adafruit_MPR121();
Adafruit_MPR121 cap11 = Adafruit_MPR121();


// Declare Midi channel
const int channel = 1;

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched1 = 0;
uint16_t currtouched1 = 0;
uint16_t lasttouched2 = 0;
uint16_t currtouched2 = 0;
uint16_t lasttouched3 = 0;
uint16_t currtouched3 = 0;
uint16_t lasttouched4 = 0;
uint16_t currtouched4 = 0;
uint16_t lasttouched5 = 0;
uint16_t currtouched5 = 0;
uint16_t lasttouched6 = 0;
uint16_t currtouched6 = 0;
uint16_t lasttouched7 = 0;
uint16_t currtouched7 = 0;
uint16_t lasttouched8 = 0;
uint16_t currtouched8 = 0;
uint16_t lasttouched9 = 0;
uint16_t currtouched9 = 0;
uint16_t lasttouched10 = 0;
uint16_t currtouched10 = 0;
uint16_t lasttouched11 = 0;
uint16_t currtouched11 = 0;

void setup() {
  usbMIDI.setHandleNoteOn(OnNoteOn); // set handle for Note On message as function named "OnNoteOn"
  usbMIDI.setHandleNoteOff(OnNoteOff); // set handle for Note Off message as function named "OnNoteOff"
  Serial.begin(9600);
  setUpLEDStrips();

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 cap1acitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap1.begin(0x5A,1)) {
    Serial.println("MPR121 1 not found, check wiring?");
    while(1);
  }
  
  if (!cap2.begin(0x5B,1)) {
    Serial.println("MPR121 2 not found, check wiring?");
    while(1);
  }

  if (!cap3.begin(0x5C,1)) {
    Serial.println("MPR121 3 not found, check wiring?");
    while(1);
  }

  if (!cap4.begin(0x5D,1)) {
    Serial.println("MPR121 4 not found, check wiring?");
    while(1);
  }

  if (!cap5.begin(0x5A,2)) {
    Serial.println("MPR121 1 not found, check wiring?");
    while(1);
  }
  
  if (!cap6.begin(0x5B,2)) {
    Serial.println("MPR121 2 not found, check wiring?");
    while(1);
  }

  if (!cap7.begin(0x5C,2)) {
    Serial.println("MPR121 3 not found, check wiring?");
    while(1);
  }

  if (!cap8.begin(0x5D,2)) {
    Serial.println("MPR121 4 not found, check wiring?");
    while(1);
  }

  if (!cap9.begin(0x5A,3)) {
    Serial.println("MPR121 1 not found, check wiring?");
    while(1);
  }
  
  if (!cap10.begin(0x5B,3)) {
    Serial.println("MPR121 2 not found, check wiring?");
    while(1);
  }

  if (!cap11.begin(0x5C,3)) {
    Serial.println("MPR121 3 not found, check wiring?");
    while(1);
  }

  
  
  Serial.println("MPR121s have been found!");
}

void loop() {
  // Get the currently touched pads
  usbMIDI.read(); // read the USB MIDI bus every loop
  currtouched1 = cap1.touched();
  currtouched2 = cap2.touched();
  currtouched3 = cap3.touched();
  currtouched4 = cap4.touched();
  currtouched5 = cap5.touched();
  currtouched6 = cap6.touched();
  currtouched7 = cap7.touched();
  currtouched8 = cap8.touched();
  currtouched9 = cap9.touched();
  currtouched10 = cap10.touched();
  currtouched11 = cap11.touched();

  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
//      if(i==0) {
//        usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C4
//        setColor(strip.Color(255, 0, 0));
//      }
//      if(i==1) {
//        usbMIDI.sendNoteOn(61, 99, channel);  
//        setColor2(strip2.Color(255, 0, 0));
//      }
//      if(i==2) {
//        usbMIDI.sendNoteOn(62, 99, channel);  
//        setColor3(strip3.Color(255, 0, 0));
//      }
//      if(i==3) {
//        usbMIDI.sendNoteOn(63, 99, channel);  
//        setColor4(strip4.Color(255, 0, 0));
//      }
//      if(i==4) {
//        usbMIDI.sendNoteOn(64, 99, channel);  
//        setColor5(strip5.Color(255, 0, 0));
//      }
//      if(i==5) {
//        usbMIDI.sendNoteOn(65, 99, channel);  
//        setColor6(strip6.Color(255, 0, 0));
//      }
//      if(i==6) {
//        usbMIDI.sendNoteOn(66, 99, channel);  
//        setColor(strip.Color(255, 0, 0));
//      }
//      if(i==7) {
//        usbMIDI.sendNoteOn(63, 99, channel);  
//        setColor4(strip4.Color(255, 0, 0));
//      }
//      if(i==8) {
//        usbMIDI.sendNoteOn(64, 99, channel);  
//        setColor5(strip5.Color(255, 0, 0));
//      }
//      if(i==9) {
//        usbMIDI.sendNoteOn(65, 99, channel);  
//        setColor6(strip6.Color(255, 0, 0));
//      }
//      if(i==10) {
//        usbMIDI.sendNoteOn(66, 99, channel);  
//        setColor(strip.Color(255, 0, 0));
//      }
//      if(i==11) {
//        usbMIDI.sendNoteOn(70, 99, channel);  
//        setColor(strip.Color(0, 0, 255));
//      }
      setColor2(strip2.Color(0, 255, 0));
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
//      if(i==0) {
//        usbMIDI.sendNoteOff(60, 99, channel);  // 60 = C4
//        setColor(strip.Color(0, 0, 0));
//      }
//      if(i==1) {
//        usbMIDI.sendNoteOff(61, 99, channel);  // 60 = C4
//        setColor2(strip2.Color(0, 0, 0));
//      }
//      if(i==2) {
//        usbMIDI.sendNoteOff(62, 99, channel);  // 60 = C4
//        setColor3(strip3.Color(0, 0, 0));
//      }
//      if(i==3) {
//        usbMIDI.sendNoteOff(63, 99, channel);  // 60 = C4
//        setColor4(strip4.Color(0, 0, 0));
//      }
//      if(i==4) {
//        usbMIDI.sendNoteOff(64, 99, channel);  // 60 = C4
//        setColor5(strip5.Color(0, 0, 0));
//      }
//      if(i==5) {
//        usbMIDI.sendNoteOff(65, 99, channel);  // 60 = C4
//        setColor6(strip6.Color(0, 0, 0));
//      }
//      if(i==6) {
//        usbMIDI.sendNoteOff(66, 99, channel);  // 60 = C4
//        setColor(strip.Color(0, 0, 0));
//      }
//      if(i==7) {
//        usbMIDI.sendNoteOn(63, 99, channel);  
//        setColor4(strip4.Color(255, 0, 0));
//      }
//      if(i==8) {
//        usbMIDI.sendNoteOn(64, 99, channel);  
//        setColor5(strip5.Color(255, 0, 0));
//      }
//      if(i==9) {
//        usbMIDI.sendNoteOn(65, 99, channel);  
//        setColor6(strip6.Color(255, 0, 0));
//      }
//      if(i==10) {
//        usbMIDI.sendNoteOn(66, 99, channel);  
//        setColor(strip.Color(255, 0, 0));
//      }
//      if(i==11) {
//        usbMIDI.sendNoteOn(70, 99, channel);  
//        setColor(strip.Color(0, 0, 255));
//      }
      setColor2(strip2.Color(0, 0, 0));
      Serial.print(i); Serial.println(" released");
    }
    /*********************************************************/
    if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColorOn(strip.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColorOff(strip.Color(0, 0, 0));
    }
    if ((currtouched4 & _BV(i)) && !(lasttouched4 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor4(strip4.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched4 & _BV(i)) && (lasttouched4 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor4(strip4.Color(0, 0, 0));
    }
    if ((currtouched3 & _BV(i)) && !(lasttouched3 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor3(strip3.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched3 & _BV(i)) && (lasttouched3 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor3(strip3.Color(0, 0, 0));
    }
    if ((currtouched5 & _BV(i)) && !(lasttouched5 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor5(strip5.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched5 & _BV(i)) && (lasttouched5 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor5(strip5.Color(0, 0, 0));
    }
    if ((currtouched6 & _BV(i)) && !(lasttouched6 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor6(strip6.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched6 & _BV(i)) && (lasttouched6 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor6(strip6.Color(0, 0, 0));
    }
    if ((currtouched7 & _BV(i)) && !(lasttouched7 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor7(strip7.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched7 & _BV(i)) && (lasttouched7 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor7(strip7.Color(0, 0, 0));
    }
    if ((currtouched8 & _BV(i)) && !(lasttouched8 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor8(strip8.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched8 & _BV(i)) && (lasttouched8 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor8(strip8.Color(0, 0, 0));
    }
    if ((currtouched9 & _BV(i)) && !(lasttouched9 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColorOn(strip.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched9 & _BV(i)) && (lasttouched9 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColorOff( strip.Color(0, 255, 0));
    }
    if ((currtouched10 & _BV(i)) && !(lasttouched10 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor8(strip8.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched10 & _BV(i)) && (lasttouched10 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor8(strip8.Color(0, 0, 0));
    }
    if ((currtouched11 & _BV(i)) && !(lasttouched11 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      setColor8(strip8.Color(255, 0, 0));
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched11 & _BV(i)) && (lasttouched11 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      setColor8(strip8.Color(0, 0, 0));
    }
  }

  // reset our state
  lasttouched1 = currtouched1;
  lasttouched2 = currtouched2;
  lasttouched3 = currtouched3;
  lasttouched4 = currtouched4;
  lasttouched5 = currtouched5;
  lasttouched6 = currtouched6;
  lasttouched7 = currtouched7;
  lasttouched8 = currtouched8;
  lasttouched9 = currtouched9;
  lasttouched10 = currtouched10;
  lasttouched11 = currtouched11;

  // comment out this line for detailed data from the sensor!
  return;
  /*
  // debugging info, what
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap1.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap1.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap1.baselineData(i)); Serial.print("\t");
  }
  Serial.println();
  */
  // put a delay so it isn't overwhelming
  delay(10);
}

// this function is called whenever a MIDI note on is received
// the function is executed using the received message bytes of channel, pitch and velocity corresponding to the variable names below
// for example, a middle C with full velocity on the first channel will be called with OnNoteOn(1, 60, 127);
// messages can be filtered by channel and pitch

void OnNoteOn(byte channel, byte pitch, byte velocity) {
  Serial.print("Testing \n");
  setColor4(strip4.Color(255, 0, 0));
  setColor3(strip3.Color(255, 0, 0));
}


// this function is called whenever a MIDI note off is received
// the function is executed using the received message bytes of channel, pitch and velocity corresponding to the variable names below
// for example, a middle C note off on the first channel will be called with OnNoteOn(1, 60, 0);
// messages can be filtered by channel and pitch

void OnNoteOff(byte channel, byte pitch, byte velocity) {
  Serial.print("Testing Again\n");
  setColor4(strip4.Color(0, 0, 0));
  setColor3(strip3.Color(0, 0, 0));
}

void setUpLEDStrips() {
  strip.begin();
  strip.show();
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show();
  strip4.begin();
  strip4.show();
  strip5.begin();
  strip5.show();
  strip6.begin();
  strip6.show();
  strip7.begin();
  strip7.show();
  strip8.begin();
  strip8.show();
}

void setColorOn(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip.setPixelColor(i, c);
  }
  for(int i=7;i<14;i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
  }
  for(int i=14;i<21;i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255));
  }
  for(int i=21;i<28;i++) {
    strip.setPixelColor(i, strip.Color(200, 25, 130));
  }
  for(int i=28;i<56;i++) {
    strip.setPixelColor(i, strip.Color(200, 25, 12));
  }
  strip.show();
}

void setColorOff(uint32_t c) {
  for(int i=0;i<56;i++) {
    strip.setPixelColor(i,  strip.Color(0, 0, 0));
  }
  strip.show();
}

void setColor2(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip2.setPixelColor(i, c);
  }
  strip2.show();
}

void setColor3(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip3.setPixelColor(i, c);
  }
  strip3.show();
}

void setColor4(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip4.setPixelColor(i, c);
  }
  strip4.show();
}

void setColor5(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip5.setPixelColor(i, c);
  }
  strip5.show();
}

void setColor6(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip6.setPixelColor(i, c);
  }
  strip6.show();
}

void setColor7(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip7.setPixelColor(i, c);
  }
  strip7.show();
}

void setColor8(uint32_t c) {
  for(int i=0;i<7;i++) {
    strip8.setPixelColor(i, c);
  }
  strip8.show();
}
