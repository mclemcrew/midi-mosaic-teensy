#include <i2c_t3.h>
#include <Bounce.h>  // Bounce library makes button change detection easy
#include "Adafruit_MPR121.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LED_SIGNAL_1 5
#define LED_SIGNAL_2 6
#define LED_SIGNAL_3 7
#define LED_SIGNAL_4 8
#define LED_SIGNAL_5 9
#define LED_SIGNAL_6 10
#define LED_SIGNAL_7 11
#define LED_SIGNAL_8 12

String readString;

// 7 is the number of pixels on the strip
Adafruit_NeoPixel led_strip_1 = Adafruit_NeoPixel(7, LED_SIGNAL_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_2 = Adafruit_NeoPixel(7, LED_SIGNAL_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_3 = Adafruit_NeoPixel(7, LED_SIGNAL_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_4 = Adafruit_NeoPixel(7, LED_SIGNAL_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_5 = Adafruit_NeoPixel(7, LED_SIGNAL_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_6 = Adafruit_NeoPixel(7, LED_SIGNAL_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_7 = Adafruit_NeoPixel(7, LED_SIGNAL_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_8 = Adafruit_NeoPixel(7, LED_SIGNAL_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip = Adafruit_NeoPixel(7, LED_SIGNAL_1, NEO_GRB + NEO_KHZ800);

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

int EN_1  = 1;
int EN_2  = 24;
int EN_3  = 25;
int EN_4  = 26;
int EN_5  = 27;
int EN_6  = 28;
int EN_7  = 29;
int EN_8  = 30;

int S0 = 20;
int S1 = 21;
int S2 = 22;
int S3 = 23;
int EN_MAIN = 2;

int S0_MAIN = 8;
int S1_MAIN = 7;
int S2_MAIN = 6;
int S3_MAIN = 5;

void setup() {

 pinMode (EN_MAIN, OUTPUT);
 pinMode (EN_1, OUTPUT);
 pinMode (EN_2, OUTPUT);
 pinMode (EN_3, OUTPUT);
 pinMode (EN_4, OUTPUT);
 pinMode (EN_5, OUTPUT);
 pinMode (EN_6, OUTPUT);
 pinMode (EN_7, OUTPUT);
 pinMode (EN_8, OUTPUT);

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
  Serial4.begin(115200);
  Serial.begin(9600);
  setUpLEDStrips();

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    //delay(10);
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
//
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

  while (Serial4.available()) {
    delay(1);  //delay to allow byte to arrive in input buffer
    char c = (char)Serial4.read();
    readString += c;
  }

  if (readString.length() >0) {
    Serial.println(readString);
    if(readString=="hello world"){
      Serial.println("This is right");
      testColorStrip(led_strip.Color(150,30,0));
    }
    readString="";
  } 
  
  
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
      Serial.print(i); Serial.println(" touched on MPR 1");
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
      Serial.print(i); Serial.println(" touched on MPR 2");
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
      Serial.print(i); Serial.println(" touched on MPR 3");
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
      if(i==11) {
        usbMIDI.sendNoteOn(48, 99, channel);  // 60 = C4
        setBlockColor(49,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(49, 99, channel);  
        setBlockColor(50,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(50, 99, channel);  
        setBlockColor(51,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(51, 99, channel);  
        setBlockColor(52,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(52, 99, channel);
        setBlockColor(53,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(53, 99, channel);  
        setBlockColor(54,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(54, 99, channel);  
        setBlockColor(55,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(55, 99, channel);  
        setBlockColor(56,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(56, 99, channel);  
        setBlockColor(57,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(57, 99, channel);  
        setBlockColor(58,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(58, 99, channel);  
        setBlockColor(59,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(59, 99, channel);  
        setBlockColor(60,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched on MPR 4");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched5 & _BV(i)) && (lasttouched5 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(48, 99, channel);  // 60 = C4
        setBlockColor(49,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(49, 99, channel);  
        setBlockColor(50,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(50, 99, channel);  
        setBlockColor(51,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(51, 99, channel);  
        setBlockColor(52,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(52, 99, channel);
        setBlockColor(53,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(53, 99, channel);  
        setBlockColor(54,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(54, 99, channel);  
        setBlockColor(55,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(55, 99, channel);  
        setBlockColor(56,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(56, 99, channel);  
        setBlockColor(57,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(57, 99, channel);  
        setBlockColor(58,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(58, 99, channel);  
        setBlockColor(59,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(59, 99, channel);  
        setBlockColor(60,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched6 & _BV(i)) && !(lasttouched6 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C4
        setBlockColor(61,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(61, 99, channel);  
        setBlockColor(62,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(62, 99, channel);  
        setBlockColor(63,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(63, 99, channel);  
        setBlockColor(64,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(64, 99, channel);
        setBlockColor(65,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(65, 99, channel);  
        setBlockColor(66,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(66, 99, channel);  
        setBlockColor(67,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(67, 99, channel);  
        setBlockColor(68,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(68, 99, channel);  
        setBlockColor(69,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(69, 99, channel);  
        setBlockColor(70,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(70, 99, channel);  
        setBlockColor(71,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(71, 99, channel);  
        setBlockColor(72,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched6 & _BV(i)) && (lasttouched6 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(60, 99, channel);  // 60 = C4
        setBlockColor(61,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(61, 99, channel);  
        setBlockColor(62,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(62, 99, channel);  
        setBlockColor(63,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(63, 99, channel);  
        setBlockColor(64,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(64, 99, channel);
        setBlockColor(65,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(65, 99, channel);  
        setBlockColor(66,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(66, 99, channel);  
        setBlockColor(67,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(67, 99, channel);  
        setBlockColor(68,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(68, 99, channel);  
        setBlockColor(69,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(69, 99, channel);  
        setBlockColor(70,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(70, 99, channel);  
        setBlockColor(71,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(71, 99, channel);  
        setBlockColor(72,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched7 & _BV(i)) && !(lasttouched7 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(72, 99, channel);  // 60 = C4
        setBlockColor(73,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(73, 99, channel);  
        setBlockColor(74,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(74, 99, channel);  
        setBlockColor(75,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(75, 99, channel);  
        setBlockColor(76,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(76, 99, channel);
        setBlockColor(77,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(77, 99, channel);  
        setBlockColor(78,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(78, 99, channel);  
        setBlockColor(79,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(79, 99, channel);  
        setBlockColor(80,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(80, 99, channel);  
        setBlockColor(81,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(81, 99, channel);  
        setBlockColor(82,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(82, 99, channel);  
        setBlockColor(83,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(83, 99, channel);  
        setBlockColor(84,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched7 & _BV(i)) && (lasttouched7 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(72, 99, channel);  // 60 = C4
        setBlockColor(73,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(73, 99, channel);  
        setBlockColor(74,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(74, 99, channel);  
        setBlockColor(75,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(75, 99, channel);  
        setBlockColor(76,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(76, 99, channel);
        setBlockColor(77,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(77, 99, channel);  
        setBlockColor(78,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(78, 99, channel);  
        setBlockColor(79,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(79, 99, channel);  
        setBlockColor(80,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(80, 99, channel);  
        setBlockColor(81,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(81, 99, channel);  
        setBlockColor(82,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(82, 99, channel);  
        setBlockColor(83,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(83, 99, channel);  
        setBlockColor(84,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched8 & _BV(i)) && !(lasttouched8 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(84, 99, channel);  // 60 = C4
        setBlockColor(85,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(85, 99, channel);  
        setBlockColor(86,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(86, 99, channel);  
        setBlockColor(87,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(87, 99, channel);  
        setBlockColor(88,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(88, 99, channel);
        setBlockColor(89,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(89, 99, channel);  
        setBlockColor(90,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(90, 99, channel);  
        setBlockColor(91,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(91, 99, channel);  
        setBlockColor(92,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(92, 99, channel);  
        setBlockColor(93,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(93, 99, channel);  
        setBlockColor(94,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(94, 99, channel);  
        setBlockColor(95,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(95, 99, channel);  
        setBlockColor(96,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched8 & _BV(i)) && (lasttouched8 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(84, 99, channel);  // 60 = C4
        setBlockColor(85,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(85, 99, channel);  
        setBlockColor(86,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(86, 99, channel);  
        setBlockColor(87,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(87, 99, channel);  
        setBlockColor(88,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(88, 99, channel);
        setBlockColor(89,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(89, 99, channel);  
        setBlockColor(90,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(90, 99, channel);  
        setBlockColor(91,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(91, 99, channel);  
        setBlockColor(92,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(92, 99, channel);  
        setBlockColor(93,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(93, 99, channel);  
        setBlockColor(94,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(94, 99, channel);  
        setBlockColor(95,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(95, 99, channel);  
        setBlockColor(96,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched9 & _BV(i)) && !(lasttouched9 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(96, 99, channel);  // 60 = C4
        setBlockColor(97,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(97, 99, channel);  
        setBlockColor(98,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(98, 99, channel);  
        setBlockColor(99,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(99, 99, channel);  
        setBlockColor(100,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(100, 99, channel);
        setBlockColor(101,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(101, 99, channel);  
        setBlockColor(102,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(102, 99, channel);  
        setBlockColor(103,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(103, 99, channel);  
        setBlockColor(104,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(104, 99, channel);  
        setBlockColor(105,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(105, 99, channel);  
        setBlockColor(106,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(106, 99, channel);  
        setBlockColor(107,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched9 & _BV(i)) && (lasttouched9 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(96, 99, channel);  // 60 = C4
        setBlockColor(97,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(97, 99, channel);  
        setBlockColor(98,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(98, 99, channel);  
        setBlockColor(99,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(99, 99, channel);  
        setBlockColor(100,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(100, 99, channel);
        setBlockColor(101,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(101, 99, channel);  
        setBlockColor(102,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(102, 99, channel);  
        setBlockColor(103,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(103, 99, channel);  
        setBlockColor(104,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(104, 99, channel);  
        setBlockColor(105,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(105, 99, channel);  
        setBlockColor(106,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(106, 99, channel);  
        setBlockColor(107,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched10 & _BV(i)) && !(lasttouched10 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(107, 99, channel);  // 60 = C4
        setBlockColor(108,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(108, 99, channel);  
        setBlockColor(109,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(109, 99, channel);  
        setBlockColor(110,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(110, 99, channel);  
        setBlockColor(111,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(111, 99, channel);
        setBlockColor(112,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(112, 99, channel);  
        setBlockColor(113,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(113, 99, channel);  
        setBlockColor(114,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(114, 99, channel);  
        setBlockColor(115,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(115, 99, channel);  
        setBlockColor(116,led_strip.Color(255,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(116, 99, channel);  
        setBlockColor(117,led_strip.Color(255,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(117, 99, channel);  
        setBlockColor(118,led_strip.Color(255,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(118, 99, channel);  
        setBlockColor(119,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched10 & _BV(i)) && (lasttouched10 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(107, 99, channel);  // 60 = C4
        setBlockColor(108,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(108, 99, channel);  
        setBlockColor(109,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(109, 99, channel);  
        setBlockColor(110,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(110, 99, channel);  
        setBlockColor(111,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(111, 99, channel);
        setBlockColor(112,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(112, 99, channel);  
        setBlockColor(113,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(113, 99, channel);  
        setBlockColor(114,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(114, 99, channel);  
        setBlockColor(115,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(115, 99, channel);  
        setBlockColor(116,led_strip.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(116, 99, channel);  
        setBlockColor(117,led_strip.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(117, 99, channel);  
        setBlockColor(118,led_strip.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(118, 99, channel);  
        setBlockColor(119,led_strip.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched11 & _BV(i)) && !(lasttouched11 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(119, 99, channel);  // 60 = C4
        setBlockColor(120,led_strip.Color(255,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(120, 99, channel);  
        setBlockColor(121,led_strip.Color(255,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(121, 99, channel);  
        setBlockColor(122,led_strip.Color(255,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(122, 99, channel);  
        setBlockColor(123,led_strip.Color(255,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(123, 99, channel);
        setBlockColor(124,led_strip.Color(255,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(124, 99, channel);  
        setBlockColor(125,led_strip.Color(255,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(125, 99, channel);  
        setBlockColor(126,led_strip.Color(255,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(126, 99, channel);  
        setBlockColor(127,led_strip.Color(255,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(127, 99, channel);  
        setBlockColor(128,led_strip.Color(255,0,0));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched11 & _BV(i)) && (lasttouched11 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(119, 99, channel);  // 60 = C4
        setBlockColor(120,led_strip.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(120, 99, channel);  
        setBlockColor(121,led_strip.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(121, 99, channel);  
        setBlockColor(122,led_strip.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(122, 99, channel);  
        setBlockColor(123,led_strip.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(123, 99, channel);
        setBlockColor(124,led_strip.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(124, 99, channel);  
        setBlockColor(125,led_strip.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(125, 99, channel);  
        setBlockColor(126,led_strip.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(126, 99, channel);  
        setBlockColor(127,led_strip.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(127, 99, channel);  
        setBlockColor(128,led_strip.Color(0,0,0));
      }
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

void out0() {
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}

// For columns 1 and 2
void out1() {
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out2()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out3()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out4()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out5()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out6()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out7()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out8()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_1.show();
}
void out9()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
void out10()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
void out11()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
void out12()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
void out13()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
void out14()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
void out15()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
void out16()
{
 digitalWrite (EN_1, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_1.show();
}
// For columns 3 and 4
void out17() {
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out18()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out19()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out20()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out21()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out22()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out23()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out24()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_2.show();
}
void out25()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
void out26()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
void out27()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
void out28()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
void out29()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
void out30()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
void out31()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
void out32()
{
 digitalWrite (EN_2, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_2.show();
}
// For columns 5 and 6
void out33() {
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out34()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out35()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out36()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out37()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out38()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out39()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out40()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out41()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
void out42()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
void out43()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
void out44()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
void out45()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
void out46()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
void out47()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
void out48()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_3.show();
}
// Used for columns 7 and 8
void out49() {
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out50()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out51()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out52()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out53()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out54()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out55()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out56()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_4.show();
}
void out57()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
void out58()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
void out59()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
void out60()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
void out61()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
void out62()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
void out63()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
void out64()
{
 digitalWrite (EN_4, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_4.show();
}
// Used for columns 9 and 10
void out65() {
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out66()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out67()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out68()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out69()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out70()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out71()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out72()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out73()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out74()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out75()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out76()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out77()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out78()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out79()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out80()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
// Used for columns 11 and 12
void out81() {
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out82()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out83()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out84()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out85()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out86()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out87()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out88()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out89()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out90()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out91()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out92()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out93()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out94()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out95()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out96()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
// Used for columns 13 and 14
void out97() {
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out98()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out99()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out100()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out101()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out102()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out103()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out104()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out105()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out106()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out107()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out108()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out109()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out110()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out111()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out112()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
// Used for columns 15 and 16
void out113() {
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out114()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out115()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out116()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out117()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out118()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out119()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out120()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out121()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out122()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out123()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out124()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out125()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out126()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out127()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out128()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
// Used to switch the main multiplexer (16 to 1 MUX acting as an 8 to 1 MUX)
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
 digitalWrite (S0_MAIN, HIGH);
 digitalWrite (S1_MAIN, LOW);
 digitalWrite (S2_MAIN, LOW);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
}
void out10_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0_MAIN, LOW);
 digitalWrite (S1_MAIN, HIGH);
 digitalWrite (S2_MAIN, LOW);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
}
void out11_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0_MAIN, HIGH);
 digitalWrite (S1_MAIN, HIGH);
 digitalWrite (S2_MAIN, LOW);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
}
void out12_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0_MAIN, LOW);
 digitalWrite (S1_MAIN, LOW);
 digitalWrite (S2_MAIN, HIGH);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
}
void out13_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0_MAIN, HIGH);
 digitalWrite (S1_MAIN, LOW);
 digitalWrite (S2_MAIN, HIGH);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
}
void out14_MAIN()
{
 digitalWrite (EN_MAIN, LOW);
 digitalWrite (S0_MAIN, LOW);
 digitalWrite (S1_MAIN, HIGH);
 digitalWrite (S2_MAIN, HIGH);
 digitalWrite (S3_MAIN, HIGH);
 led_strip.show();
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
  led_strip_1.begin();
  led_strip_1.show();
  led_strip_2.begin();
  led_strip_2.show();
  led_strip_3.begin();
  led_strip_3.show();
  led_strip_4.begin();
  led_strip_5.show();
  led_strip_5.begin();
  led_strip_5.show();
  led_strip_6.begin();
  led_strip_6.show();
  led_strip_7.begin();
  led_strip_7.show();
  led_strip_8.begin();
  led_strip_8.show();
}

void testColorStrip(uint32_t color) {
  out8();
  for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
}

void setBlockColor(uint8_t number, uint32_t color) {
  switch (number) {
    case 1:
      out1();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 2:
      out2();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 3:
      out3();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 4:
      out4();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 5:
      out5();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 6:
      out6();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 7:
      out7();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 8:
      out8();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 9:
      out9();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 10:
      out10();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 11:
      out11();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 12:
      out12();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 13:
      out13();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 14:
      out14();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 15:
      out15();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 16:
      out16();
      for(int i=0;i<7;i++) {
        led_strip_1.setPixelColor(i, color);
      }
      led_strip_1.show();
      break;
    case 17:
      out17();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 18:
      out18();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 19:
      out19();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 20:
      out20();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 21:
      out21();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 22:
      out22();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 23:
      out23();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 24:
      out24();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 25:
      out25();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 26:
      out26();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 27:
      out27();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 28:
      out28();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 29:
      out29();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 30:
      out32();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 31:
      out31();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 32:
      out30();
      for(int i=0;i<7;i++) {
        led_strip_2.setPixelColor(i, color);
      }
      led_strip_2.show();
      break;
    case 33:
      out33();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 34:
      out34();      
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 35:
      out35();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 36:
      out36();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 37:
      out37();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 38:
      out38();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 39:
      out39();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 40:
      out40();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 41:
      out41();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 42:
      out42();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 43:
      out43();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 44:
      out44();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 45:
      out45();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 46:
      out46();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 47:
      out47();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 48:
      out48();
      for(int i=0;i<7;i++) {
        led_strip_3.setPixelColor(i, color);
      }
      led_strip_3.show();
      break;
    case 49:
      out49();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 50:
      out50();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 51:
      out51();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 52:
      out52();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 53:
      out53();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 54:
      out54();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 55:
      out55();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 56:
      out56();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 57:
      out57();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 58:
      out58();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 59:
      out59();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 60:
      out60();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 61:
      out61();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 62:
      out62();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 63:
      out63();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
      break;
    case 64:
      out64();
      for(int i=0;i<7;i++) {
        led_strip_4.setPixelColor(i, color);
      }
      led_strip_4.show();
    case 65:
      out69();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 66:
      out68();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 67:
      out67();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 68:
      out66();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 69:
      out65();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 70:
      out70();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 71:
      out71();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 72:
      out72();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 73:
      out77();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 74:
      out76();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 75:
      out75();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 76:
      out74();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 77:
      out73();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 78:
      out78();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 79:
      out79();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 80:
      out80();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 81:
      out85();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 82:
      out84();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 83:
      out83();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 84:
      out82();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 85:
      out81();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 86:
      out86();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 87:
      out87();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 88:
      out88();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 89:
      out93();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 90:
      out92();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 91:
      out91();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 92:
      out90();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 93:
      out89();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 94:
      out94();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 95:
      out95();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 96:
      out96();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 97:
      out101();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 98:
      out100();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 99:
      out99();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 100:
      out98();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 101:
      out97();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 102:
      out104();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 103:
      out103();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 104:
      out102();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 105:
      out109();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 106:
      out108();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 107:
      out107();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 108:
      out106();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 109:
      out105();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 110:
      out112();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 111:
      out111();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 112:
      out110();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 113:
      out117();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 114:
      out116();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 115:
      out115();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 116:
      out114();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 117:
      out113();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 118:
      out120();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 119:
      out119();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 120:
      out118();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
    case 121:
      out125();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 122:
      out124();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 123:
      out123();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 124:
      out122();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 125:
      out121();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 126:
      out128();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 127:
      out127();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 128:
      out126();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    default:
      break;
      // statements
  }
}




