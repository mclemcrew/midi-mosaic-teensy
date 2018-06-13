#include <i2c_t3.h>
#include <Bounce.h>  // Bounce library makes button change detection easy
#include "Adafruit_MPR121.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LED_SIGNAL 23

// 7 is the number of pixels on the strip
Adafruit_NeoPixel led_strip = Adafruit_NeoPixel(7, LED_SIGNAL, NEO_GRB + NEO_KHZ800);

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

int EN_MAIN = 2;
int EN  = 24;

int S0_MAIN = 8;
int S1_MAIN = 7;
int S2_MAIN = 6;
int S3_MAIN = 5;

int S0 = 12;
int S1 = 11;
int S2 = 10;
int S3 = 9;

void setup() {

 pinMode (EN_MAIN, OUTPUT);
 pinMode (EN, OUTPUT);

 pinMode (S0_MAIN, OUTPUT);
 pinMode (S1_MAIN, OUTPUT);
 pinMode (S2_MAIN, OUTPUT);
 pinMode (S3_MAIN, OUTPUT);

 pinMode (S0, OUTPUT);
 pinMode (S1, OUTPUT);
 pinMode (S2, OUTPUT);
 pinMode (S3, OUTPUT);
 
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

  Serial.println("All MPR121S have been found and you're good to go!");
}

void loop() {
  // Get the currently touched pads
  // usbMIDI.read(); // read the USB MIDI bus every loop
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

    /* Used for detecting and handling touch events that occur on the first MPR121 Module */
    if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(0, 99, channel);  // 60 = C4
        setBlockColor(1,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(1, 99, channel);  
        setBlockColor(2,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(2, 99, channel);  
        setBlockColor(3,led_strip.Color(150,0,20));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(3, 99, channel);  
        setBlockColor(4,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(4, 99, channel);
        setBlockColor(5,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(5, 99, channel);  
        setBlockColor(6,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(6, 99, channel);  
        setBlockColor(7,led_strip.Color(0,0,250));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(7, 99, channel);  
        setBlockColor(8,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(8, 99, channel);  
        setBlockColor(9,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(9, 99, channel);  
        setBlockColor(10,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(10, 99, channel);  
        setBlockColor(11,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(11, 99, channel);  
        setBlockColor(12,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(0, 99, channel);  // 60 = C4
        setBlockColor(1,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(1, 99, channel);  
        setBlockColor(2,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(2, 99, channel);  
        setBlockColor(3,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(3, 99, channel);  
        setBlockColor(4,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(4, 99, channel);
        setBlockColor(5,led_strip.Color(0,0,0));
      }
      if(i==6) {
        usbMIDI.sendNoteOff(5, 99, channel);  
        setBlockColor(6,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(6, 99, channel);  
        setBlockColor(7,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(7, 99, channel);  
        setBlockColor(8,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(8, 99, channel);  
        setBlockColor(9,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(9, 99, channel);  
        setBlockColor(10,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(10, 99, channel);  
        setBlockColor(11,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(11, 99, channel);  
        setBlockColor(12,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    /*********************************************************/
    if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(12, 99, channel);  // 60 = C4
        setBlockColor(13,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(13, 99, channel);  
        setBlockColor(14,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(14, 99, channel);  
        setBlockColor(15,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(15, 99, channel);  
        setBlockColor(16,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(16, 99, channel);
        setBlockColor(17,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(17, 99, channel);  
        setBlockColor(18,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(18, 99, channel);  
        setBlockColor(19,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(19, 99, channel);  
        setBlockColor(20,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(20, 99, channel);  
        setBlockColor(21,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(21, 99, channel);  
        setBlockColor(22,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(22, 99, channel);  
        setBlockColor(23,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(23, 99, channel);  
        setBlockColor(24,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(12, 99, channel);  // 60 = C4
        setBlockColor(13,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(13, 99, channel);  
        setBlockColor(14,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(14, 99, channel);  
        setBlockColor(15,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(15, 99, channel);  
        setBlockColor(16,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(16, 99, channel);
        setBlockColor(17,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(17, 99, channel);  
        setBlockColor(18,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(18, 99, channel);  
        setBlockColor(19,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(19, 99, channel);  
        setBlockColor(20,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(20, 99, channel);  
        setBlockColor(21,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(21, 99, channel);  
        setBlockColor(22,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(22, 99, channel);  
        setBlockColor(23,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(23, 99, channel);  
        setBlockColor(24,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched3 & _BV(i)) && !(lasttouched3 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(24, 99, channel);  // 60 = C4
        setBlockColor(25,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(25, 99, channel);  
        setBlockColor(26,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(26, 99, channel);  
        setBlockColor(27,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(27, 99, channel);  
        setBlockColor(28,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(28, 99, channel);
        setBlockColor(29,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(29, 99, channel);  
        setBlockColor(30,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(30, 99, channel);  
        setBlockColor(31,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(31, 99, channel);  
        setBlockColor(32,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(32, 99, channel);  
        setBlockColor(33,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(33, 99, channel);  
        setBlockColor(34,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(34, 99, channel);  
        setBlockColor(35,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(35, 99, channel);  
        setBlockColor(36,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched3 & _BV(i)) && (lasttouched3 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(24, 99, channel);  // 60 = C4
        setBlockColor(25,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(25, 99, channel);  
        setBlockColor(26,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(26, 99, channel);  
        setBlockColor(27,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(27, 99, channel);  
        setBlockColor(28,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(28, 99, channel);
        setBlockColor(29,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(29, 99, channel);  
        setBlockColor(30,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(30, 99, channel);  
        setBlockColor(31,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(31, 99, channel);  
        setBlockColor(32,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(32, 99, channel);  
        setBlockColor(33,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(33, 99, channel);  
        setBlockColor(34,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(34, 99, channel);  
        setBlockColor(35,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(35, 99, channel);  
        setBlockColor(36,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched4 & _BV(i)) && !(lasttouched4 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(36, 99, channel);  // 60 = C4
        setBlockColor(37,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(37, 99, channel);  
        setBlockColor(38,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(38, 99, channel);  
        setBlockColor(39,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(39, 99, channel);  
        setBlockColor(40,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(40, 99, channel);
        setBlockColor(41,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(41, 99, channel);  
        setBlockColor(42,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(42, 99, channel);  
        setBlockColor(43,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(43, 99, channel);  
        setBlockColor(44,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(44, 99, channel);  
        setBlockColor(45,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(45, 99, channel);  
        setBlockColor(46,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(46, 99, channel);  
        setBlockColor(47,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(47, 99, channel);  
        setBlockColor(48,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched4 & _BV(i)) && (lasttouched4 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(36, 99, channel);  // 60 = C4
        setBlockColor(37,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(37, 99, channel);  
        setBlockColor(38,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(38, 99, channel);  
        setBlockColor(39,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(39, 99, channel);  
        setBlockColor(40,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(40, 99, channel);
        setBlockColor(41,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(41, 99, channel);  
        setBlockColor(42,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(42, 99, channel);  
        setBlockColor(43,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(43, 99, channel);  
        setBlockColor(44,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(44, 99, channel);  
        setBlockColor(45,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(45, 99, channel);  
        setBlockColor(46,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(46, 99, channel);  
        setBlockColor(47,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(47, 99, channel);  
        setBlockColor(48,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched5 & _BV(i)) && !(lasttouched5 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched5 & _BV(i)) && (lasttouched5 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched6 & _BV(i)) && !(lasttouched6 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched6 & _BV(i)) && (lasttouched6 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched7 & _BV(i)) && !(lasttouched7 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched7 & _BV(i)) && (lasttouched7 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched8 & _BV(i)) && !(lasttouched8 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched8 & _BV(i)) && (lasttouched8 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched9 & _BV(i)) && !(lasttouched9 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched9 & _BV(i)) && (lasttouched9 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched10 & _BV(i)) && !(lasttouched10 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched10 & _BV(i)) && (lasttouched10 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched11 & _BV(i)) && !(lasttouched11 & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched11 & _BV(i)) && (lasttouched11 & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
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
  // debugging info
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
  delay(5);
}

// this function is called whenever a MIDI note on is received
// the function is executed using the received message bytes of channel, pitch and velocity corresponding to the variable names below
// for example, a middle C with full velocity on the first channel will be called with OnNoteOn(1, 60, 127);
// messages can be filtered by channel and pitch

void OnNoteOn(byte channel, byte pitch, byte velocity) {
  // Serial.print("Testing \n");
  // setColor4(strip4.Color(255, 0, 0));
  // setColor3(led_strip.Color(255, 0, 0));
}


// this function is called whenever a MIDI note off is received
// the function is executed using the received message bytes of channel, pitch and velocity corresponding to the variable names below
// for example, a middle C note off on the first channel will be called with OnNoteOn(1, 60, 0);
// messages can be filtered by channel and pitch

void OnNoteOff(byte channel, byte pitch, byte velocity) {
  // Serial.print("Testing Again\n");
  // setColor4(strip4.Color(0, 0, 0));
  // setColor3(led_strip.Color(0, 0, 0));
}
// void out0_MAIN() {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, LOW);
//  digitalWrite (S1, LOW);
//  digitalWrite (S2, LOW);
//  digitalWrite (S3, LOW);
// }
// void out1_MAIN()
// {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, HIGH);
//  digitalWrite (S1, LOW);
//  digitalWrite (S2, LOW);
//  digitalWrite (S3, LOW);
// }
// void out2_MAIN()
// {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, LOW);
//  digitalWrite (S1, HIGH);
//  digitalWrite (S2, LOW);
//  digitalWrite (S3, LOW);
// }
// void out3_MAIN()
// {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, HIGH);
//  digitalWrite (S1, HIGH);
//  digitalWrite (S2, LOW);
//  digitalWrite (S3, LOW);
// }
// void out4_MAIN()
// {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, LOW);
//  digitalWrite (S1, LOW);
//  digitalWrite (S2, HIGH);
//  digitalWrite (S3, LOW);
// }
// void out5_MAIN()
// {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, HIGH);
//  digitalWrite (S1, LOW);
//  digitalWrite (S2, HIGH);
//  digitalWrite (S3, LOW);
// }
// void out6_MAIN()
// {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, LOW);
//  digitalWrite (S1, HIGH);
//  digitalWrite (S2, HIGH);
//  digitalWrite (S3, LOW);
// }
// void out7_MAIN()
// {
//  digitalWrite (EN_MAIN, LOW);
//  digitalWrite (S0, HIGH);
//  digitalWrite (S1, HIGH);
//  digitalWrite (S2, HIGH);
//  digitalWrite (S3, LOW);
// }

void out0() {
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
// led_strip.show();
}
void out1()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
// led_strip.show();
}
void out2()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
// led_strip.show();
}
void out3()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
// led_strip.show();
}
void out4()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
}
void out5()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
}
void out6()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
}
void out7()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
}
void out8()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
}
void out9()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
}
void out10()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
}
void out11()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
}
void out12()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
}
void out13()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
}
void out14()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
}
void out15()
{
 digitalWrite (EN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
}

void out8_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0_MAIN, LOW);
 digitalWrite (S1_MAIN, LOW);
 digitalWrite (S2_MAIN, LOW);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
}
void out9_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
}
void out10_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
}
void out11_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
}
void out12_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
}
void out13_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
}
void out14_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
}
void out15_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0_MAIN, HIGH);
 digitalWrite (S1_MAIN, HIGH);
 digitalWrite (S2_MAIN, HIGH);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
}

void setUpLEDStrips() {
  led_strip.begin();
  led_strip.show();
}

void setBlockColor(uint8_t number, uint32_t color) {
  switch (number) {
    case 1:
      out8_MAIN();
      out0();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 2:
      out8_MAIN();
      out1();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 3:
      out8_MAIN();
      out2();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 4:
      out8_MAIN();
      out3();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 5:
      out8_MAIN();
      out4();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 6:
      out8_MAIN();
      out5();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 7:
      out8_MAIN();
      out6();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 8:
      out8_MAIN();
      out7();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      led_strip.show();
      break;
    case 9:
      out8_MAIN();
      out8();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 10:
      out8_MAIN();
      out9();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 11:
      out8_MAIN();
      out10();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 12:
      out8_MAIN();
      out11();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 13:
      out8_MAIN();
      out12();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 14:
      out8_MAIN();
      out13();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 15:
      out8_MAIN();
      out14();
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 16:
      out8_MAIN();
      out15();
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 17:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 18:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 19:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 20:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 21:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 22:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 23:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 24:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 25:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 26:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 27:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 28:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 29:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 30:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 31:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 32:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 33:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 34:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 35:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 36:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 37:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 38:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 39:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 40:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 41:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 42:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 43:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 44:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 45:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 46:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 47:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 48:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 49:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 50:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 51:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 52:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 53:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 54:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 55:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 56:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 57:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 58:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 59:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 60:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 61:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 62:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 63:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 64:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 65:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 66:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 67:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 68:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 69:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 70:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 71:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 72:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 73:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 74:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 75:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 76:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 77:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 78:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 79:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 80:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 81:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 82:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 83:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 84:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 85:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 86:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 87:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 88:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 89:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 90:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 91:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 92:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 93:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 94:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 95:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 96:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 97:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 98:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 99:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 100:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 101:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 102:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 103:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 104:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 105:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 106:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 107:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 108:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 109:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 110:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 111:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 112:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 113:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 114:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 115:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 116:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 117:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 118:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 119:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 120:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
    case 121:
      for(int i=0;i<7;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 122:
      for(int i=7;i<14;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 123:
      for(int i=14;i<21;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 124:
      for(int i=21;i<28;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 125:
      for(int i=28;i<35;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 126:
      for(int i=35;i<42;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 127:
      for(int i=42;i<49;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    case 128:
      for(int i=49;i<56;i++) {
        led_strip.setPixelColor(i, color);
      }
      break;
    default:
      break;
      // statements
  }
}
