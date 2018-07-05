#include <i2c_t3.h>
#include <Bounce.h>  // Bounce library makes button change detection easy
#include "Adafruit_MPR121.h"
#include <Adafruit_NeoPixel.h>
#include <MIDI.h>
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

// Define colors for each box
// Colors for 1st column (red)
int COLOR_1[] = {255,0,0};
int COLOR_2[] = {255,0,0};
int COLOR_3[] = {255,0,0};
int COLOR_4[] = {255,0,0};
int COLOR_5[] = {255,0,0};
int COLOR_6[] = {255,0,0};
int COLOR_7[] = {255,0,0};
int COLOR_8[] = {255,0,0};

// Colors for 2nd column (red-orange)
int  COLOR_9[] = {255,80,0};
int COLOR_10[] = {255,80,0};
int COLOR_11[] = {255,80,0};
int COLOR_12[] = {255,80,0};
int COLOR_13[] = {255,80,0};
int COLOR_14[] = {255,80,0};
int COLOR_15[] = {255,80,0};
int COLOR_16[] = {255,80,0};

// Colors for 3rd column (orange)
int COLOR_17[] = {255,125,0};
int COLOR_18[] = {255,125,0};
int COLOR_19[] = {255,125,0};
int COLOR_20[] = {255,125,0};
int COLOR_21[] = {255,125,0};
int COLOR_22[] = {255,125,0};
int COLOR_23[] = {255,125,0};
int COLOR_24[] = {255,125,0};

// Colors for 4th column (yellow)
int COLOR_25[] = {255,255,0};
int COLOR_26[] = {255,255,0};
int COLOR_27[] = {255,255,0};
int COLOR_28[] = {255,255,0};
int COLOR_29[] = {255,255,0};
int COLOR_30[] = {255,255,0};
int COLOR_31[] = {255,255,0};
int COLOR_32[] = {255,255,0};

// Colors for 5th column (yellow-green)
int COLOR_33[] = {125,255,0};
int COLOR_34[] = {125,255,0};
int COLOR_35[] = {125,255,0};
int COLOR_36[] = {125,255,0};
int COLOR_37[] = {125,255,0};
int COLOR_38[] = {125,255,0};
int COLOR_39[] = {125,255,0};
int COLOR_40[] = {125,255,0};

// Colors for 6th column (green)
int COLOR_41[] = {0,255,0};
int COLOR_42[] = {0,255,0};
int COLOR_43[] = {0,255,0};
int COLOR_44[] = {0,255,0};
int COLOR_45[] = {0,255,0};
int COLOR_46[] = {0,255,0};
int COLOR_47[] = {0,255,0};
int COLOR_48[] = {0,255,0};

// Colors for 7th column (green-cyan)
int COLOR_49[] = {0,255,80};
int COLOR_50[] = {0,255,80};
int COLOR_51[] = {0,255,80};
int COLOR_52[] = {0,255,80};
int COLOR_53[] = {0,255,80};
int COLOR_54[] = {0,255,80};
int COLOR_55[] = {0,255,80};
int COLOR_56[] = {0,255,80};

// Colors for 8th column (cyan-green)
int COLOR_57[] = {0,255,180};
int COLOR_58[] = {0,255,180};
int COLOR_59[] = {0,255,180};
int COLOR_60[] = {0,255,180};
int COLOR_61[] = {0,255,180};
int COLOR_62[] = {0,255,180};
int COLOR_63[] = {0,255,180};
int COLOR_64[] = {0,255,180};

// Colors for 9th column (cyan)
int COLOR_65[] = {0,255,255};
int COLOR_66[] = {0,255,255};
int COLOR_67[] = {0,255,255};
int COLOR_68[] = {0,255,255};
int COLOR_69[] = {0,255,255};
int COLOR_70[] = {0,255,255};
int COLOR_71[] = {0,255,255};
int COLOR_72[] = {0,255,255};

// Colors for 10th column (cyan with more blue)
int COLOR_73[] = {0,180,255};
int COLOR_74[] = {0,180,255};
int COLOR_75[] = {0,180,255};
int COLOR_76[] = {0,180,255};
int COLOR_77[] = {0,180,255};
int COLOR_78[] = {0,180,255};
int COLOR_79[] = {0,180,255};
int COLOR_80[] = {0,180,255};

// Colors for 11th column (cyan-blue)
int COLOR_81[] = {0,125,255};
int COLOR_82[] = {0,125,255};
int COLOR_83[] = {0,125,255};
int COLOR_84[] = {0,125,255};
int COLOR_85[] = {0,125,255};
int COLOR_86[] = {0,125,255};
int COLOR_87[] = {0,125,255};
int COLOR_88[] = {0,125,255};

// Colors for 12th column (blue-cyan)
int COLOR_89[] = {0,50,255};
int COLOR_90[] = {0,50,255};
int COLOR_91[] = {0,50,255};
int COLOR_92[] = {0,50,255};
int COLOR_93[] = {0,50,255};
int COLOR_94[] = {0,50,255};
int COLOR_95[] = {0,50,255};
int COLOR_96[] = {0,50,255};

// Colors for 13th column (blue)
int  COLOR_97[] = {0,0,255};
int  COLOR_98[] = {0,0,255};
int  COLOR_99[] = {0,0,255};
int COLOR_100[] = {0,0,255};
int COLOR_101[] = {0,0,255};
int COLOR_102[] = {0,0,255};
int COLOR_103[] = {0,0,255};
int COLOR_104[] = {0,0,255};

// Colors for 14th column (blue-red)
int COLOR_105[] = {80,0,255};
int COLOR_106[] = {80,0,255};
int COLOR_107[] = {80,0,255};
int COLOR_108[] = {80,0,255};
int COLOR_109[] = {80,0,255};
int COLOR_110[] = {80,0,255};
int COLOR_111[] = {80,0,255};
int COLOR_112[] = {80,0,255};

// Colors for 15th column (blue-magenta)
int COLOR_113[] = {130,0,255};
int COLOR_114[] = {130,0,255};
int COLOR_115[] = {130,0,255};
int COLOR_116[] = {130,0,255};
int COLOR_117[] = {130,0,255};
int COLOR_118[] = {130,0,255};
int COLOR_119[] = {130,0,255};
int COLOR_120[] = {130,0,255};

// Colors for 16th column (purple)
int COLOR_121[] = {255,0,255};
int COLOR_122[] = {255,0,255};
int COLOR_123[] = {255,0,255};
int COLOR_124[] = {255,0,255};
int COLOR_125[] = {255,0,255};
int COLOR_126[] = {255,0,255};
int COLOR_127[] = {255,0,255};
int COLOR_128[] = {255,0,255};

int ColorArray[16][8][3];

String readString;

// 7 is the number of pixels on the strip
Adafruit_NeoPixel led_strip_1 = Adafruit_NeoPixel(7, LED_SIGNAL_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_2 = Adafruit_NeoPixel(7, LED_SIGNAL_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_3 = Adafruit_NeoPixel(7, LED_SIGNAL_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_4 = Adafruit_NeoPixel(7, LED_SIGNAL_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_5 = Adafruit_NeoPixel(7, LED_SIGNAL_5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_6 = Adafruit_NeoPixel(7, LED_SIGNAL_6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_7 = Adafruit_NeoPixel(7, LED_SIGNAL_7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_strip_8 = Adafruit_NeoPixel(7, LED_SIGNAL_8, NEO_GRB + NEO_KHZ800);
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
int channel = 1;

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

 for(int i=0;i<16; i++) {
  for(int j=0;j<8;j++) {
    switch(i){
      case 0:
        ColorArray[i][j][0] = 255;
        ColorArray[i][j][1] = 0;
        ColorArray[i][j][2] = 0;
        break;
      case 1:
        ColorArray[i][j][0] = 255;
        ColorArray[i][j][1] = 80;
        ColorArray[i][j][2] = 0;
        break;
      case 2:
        ColorArray[i][j][0] = 255;
        ColorArray[i][j][1] = 125;
        ColorArray[i][j][2] = 0;
        break;
      case 3:
        ColorArray[i][j][0] = 255;
        ColorArray[i][j][1] = 255;
        ColorArray[i][j][2] = 0;
        break;
      case 4:
        ColorArray[i][j][0] = 125;
        ColorArray[i][j][1] = 255;
        ColorArray[i][j][2] = 0;
        break;
      case 5:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 255;
        ColorArray[i][j][2] = 0;
        break;
      case 6:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 255;
        ColorArray[i][j][2] = 80;
        break;
      case 7:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 255;
        ColorArray[i][j][2] = 180;
        break;
      case 8:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 255;
        ColorArray[i][j][2] = 255;
        break;
      case 9:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 180;
        ColorArray[i][j][2] = 255;
        break;
      case 10:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 125;
        ColorArray[i][j][2] = 255;
        break;
      case 11:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 50;
        ColorArray[i][j][2] = 255;
        break;
      case 12:
        ColorArray[i][j][0] = 0;
        ColorArray[i][j][1] = 0;
        ColorArray[i][j][2] = 255;
        break;
      case 13:
        ColorArray[i][j][0] = 80;
        ColorArray[i][j][1] = 0;
        ColorArray[i][j][2] = 255;
        break;
      case 14:
        ColorArray[i][j][0] = 130;
        ColorArray[i][j][1] = 0;
        ColorArray[i][j][2] = 255;
        break;
      case 15:
        ColorArray[i][j][0] = 255;
        ColorArray[i][j][1] = 0;
        ColorArray[i][j][2] = 255;
        break;
    }
  }
 }
 
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
   Serial.println("MPR121 5 not found, check wiring?");
   while(1);
 }
 
 if (!cap6.begin(0x5B,2)) {
   Serial.println("MPR121 6 not found, check wiring?");
   while(1);
 }

 if (!cap7.begin(0x5C,2)) {
   Serial.println("MPR121 7 not found, check wiring?");
   while(1);
 }

 if (!cap8.begin(0x5D,2)) {
   Serial.println("MPR121 8 not found, check wiring?");
   while(1);
 }


 if (!cap9.begin(0x5A,3)) {
   Serial.println("MPR121 9 not found, check wiring?");
   while(1);
 }
 
 if (!cap10.begin(0x5B,3)) {
   Serial.println("MPR121 10 not found, check wiring?");
   while(1);
 }

 if (!cap11.begin(0x5C,3)) {
   Serial.println("MPR121 11 not found, check wiring?");
   while(1);
 }

  Serial.println("All MPR121S have been found and you're good to go!  Enjoy the Midi Mosaic! :D");
}

/*                MIDI NOTE NUMBERS 
      C   C#  D   D#  E   F   F#  G   G#  A   A#  B
   |------------------------------------------------ 
-2 |   0   1   2   3   4   5   6   7   8   9  10  11
-1 |  12  13  14  15  16  17  18  19  20  21  22  23
 0 |  24  25  26  27  28  29  30  31  32  33  34  35
 1 |  36  37  38  39  40  41  42  43  44  45  46  47
 2 |  48  49  50  51  52  53  54  55  56  57  58  59
 3 |  60  61  62  63  64  65  66  67  68  69  70  71
 4 |  72  73  74  75  76  77  78  79  80  81  82  83
 5 |  84  85  86  87  88  89  90  91  92  93  94  95
 6 |  96  97  98  99 100 101 102 103 104 105 106 107
 7 | 108 109 110 111 112 113 114 115 116 117 118 119
 8 | 120 121 122 123 124 125 126 127
*/

void loop() {
  /*
  for(int i=1;i<=128;i++) {
        setBlockColor(i,led_strip_1.Color(0,0,0));
      }
    delay(2000);
    demo();
  int type, note, channel_observe;
  while(1) {
  if (usbMIDI.read()) {                    // Is there a MIDI message incoming ?
    byte type = usbMIDI.getType();
    switch (type) {
      case midi::NoteOn:
        note = usbMIDI.getData1();
        channel_observe = usbMIDI.getChannel();
//        Serial.println(String("Note On:  ch=") + channel_observe + ", note=" + note);
        if(note==0) {
          setBlockColor(1,led_strip_4.Color(0,80,250));
          break;
        }
        if(note==1) {
          setBlockColor(2,led_strip_4.Color(0,80,250));break;
        }
        if(note==2) {
          setBlockColor(3,led_strip_4.Color(0,80,250));break;
        }
        if(note==3) {
          setBlockColor(4,led_strip_4.Color(0,80,250));break;
        }
        if(note==4) {
          setBlockColor(5,led_strip_4.Color(0,80,250));break;
        }
        if(note==5) {
          setBlockColor(6,led_strip_4.Color(0,80,250));break;
        }
        if(note==6) {
          setBlockColor(7,led_strip_4.Color(0,80,250));break;
        }
        if(note==7) {
          setBlockColor(8,led_strip_4.Color(0,80,250));break;
        }
        if(note==8) {
          setBlockColor(9,led_strip_4.Color(0,80,250));break;
        }
        if(note==9) {
          setBlockColor(10,led_strip_4.Color(0,80,250));break;
        }
        if(note==10) {
          setBlockColor(11,led_strip_4.Color(0,80,250));break;
        }
        if(note==11) {
          setBlockColor(12,led_strip_4.Color(0,80,250));break;
        }
        if(note==12) {
          setBlockColor(13,led_strip_4.Color(0,80,250));break;
        }
        if(note==13) {
          setBlockColor(14,led_strip_4.Color(0,80,250));break;
        }
        if(note==14) {
          setBlockColor(15,led_strip_4.Color(0,80,250));break;
        }
        if(note==15) {
          setBlockColor(16,led_strip_4.Color(0,80,250));break;
        }
        if(note==16) {
          setBlockColor(17,led_strip_4.Color(0,80,250));break;
        }
        if(note==17) {
          setBlockColor(18,led_strip_4.Color(0,80,250));break;
        }
        if(note==18) {
          setBlockColor(19,led_strip_4.Color(0,80,250));break;
        }
        if(note==19) {
          setBlockColor(20,led_strip_4.Color(0,80,250));break;
        }
        if(note==20) {
          setBlockColor(21,led_strip_4.Color(0,80,250));break;
        }
        if(note==21) {
          setBlockColor(22,led_strip_4.Color(0,80,250));break;
        }
        if(note==22) {
          setBlockColor(23,led_strip_4.Color(0,80,250));break;
        }
        if(note==23) {
          setBlockColor(24,led_strip_4.Color(0,80,250));break;
        }
        if(note==24) {
          setBlockColor(25,led_strip_4.Color(0,80,250));break;
        }
        if(note==25) {
          setBlockColor(26,led_strip_4.Color(0,80,250));break;
        }
        if(note==26) {
          setBlockColor(27,led_strip_4.Color(0,80,250));break;
        }
        if(note==27) {
          setBlockColor(28,led_strip_4.Color(0,80,250));break;
        }
        if(note==28) {
          setBlockColor(29,led_strip_4.Color(0,80,250));break;
        }
        if(note==29) {
          setBlockColor(30,led_strip_4.Color(0,80,250));break;
        }
        if(note==30) {
          setBlockColor(31,led_strip_4.Color(0,80,250));break;
        }
        if(note==31) {
          setBlockColor(32,led_strip_4.Color(0,80,250));break;
        }
        if(note==32) {
          setBlockColor(33,led_strip_4.Color(0,80,250));break;
        }
        if(note==33) {
          setBlockColor(34,led_strip_4.Color(0,80,250));break;
        }
        if(note==34) {
          setBlockColor(35,led_strip_4.Color(0,80,250));break;
        }
        if(note==35) {
          setBlockColor(36,led_strip_4.Color(0,80,250));break;
        }
        if(note==36) {
          setBlockColor(37,led_strip_4.Color(0,80,250));break;
        }
        if(note==37) {
          setBlockColor(38,led_strip_4.Color(0,80,250));break;
        }
        if(note==38) {
          setBlockColor(39,led_strip_4.Color(0,80,250));break;
        }
        if(note==39) {
          setBlockColor(40,led_strip_4.Color(0,80,250));break;
        }
        if(note==40) {
          setBlockColor(41,led_strip_4.Color(0,80,250));break;
        }
        if(note==41) {
          setBlockColor(42,led_strip_4.Color(0,80,250));break;
        }
        if(note==42) {
          setBlockColor(43,led_strip_4.Color(0,80,250));break;
        }
        if(note==43) {
          setBlockColor(44,led_strip_4.Color(0,80,250));break;
        }
        if(note==44) {
          setBlockColor(45,led_strip_4.Color(0,80,250));break;
        }
        if(note==45) {
          setBlockColor(46,led_strip_4.Color(0,80,250));break;
        }
        if(note==46) {
          setBlockColor(47,led_strip_4.Color(0,80,250));break;
        }
        if(note==47) {
          setBlockColor(48,led_strip_4.Color(0,80,250));break;
        }
        if(note==48) {
          setBlockColor(49,led_strip_4.Color(0,80,250));break;
        }
        if(note==49) {
          setBlockColor(50,led_strip_4.Color(0,80,250));break;
        }
        if(note==50) {
          setBlockColor(51,led_strip_4.Color(0,80,250));break;
        }
        if(note==51) {
          setBlockColor(52,led_strip_4.Color(0,80,250));break;
        }
        if(note==52) {
          setBlockColor(53,led_strip_4.Color(0,80,250));break;
        }
        if(note==53) {
          setBlockColor(54,led_strip_4.Color(0,80,250));break;
        }
        if(note==54) {
          setBlockColor(55,led_strip_4.Color(0,80,250));break;
        }
        if(note==55) {
          setBlockColor(56,led_strip_4.Color(0,80,250));break;
        }
        if(note==56) {
          setBlockColor(57,led_strip_4.Color(0,80,250));break;
        }
        if(note==57) {
          setBlockColor(58,led_strip_4.Color(0,80,250));break;
        }
        if(note==58) {
          setBlockColor(59,led_strip_4.Color(0,80,250));break;
        }
        if(note==59) {
          setBlockColor(60,led_strip_4.Color(0,80,250));break;
        }
        if(note==60) {
          setBlockColor(61,led_strip_4.Color(0,80,250));break;
        }
        if(note==61) {
          setBlockColor(62,led_strip_4.Color(0,80,250));break;
        }
        if(note==62) {
          setBlockColor(63,led_strip_4.Color(0,80,250));break;
        }
        if(note==63) {
          setBlockColor(64,led_strip_4.Color(0,80,250));break;
        }
        if(note==64) {
          setBlockColor(65,led_strip_4.Color(0,80,250));break;
        }
        if(note==65) {
          setBlockColor(66,led_strip_4.Color(0,80,250));break;
        }
        if(note==66) {
          setBlockColor(67,led_strip_4.Color(0,80,250));break;
        }
        if(note==67) {
          setBlockColor(68,led_strip_4.Color(0,80,250));break;
        }
        if(note==68) {
          setBlockColor(69,led_strip_4.Color(0,80,250));break;
        }
        if(note==69) {
          setBlockColor(70,led_strip_4.Color(0,80,250));break;
        }
        if(note==70) {
          setBlockColor(71,led_strip_4.Color(0,80,250));break;
        }
        if(note==71) {
          setBlockColor(72,led_strip_4.Color(0,80,250));break;
        }
        if(note==72) {
          setBlockColor(73,led_strip_4.Color(0,80,250));break;
        }
        if(note==73) {
          setBlockColor(74,led_strip_4.Color(0,80,250));break;
        }
        if(note==74) {
          setBlockColor(75,led_strip_4.Color(0,80,250));break;
        }
        if(note==75) {
          setBlockColor(76,led_strip_4.Color(0,80,250));break;
        }
        if(note==76) {
          setBlockColor(77,led_strip_4.Color(0,80,250));break;
        }
        if(note==77) {
          setBlockColor(78,led_strip_4.Color(0,80,250));break;
        }
        if(note==78) {
          setBlockColor(79,led_strip_4.Color(0,80,250));break;
        }
        if(note==79) {
          setBlockColor(80,led_strip_4.Color(0,80,250));break;
        }
        if(note==80) {
          setBlockColor(81,led_strip_4.Color(0,80,250));break;
        }
        if(note==81) {
          setBlockColor(82,led_strip_4.Color(0,80,250));break;
        }
        if(note==82) {
          setBlockColor(83,led_strip_4.Color(0,80,250));break;
        }
        if(note==83) {
          setBlockColor(84,led_strip_4.Color(0,80,250));break;
        }
        if(note==84) {
          setBlockColor(85,led_strip_4.Color(0,80,250));break;
        }
        if(note==85) {
          setBlockColor(86,led_strip_4.Color(0,80,250));break;
        }
        if(note==86) {
          setBlockColor(87,led_strip_4.Color(0,80,250));break;
        }
        if(note==87) {
          setBlockColor(88,led_strip_4.Color(0,80,250));break;
        }
        if(note==88) {
          setBlockColor(89,led_strip_4.Color(0,80,250));break;
        }
        if(note==89) {
          setBlockColor(90,led_strip_4.Color(0,80,250));break;
        }
        if(note==90) {
          setBlockColor(91,led_strip_4.Color(0,80,250));break;
        }
        if(note==91) {
          setBlockColor(92,led_strip_4.Color(0,80,250));break;
        }
        if(note==92) {
          setBlockColor(93,led_strip_4.Color(0,80,250));break;
        }
        if(note==93) {
          setBlockColor(94,led_strip_4.Color(0,80,250));break;
        }
        if(note==94) {
          setBlockColor(95,led_strip_4.Color(0,80,250));break;
        }
        if(note==95) {
          setBlockColor(96,led_strip_4.Color(0,80,250));break;
        }
        if(note==96) {
          setBlockColor(97,led_strip_4.Color(0,80,250));break;
        }
        if(note==97) {
          setBlockColor(98,led_strip_4.Color(0,80,250));break;
        }
        if(note==98) {
          setBlockColor(99,led_strip_4.Color(0,80,250));break;
        }
        if(note==99) {
          setBlockColor(100,led_strip_4.Color(0,80,250));break;
        }
        if(note==100) {
          setBlockColor(101,led_strip_4.Color(0,80,250));break;
        }
        if(note==101) {
          setBlockColor(102,led_strip_4.Color(0,80,250));break;
        }
        if(note==102) {
          setBlockColor(103,led_strip_4.Color(0,80,250));break;
        }
        if(note==103) {
          setBlockColor(104,led_strip_4.Color(0,80,250));break;
        }
        if(note==104) {
          setBlockColor(105,led_strip_4.Color(0,80,250));break;
        }
        if(note==105) {
          setBlockColor(106,led_strip_4.Color(0,80,250));break;
        }
        if(note==106) {
          setBlockColor(107,led_strip_4.Color(0,80,250));break;
        }
        if(note==107) {
          setBlockColor(108,led_strip_4.Color(0,80,250));break;
        }
        if(note==108) {
          setBlockColor(109,led_strip_4.Color(0,80,250));break;
        }
        if(note==109) {
          setBlockColor(110,led_strip_4.Color(0,80,250));break;
        }
        if(note==110) {
          setBlockColor(111,led_strip_4.Color(0,80,250));break;
        }
        if(note==111) {
          setBlockColor(112,led_strip_4.Color(0,80,250));break;
        }
        if(note==112) {
          setBlockColor(113,led_strip_4.Color(0,80,250));break;
        }
        if(note==113) {
          setBlockColor(114,led_strip_4.Color(0,80,250));break;
        }
        if(note==114) {
          setBlockColor(115,led_strip_4.Color(0,80,250));break;
        }
        if(note==115) {
          setBlockColor(116,led_strip_4.Color(0,80,250));break;
        }
        if(note==116) {
          setBlockColor(117,led_strip_4.Color(0,80,250));break;
        }
        if(note==117) {
          setBlockColor(118,led_strip_4.Color(0,80,250));break;
        }
        if(note==118) {
          setBlockColor(119,led_strip_4.Color(0,80,250));break;
        }
        if(note==119) {
          setBlockColor(120,led_strip_4.Color(0,80,250));break;
        }
        if(note==120) {
          setBlockColor(121,led_strip_4.Color(0,80,250));break;
        }
        if(note==121) {
          setBlockColor(122,led_strip_4.Color(0,80,250));break;
        }
        if(note==122) {
          setBlockColor(123,led_strip_4.Color(0,80,250));break;
        }
        if(note==123) {
          setBlockColor(124,led_strip_4.Color(0,80,250));break;
        }
        if(note==124) {
          setBlockColor(125,led_strip_4.Color(0,80,250));break;
        }
        if(note==125) {
          setBlockColor(126,led_strip_4.Color(0,80,250));break;
        }
        if(note==126) {
          setBlockColor(127,led_strip_4.Color(0,80,250));break;
        }
        if(note==127) {
          setBlockColor(128,led_strip_4.Color(0,80,250));
        }
        break;
      case midi::NoteOff:
        note = usbMIDI.getData1();
        channel_observe = usbMIDI.getChannel();
//        Serial.println(String("Note Off: ch=") + channel_observe + ", note=" + note);
        if(note==0) {
          setBlockColor(1,led_strip_4.Color(0,0,0));
          break;
        }
        if(note==1) {
          setBlockColor(2,led_strip_4.Color(0,0,0));break;
        }
        if(note==2) {
          setBlockColor(3,led_strip_4.Color(0,0,0));break;
        }
        if(note==3) {
          setBlockColor(4,led_strip_4.Color(0,0,0));break;
        }
        if(note==4) {
          setBlockColor(5,led_strip_4.Color(0,0,0));break;
        }
        if(note==5) {
          setBlockColor(6,led_strip_4.Color(0,0,0));break;
        }
        if(note==6) {
          setBlockColor(7,led_strip_4.Color(0,0,0));break;
        }
        if(note==7) {
          setBlockColor(8,led_strip_4.Color(0,0,0));break;
        }
        if(note==8) {
          setBlockColor(9,led_strip_4.Color(0,0,0));break;
        }
        if(note==9) {
          setBlockColor(10,led_strip_4.Color(0,0,0));break;
        }
        if(note==10) {
          setBlockColor(11,led_strip_4.Color(0,0,0));break;
        }
        if(note==11) {
          setBlockColor(12,led_strip_4.Color(0,0,0));break;
        }
        if(note==12) {
          setBlockColor(13,led_strip_4.Color(0,0,0));break;
        }
        if(note==13) {
          setBlockColor(14,led_strip_4.Color(0,0,0));break;
        }
        if(note==14) {
          setBlockColor(15,led_strip_4.Color(0,0,0));break;
        }
        if(note==15) {
          setBlockColor(16,led_strip_4.Color(0,0,0));break;
        }
        if(note==16) {
          setBlockColor(17,led_strip_4.Color(0,0,0));break;
        }
        if(note==17) {
          setBlockColor(18,led_strip_4.Color(0,0,0));break;
        }
        if(note==18) {
          setBlockColor(19,led_strip_4.Color(0,0,0));break;
        }
        if(note==19) {
          setBlockColor(20,led_strip_4.Color(0,0,0));break;
        }
        if(note==20) {
          setBlockColor(21,led_strip_4.Color(0,0,0));break;
        }
        if(note==21) {
          setBlockColor(22,led_strip_4.Color(0,0,0));break;
        }
        if(note==22) {
          setBlockColor(23,led_strip_4.Color(0,0,0));break;
        }
        if(note==23) {
          setBlockColor(24,led_strip_4.Color(0,0,0));break;
        }
        if(note==24) {
          setBlockColor(25,led_strip_4.Color(0,0,0));break;
        }
        if(note==25) {
          setBlockColor(26,led_strip_4.Color(0,0,0));break;
        }
        if(note==26) {
          setBlockColor(27,led_strip_4.Color(0,0,0));break;
        }
        if(note==27) {
          setBlockColor(28,led_strip_4.Color(0,0,0));break;
        }
        if(note==28) {
          setBlockColor(29,led_strip_4.Color(0,0,0));break;
        }
        if(note==29) {
          setBlockColor(30,led_strip_4.Color(0,0,0));break;
        }
        if(note==30) {
          setBlockColor(31,led_strip_4.Color(0,0,0));break;
        }
        if(note==31) {
          setBlockColor(32,led_strip_4.Color(0,0,0));break;
        }
        if(note==32) {
          setBlockColor(33,led_strip_4.Color(0,0,0));break;
        }
        if(note==33) {
          setBlockColor(34,led_strip_4.Color(0,0,0));break;
        }
        if(note==34) {
          setBlockColor(35,led_strip_4.Color(0,0,0));break;
        }
        if(note==35) {
          setBlockColor(36,led_strip_4.Color(0,0,0));break;
        }
        if(note==36) {
          setBlockColor(37,led_strip_4.Color(0,0,0));break;
        }
        if(note==37) {
          setBlockColor(38,led_strip_4.Color(0,0,0));break;
        }
        if(note==38) {
          setBlockColor(39,led_strip_4.Color(0,0,0));break;
        }
        if(note==39) {
          setBlockColor(40,led_strip_4.Color(0,0,0));break;
        }
        if(note==40) {
          setBlockColor(41,led_strip_4.Color(0,0,0));break;
        }
        if(note==41) {
          setBlockColor(42,led_strip_4.Color(0,0,0));break;
        }
        if(note==42) {
          setBlockColor(43,led_strip_4.Color(0,0,0));break;
        }
        if(note==43) {
          setBlockColor(44,led_strip_4.Color(0,0,0));break;
        }
        if(note==44) {
          setBlockColor(45,led_strip_4.Color(0,0,0));break;
        }
        if(note==45) {
          setBlockColor(46,led_strip_4.Color(0,0,0));break;
        }
        if(note==46) {
          setBlockColor(47,led_strip_4.Color(0,0,0));break;
        }
        if(note==47) {
          setBlockColor(48,led_strip_4.Color(0,0,0));break;
        }
        if(note==48) {
          setBlockColor(49,led_strip_4.Color(0,0,0));break;
        }
        if(note==49) {
          setBlockColor(50,led_strip_4.Color(0,0,0));break;
        }
        if(note==50) {
          setBlockColor(51,led_strip_4.Color(0,0,0));break;
        }
        if(note==51) {
          setBlockColor(52,led_strip_4.Color(0,0,0));break;
        }
        if(note==52) {
          setBlockColor(53,led_strip_4.Color(0,0,0));break;
        }
        if(note==53) {
          setBlockColor(54,led_strip_4.Color(0,0,0));break;
        }
        if(note==54) {
          setBlockColor(55,led_strip_4.Color(0,0,0));break;
        }
        if(note==55) {
          setBlockColor(56,led_strip_4.Color(0,0,0));break;
        }
        if(note==56) {
          setBlockColor(57,led_strip_4.Color(0,0,0));break;
        }
        if(note==57) {
          setBlockColor(58,led_strip_4.Color(0,0,0));break;
        }
        if(note==58) {
          setBlockColor(59,led_strip_4.Color(0,0,0));break;
        }
        if(note==59) {
          setBlockColor(60,led_strip_4.Color(0,0,0));break;
        }
        if(note==60) {
          setBlockColor(61,led_strip_4.Color(0,0,0));break;
        }
        if(note==61) {
          setBlockColor(62,led_strip_4.Color(0,0,0));break;
        }
        if(note==62) {
          setBlockColor(63,led_strip_4.Color(0,0,0));break;
        }
        if(note==63) {
          setBlockColor(64,led_strip_4.Color(0,0,0));break;
        }
        if(note==64) {
          setBlockColor(65,led_strip_4.Color(0,0,0));break;
        }
        if(note==65) {
          setBlockColor(66,led_strip_4.Color(0,0,0));break;
        }
        if(note==66) {
          setBlockColor(67,led_strip_4.Color(0,0,0));break;
        }
        if(note==67) {
          setBlockColor(68,led_strip_4.Color(0,0,0));break;
        }
        if(note==68) {
          setBlockColor(69,led_strip_4.Color(0,0,0));break;
        }
        if(note==69) {
          setBlockColor(70,led_strip_4.Color(0,0,0));break;
        }
        if(note==70) {
          setBlockColor(71,led_strip_4.Color(0,0,0));break;
        }
        if(note==71) {
          setBlockColor(72,led_strip_4.Color(0,0,0));break;
        }
        if(note==72) {
          setBlockColor(73,led_strip_4.Color(0,0,0));break;
        }
        if(note==73) {
          setBlockColor(74,led_strip_4.Color(0,0,0));break;
        }
        if(note==74) {
          setBlockColor(75,led_strip_4.Color(0,0,0));break;
        }
        if(note==75) {
          setBlockColor(76,led_strip_4.Color(0,0,0));break;
        }
        if(note==76) {
          setBlockColor(77,led_strip_4.Color(0,0,0));break;
        }
        if(note==77) {
          setBlockColor(78,led_strip_4.Color(0,0,0));break;
        }
        if(note==78) {
          setBlockColor(79,led_strip_4.Color(0,0,0));break;
        }
        if(note==79) {
          setBlockColor(80,led_strip_4.Color(0,0,0));break;
        }
        if(note==80) {
          setBlockColor(81,led_strip_4.Color(0,0,0));break;
        }
        if(note==81) {
          setBlockColor(82,led_strip_4.Color(0,0,0));break;
        }
        if(note==82) {
          setBlockColor(83,led_strip_4.Color(0,0,0));break;
        }
        if(note==83) {
          setBlockColor(84,led_strip_4.Color(0,0,0));break;
        }
        if(note==84) {
          setBlockColor(85,led_strip_4.Color(0,0,0));break;
        }
        if(note==85) {
          setBlockColor(86,led_strip_4.Color(0,0,0));break;
        }
        if(note==86) {
          setBlockColor(87,led_strip_4.Color(0,0,0));break;
        }
        if(note==87) {
          setBlockColor(88,led_strip_4.Color(0,0,0));break;
        }
        if(note==88) {
          setBlockColor(89,led_strip_4.Color(0,0,0));break;
        }
        if(note==89) {
          setBlockColor(90,led_strip_4.Color(0,0,0));break;
        }
        if(note==90) {
          setBlockColor(91,led_strip_4.Color(0,0,0));break;
        }
        if(note==91) {
          setBlockColor(92,led_strip_4.Color(0,0,0));break;
        }
        if(note==92) {
          setBlockColor(93,led_strip_4.Color(0,0,0));break;
        }
        if(note==93) {
          setBlockColor(94,led_strip_4.Color(0,0,0));break;
        }
        if(note==94) {
          setBlockColor(95,led_strip_4.Color(0,0,0));break;
        }
        if(note==95) {
          setBlockColor(96,led_strip_4.Color(0,0,0));break;
        }
        if(note==96) {
          setBlockColor(97,led_strip_4.Color(0,0,0));break;
        }
        if(note==97) {
          setBlockColor(98,led_strip_4.Color(0,0,0));break;
        }
        if(note==98) {
          setBlockColor(99,led_strip_4.Color(0,0,0));break;
        }
        if(note==99) {
          setBlockColor(100,led_strip_4.Color(0,0,0));break;
        }
        if(note==100) {
          setBlockColor(101,led_strip_4.Color(0,0,0));break;
        }
        if(note==101) {
          setBlockColor(102,led_strip_4.Color(0,0,0));break;
        }
        if(note==102) {
          setBlockColor(103,led_strip_4.Color(0,0,0));break;
        }
        if(note==103) {
          setBlockColor(104,led_strip_4.Color(0,0,0));break;
        }
        if(note==104) {
          setBlockColor(105,led_strip_4.Color(0,0,0));break;
        }
        if(note==105) {
          setBlockColor(106,led_strip_4.Color(0,0,0));break;
        }
        if(note==106) {
          setBlockColor(107,led_strip_4.Color(0,0,0));break;
        }
        if(note==107) {
          setBlockColor(108,led_strip_4.Color(0,0,0));break;
        }
        if(note==108) {
          setBlockColor(109,led_strip_4.Color(0,0,0));break;
        }
        if(note==109) {
          setBlockColor(110,led_strip_4.Color(0,0,0));break;
        }
        if(note==110) {
          setBlockColor(111,led_strip_4.Color(0,0,0));break;
        }
        if(note==111) {
          setBlockColor(112,led_strip_4.Color(0,0,0));break;
        }
        if(note==112) {
          setBlockColor(113,led_strip_4.Color(0,0,0));break;
        }
        if(note==113) {
          setBlockColor(114,led_strip_4.Color(0,0,0));break;
        }
        if(note==114) {
          setBlockColor(115,led_strip_4.Color(0,0,0));break;
        }
        if(note==115) {
          setBlockColor(116,led_strip_4.Color(0,0,0));break;
        }
        if(note==116) {
          setBlockColor(117,led_strip_4.Color(0,0,0));break;
        }
        if(note==117) {
          setBlockColor(118,led_strip_4.Color(0,0,0));break;
        }
        if(note==118) {
          setBlockColor(119,led_strip_4.Color(0,0,0));break;
        }
        if(note==119) {
          setBlockColor(120,led_strip_4.Color(0,0,0));break;
        }
        if(note==120) {
          setBlockColor(121,led_strip_4.Color(0,0,0));break;
        }
        if(note==121) {
          setBlockColor(122,led_strip_4.Color(0,0,0));break;
        }
        if(note==122) {
          setBlockColor(123,led_strip_4.Color(0,0,0));break;
        }
        if(note==123) {
          setBlockColor(124,led_strip_4.Color(0,0,0));break;
        }
        if(note==124) {
          setBlockColor(125,led_strip_4.Color(0,0,0));break;
        }
        if(note==125) {
          setBlockColor(126,led_strip_4.Color(0,0,0));break;
        }
        if(note==126) {
          setBlockColor(127,led_strip_4.Color(0,0,0));break;
        }
        if(note==127) {
          setBlockColor(128,led_strip_4.Color(0,0,0));
        }
        break;
      default:
        Serial.println("Something else was received");
    }
  } // Comment out if you want more than just viewing
  }
  */


  // Demo for the 4th

  while(1) {
    demo4th();
  }
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


  // Used for Bluetooth communcation
  while (Serial4.available()) {
    delay(1);  //delay to allow byte to arrive in input buffer
    char c = (char)Serial4.read();
    readString += c;
  }

  if (readString.length() >0) {
    Serial.println(readString);
    int commaIndex = readString.indexOf(',');
    int secondCommaIndex = readString.indexOf(',', commaIndex + 1);
    int thirdCommaIndex = readString.indexOf(',', secondCommaIndex + 1);
    int fourthCommaIndex = readString.indexOf(',', thirdCommaIndex + 1);

    String controlValue = readString.substring(0, commaIndex);
    String numberValue = readString.substring(commaIndex + 1, secondCommaIndex);
    String redValue = readString.substring(secondCommaIndex + 1, thirdCommaIndex);
    String greenValue = readString.substring(thirdCommaIndex + 1, fourthCommaIndex);
    String blueValue = readString.substring(fourthCommaIndex + 1);

    Serial.println("Cntr: " + controlValue);
    Serial.println("Num: " + numberValue);
    Serial.println("Red: " + redValue);
    Serial.println("Green: " + greenValue);
    Serial.println("Blue: " + blueValue);
    
    int numberVal = numberValue.toInt();
    int red = redValue.toInt();
    int green = greenValue.toInt();
    int blue = blueValue.toInt();

    int divisor = numberVal/8;
    int remainder = numberVal%8;

    Serial.println(divisor);
    Serial.println(remainder);
    
    if(controlValue=="a"){
      for(int i=0;i<16;i++) {
        for(int j=0;j<8;j++) {
          ColorArray[i][j][0] = red;
          ColorArray[i][j][1] = green;
          ColorArray[i][j][2] = blue;
        }
      }

      for(int i=1;i<=128;i++) {
        setBlockColor(i,led_strip_1.Color(red,green,blue));
      }
      delay(2500);
      for(int i=1;i<=128;i++) {
        setBlockColor(i,led_strip_1.Color(0,0,0));
      }
    }
    
    if(controlValue=="b"){
      ColorArray[divisor][remainder-1][0] = red;
      ColorArray[divisor][remainder-1][1] = green;
      ColorArray[divisor][remainder-1][2] = blue;
      setBlockColor(numberVal,led_strip_1.Color(red,green,blue));
      delay(2500);
      setBlockColor(numberVal,led_strip_1.Color(0,0,0));
    }
    if(controlValue=="r"){
      for(int i=0;i<16;i++) {
        ColorArray[i][numberVal-1][0] = red;
        ColorArray[i][numberVal-1][1] = green;
        ColorArray[i][numberVal-1][2] = blue;
      }
      for(int i=0;i<16;i++) {
        setBlockColor(numberVal+(i*8),led_strip_1.Color(red,green,blue));
      }
      delay(2500);
      for(int i=0;i<16;i++) {
        setBlockColor(numberVal+(i*8),led_strip_1.Color(0,0,0));
      }
    }
    if(controlValue=="c"){
      for(int i=0;i<8;i++) {
        ColorArray[numberVal-1][i][0] = red;
        ColorArray[numberVal-1][i][1] = green;
        ColorArray[numberVal-1][i][2] = blue;
      }
      for(int i=1;i<=8;i++) {
        setBlockColor((numberVal-1)*8+i,led_strip_1.Color(red,green,blue));
      }
      delay(2500);
      for(int i=1;i<=8;i++) {
        setBlockColor((numberVal-1)*8+i,led_strip_1.Color(0,0,0));
      }
    }
    readString="";
  } 
  
  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!

    /* Used for detecting and handling touch events that occur on the first MPR121 Module */
    if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(0, 99, channel);  // 60 = C4
        setBlockColor(1,led_strip_1.Color(ColorArray[0][0][0],ColorArray[0][0][1],ColorArray[0][0][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(1, 99, channel);  
        setBlockColor(2,led_strip_1.Color(ColorArray[0][1][0],ColorArray[0][1][1],ColorArray[0][1][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(2, 99, channel);  
        setBlockColor(3,led_strip_1.Color(ColorArray[0][2][0],ColorArray[0][2][1],ColorArray[0][2][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(3, 99, channel);  
        setBlockColor(4,led_strip_1.Color(ColorArray[0][3][0],ColorArray[0][3][1],ColorArray[0][3][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(4, 99, channel);
        setBlockColor(5,led_strip_1.Color(ColorArray[0][4][0],ColorArray[0][4][1],ColorArray[0][4][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(5, 99, channel);  
        setBlockColor(6,led_strip_1.Color(ColorArray[0][5][0],ColorArray[0][5][1],ColorArray[0][5][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(6, 99, channel);  
        setBlockColor(7,led_strip_1.Color(ColorArray[0][6][0],ColorArray[0][6][1],ColorArray[0][6][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(7, 99, channel);  
        setBlockColor(8,led_strip_1.Color(ColorArray[0][7][0],ColorArray[0][7][1],ColorArray[0][7][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(8, 99, channel);  
        setBlockColor(9,led_strip_1.Color(ColorArray[1][0][0],ColorArray[1][0][1],ColorArray[1][0][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(9, 99, channel);  
        setBlockColor(10,led_strip_1.Color(ColorArray[1][1][0],ColorArray[1][1][1],ColorArray[1][1][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(10, 99, channel);  
        setBlockColor(11,led_strip_1.Color(ColorArray[1][2][0],ColorArray[1][2][1],ColorArray[1][2][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(11, 99, channel);  
        setBlockColor(12,led_strip_1.Color(ColorArray[1][3][0],ColorArray[1][3][1],ColorArray[1][3][2]));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(0, 99, channel);  // 60 = C4
        setBlockColor(1,led_strip_1.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(1, 99, channel);  
        setBlockColor(2,led_strip_1.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(2, 99, channel);  
        setBlockColor(3,led_strip_1.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(3, 99, channel);  
        setBlockColor(4,led_strip_1.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(4, 99, channel);
        setBlockColor(5,led_strip_1.Color(0,0,0));
      }
      if(i==6) {
        usbMIDI.sendNoteOff(5, 99, channel);  
        setBlockColor(6,led_strip_1.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(6, 99, channel);  
        setBlockColor(7,led_strip_1.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(7, 99, channel);  
        setBlockColor(8,led_strip_1.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(8, 99, channel);  
        setBlockColor(9,led_strip_1.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(9, 99, channel);  
        setBlockColor(10,led_strip_1.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(10, 99, channel);  
        setBlockColor(11,led_strip_1.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(11, 99, channel);  
        setBlockColor(12,led_strip_1.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    /*********************************************************/
    if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(12, 99, channel);  // 60 = C4
        setBlockColor(13,led_strip_1.Color(ColorArray[1][4][0],ColorArray[1][4][1],ColorArray[1][4][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(13, 99, channel);  
        setBlockColor(14,led_strip_1.Color(ColorArray[1][5][0],ColorArray[1][5][1],ColorArray[1][5][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(14, 99, channel);  
        setBlockColor(15,led_strip_1.Color(ColorArray[1][6][0],ColorArray[1][6][1],ColorArray[1][6][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(15, 99, channel);  
        setBlockColor(16,led_strip_1.Color(ColorArray[1][7][0],ColorArray[1][7][1],ColorArray[1][7][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(16, 99, channel);
        setBlockColor(17,led_strip_2.Color(ColorArray[2][0][0],ColorArray[2][0][1],ColorArray[2][0][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(17, 99, channel);  
        setBlockColor(18,led_strip_2.Color(ColorArray[2][1][0],ColorArray[2][1][1],ColorArray[2][1][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(18, 99, channel);  
        setBlockColor(19,led_strip_2.Color(ColorArray[2][2][0],ColorArray[2][2][1],ColorArray[2][2][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(19, 99, channel);  
        setBlockColor(20,led_strip_2.Color(ColorArray[2][3][0],ColorArray[2][3][1],ColorArray[2][3][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(20, 99, channel);  
        setBlockColor(21,led_strip_2.Color(ColorArray[2][4][0],ColorArray[2][4][1],ColorArray[2][4][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(21, 99, channel);  
        setBlockColor(22,led_strip_2.Color(ColorArray[2][5][0],ColorArray[2][5][1],ColorArray[2][5][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(22, 99, channel);  
        setBlockColor(23,led_strip_2.Color(ColorArray[2][6][0],ColorArray[2][6][1],ColorArray[2][6][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(23, 99, channel);  
        setBlockColor(24,led_strip_2.Color(ColorArray[2][7][0],ColorArray[2][7][1],ColorArray[2][7][2]));
      }
      Serial.print(i); Serial.println(" touched on MPR 1");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(12, 99, channel);  // 60 = C4
        setBlockColor(13,led_strip_1.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(13, 99, channel);  
        setBlockColor(14,led_strip_1.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(14, 99, channel);  
        setBlockColor(15,led_strip_1.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(15, 99, channel);  
        setBlockColor(16,led_strip_1.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(16, 99, channel);
        setBlockColor(17,led_strip_2.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(17, 99, channel);  
        setBlockColor(18,led_strip_2.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(18, 99, channel);  
        setBlockColor(19,led_strip_2.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(19, 99, channel);  
        setBlockColor(20,led_strip_2.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(20, 99, channel);  
        setBlockColor(21,led_strip_2.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(21, 99, channel);  
        setBlockColor(22,led_strip_2.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(22, 99, channel);  
        setBlockColor(23,led_strip_2.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(23, 99, channel);  
        setBlockColor(24,led_strip_2.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched3 & _BV(i)) && !(lasttouched3 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(24, 99, channel);  // 60 = C4
        setBlockColor(25,led_strip_2.Color(ColorArray[3][0][0],ColorArray[3][0][1],ColorArray[3][0][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(25, 99, channel);  
        setBlockColor(26,led_strip_2.Color(ColorArray[3][1][0],ColorArray[3][1][1],ColorArray[3][1][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(26, 99, channel);  
        setBlockColor(27,led_strip_2.Color(ColorArray[3][2][0],ColorArray[3][2][1],ColorArray[3][2][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(27, 99, channel);  
        setBlockColor(28,led_strip_2.Color(ColorArray[3][3][0],ColorArray[3][3][1],ColorArray[3][3][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(28, 99, channel);
        setBlockColor(29,led_strip_2.Color(ColorArray[3][4][0],ColorArray[3][4][1],ColorArray[3][4][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(29, 99, channel);  
        setBlockColor(30,led_strip_2.Color(ColorArray[3][5][0],ColorArray[3][5][1],ColorArray[3][5][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(30, 99, channel);  
        setBlockColor(31,led_strip_2.Color(ColorArray[3][6][0],ColorArray[3][6][1],ColorArray[3][6][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(31, 99, channel);  
        setBlockColor(32,led_strip_2.Color(ColorArray[3][7][0],ColorArray[3][7][1],ColorArray[3][7][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(32, 99, channel);  
        setBlockColor(33,led_strip_3.Color(ColorArray[4][0][0],ColorArray[4][0][1],ColorArray[4][0][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(33, 99, channel);  
        setBlockColor(34,led_strip_3.Color(ColorArray[4][1][0],ColorArray[4][1][1],ColorArray[4][1][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(34, 99, channel);  
        setBlockColor(35,led_strip_3.Color(ColorArray[4][2][0],ColorArray[4][2][1],ColorArray[4][2][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(35, 99, channel);  
        setBlockColor(36,led_strip_3.Color(ColorArray[4][3][0],ColorArray[4][3][1],ColorArray[4][3][2]));
      }
      Serial.print(i); Serial.println(" touched on MPR 2");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched3 & _BV(i)) && (lasttouched3 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(24, 99, channel);  // 60 = C4
        setBlockColor(25,led_strip_2.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(25, 99, channel);  
        setBlockColor(26,led_strip_2.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(26, 99, channel);  
        setBlockColor(27,led_strip_2.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(27, 99, channel);  
        setBlockColor(28,led_strip_2.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(28, 99, channel);
        setBlockColor(29,led_strip_2.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(29, 99, channel);  
        setBlockColor(30,led_strip_2.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(30, 99, channel);  
        setBlockColor(31,led_strip_2.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(31, 99, channel);  
        setBlockColor(32,led_strip_2.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(32, 99, channel);  
        setBlockColor(33,led_strip_3.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(33, 99, channel);  
        setBlockColor(34,led_strip_3.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(34, 99, channel);  
        setBlockColor(35,led_strip_3.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(35, 99, channel);  
        setBlockColor(36,led_strip_3.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched4 & _BV(i)) && !(lasttouched4 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(36, 99, channel);  // 60 = C4
        setBlockColor(37,led_strip_3.Color(ColorArray[4][4][0],ColorArray[4][4][1],ColorArray[4][4][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(37, 99, channel);  
        setBlockColor(38,led_strip_3.Color(ColorArray[4][5][0],ColorArray[4][5][1],ColorArray[4][5][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(38, 99, channel);  
        setBlockColor(39,led_strip_3.Color(ColorArray[4][6][0],ColorArray[4][6][1],ColorArray[4][6][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(39, 99, channel);  
        setBlockColor(40,led_strip_3.Color(ColorArray[4][7][0],ColorArray[4][7][1],ColorArray[4][7][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(40, 99, channel);
        setBlockColor(41,led_strip_3.Color(ColorArray[5][0][0],ColorArray[5][0][1],ColorArray[5][0][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(41, 99, channel);  
        setBlockColor(42,led_strip_3.Color(ColorArray[5][1][0],ColorArray[5][1][1],ColorArray[5][1][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(42, 99, channel);  
        setBlockColor(43,led_strip_3.Color(ColorArray[5][2][0],ColorArray[5][2][1],ColorArray[5][2][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(43, 99, channel);  
        setBlockColor(44,led_strip_3.Color(ColorArray[5][3][0],ColorArray[5][3][1],ColorArray[5][3][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(44, 99, channel);  
        setBlockColor(45,led_strip_3.Color(ColorArray[5][4][0],ColorArray[5][4][1],ColorArray[5][4][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(45, 99, channel);  
        setBlockColor(46,led_strip_3.Color(ColorArray[5][5][0],ColorArray[5][5][1],ColorArray[5][5][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(46, 99, channel);  
        setBlockColor(47,led_strip_3.Color(ColorArray[5][6][0],ColorArray[5][6][1],ColorArray[5][6][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(47, 99, channel);  
        setBlockColor(48,led_strip_3.Color(ColorArray[5][7][0],ColorArray[5][7][1],ColorArray[5][7][2]));
      }
      Serial.print(i); Serial.println(" touched on MPR 3");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched4 & _BV(i)) && (lasttouched4 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(36, 99, channel);  // 60 = C4
        setBlockColor(37,led_strip_3.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(37, 99, channel);  
        setBlockColor(38,led_strip_3.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(38, 99, channel);  
        setBlockColor(39,led_strip_3.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(39, 99, channel);  
        setBlockColor(40,led_strip_3.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(40, 99, channel);
        setBlockColor(41,led_strip_3.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(41, 99, channel);  
        setBlockColor(42,led_strip_3.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(42, 99, channel);  
        setBlockColor(43,led_strip_3.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(43, 99, channel);  
        setBlockColor(44,led_strip_3.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(44, 99, channel);  
        setBlockColor(45,led_strip_3.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(45, 99, channel);  
        setBlockColor(46,led_strip_3.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(46, 99, channel);  
        setBlockColor(47,led_strip_3.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(47, 99, channel);  
        setBlockColor(48,led_strip_3.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched5 & _BV(i)) && !(lasttouched5 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(48, 99, channel);  // 60 = C4
        setBlockColor(49,led_strip_4.Color(ColorArray[6][0][0],ColorArray[6][0][1],ColorArray[6][0][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(49, 99, channel);  
        setBlockColor(50,led_strip_4.Color(ColorArray[6][1][0],ColorArray[6][1][1],ColorArray[6][1][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(50, 99, channel);  
        setBlockColor(51,led_strip_4.Color(ColorArray[6][2][0],ColorArray[6][2][1],ColorArray[6][2][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(51, 99, channel);  
        setBlockColor(52,led_strip_4.Color(ColorArray[6][3][0],ColorArray[6][3][1],ColorArray[6][3][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(52, 99, channel);
        setBlockColor(53,led_strip_4.Color(ColorArray[6][4][0],ColorArray[6][4][1],ColorArray[6][4][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(53, 99, channel);  
        setBlockColor(54,led_strip_4.Color(ColorArray[6][5][0],ColorArray[6][5][1],ColorArray[6][5][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(54, 99, channel);  
        setBlockColor(55,led_strip_4.Color(ColorArray[6][6][0],ColorArray[6][6][1],ColorArray[6][6][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(55, 99, channel);  
        setBlockColor(56,led_strip_4.Color(ColorArray[6][7][0],ColorArray[6][7][1],ColorArray[6][7][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(56, 99, channel);  
        setBlockColor(57,led_strip_4.Color(ColorArray[7][0][0],ColorArray[7][0][1],ColorArray[7][0][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(57, 99, channel);  
        setBlockColor(58,led_strip_4.Color(ColorArray[7][1][0],ColorArray[7][1][1],ColorArray[7][1][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(58, 99, channel);  
        setBlockColor(59,led_strip_4.Color(ColorArray[7][2][0],ColorArray[7][2][1],ColorArray[7][2][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(59, 99, channel);  
        setBlockColor(60,led_strip_4.Color(ColorArray[7][3][0],ColorArray[7][3][1],ColorArray[7][3][2]));
      }
      Serial.print(i); Serial.println(" touched on MPR 4");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched5 & _BV(i)) && (lasttouched5 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(48, 99, channel);  // 60 = C4
        setBlockColor(49,led_strip_4.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(49, 99, channel);  
        setBlockColor(50,led_strip_4.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(50, 99, channel);  
        setBlockColor(51,led_strip_4.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(51, 99, channel);  
        setBlockColor(52,led_strip_4.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(52, 99, channel);
        setBlockColor(53,led_strip_4.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(53, 99, channel);  
        setBlockColor(54,led_strip_4.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(54, 99, channel);  
        setBlockColor(55,led_strip_4.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(55, 99, channel);  
        setBlockColor(56,led_strip_4.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(56, 99, channel);  
        setBlockColor(57,led_strip_4.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(57, 99, channel);  
        setBlockColor(58,led_strip_4.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(58, 99, channel);  
        setBlockColor(59,led_strip_4.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(59, 99, channel);  
        setBlockColor(60,led_strip_4.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched6 & _BV(i)) && !(lasttouched6 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C4
        setBlockColor(61,led_strip_4.Color(ColorArray[7][4][0],ColorArray[7][4][1],ColorArray[7][4][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(61, 99, channel);  
        setBlockColor(62,led_strip_4.Color(ColorArray[7][5][0],ColorArray[7][5][1],ColorArray[7][5][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(62, 99, channel);  
        setBlockColor(63,led_strip_4.Color(ColorArray[7][6][0],ColorArray[7][6][1],ColorArray[7][6][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(63, 99, channel);  
        setBlockColor(64,led_strip_4.Color(ColorArray[7][7][0],ColorArray[7][7][1],ColorArray[7][7][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(64, 99, channel);
        setBlockColor(65,led_strip_5.Color(ColorArray[8][0][0],ColorArray[8][0][1],ColorArray[8][0][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(65, 99, channel);  
        setBlockColor(66,led_strip_5.Color(ColorArray[8][1][0],ColorArray[8][1][1],ColorArray[8][1][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(66, 99, channel);  
        setBlockColor(67,led_strip_5.Color(ColorArray[8][2][0],ColorArray[8][2][1],ColorArray[8][2][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(67, 99, channel);  
        setBlockColor(68,led_strip_5.Color(ColorArray[8][3][0],ColorArray[8][3][1],ColorArray[8][3][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(68, 99, channel);  
        setBlockColor(69,led_strip_5.Color(ColorArray[8][4][0],ColorArray[8][4][1],ColorArray[8][4][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(69, 99, channel);  
        setBlockColor(70,led_strip_5.Color(ColorArray[8][5][0],ColorArray[8][5][1],ColorArray[8][5][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(70, 99, channel);  
        setBlockColor(71,led_strip_5.Color(ColorArray[8][6][0],ColorArray[8][6][1],ColorArray[8][6][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(71, 99, channel);  
        setBlockColor(72,led_strip_5.Color(ColorArray[8][7][0],ColorArray[8][7][1],ColorArray[8][7][2]));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched6 & _BV(i)) && (lasttouched6 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(60, 99, channel);  // 60 = C4
        setBlockColor(61,led_strip_4.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(61, 99, channel);  
        setBlockColor(62,led_strip_4.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(62, 99, channel);  
        setBlockColor(63,led_strip_4.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(63, 99, channel);  
        setBlockColor(64,led_strip_4.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(64, 99, channel);
        setBlockColor(65,led_strip_5.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(65, 99, channel);  
        setBlockColor(66,led_strip_5.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(66, 99, channel);  
        setBlockColor(67,led_strip_5.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(67, 99, channel);  
        setBlockColor(68,led_strip_5.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(68, 99, channel);  
        setBlockColor(69,led_strip_5.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(69, 99, channel);  
        setBlockColor(70,led_strip_5.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(70, 99, channel);  
        setBlockColor(71,led_strip_5.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(71, 99, channel);  
        setBlockColor(72,led_strip_5.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched7 & _BV(i)) && !(lasttouched7 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(72, 99, channel);  // 60 = C4
        setBlockColor(73,led_strip_5.Color(ColorArray[9][0][0],ColorArray[9][0][1],ColorArray[9][0][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(73, 99, channel);  
        setBlockColor(74,led_strip_5.Color(ColorArray[9][1][0],ColorArray[9][1][1],ColorArray[9][1][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(74, 99, channel);  
        setBlockColor(75,led_strip_5.Color(ColorArray[9][2][0],ColorArray[9][2][1],ColorArray[9][2][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(75, 99, channel);  
        setBlockColor(76,led_strip_5.Color(ColorArray[9][3][0],ColorArray[9][3][1],ColorArray[9][3][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(76, 99, channel);
        setBlockColor(77,led_strip_5.Color(ColorArray[9][4][0],ColorArray[9][4][1],ColorArray[9][4][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(77, 99, channel);  
        setBlockColor(78,led_strip_5.Color(ColorArray[9][5][0],ColorArray[9][5][1],ColorArray[9][5][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(78, 99, channel);  
        setBlockColor(79,led_strip_5.Color(ColorArray[9][6][0],ColorArray[9][6][1],ColorArray[9][6][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(79, 99, channel);  
        setBlockColor(80,led_strip_5.Color(ColorArray[9][7][0],ColorArray[9][7][1],ColorArray[9][7][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(80, 99, channel);  
        setBlockColor(81,led_strip_5.Color(ColorArray[10][0][0],ColorArray[10][0][1],ColorArray[10][0][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(81, 99, channel);  
        setBlockColor(82,led_strip_5.Color(ColorArray[10][1][0],ColorArray[10][1][1],ColorArray[10][1][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(82, 99, channel);  
        setBlockColor(83,led_strip_5.Color(ColorArray[10][2][0],ColorArray[10][2][1],ColorArray[10][2][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(83, 99, channel);  
        setBlockColor(84,led_strip_5.Color(ColorArray[10][3][0],ColorArray[10][3][1],ColorArray[10][3][2]));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched7 & _BV(i)) && (lasttouched7 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(72, 99, channel);  // 60 = C4
        setBlockColor(73,led_strip_5.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(73, 99, channel);  
        setBlockColor(74,led_strip_5.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(74, 99, channel);  
        setBlockColor(75,led_strip_5.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(75, 99, channel);  
        setBlockColor(76,led_strip_5.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(76, 99, channel);
        setBlockColor(77,led_strip_5.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(77, 99, channel);  
        setBlockColor(78,led_strip_5.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(78, 99, channel);  
        setBlockColor(79,led_strip_5.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(79, 99, channel);  
        setBlockColor(80,led_strip_5.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(80, 99, channel);  
        setBlockColor(81,led_strip_5.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(81, 99, channel);  
        setBlockColor(82,led_strip_5.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(82, 99, channel);  
        setBlockColor(83,led_strip_5.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(83, 99, channel);  
        setBlockColor(84,led_strip_5.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched8 & _BV(i)) && !(lasttouched8 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(84, 99, channel);  // 60 = C4
        setBlockColor(85,led_strip_5.Color(ColorArray[10][4][0],ColorArray[10][4][1],ColorArray[10][4][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(85, 99, channel);  
        setBlockColor(86,led_strip_5.Color(ColorArray[10][5][0],ColorArray[10][5][1],ColorArray[10][5][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(86, 99, channel);  
        setBlockColor(87,led_strip_5.Color(ColorArray[10][6][0],ColorArray[10][6][1],ColorArray[10][6][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(87, 99, channel);  
        setBlockColor(88,led_strip_5.Color(ColorArray[10][7][0],ColorArray[10][7][1],ColorArray[10][7][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(88, 99, channel);
        setBlockColor(89,led_strip_6.Color(ColorArray[11][0][0],ColorArray[11][0][1],ColorArray[11][0][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(89, 99, channel);  
        setBlockColor(90,led_strip_6.Color(ColorArray[11][1][0],ColorArray[11][1][1],ColorArray[11][1][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(90, 99, channel);  
        setBlockColor(91,led_strip_6.Color(ColorArray[11][2][0],ColorArray[11][2][1],ColorArray[11][2][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(91, 99, channel);  
        setBlockColor(92,led_strip_6.Color(ColorArray[11][3][0],ColorArray[11][3][1],ColorArray[11][3][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(92, 99, channel);  
        setBlockColor(93,led_strip_6.Color(ColorArray[11][4][0],ColorArray[11][4][1],ColorArray[11][4][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(93, 99, channel);  
        setBlockColor(94,led_strip_6.Color(ColorArray[11][5][0],ColorArray[11][5][1],ColorArray[11][5][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(94, 99, channel);  
        setBlockColor(95,led_strip_6.Color(ColorArray[11][6][0],ColorArray[11][6][1],ColorArray[11][6][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(95, 99, channel);  
        setBlockColor(96,led_strip_6.Color(ColorArray[11][7][0],ColorArray[11][7][1],ColorArray[11][7][2]));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched8 & _BV(i)) && (lasttouched8 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(84, 99, channel);  // 60 = C4
        setBlockColor(85,led_strip_5.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(85, 99, channel);  
        setBlockColor(86,led_strip_5.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(86, 99, channel);  
        setBlockColor(87,led_strip_5.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(87, 99, channel);  
        setBlockColor(88,led_strip_5.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(88, 99, channel);
        setBlockColor(89,led_strip_6.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(89, 99, channel);  
        setBlockColor(90,led_strip_6.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(90, 99, channel);  
        setBlockColor(91,led_strip_6.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(91, 99, channel);  
        setBlockColor(92,led_strip_6.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(92, 99, channel);  
        setBlockColor(93,led_strip_6.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(93, 99, channel);  
        setBlockColor(94,led_strip_6.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(94, 99, channel);  
        setBlockColor(95,led_strip_6.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(95, 99, channel);  
        setBlockColor(96,led_strip_6.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched9 & _BV(i)) && !(lasttouched9 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(96, 99, channel);  // 60 = C4
        setBlockColor(97,led_strip_6.Color(ColorArray[12][0][0],ColorArray[12][0][1],ColorArray[12][0][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(97, 99, channel);  
        setBlockColor(98,led_strip_6.Color(ColorArray[12][1][0],ColorArray[12][1][1],ColorArray[12][1][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(98, 99, channel);  
        setBlockColor(99,led_strip_6.Color(ColorArray[12][2][0],ColorArray[12][2][1],ColorArray[12][2][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(99, 99, channel);  
        setBlockColor(100,led_strip_6.Color(ColorArray[12][3][0],ColorArray[12][3][1],ColorArray[12][3][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(100, 99, channel);
        setBlockColor(101,led_strip_6.Color(ColorArray[12][4][0],ColorArray[12][4][1],ColorArray[12][4][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(101, 99, channel);  
        setBlockColor(102,led_strip_6.Color(ColorArray[12][5][0],ColorArray[12][5][1],ColorArray[12][5][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(102, 99, channel);  
        setBlockColor(103,led_strip_6.Color(ColorArray[12][6][0],ColorArray[12][6][1],ColorArray[12][6][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(103, 99, channel);  
        setBlockColor(104,led_strip_6.Color(ColorArray[12][7][0],ColorArray[12][7][1],ColorArray[12][7][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(104, 99, channel);  
        setBlockColor(105,led_strip_7.Color(ColorArray[13][0][0],ColorArray[13][0][1],ColorArray[13][0][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(105, 99, channel);  
        setBlockColor(106,led_strip_7.Color(ColorArray[13][1][0],ColorArray[13][1][1],ColorArray[13][1][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(106, 99, channel);  
        setBlockColor(107,led_strip_7.Color(ColorArray[13][2][0],ColorArray[13][2][1],ColorArray[13][2][2]));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched9 & _BV(i)) && (lasttouched9 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(96, 99, channel);  // 60 = C4
        setBlockColor(97,led_strip_6.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(97, 99, channel);  
        setBlockColor(98,led_strip_6.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(98, 99, channel);  
        setBlockColor(99,led_strip_6.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(99, 99, channel);  
        setBlockColor(100,led_strip_6.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(100, 99, channel);
        setBlockColor(101,led_strip_6.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(101, 99, channel);  
        setBlockColor(102,led_strip_6.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(102, 99, channel);  
        setBlockColor(103,led_strip_6.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(103, 99, channel);  
        setBlockColor(104,led_strip_6.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(104, 99, channel);  
        setBlockColor(105,led_strip_7.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(105, 99, channel);  
        setBlockColor(106,led_strip_7.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(106, 99, channel);  
        setBlockColor(107,led_strip_7.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched10 & _BV(i)) && !(lasttouched10 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(107, 99, channel);  // 60 = C4
        setBlockColor(108,led_strip_7.Color(ColorArray[13][3][0],ColorArray[13][3][1],ColorArray[13][3][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(108, 99, channel);  
        setBlockColor(109,led_strip_7.Color(ColorArray[13][4][0],ColorArray[13][4][1],ColorArray[13][4][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(109, 99, channel);  
        setBlockColor(110,led_strip_7.Color(ColorArray[13][5][0],ColorArray[13][5][1],ColorArray[13][5][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(110, 99, channel);  
        setBlockColor(111,led_strip_7.Color(ColorArray[13][6][0],ColorArray[13][6][1],ColorArray[13][6][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(111, 99, channel);
        setBlockColor(112,led_strip_7.Color(ColorArray[13][7][0],ColorArray[13][7][1],ColorArray[13][7][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(112, 99, channel);  
        setBlockColor(113,led_strip_7.Color(ColorArray[14][0][0],ColorArray[14][0][1],ColorArray[14][0][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(113, 99, channel);  
        setBlockColor(114,led_strip_7.Color(ColorArray[14][1][0],ColorArray[14][1][1],ColorArray[14][1][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(114, 99, channel);  
        setBlockColor(115,led_strip_7.Color(ColorArray[14][2][0],ColorArray[14][2][1],ColorArray[14][2][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(115, 99, channel);  
        setBlockColor(116,led_strip_7.Color(ColorArray[14][3][0],ColorArray[14][3][1],ColorArray[14][3][2]));
      }
      if(i==2) {
        usbMIDI.sendNoteOn(116, 99, channel);  
        setBlockColor(117,led_strip_7.Color(ColorArray[14][4][0],ColorArray[14][4][1],ColorArray[14][4][2]));
      }
      if(i==1) {
        usbMIDI.sendNoteOn(117, 99, channel);  
        setBlockColor(118,led_strip_7.Color(ColorArray[14][5][0],ColorArray[14][5][1],ColorArray[14][5][2]));
      }
      if(i==0) {
        usbMIDI.sendNoteOn(118, 99, channel);  
        setBlockColor(119,led_strip_7.Color(ColorArray[14][6][0],ColorArray[14][6][1],ColorArray[14][6][2]));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched10 & _BV(i)) && (lasttouched10 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(107, 99, channel);  // 60 = C4
        setBlockColor(108,led_strip_7.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(108, 99, channel);  
        setBlockColor(109,led_strip_7.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(109, 99, channel);  
        setBlockColor(110,led_strip_7.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(110, 99, channel);  
        setBlockColor(111,led_strip_7.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(111, 99, channel);
        setBlockColor(112,led_strip_7.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(112, 99, channel);  
        setBlockColor(113,led_strip_7.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(113, 99, channel);  
        setBlockColor(114,led_strip_7.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(114, 99, channel);  
        setBlockColor(115,led_strip_7.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(115, 99, channel);  
        setBlockColor(116,led_strip_7.Color(0,0,0));
      }
      if(i==2) {
        usbMIDI.sendNoteOff(116, 99, channel);  
        setBlockColor(117,led_strip_7.Color(0,0,0));
      }
      if(i==1) {
        usbMIDI.sendNoteOff(117, 99, channel);  
        setBlockColor(118,led_strip_7.Color(0,0,0));
      }
      if(i==0) {
        usbMIDI.sendNoteOff(118, 99, channel);  
        setBlockColor(119,led_strip_7.Color(0,0,0));
      }
      Serial.print(i); Serial.println(" released");
    }
    if ((currtouched11 & _BV(i)) && !(lasttouched11 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOn(119, 99, channel);  // 60 = C4
        setBlockColor(120,led_strip_8.Color(ColorArray[14][7][0],ColorArray[14][7][1],ColorArray[14][7][2]));
      }
      if(i==10) {
        usbMIDI.sendNoteOn(120, 99, channel);  
        setBlockColor(121,led_strip_8.Color(ColorArray[15][0][0],ColorArray[15][0][1],ColorArray[15][0][2]));
      }
      if(i==9) {
        usbMIDI.sendNoteOn(121, 99, channel);  
        setBlockColor(122,led_strip_8.Color(ColorArray[15][1][0],ColorArray[15][1][1],ColorArray[15][1][2]));
      }
      if(i==8) {
        usbMIDI.sendNoteOn(122, 99, channel);  
        setBlockColor(123,led_strip_8.Color(ColorArray[15][2][0],ColorArray[15][2][1],ColorArray[15][2][2]));
      }
      if(i==7) {
        usbMIDI.sendNoteOn(123, 99, channel);
        // TODO
        // Change this for after the demo
        if(channel==1) {
          channel = 2;
        }
        else {
          channel = 1;
        }
        setBlockColor(124,led_strip_8.Color(ColorArray[15][3][0],ColorArray[15][3][1],ColorArray[15][3][2])); 
      }
      if(i==6) {
        usbMIDI.sendNoteOn(124, 99, channel);  
        setBlockColor(125,led_strip_8.Color(ColorArray[15][4][0],ColorArray[15][4][1],ColorArray[15][4][2]));
      }
      if(i==5) {
        usbMIDI.sendNoteOn(125, 99, channel);  
        setBlockColor(126,led_strip_8.Color(ColorArray[15][5][0],ColorArray[15][5][1],ColorArray[15][5][2]));
      }
      if(i==4) {
        usbMIDI.sendNoteOn(126, 99, channel);  
        setBlockColor(127,led_strip_8.Color(ColorArray[15][6][0],ColorArray[15][6][1],ColorArray[15][6][2]));
      }
      if(i==3) {
        usbMIDI.sendNoteOn(127, 99, channel);  
        setBlockColor(128,led_strip_8.Color(ColorArray[15][7][0],ColorArray[15][7][1],ColorArray[15][7][2]));
      }
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched11 & _BV(i)) && (lasttouched11 & _BV(i)) ) {
      if(i==11) {
        usbMIDI.sendNoteOff(119, 99, channel);  // 60 = C4
        setBlockColor(120,led_strip_8.Color(0,0,0));
      }
      if(i==10) {
        usbMIDI.sendNoteOff(120, 99, channel);  
        setBlockColor(121,led_strip_8.Color(0,0,0));
      }
      if(i==9) {
        usbMIDI.sendNoteOff(121, 99, channel);  
        setBlockColor(122,led_strip_8.Color(0,0,0));
      }
      if(i==8) {
        usbMIDI.sendNoteOff(122, 99, channel);  
        setBlockColor(123,led_strip_8.Color(0,0,0));
      }
      if(i==7) {
        usbMIDI.sendNoteOff(123, 99, channel);
        setBlockColor(124,led_strip_8.Color(0,0,0)); 
      }
      if(i==6) {
        usbMIDI.sendNoteOff(124, 99, channel);  
        setBlockColor(125,led_strip_8.Color(0,0,0));
      }
      if(i==5) {
        usbMIDI.sendNoteOff(125, 99, channel);  
        setBlockColor(126,led_strip_8.Color(0,0,0));
      }
      if(i==4) {
        usbMIDI.sendNoteOff(126, 99, channel);  
        setBlockColor(127,led_strip_8.Color(0,0,0));
      }
      if(i==3) {
        usbMIDI.sendNoteOff(127, 99, channel);  
        setBlockColor(128,led_strip_8.Color(0,0,0));
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
void out32()
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
void out30()
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
void out38()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out39()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out40()
{
 digitalWrite (EN_3, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_3.show();
}
void out37()
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
void out69() {
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out68()
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
void out66()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_5.show();
}
void out65()
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
void out77()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out76()
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
void out74()
{
 digitalWrite (EN_5, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_5.show();
}
void out73()
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
void out85() {
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out84()
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
void out82()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_6.show();
}
void out81()
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
void out93()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out92()
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
void out90()
{
 digitalWrite (EN_6, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_6.show();
}
void out89()
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
void out101() {
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out100()
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
void out98()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out97()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out104()
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
void out102()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_7.show();
}
void out109()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out108()
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
void out106()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out105()
{
 digitalWrite (EN_7, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_7.show();
}
void out112()
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
void out110()
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
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out114()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
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
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out117()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out118()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
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
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, LOW);
 led_strip_8.show();
}
void out121()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, HIGH);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out122()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
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
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out125()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, LOW);
 digitalWrite (S1, LOW);
 digitalWrite (S2, LOW);
 digitalWrite (S3, HIGH);
 led_strip_8.show();
}
void out126()
{
 digitalWrite (EN_8, LOW);
 digitalWrite (S0, HIGH);
 digitalWrite (S1, HIGH);
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
 digitalWrite (S1, LOW);
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
      out30();
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
      out32();
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
      break;
    case 65:
      out65();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 66:
      out66();
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
      out68();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 69:
      out69();
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
      out73();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 74:
      out74();
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
      out76();
      for(int i=0;i<7;i++) {
        led_strip_5.setPixelColor(i, color);
      }
      led_strip_5.show();
      break;
    case 77:
      out77();
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
      out81();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 82:
      out82();
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
      out84();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 85:
      out85();
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
      out89();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 90:
      out90();
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
      out92();
      for(int i=0;i<7;i++) {
        led_strip_6.setPixelColor(i, color);
      }
      led_strip_6.show();
      break;
    case 93:
      out93();
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
      out97();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 98:
      out98();
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
      out100();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 101:
      out101();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 102:
      out102();
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
      out104();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 105:
      out105();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 106:
      out106();
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
      out108();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 109:
      out109();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 110:
      out110();
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
      out112();
      for(int i=0;i<7;i++) {
        led_strip_7.setPixelColor(i, color);
      }
      led_strip_7.show();
      break;
    case 113:
      out113();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 114:
      out114();
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
      out116();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 117:
      out117();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 118:
      out118();
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
      out120();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 121:
      out121();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 122:
      out122();
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
      out124();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 125:
      out125();
      for(int i=0;i<7;i++) {
        led_strip_8.setPixelColor(i, color);
      }
      led_strip_8.show();
      break;
    case 126:
      out126();
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
      out128();
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

void testBluetoothLEDLoop() {
//  for(int i=1;i<=128;i++) {
//    setBlockColor(i,led_strip_1.Color(255,30,0));
//    delay(10);
//  }
//  for(int i=1;i<=128;i++) {
//    setBlockColor(i,led_strip_1.Color(0,0,0));
//  }
//
//  for(int i=128;i>=1;i--) {
//    setBlockColor(i,led_strip_1.Color(0,100,255));
//    delay(10);
//  }
//  for(int i=128;i>=1;i--) {
//    setBlockColor(i,led_strip_1.Color(0,0,0));
//  }
//
//  for(int i=1;i<=128;i++) {
//    setBlockColor(i,led_strip_1.Color(255,0,0));
//    delay(10);
//  }
//  for(int i=1;i<=128;i++) {
//    setBlockColor(i,led_strip_1.Color(0,0,0));
//  }

  
  setBlockColor(17,led_strip_1.Color(253,86,0));
  setBlockColor(18,led_strip_1.Color(253,86,0));
  setBlockColor(19,led_strip_1.Color(253,86,0));
  setBlockColor(20,led_strip_1.Color(253,86,0));
  setBlockColor(21,led_strip_1.Color(253,86,0));
  setBlockColor(22,led_strip_1.Color(253,86,0));
  setBlockColor(23,led_strip_1.Color(253,86,0));
  setBlockColor(24,led_strip_1.Color(253,86,0));
  setBlockColor(28,led_strip_1.Color(253,86,0));
  setBlockColor(29,led_strip_1.Color(253,86,0));
  setBlockColor(36,led_strip_1.Color(253,86,0));
  setBlockColor(37,led_strip_1.Color(253,86,0));
  setBlockColor(41,led_strip_1.Color(253,86,0));
  setBlockColor(42,led_strip_1.Color(253,86,0));
  setBlockColor(43,led_strip_1.Color(253,86,0));
  setBlockColor(44,led_strip_1.Color(253,86,0));
  setBlockColor(45,led_strip_1.Color(253,86,0));
  setBlockColor(46,led_strip_1.Color(253,86,0));
  setBlockColor(47,led_strip_1.Color(253,86,0));
  setBlockColor(48,led_strip_1.Color(253,86,0));
  setBlockColor(57,led_strip_1.Color(253,86,0));
  setBlockColor(58,led_strip_1.Color(253,86,0));
  setBlockColor(59,led_strip_1.Color(253,86,0));
  setBlockColor(60,led_strip_1.Color(253,86,0));
  setBlockColor(61,led_strip_1.Color(253,86,0));
  setBlockColor(62,led_strip_1.Color(253,86,0));
  setBlockColor(63,led_strip_1.Color(253,86,0));
  setBlockColor(64,led_strip_1.Color(253,86,0));
  setBlockColor(65,led_strip_1.Color(253,86,0));
  setBlockColor(68,led_strip_1.Color(253,86,0));
  setBlockColor(72,led_strip_1.Color(253,86,0));
  setBlockColor(73,led_strip_1.Color(253,86,0));
  setBlockColor(76,led_strip_1.Color(253,86,0));
  setBlockColor(80,led_strip_1.Color(253,86,0));
  setBlockColor(89,led_strip_1.Color(253,86,0));
  setBlockColor(98,led_strip_1.Color(253,86,0));
  setBlockColor(107,led_strip_1.Color(253,86,0));
  setBlockColor(108,led_strip_1.Color(253,86,0));
  setBlockColor(109,led_strip_1.Color(253,86,0));
  setBlockColor(110,led_strip_1.Color(253,86,0));
  setBlockColor(111,led_strip_1.Color(253,86,0));
  setBlockColor(112,led_strip_1.Color(253,86,0));
  setBlockColor(114,led_strip_1.Color(253,86,0));
  setBlockColor(121,led_strip_1.Color(253,86,0));
  delay(7000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
}

void setMidiWord() {
  
  setBlockColor(1,led_strip_1.Color(255,92,0));
  setBlockColor(2,led_strip_1.Color(255,92,0));
  setBlockColor(3,led_strip_1.Color(255,92,0));
  setBlockColor(4,led_strip_1.Color(255,92,0));
  setBlockColor(5,led_strip_1.Color(255,92,0));
  setBlockColor(6,led_strip_1.Color(255,92,0));
  setBlockColor(7,led_strip_1.Color(255,92,0));
  setBlockColor(8,led_strip_1.Color(255,92,0));
  setBlockColor(10,led_strip_1.Color(255,92,0));
  setBlockColor(19,led_strip_1.Color(255,92,0));
  setBlockColor(20,led_strip_1.Color(255,92,0));
  setBlockColor(26,led_strip_1.Color(255,92,0));
  setBlockColor(33,led_strip_1.Color(255,92,0));
  setBlockColor(34,led_strip_1.Color(255,92,0));
  setBlockColor(35,led_strip_1.Color(255,92,0));
  setBlockColor(36,led_strip_1.Color(255,92,0));
  setBlockColor(37,led_strip_1.Color(255,92,0));
  setBlockColor(38,led_strip_1.Color(255,92,0));
  setBlockColor(39,led_strip_1.Color(255,92,0));
  setBlockColor(40,led_strip_1.Color(255,92,0));
  setBlockColor(49,led_strip_1.Color(255,92,0));
  setBlockColor(50,led_strip_1.Color(255,92,0));
  setBlockColor(51,led_strip_1.Color(255,92,0));
  setBlockColor(52,led_strip_1.Color(255,92,0));
  setBlockColor(53,led_strip_1.Color(255,92,0));
  setBlockColor(54,led_strip_1.Color(255,92,0));
  setBlockColor(55,led_strip_1.Color(255,92,0));
  setBlockColor(56,led_strip_1.Color(255,92,0));
  setBlockColor(65,led_strip_1.Color(255,92,0));
  setBlockColor(66,led_strip_1.Color(255,92,0));
  setBlockColor(67,led_strip_1.Color(255,92,0));
  setBlockColor(68,led_strip_1.Color(255,92,0));
  setBlockColor(69,led_strip_1.Color(255,92,0));
  setBlockColor(70,led_strip_1.Color(255,92,0));
  setBlockColor(71,led_strip_1.Color(255,92,0));
  setBlockColor(72,led_strip_1.Color(255,92,0));
  setBlockColor(73,led_strip_1.Color(255,92,0));
  setBlockColor(80,led_strip_1.Color(255,92,0));
  setBlockColor(82,led_strip_1.Color(255,92,0));
  setBlockColor(87,led_strip_1.Color(255,92,0));
  setBlockColor(91,led_strip_1.Color(255,92,0));
  setBlockColor(92,led_strip_1.Color(255,92,0));
  setBlockColor(93,led_strip_1.Color(255,92,0));
  setBlockColor(94,led_strip_1.Color(255,92,0));
  setBlockColor(105,led_strip_1.Color(255,92,0));
  setBlockColor(106,led_strip_1.Color(255,92,0));
  setBlockColor(107,led_strip_1.Color(255,92,0));
  setBlockColor(108,led_strip_1.Color(255,92,0));
  setBlockColor(109,led_strip_1.Color(255,92,0));
  setBlockColor(110,led_strip_1.Color(255,92,0));
  setBlockColor(111,led_strip_1.Color(255,92,0));
  setBlockColor(112,led_strip_1.Color(255,92,0));
}

void demo4th() {
  //H
  
  setBlockColor(49,led_strip_1.Color(255,255,255));
  setBlockColor(50,led_strip_1.Color(255,255,255));
  setBlockColor(51,led_strip_1.Color(255,255,255));
  setBlockColor(52,led_strip_1.Color(255,255,255));
  setBlockColor(53,led_strip_1.Color(255,255,255));
  setBlockColor(54,led_strip_1.Color(255,255,255));
  setBlockColor(55,led_strip_1.Color(255,255,255));
  setBlockColor(56,led_strip_1.Color(255,255,255));
  setBlockColor(60,led_strip_1.Color(255,255,255));
  setBlockColor(61,led_strip_1.Color(255,255,255));
  setBlockColor(68,led_strip_1.Color(255,255,255));
  setBlockColor(69,led_strip_1.Color(255,255,255));
  setBlockColor(73,led_strip_1.Color(255,255,255));
  setBlockColor(74,led_strip_1.Color(255,255,255));
  setBlockColor(75,led_strip_1.Color(255,255,255));
  setBlockColor(76,led_strip_1.Color(255,255,255));
  setBlockColor(77,led_strip_1.Color(255,255,255));
  setBlockColor(78,led_strip_1.Color(255,255,255));
  setBlockColor(79,led_strip_1.Color(255,255,255));
  setBlockColor(80,led_strip_1.Color(255,255,255));
  delay(800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  //A
  
  setBlockColor(50,led_strip_1.Color(0,88,255));
  setBlockColor(51,led_strip_1.Color(0,88,255));
  setBlockColor(52,led_strip_1.Color(0,88,255));
  setBlockColor(53,led_strip_1.Color(0,88,255));
  setBlockColor(54,led_strip_1.Color(0,88,255));
  setBlockColor(55,led_strip_1.Color(0,88,255));
  setBlockColor(56,led_strip_1.Color(0,88,255));
  setBlockColor(57,led_strip_1.Color(0,88,255));
  setBlockColor(61,led_strip_1.Color(0,88,255));
  setBlockColor(66,led_strip_1.Color(0,88,255));
  setBlockColor(67,led_strip_1.Color(0,88,255));
  setBlockColor(68,led_strip_1.Color(0,88,255));
  setBlockColor(69,led_strip_1.Color(0,88,255));
  setBlockColor(70,led_strip_1.Color(0,88,255));
  setBlockColor(71,led_strip_1.Color(0,88,255));
  setBlockColor(72,led_strip_1.Color(0,88,255));
  delay(800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // P
  
  setBlockColor(57,led_strip_1.Color(255,0,0));
  setBlockColor(58,led_strip_1.Color(255,0,0));
  setBlockColor(59,led_strip_1.Color(255,0,0));
  setBlockColor(60,led_strip_1.Color(255,0,0));
  setBlockColor(61,led_strip_1.Color(255,0,0));
  setBlockColor(62,led_strip_1.Color(255,0,0));
  setBlockColor(63,led_strip_1.Color(255,0,0));
  setBlockColor(64,led_strip_1.Color(255,0,0));
  setBlockColor(65,led_strip_1.Color(255,0,0));
  setBlockColor(67,led_strip_1.Color(255,0,0));
  setBlockColor(73,led_strip_1.Color(255,0,0));
  setBlockColor(74,led_strip_1.Color(255,0,0));
  setBlockColor(75,led_strip_1.Color(255,0,0));
  delay(800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // P
  setBlockColor(57,led_strip_1.Color(255,255,255));
  setBlockColor(58,led_strip_1.Color(255,255,255));
  setBlockColor(59,led_strip_1.Color(255,255,255));
  setBlockColor(60,led_strip_1.Color(255,255,255));
  setBlockColor(61,led_strip_1.Color(255,255,255));
  setBlockColor(62,led_strip_1.Color(255,255,255));
  setBlockColor(63,led_strip_1.Color(255,255,255));
  setBlockColor(64,led_strip_1.Color(255,255,255));
  setBlockColor(65,led_strip_1.Color(255,255,255));
  setBlockColor(67,led_strip_1.Color(255,255,255));
  setBlockColor(73,led_strip_1.Color(255,255,255));
  setBlockColor(74,led_strip_1.Color(255,255,255));
  setBlockColor(75,led_strip_1.Color(255,255,255));
  delay(800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // Y
  
  setBlockColor(49,led_strip_1.Color(0,88,255));
  setBlockColor(50,led_strip_1.Color(0,88,255));
  setBlockColor(51,led_strip_1.Color(0,88,255));
  setBlockColor(59,led_strip_1.Color(0,88,255));
  setBlockColor(60,led_strip_1.Color(0,88,255));
  setBlockColor(61,led_strip_1.Color(0,88,255));
  setBlockColor(62,led_strip_1.Color(0,88,255));
  setBlockColor(63,led_strip_1.Color(0,88,255));
  setBlockColor(64,led_strip_1.Color(0,88,255));
  setBlockColor(65,led_strip_1.Color(0,88,255));
  setBlockColor(66,led_strip_1.Color(0,88,255));
  setBlockColor(67,led_strip_1.Color(0,88,255));
  delay(1000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // 4th
  
  setBlockColor(33,led_strip_1.Color(255,0,0));
  setBlockColor(34,led_strip_1.Color(255,0,0));
  setBlockColor(35,led_strip_1.Color(255,0,0));
  setBlockColor(43,led_strip_1.Color(255,0,0));
  setBlockColor(49,led_strip_1.Color(255,0,0));
  setBlockColor(50,led_strip_1.Color(255,0,0));
  setBlockColor(51,led_strip_1.Color(255,0,0));
  setBlockColor(52,led_strip_1.Color(255,0,0));
  setBlockColor(53,led_strip_1.Color(255,0,0));
  setBlockColor(54,led_strip_1.Color(255,0,0));
  setBlockColor(55,led_strip_1.Color(255,0,0));
  setBlockColor(56,led_strip_1.Color(255,0,0));
  setBlockColor(66,led_strip_1.Color(255,0,0));
  setBlockColor(73,led_strip_1.Color(255,0,0));
  setBlockColor(74,led_strip_1.Color(255,0,0));
  setBlockColor(75,led_strip_1.Color(255,0,0));
  setBlockColor(76,led_strip_1.Color(255,0,0));
  setBlockColor(82,led_strip_1.Color(255,0,0));
  setBlockColor(97,led_strip_1.Color(255,0,0));
  setBlockColor(98,led_strip_1.Color(255,0,0));
  setBlockColor(99,led_strip_1.Color(255,0,0));
  setBlockColor(100,led_strip_1.Color(255,0,0));
  setBlockColor(107,led_strip_1.Color(255,0,0));
  setBlockColor(115,led_strip_1.Color(255,0,0));
  setBlockColor(116,led_strip_1.Color(255,0,0));
  delay(2200);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  //From
  
  setBlockColor(1,led_strip_1.Color(255,255,255));
  setBlockColor(2,led_strip_1.Color(255,255,255));
  setBlockColor(3,led_strip_1.Color(255,255,255));
  setBlockColor(4,led_strip_1.Color(255,255,255));
  setBlockColor(5,led_strip_1.Color(255,255,255));
  setBlockColor(6,led_strip_1.Color(255,255,255));
  setBlockColor(7,led_strip_1.Color(255,255,255));
  setBlockColor(8,led_strip_1.Color(255,255,255));
  setBlockColor(9,led_strip_1.Color(255,255,255));
  setBlockColor(11,led_strip_1.Color(255,255,255));
  setBlockColor(17,led_strip_1.Color(255,255,255));
  setBlockColor(19,led_strip_1.Color(255,255,255));
  setBlockColor(33,led_strip_1.Color(255,255,255));
  setBlockColor(34,led_strip_1.Color(255,255,255));
  setBlockColor(35,led_strip_1.Color(255,255,255));
  setBlockColor(36,led_strip_1.Color(255,255,255));
  setBlockColor(37,led_strip_1.Color(255,255,255));
  setBlockColor(38,led_strip_1.Color(255,255,255));
  setBlockColor(39,led_strip_1.Color(255,255,255));
  setBlockColor(40,led_strip_1.Color(255,255,255));
  setBlockColor(41,led_strip_1.Color(255,255,255));
  setBlockColor(44,led_strip_1.Color(255,255,255));
  setBlockColor(45,led_strip_1.Color(255,255,255));
  setBlockColor(49,led_strip_1.Color(255,255,255));
  setBlockColor(52,led_strip_1.Color(255,255,255));
  setBlockColor(54,led_strip_1.Color(255,255,255));
  setBlockColor(57,led_strip_1.Color(255,255,255));
  setBlockColor(58,led_strip_1.Color(255,255,255));
  setBlockColor(59,led_strip_1.Color(255,255,255));
  setBlockColor(60,led_strip_1.Color(255,255,255));
  setBlockColor(63,led_strip_1.Color(255,255,255));
  setBlockColor(64,led_strip_1.Color(255,255,255));
  setBlockColor(73,led_strip_1.Color(255,255,255));
  setBlockColor(74,led_strip_1.Color(255,255,255));
  setBlockColor(75,led_strip_1.Color(255,255,255));
  setBlockColor(76,led_strip_1.Color(255,255,255));
  setBlockColor(77,led_strip_1.Color(255,255,255));
  setBlockColor(78,led_strip_1.Color(255,255,255));
  setBlockColor(79,led_strip_1.Color(255,255,255));
  setBlockColor(80,led_strip_1.Color(255,255,255));
  setBlockColor(81,led_strip_1.Color(255,255,255));
  setBlockColor(88,led_strip_1.Color(255,255,255));
  setBlockColor(89,led_strip_1.Color(255,255,255));
  setBlockColor(90,led_strip_1.Color(255,255,255));
  setBlockColor(91,led_strip_1.Color(255,255,255));
  setBlockColor(92,led_strip_1.Color(255,255,255));
  setBlockColor(93,led_strip_1.Color(255,255,255));
  setBlockColor(94,led_strip_1.Color(255,255,255));
  setBlockColor(95,led_strip_1.Color(255,255,255));
  setBlockColor(96,led_strip_1.Color(255,255,255));
  setBlockColor(105,led_strip_1.Color(255,255,255));
  setBlockColor(106,led_strip_1.Color(255,255,255));
  setBlockColor(107,led_strip_1.Color(255,255,255));
  setBlockColor(108,led_strip_1.Color(255,255,255));
  setBlockColor(109,led_strip_1.Color(255,255,255));
  setBlockColor(110,led_strip_1.Color(255,255,255));
  setBlockColor(111,led_strip_1.Color(255,255,255));
  setBlockColor(112,led_strip_1.Color(255,255,255));
  setBlockColor(114,led_strip_1.Color(255,255,255));
  setBlockColor(121,led_strip_1.Color(255,255,255));
  setBlockColor(122,led_strip_1.Color(255,255,255));
  setBlockColor(123,led_strip_1.Color(255,255,255));
  setBlockColor(124,led_strip_1.Color(255,255,255));
  setBlockColor(125,led_strip_1.Color(255,255,255));
  setBlockColor(126,led_strip_1.Color(255,255,255));
  setBlockColor(127,led_strip_1.Color(255,255,255));
  setBlockColor(128,led_strip_1.Color(255,255,255));
  delay(2500);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // THE
  setBlockColor(9,led_strip_1.Color(0,88,255));
  setBlockColor(17,led_strip_1.Color(0,88,255));
  setBlockColor(25,led_strip_1.Color(0,88,255));
  setBlockColor(26,led_strip_1.Color(0,88,255));
  setBlockColor(27,led_strip_1.Color(0,88,255));
  setBlockColor(28,led_strip_1.Color(0,88,255));
  setBlockColor(29,led_strip_1.Color(0,88,255));
  setBlockColor(30,led_strip_1.Color(0,88,255));
  setBlockColor(31,led_strip_1.Color(0,88,255));
  setBlockColor(32,led_strip_1.Color(0,88,255));
  setBlockColor(33,led_strip_1.Color(0,88,255));
  setBlockColor(49,led_strip_1.Color(0,88,255));
  setBlockColor(50,led_strip_1.Color(0,88,255));
  setBlockColor(51,led_strip_1.Color(0,88,255));
  setBlockColor(52,led_strip_1.Color(0,88,255));
  setBlockColor(53,led_strip_1.Color(0,88,255));
  setBlockColor(54,led_strip_1.Color(0,88,255));
  setBlockColor(55,led_strip_1.Color(0,88,255));
  setBlockColor(56,led_strip_1.Color(0,88,255));
  setBlockColor(61,led_strip_1.Color(0,88,255));
  setBlockColor(69,led_strip_1.Color(0,88,255));
  setBlockColor(73,led_strip_1.Color(0,88,255));
  setBlockColor(74,led_strip_1.Color(0,88,255));
  setBlockColor(75,led_strip_1.Color(0,88,255));
  setBlockColor(76,led_strip_1.Color(0,88,255));
  setBlockColor(77,led_strip_1.Color(0,88,255));
  setBlockColor(78,led_strip_1.Color(0,88,255));
  setBlockColor(79,led_strip_1.Color(0,88,255));
  setBlockColor(80,led_strip_1.Color(0,88,255));
  setBlockColor(89,led_strip_1.Color(0,88,255));
  setBlockColor(90,led_strip_1.Color(0,88,255));
  setBlockColor(91,led_strip_1.Color(0,88,255));
  setBlockColor(92,led_strip_1.Color(0,88,255));
  setBlockColor(93,led_strip_1.Color(0,88,255));
  setBlockColor(94,led_strip_1.Color(0,88,255));
  setBlockColor(95,led_strip_1.Color(0,88,255));
  setBlockColor(96,led_strip_1.Color(0,88,255));
  setBlockColor(97,led_strip_1.Color(0,88,255));
  setBlockColor(101,led_strip_1.Color(0,88,255));
  setBlockColor(104,led_strip_1.Color(0,88,255));
  setBlockColor(105,led_strip_1.Color(0,88,255));
  setBlockColor(109,led_strip_1.Color(0,88,255));
  setBlockColor(112,led_strip_1.Color(0,88,255));
  setBlockColor(113,led_strip_1.Color(0,88,255));
  setBlockColor(120,led_strip_1.Color(0,88,255));
  delay(2000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // MIDI
  setBlockColor(1,led_strip_1.Color(255,0,0));
  setBlockColor(2,led_strip_1.Color(255,0,0));
  setBlockColor(3,led_strip_1.Color(255,0,0));
  setBlockColor(4,led_strip_1.Color(255,0,0));
  setBlockColor(5,led_strip_1.Color(255,0,0));
  setBlockColor(6,led_strip_1.Color(255,0,0));
  setBlockColor(7,led_strip_1.Color(255,0,0));
  setBlockColor(8,led_strip_1.Color(255,0,0));
  setBlockColor(10,led_strip_1.Color(255,0,0));
  setBlockColor(19,led_strip_1.Color(255,0,0));
  setBlockColor(20,led_strip_1.Color(255,0,0));
  setBlockColor(26,led_strip_1.Color(255,0,0));
  setBlockColor(33,led_strip_1.Color(255,0,0));
  setBlockColor(34,led_strip_1.Color(255,0,0));
  setBlockColor(35,led_strip_1.Color(255,0,0));
  setBlockColor(36,led_strip_1.Color(255,0,0));
  setBlockColor(37,led_strip_1.Color(255,0,0));
  setBlockColor(38,led_strip_1.Color(255,0,0));
  setBlockColor(39,led_strip_1.Color(255,0,0));
  setBlockColor(40,led_strip_1.Color(255,0,0));
  setBlockColor(49,led_strip_1.Color(255,0,0));
  setBlockColor(50,led_strip_1.Color(255,0,0));
  setBlockColor(51,led_strip_1.Color(255,0,0));
  setBlockColor(52,led_strip_1.Color(255,0,0));
  setBlockColor(53,led_strip_1.Color(255,0,0));
  setBlockColor(54,led_strip_1.Color(255,0,0));
  setBlockColor(55,led_strip_1.Color(255,0,0));
  setBlockColor(56,led_strip_1.Color(255,0,0));
  setBlockColor(65,led_strip_1.Color(255,0,0));
  setBlockColor(66,led_strip_1.Color(255,0,0));
  setBlockColor(67,led_strip_1.Color(255,0,0));
  setBlockColor(68,led_strip_1.Color(255,0,0));
  setBlockColor(69,led_strip_1.Color(255,0,0));
  setBlockColor(70,led_strip_1.Color(255,0,0));
  setBlockColor(71,led_strip_1.Color(255,0,0));
  setBlockColor(72,led_strip_1.Color(255,0,0));
  setBlockColor(73,led_strip_1.Color(255,0,0));
  setBlockColor(80,led_strip_1.Color(255,0,0));
  setBlockColor(82,led_strip_1.Color(255,0,0));
  setBlockColor(87,led_strip_1.Color(255,0,0));
  setBlockColor(91,led_strip_1.Color(255,0,0));
  setBlockColor(92,led_strip_1.Color(255,0,0));
  setBlockColor(93,led_strip_1.Color(255,0,0));
  setBlockColor(94,led_strip_1.Color(255,0,0));
  setBlockColor(105,led_strip_1.Color(255,0,0));
  setBlockColor(106,led_strip_1.Color(255,0,0));
  setBlockColor(107,led_strip_1.Color(255,0,0));
  setBlockColor(108,led_strip_1.Color(255,0,0));
  setBlockColor(109,led_strip_1.Color(255,0,0));
  setBlockColor(110,led_strip_1.Color(255,0,0));
  setBlockColor(111,led_strip_1.Color(255,0,0));
  setBlockColor(112,led_strip_1.Color(255,0,0));
  delay(2300);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // M
  setBlockColor(41,led_strip_1.Color(255,255,255));
  setBlockColor(42,led_strip_1.Color(255,255,255));
  setBlockColor(43,led_strip_1.Color(255,255,255));
  setBlockColor(44,led_strip_1.Color(255,255,255));
  setBlockColor(45,led_strip_1.Color(255,255,255));
  setBlockColor(46,led_strip_1.Color(255,255,255));
  setBlockColor(47,led_strip_1.Color(255,255,255));
  setBlockColor(48,led_strip_1.Color(255,255,255));
  setBlockColor(50,led_strip_1.Color(255,255,255));
  setBlockColor(59,led_strip_1.Color(255,255,255));
  setBlockColor(60,led_strip_1.Color(255,255,255));
  setBlockColor(66,led_strip_1.Color(255,255,255));
  setBlockColor(73,led_strip_1.Color(255,255,255));
  setBlockColor(74,led_strip_1.Color(255,255,255));
  setBlockColor(75,led_strip_1.Color(255,255,255));
  setBlockColor(76,led_strip_1.Color(255,255,255));
  setBlockColor(77,led_strip_1.Color(255,255,255));
  setBlockColor(78,led_strip_1.Color(255,255,255));
  setBlockColor(79,led_strip_1.Color(255,255,255));
  setBlockColor(80,led_strip_1.Color(255,255,255));
  delay(600);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // O
  setBlockColor(49,led_strip_1.Color(0,88,255));
  setBlockColor(50,led_strip_1.Color(0,88,255));
  setBlockColor(51,led_strip_1.Color(0,88,255));
  setBlockColor(52,led_strip_1.Color(0,88,255));
  setBlockColor(53,led_strip_1.Color(0,88,255));
  setBlockColor(54,led_strip_1.Color(0,88,255));
  setBlockColor(55,led_strip_1.Color(0,88,255));
  setBlockColor(56,led_strip_1.Color(0,88,255));
  setBlockColor(57,led_strip_1.Color(0,88,255));
  setBlockColor(64,led_strip_1.Color(0,88,255));
  setBlockColor(65,led_strip_1.Color(0,88,255));
  setBlockColor(72,led_strip_1.Color(0,88,255));
  setBlockColor(73,led_strip_1.Color(0,88,255));
  setBlockColor(74,led_strip_1.Color(0,88,255));
  setBlockColor(75,led_strip_1.Color(0,88,255));
  setBlockColor(76,led_strip_1.Color(0,88,255));
  setBlockColor(77,led_strip_1.Color(0,88,255));
  setBlockColor(78,led_strip_1.Color(0,88,255));
  setBlockColor(79,led_strip_1.Color(0,88,255));
  setBlockColor(80,led_strip_1.Color(0,88,255));
  delay(600);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // S
  setBlockColor(49,led_strip_1.Color(255,0,0));
  setBlockColor(50,led_strip_1.Color(255,0,0));
  setBlockColor(51,led_strip_1.Color(255,0,0));
  setBlockColor(52,led_strip_1.Color(255,0,0));
  setBlockColor(53,led_strip_1.Color(255,0,0));
  setBlockColor(56,led_strip_1.Color(255,0,0));
  setBlockColor(57,led_strip_1.Color(255,0,0));
  setBlockColor(61,led_strip_1.Color(255,0,0));
  setBlockColor(64,led_strip_1.Color(255,0,0));
  setBlockColor(65,led_strip_1.Color(255,0,0));
  setBlockColor(69,led_strip_1.Color(255,0,0));
  setBlockColor(72,led_strip_1.Color(255,0,0));
  setBlockColor(73,led_strip_1.Color(255,0,0));
  setBlockColor(77,led_strip_1.Color(255,0,0));
  setBlockColor(78,led_strip_1.Color(255,0,0));
  setBlockColor(79,led_strip_1.Color(255,0,0));
  setBlockColor(80,led_strip_1.Color(255,0,0));
  
  delay(600);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // A
  setBlockColor(50,led_strip_1.Color(255,255,255));
  setBlockColor(51,led_strip_1.Color(255,255,255));
  setBlockColor(52,led_strip_1.Color(255,255,255));
  setBlockColor(53,led_strip_1.Color(255,255,255));
  setBlockColor(54,led_strip_1.Color(255,255,255));
  setBlockColor(55,led_strip_1.Color(255,255,255));
  setBlockColor(56,led_strip_1.Color(255,255,255));
  setBlockColor(57,led_strip_1.Color(255,255,255));
  setBlockColor(61,led_strip_1.Color(255,255,255));
  setBlockColor(66,led_strip_1.Color(255,255,255));
  setBlockColor(67,led_strip_1.Color(255,255,255));
  setBlockColor(68,led_strip_1.Color(255,255,255));
  setBlockColor(69,led_strip_1.Color(255,255,255));
  setBlockColor(70,led_strip_1.Color(255,255,255));
  setBlockColor(71,led_strip_1.Color(255,255,255));
  setBlockColor(72,led_strip_1.Color(255,255,255));
  delay(600);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // I
  
  setBlockColor(57,led_strip_1.Color(0,88,255));
  setBlockColor(58,led_strip_1.Color(0,88,255));
  setBlockColor(59,led_strip_1.Color(0,88,255));
  setBlockColor(60,led_strip_1.Color(0,88,255));
  setBlockColor(61,led_strip_1.Color(0,88,255));
  setBlockColor(62,led_strip_1.Color(0,88,255));
  setBlockColor(63,led_strip_1.Color(0,88,255));
  setBlockColor(64,led_strip_1.Color(0,88,255));
  delay(600);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // C
  setBlockColor(49,led_strip_1.Color(255,0,0));
  setBlockColor(50,led_strip_1.Color(255,0,0));
  setBlockColor(51,led_strip_1.Color(255,0,0));
  setBlockColor(52,led_strip_1.Color(255,0,0));
  setBlockColor(53,led_strip_1.Color(255,0,0));
  setBlockColor(54,led_strip_1.Color(255,0,0));
  setBlockColor(55,led_strip_1.Color(255,0,0));
  setBlockColor(56,led_strip_1.Color(255,0,0));
  setBlockColor(57,led_strip_1.Color(255,0,0));
  setBlockColor(64,led_strip_1.Color(255,0,0));
  setBlockColor(65,led_strip_1.Color(255,0,0));
  setBlockColor(72,led_strip_1.Color(255,0,0));
  setBlockColor(73,led_strip_1.Color(255,0,0));
  setBlockColor(80,led_strip_1.Color(255,0,0));
delay(800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // AND
  
  setBlockColor(10,led_strip_1.Color(255,255,255));
  setBlockColor(11,led_strip_1.Color(255,255,255));
  setBlockColor(12,led_strip_1.Color(255,255,255));
  setBlockColor(13,led_strip_1.Color(255,255,255));
  setBlockColor(14,led_strip_1.Color(255,255,255));
  setBlockColor(15,led_strip_1.Color(255,255,255));
  setBlockColor(16,led_strip_1.Color(255,255,255));
  setBlockColor(17,led_strip_1.Color(255,255,255));
  setBlockColor(21,led_strip_1.Color(255,255,255));
  setBlockColor(26,led_strip_1.Color(255,255,255));
  setBlockColor(27,led_strip_1.Color(255,255,255));
  setBlockColor(28,led_strip_1.Color(255,255,255));
  setBlockColor(29,led_strip_1.Color(255,255,255));
  setBlockColor(30,led_strip_1.Color(255,255,255));
  setBlockColor(31,led_strip_1.Color(255,255,255));
  setBlockColor(32,led_strip_1.Color(255,255,255));
  setBlockColor(41,led_strip_1.Color(255,255,255));
  setBlockColor(42,led_strip_1.Color(255,255,255));
  setBlockColor(43,led_strip_1.Color(255,255,255));
  setBlockColor(44,led_strip_1.Color(255,255,255));
  setBlockColor(45,led_strip_1.Color(255,255,255));
  setBlockColor(46,led_strip_1.Color(255,255,255));
  setBlockColor(47,led_strip_1.Color(255,255,255));
  setBlockColor(48,led_strip_1.Color(255,255,255));
  setBlockColor(51,led_strip_1.Color(255,255,255));
  setBlockColor(60,led_strip_1.Color(255,255,255));
  setBlockColor(69,led_strip_1.Color(255,255,255));
  setBlockColor(73,led_strip_1.Color(255,255,255));
  setBlockColor(74,led_strip_1.Color(255,255,255));
  setBlockColor(75,led_strip_1.Color(255,255,255));
  setBlockColor(76,led_strip_1.Color(255,255,255));
  setBlockColor(77,led_strip_1.Color(255,255,255));
  setBlockColor(78,led_strip_1.Color(255,255,255));
  setBlockColor(79,led_strip_1.Color(255,255,255));
  setBlockColor(80,led_strip_1.Color(255,255,255));
  setBlockColor(89,led_strip_1.Color(255,255,255));
  setBlockColor(90,led_strip_1.Color(255,255,255));
  setBlockColor(91,led_strip_1.Color(255,255,255));
  setBlockColor(92,led_strip_1.Color(255,255,255));
  setBlockColor(93,led_strip_1.Color(255,255,255));
  setBlockColor(94,led_strip_1.Color(255,255,255));
  setBlockColor(95,led_strip_1.Color(255,255,255));
  setBlockColor(96,led_strip_1.Color(255,255,255));
  setBlockColor(97,led_strip_1.Color(255,255,255));
  setBlockColor(104,led_strip_1.Color(255,255,255));
  setBlockColor(106,led_strip_1.Color(255,255,255));
  setBlockColor(111,led_strip_1.Color(255,255,255));
  setBlockColor(115,led_strip_1.Color(255,255,255));
  setBlockColor(116,led_strip_1.Color(255,255,255));
  setBlockColor(117,led_strip_1.Color(255,255,255));
  setBlockColor(118,led_strip_1.Color(255,255,255));
  
  delay(2200);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // M
  
  setBlockColor(41,led_strip_1.Color(0,88,255));
  setBlockColor(42,led_strip_1.Color(0,88,255));
  setBlockColor(43,led_strip_1.Color(0,88,255));
  setBlockColor(44,led_strip_1.Color(0,88,255));
  setBlockColor(45,led_strip_1.Color(0,88,255));
  setBlockColor(46,led_strip_1.Color(0,88,255));
  setBlockColor(47,led_strip_1.Color(0,88,255));
  setBlockColor(48,led_strip_1.Color(0,88,255));
  setBlockColor(50,led_strip_1.Color(0,88,255));
  setBlockColor(59,led_strip_1.Color(0,88,255));
  setBlockColor(60,led_strip_1.Color(0,88,255));
  setBlockColor(66,led_strip_1.Color(0,88,255));
  setBlockColor(73,led_strip_1.Color(0,88,255));
  setBlockColor(74,led_strip_1.Color(0,88,255));
  setBlockColor(75,led_strip_1.Color(0,88,255));
  setBlockColor(76,led_strip_1.Color(0,88,255));
  setBlockColor(77,led_strip_1.Color(0,88,255));
  setBlockColor(78,led_strip_1.Color(0,88,255));
  setBlockColor(79,led_strip_1.Color(0,88,255));
  setBlockColor(80,led_strip_1.Color(0,88,255));
  delay(1000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // CLEM
  
  setBlockColor(1,led_strip_1.Color(255,0,0));
  setBlockColor(2,led_strip_1.Color(255,0,0));
  setBlockColor(3,led_strip_1.Color(255,0,0));
  setBlockColor(4,led_strip_1.Color(255,0,0));
  setBlockColor(5,led_strip_1.Color(255,0,0));
  setBlockColor(6,led_strip_1.Color(255,0,0));
  setBlockColor(7,led_strip_1.Color(255,0,0));
  setBlockColor(8,led_strip_1.Color(255,0,0));
  setBlockColor(9,led_strip_1.Color(255,0,0));
  setBlockColor(16,led_strip_1.Color(255,0,0));
  setBlockColor(17,led_strip_1.Color(255,0,0));
  setBlockColor(24,led_strip_1.Color(255,0,0));
  setBlockColor(33,led_strip_1.Color(255,0,0));
  setBlockColor(34,led_strip_1.Color(255,0,0));
  setBlockColor(35,led_strip_1.Color(255,0,0));
  setBlockColor(36,led_strip_1.Color(255,0,0));
  setBlockColor(37,led_strip_1.Color(255,0,0));
  setBlockColor(38,led_strip_1.Color(255,0,0));
  setBlockColor(39,led_strip_1.Color(255,0,0));
  setBlockColor(40,led_strip_1.Color(255,0,0));
  setBlockColor(48,led_strip_1.Color(255,0,0));
  setBlockColor(56,led_strip_1.Color(255,0,0));
  setBlockColor(65,led_strip_1.Color(255,0,0));
  setBlockColor(66,led_strip_1.Color(255,0,0));
  setBlockColor(67,led_strip_1.Color(255,0,0));
  setBlockColor(68,led_strip_1.Color(255,0,0));
  setBlockColor(69,led_strip_1.Color(255,0,0));
  setBlockColor(70,led_strip_1.Color(255,0,0));
  setBlockColor(71,led_strip_1.Color(255,0,0));
  setBlockColor(72,led_strip_1.Color(255,0,0));
  setBlockColor(73,led_strip_1.Color(255,0,0));
  setBlockColor(77,led_strip_1.Color(255,0,0));
  setBlockColor(80,led_strip_1.Color(255,0,0));
  setBlockColor(81,led_strip_1.Color(255,0,0));
  setBlockColor(85,led_strip_1.Color(255,0,0));
  setBlockColor(88,led_strip_1.Color(255,0,0));
  setBlockColor(97,led_strip_1.Color(255,0,0));
  setBlockColor(98,led_strip_1.Color(255,0,0));
  setBlockColor(99,led_strip_1.Color(255,0,0));
  setBlockColor(100,led_strip_1.Color(255,0,0));
  setBlockColor(101,led_strip_1.Color(255,0,0));
  setBlockColor(102,led_strip_1.Color(255,0,0));
  setBlockColor(103,led_strip_1.Color(255,0,0));
  setBlockColor(104,led_strip_1.Color(255,0,0));
  setBlockColor(106,led_strip_1.Color(255,0,0));
  setBlockColor(114,led_strip_1.Color(255,0,0));
  setBlockColor(121,led_strip_1.Color(255,0,0));
  setBlockColor(122,led_strip_1.Color(255,0,0));
  setBlockColor(123,led_strip_1.Color(255,0,0));
  setBlockColor(124,led_strip_1.Color(255,0,0));
  setBlockColor(125,led_strip_1.Color(255,0,0));
  setBlockColor(126,led_strip_1.Color(255,0,0));
  setBlockColor(127,led_strip_1.Color(255,0,0));
  setBlockColor(128,led_strip_1.Color(255,0,0));
  delay(2500);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  //FLAG  
  
  setBlockColor(1,led_strip_1.Color(0,88,255));
  setBlockColor(2,led_strip_1.Color(0,88,255));
  setBlockColor(3,led_strip_1.Color(0,88,255));
  setBlockColor(4,led_strip_1.Color(0,88,255));
  setBlockColor(5,led_strip_1.Color(255,0,0));
  setBlockColor(6,led_strip_1.Color(255,255,255));
  setBlockColor(7,led_strip_1.Color(255,0,0));
  setBlockColor(8,led_strip_1.Color(255,255,255));
  setBlockColor(9,led_strip_1.Color(0,88,255));
  setBlockColor(10,led_strip_1.Color(0,88,255));
  setBlockColor(11,led_strip_1.Color(0,88,255));
  setBlockColor(12,led_strip_1.Color(0,88,255));
  setBlockColor(13,led_strip_1.Color(255,0,0));
  setBlockColor(14,led_strip_1.Color(255,255,255));
  setBlockColor(15,led_strip_1.Color(255,0,0));
  setBlockColor(16,led_strip_1.Color(255,255,255));
  setBlockColor(17,led_strip_1.Color(0,88,255));
  setBlockColor(18,led_strip_1.Color(0,88,255));
  setBlockColor(19,led_strip_1.Color(0,88,255));
  setBlockColor(20,led_strip_1.Color(0,88,255));
  setBlockColor(21,led_strip_1.Color(255,0,0));
  setBlockColor(22,led_strip_1.Color(255,255,255));
  setBlockColor(23,led_strip_1.Color(255,0,0));
  setBlockColor(24,led_strip_1.Color(255,255,255));
  setBlockColor(25,led_strip_1.Color(0,88,255));
  setBlockColor(26,led_strip_1.Color(0,88,255));
  setBlockColor(27,led_strip_1.Color(0,88,255));
  setBlockColor(28,led_strip_1.Color(0,88,255));
  setBlockColor(29,led_strip_1.Color(255,0,0));
  setBlockColor(30,led_strip_1.Color(255,255,255));
  setBlockColor(31,led_strip_1.Color(255,0,0));
  setBlockColor(32,led_strip_1.Color(255,255,255));
  setBlockColor(33,led_strip_1.Color(0,88,255));
  setBlockColor(34,led_strip_1.Color(0,88,255));
  setBlockColor(35,led_strip_1.Color(0,88,255));
  setBlockColor(36,led_strip_1.Color(0,88,255));
  setBlockColor(37,led_strip_1.Color(255,0,0));
  setBlockColor(38,led_strip_1.Color(255,255,255));
  setBlockColor(39,led_strip_1.Color(255,0,0));
  setBlockColor(40,led_strip_1.Color(255,255,255));
  setBlockColor(41,led_strip_1.Color(255,0,0));
  setBlockColor(42,led_strip_1.Color(255,255,255));
  setBlockColor(43,led_strip_1.Color(255,0,0));
  setBlockColor(44,led_strip_1.Color(255,255,255));
  setBlockColor(45,led_strip_1.Color(255,0,0));
  setBlockColor(46,led_strip_1.Color(255,255,255));
  setBlockColor(47,led_strip_1.Color(255,0,0));
  setBlockColor(48,led_strip_1.Color(255,255,255));
  setBlockColor(49,led_strip_1.Color(255,0,0));
  setBlockColor(50,led_strip_1.Color(255,255,255));
  setBlockColor(51,led_strip_1.Color(255,0,0));
  setBlockColor(52,led_strip_1.Color(255,255,255));
  setBlockColor(53,led_strip_1.Color(255,0,0));
  setBlockColor(54,led_strip_1.Color(255,255,255));
  setBlockColor(55,led_strip_1.Color(255,0,0));
  setBlockColor(56,led_strip_1.Color(255,255,255));
  setBlockColor(57,led_strip_1.Color(255,0,0));
  setBlockColor(58,led_strip_1.Color(255,255,255));
  setBlockColor(59,led_strip_1.Color(255,0,0));
  setBlockColor(60,led_strip_1.Color(255,255,255));
  setBlockColor(61,led_strip_1.Color(255,0,0));
  setBlockColor(62,led_strip_1.Color(255,255,255));
  setBlockColor(63,led_strip_1.Color(255,0,0));
  setBlockColor(64,led_strip_1.Color(255,255,255));
  setBlockColor(65,led_strip_1.Color(255,0,0));
  setBlockColor(66,led_strip_1.Color(255,255,255));
  setBlockColor(67,led_strip_1.Color(255,0,0));
  setBlockColor(68,led_strip_1.Color(255,255,255));
  setBlockColor(69,led_strip_1.Color(255,0,0));
  setBlockColor(70,led_strip_1.Color(255,255,255));
  setBlockColor(71,led_strip_1.Color(255,0,0));
  setBlockColor(72,led_strip_1.Color(255,255,255));
  setBlockColor(73,led_strip_1.Color(255,0,0));
  setBlockColor(74,led_strip_1.Color(255,255,255));
  setBlockColor(75,led_strip_1.Color(255,0,0));
  setBlockColor(76,led_strip_1.Color(255,255,255));
  setBlockColor(77,led_strip_1.Color(255,0,0));
  setBlockColor(78,led_strip_1.Color(255,255,255));
  setBlockColor(79,led_strip_1.Color(255,0,0));
  setBlockColor(80,led_strip_1.Color(255,255,255));
  setBlockColor(81,led_strip_1.Color(255,0,0));
  setBlockColor(82,led_strip_1.Color(255,255,255));
  setBlockColor(83,led_strip_1.Color(255,0,0));
  setBlockColor(84,led_strip_1.Color(255,255,255));
  setBlockColor(85,led_strip_1.Color(255,0,0));
  setBlockColor(86,led_strip_1.Color(255,255,255));
  setBlockColor(87,led_strip_1.Color(255,0,0));
  setBlockColor(88,led_strip_1.Color(255,255,255));
  setBlockColor(89,led_strip_1.Color(255,0,0));
  setBlockColor(90,led_strip_1.Color(255,255,255));
  setBlockColor(91,led_strip_1.Color(255,0,0));
  setBlockColor(92,led_strip_1.Color(255,255,255));
  setBlockColor(93,led_strip_1.Color(255,0,0));
  setBlockColor(94,led_strip_1.Color(255,255,255));
  setBlockColor(95,led_strip_1.Color(255,0,0));
  setBlockColor(96,led_strip_1.Color(255,255,255));
  setBlockColor(97,led_strip_1.Color(255,0,0));
  setBlockColor(98,led_strip_1.Color(255,255,255));
  setBlockColor(99,led_strip_1.Color(255,0,0));
  setBlockColor(100,led_strip_1.Color(255,255,255));
  setBlockColor(101,led_strip_1.Color(255,0,0));
  setBlockColor(102,led_strip_1.Color(255,255,255));
  setBlockColor(103,led_strip_1.Color(255,0,0));
  setBlockColor(104,led_strip_1.Color(255,255,255));
  setBlockColor(105,led_strip_1.Color(255,0,0));
  setBlockColor(106,led_strip_1.Color(255,255,255));
  setBlockColor(107,led_strip_1.Color(255,0,0));
  setBlockColor(108,led_strip_1.Color(255,255,255));
  setBlockColor(109,led_strip_1.Color(255,0,0));
  setBlockColor(110,led_strip_1.Color(255,255,255));
  setBlockColor(111,led_strip_1.Color(255,0,0));
  setBlockColor(112,led_strip_1.Color(255,255,255));
  setBlockColor(113,led_strip_1.Color(255,0,0));
  setBlockColor(114,led_strip_1.Color(255,255,255));
  setBlockColor(115,led_strip_1.Color(255,0,0));
  setBlockColor(116,led_strip_1.Color(255,255,255));
  setBlockColor(117,led_strip_1.Color(255,0,0));
  setBlockColor(118,led_strip_1.Color(255,255,255));
  setBlockColor(119,led_strip_1.Color(255,0,0));
  setBlockColor(120,led_strip_1.Color(255,255,255));
  setBlockColor(121,led_strip_1.Color(255,0,0));
  setBlockColor(122,led_strip_1.Color(255,255,255));
  setBlockColor(123,led_strip_1.Color(255,0,0));
  setBlockColor(124,led_strip_1.Color(255,255,255));
  setBlockColor(125,led_strip_1.Color(255,0,0));
  setBlockColor(126,led_strip_1.Color(255,255,255));
  setBlockColor(127,led_strip_1.Color(255,0,0));
  setBlockColor(128,led_strip_1.Color(255,255,255));
  delay(5000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
}

void demo() {
  // Hi
  setBlockColor(33,led_strip_1.Color(255,0,0));
  setBlockColor(34,led_strip_1.Color(255,0,0));
  setBlockColor(35,led_strip_1.Color(255,0,0));
  setBlockColor(36,led_strip_1.Color(255,0,0));
  setBlockColor(37,led_strip_1.Color(255,0,0));
  setBlockColor(38,led_strip_1.Color(255,0,0));
  setBlockColor(39,led_strip_1.Color(255,0,0));
  setBlockColor(40,led_strip_1.Color(255,0,0));
  setBlockColor(44,led_strip_1.Color(255,0,0));
  setBlockColor(45,led_strip_1.Color(255,0,0));
  setBlockColor(52,led_strip_1.Color(255,0,0));
  setBlockColor(53,led_strip_1.Color(255,0,0));
  setBlockColor(57,led_strip_1.Color(255,0,0));
  setBlockColor(58,led_strip_1.Color(255,0,0));
  setBlockColor(59,led_strip_1.Color(255,0,0));
  setBlockColor(60,led_strip_1.Color(255,0,0));
  setBlockColor(61,led_strip_1.Color(255,0,0));
  setBlockColor(62,led_strip_1.Color(255,0,0));
  setBlockColor(63,led_strip_1.Color(255,0,0));
  setBlockColor(64,led_strip_1.Color(255,0,0));
  setBlockColor(81,led_strip_1.Color(255,0,0));
  setBlockColor(82,led_strip_1.Color(255,0,0));
  setBlockColor(83,led_strip_1.Color(255,0,0));
  setBlockColor(84,led_strip_1.Color(255,0,0));
  setBlockColor(85,led_strip_1.Color(255,0,0));
  setBlockColor(86,led_strip_1.Color(255,0,0));
  setBlockColor(87,led_strip_1.Color(255,0,0));
  setBlockColor(88,led_strip_1.Color(255,0,0));
  delay(2500);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // I
  setBlockColor(57,led_strip_1.Color(0,239,255));
  setBlockColor(58,led_strip_1.Color(0,239,255));
  setBlockColor(59,led_strip_1.Color(0,239,255));
  setBlockColor(60,led_strip_1.Color(0,239,255));
  setBlockColor(61,led_strip_1.Color(0,239,255));
  setBlockColor(62,led_strip_1.Color(0,239,255));
  setBlockColor(63,led_strip_1.Color(0,239,255));
  setBlockColor(64,led_strip_1.Color(0,239,255));
  delay(1500);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // AM
  setBlockColor(34,led_strip_1.Color(0,239,255));
  setBlockColor(35,led_strip_1.Color(0,239,255));
  setBlockColor(36,led_strip_1.Color(0,239,255));
  setBlockColor(37,led_strip_1.Color(0,239,255));
  setBlockColor(38,led_strip_1.Color(0,239,255));
  setBlockColor(39,led_strip_1.Color(0,239,255));
  setBlockColor(40,led_strip_1.Color(0,239,255));
  setBlockColor(41,led_strip_1.Color(0,239,255));
  setBlockColor(45,led_strip_1.Color(0,239,255));
  setBlockColor(50,led_strip_1.Color(0,239,255));
  setBlockColor(51,led_strip_1.Color(0,239,255));
  setBlockColor(52,led_strip_1.Color(0,239,255));
  setBlockColor(53,led_strip_1.Color(0,239,255));
  setBlockColor(54,led_strip_1.Color(0,239,255));
  setBlockColor(55,led_strip_1.Color(0,239,255));
  setBlockColor(56,led_strip_1.Color(0,239,255));
  setBlockColor(65,led_strip_1.Color(0,239,255));
  setBlockColor(66,led_strip_1.Color(0,239,255));
  setBlockColor(67,led_strip_1.Color(0,239,255));
  setBlockColor(68,led_strip_1.Color(0,239,255));
  setBlockColor(69,led_strip_1.Color(0,239,255));
  setBlockColor(70,led_strip_1.Color(0,239,255));
  setBlockColor(71,led_strip_1.Color(0,239,255));
  setBlockColor(72,led_strip_1.Color(0,239,255));
  setBlockColor(74,led_strip_1.Color(0,239,255));
  setBlockColor(83,led_strip_1.Color(0,239,255));
  setBlockColor(84,led_strip_1.Color(0,239,255));
  setBlockColor(90,led_strip_1.Color(0,239,255));
  setBlockColor(97,led_strip_1.Color(0,239,255));
  setBlockColor(98,led_strip_1.Color(0,239,255));
  setBlockColor(99,led_strip_1.Color(0,239,255));
  setBlockColor(100,led_strip_1.Color(0,239,255));
  setBlockColor(101,led_strip_1.Color(0,239,255));
  setBlockColor(102,led_strip_1.Color(0,239,255));
  setBlockColor(103,led_strip_1.Color(0,239,255));
  setBlockColor(104,led_strip_1.Color(0,239,255));
  delay(1500);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // THE
  setBlockColor(9,led_strip_1.Color(0,239,255));
  setBlockColor(17,led_strip_1.Color(0,239,255));
  setBlockColor(25,led_strip_1.Color(0,239,255));
  setBlockColor(26,led_strip_1.Color(0,239,255));
  setBlockColor(27,led_strip_1.Color(0,239,255));
  setBlockColor(28,led_strip_1.Color(0,239,255));
  setBlockColor(29,led_strip_1.Color(0,239,255));
  setBlockColor(30,led_strip_1.Color(0,239,255));
  setBlockColor(31,led_strip_1.Color(0,239,255));
  setBlockColor(32,led_strip_1.Color(0,239,255));
  setBlockColor(33,led_strip_1.Color(0,239,255));
  setBlockColor(49,led_strip_1.Color(0,239,255));
  setBlockColor(50,led_strip_1.Color(0,239,255));
  setBlockColor(51,led_strip_1.Color(0,239,255));
  setBlockColor(52,led_strip_1.Color(0,239,255));
  setBlockColor(53,led_strip_1.Color(0,239,255));
  setBlockColor(54,led_strip_1.Color(0,239,255));
  setBlockColor(55,led_strip_1.Color(0,239,255));
  setBlockColor(56,led_strip_1.Color(0,239,255));
  setBlockColor(61,led_strip_1.Color(0,239,255));
  setBlockColor(69,led_strip_1.Color(0,239,255));
  setBlockColor(73,led_strip_1.Color(0,239,255));
  setBlockColor(74,led_strip_1.Color(0,239,255));
  setBlockColor(75,led_strip_1.Color(0,239,255));
  setBlockColor(76,led_strip_1.Color(0,239,255));
  setBlockColor(77,led_strip_1.Color(0,239,255));
  setBlockColor(78,led_strip_1.Color(0,239,255));
  setBlockColor(79,led_strip_1.Color(0,239,255));
  setBlockColor(80,led_strip_1.Color(0,239,255));
  setBlockColor(89,led_strip_1.Color(0,239,255));
  setBlockColor(90,led_strip_1.Color(0,239,255));
  setBlockColor(91,led_strip_1.Color(0,239,255));
  setBlockColor(92,led_strip_1.Color(0,239,255));
  setBlockColor(93,led_strip_1.Color(0,239,255));
  setBlockColor(94,led_strip_1.Color(0,239,255));
  setBlockColor(95,led_strip_1.Color(0,239,255));
  setBlockColor(96,led_strip_1.Color(0,239,255));
  setBlockColor(97,led_strip_1.Color(0,239,255));
  setBlockColor(101,led_strip_1.Color(0,239,255));
  setBlockColor(104,led_strip_1.Color(0,239,255));
  setBlockColor(105,led_strip_1.Color(0,239,255));
  setBlockColor(109,led_strip_1.Color(0,239,255));
  setBlockColor(112,led_strip_1.Color(0,239,255));
  setBlockColor(113,led_strip_1.Color(0,239,255));
  setBlockColor(120,led_strip_1.Color(0,239,255));
  delay(1500);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // MIDI
  setBlockColor(1,led_strip_1.Color(0,150,255));
  setBlockColor(2,led_strip_1.Color(0,150,255));
  setBlockColor(3,led_strip_1.Color(0,150,255));
  setBlockColor(4,led_strip_1.Color(0,150,255));
  setBlockColor(5,led_strip_1.Color(0,150,255));
  setBlockColor(6,led_strip_1.Color(0,150,255));
  setBlockColor(7,led_strip_1.Color(0,150,255));
  setBlockColor(8,led_strip_1.Color(0,150,255));
  setBlockColor(10,led_strip_1.Color(0,150,255));
  setBlockColor(19,led_strip_1.Color(0,150,255));
  setBlockColor(20,led_strip_1.Color(0,150,255));
  setBlockColor(26,led_strip_1.Color(0,150,255));
  setBlockColor(33,led_strip_1.Color(0,150,255));
  setBlockColor(34,led_strip_1.Color(0,150,255));
  setBlockColor(35,led_strip_1.Color(0,150,255));
  setBlockColor(36,led_strip_1.Color(0,150,255));
  setBlockColor(37,led_strip_1.Color(0,150,255));
  setBlockColor(38,led_strip_1.Color(0,150,255));
  setBlockColor(39,led_strip_1.Color(0,150,255));
  setBlockColor(40,led_strip_1.Color(0,150,255));
  setBlockColor(49,led_strip_1.Color(0,150,255));
  setBlockColor(50,led_strip_1.Color(0,150,255));
  setBlockColor(51,led_strip_1.Color(0,150,255));
  setBlockColor(52,led_strip_1.Color(0,150,255));
  setBlockColor(53,led_strip_1.Color(0,150,255));
  setBlockColor(54,led_strip_1.Color(0,150,255));
  setBlockColor(55,led_strip_1.Color(0,150,255));
  setBlockColor(56,led_strip_1.Color(0,150,255));
  setBlockColor(65,led_strip_1.Color(0,150,255));
  setBlockColor(66,led_strip_1.Color(0,150,255));
  setBlockColor(67,led_strip_1.Color(0,150,255));
  setBlockColor(68,led_strip_1.Color(0,150,255));
  setBlockColor(69,led_strip_1.Color(0,150,255));
  setBlockColor(70,led_strip_1.Color(0,150,255));
  setBlockColor(71,led_strip_1.Color(0,150,255));
  setBlockColor(72,led_strip_1.Color(0,150,255));
  setBlockColor(73,led_strip_1.Color(0,150,255));
  setBlockColor(80,led_strip_1.Color(0,150,255));
  setBlockColor(82,led_strip_1.Color(0,150,255));
  setBlockColor(87,led_strip_1.Color(0,150,255));
  setBlockColor(91,led_strip_1.Color(0,150,255));
  setBlockColor(92,led_strip_1.Color(0,150,255));
  setBlockColor(93,led_strip_1.Color(0,150,255));
  setBlockColor(94,led_strip_1.Color(0,150,255));
  setBlockColor(105,led_strip_1.Color(0,150,255));
  setBlockColor(106,led_strip_1.Color(0,150,255));
  setBlockColor(107,led_strip_1.Color(0,150,255));
  setBlockColor(108,led_strip_1.Color(0,150,255));
  setBlockColor(109,led_strip_1.Color(0,150,255));
  setBlockColor(110,led_strip_1.Color(0,150,255));
  setBlockColor(111,led_strip_1.Color(0,150,255));
  setBlockColor(112,led_strip_1.Color(0,150,255));
  delay(2000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // M
  setBlockColor(41,led_strip_1.Color(0,255,23));
  setBlockColor(42,led_strip_1.Color(0,255,23));
  setBlockColor(43,led_strip_1.Color(0,255,23));
  setBlockColor(44,led_strip_1.Color(0,255,23));
  setBlockColor(45,led_strip_1.Color(0,255,23));
  setBlockColor(46,led_strip_1.Color(0,255,23));
  setBlockColor(47,led_strip_1.Color(0,255,23));
  setBlockColor(48,led_strip_1.Color(0,255,23));
  setBlockColor(50,led_strip_1.Color(0,255,23));
  setBlockColor(59,led_strip_1.Color(0,255,23));
  setBlockColor(60,led_strip_1.Color(0,255,23));
  setBlockColor(66,led_strip_1.Color(0,255,23));
  setBlockColor(73,led_strip_1.Color(0,255,23));
  setBlockColor(74,led_strip_1.Color(0,255,23));
  setBlockColor(75,led_strip_1.Color(0,255,23));
  setBlockColor(76,led_strip_1.Color(0,255,23));
  setBlockColor(77,led_strip_1.Color(0,255,23));
  setBlockColor(78,led_strip_1.Color(0,255,23));
  setBlockColor(79,led_strip_1.Color(0,255,23));
  setBlockColor(80,led_strip_1.Color(0,255,23));
  delay(400);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // O
  setBlockColor(49,led_strip_1.Color(255,0,232));
  setBlockColor(50,led_strip_1.Color(255,0,232));
  setBlockColor(51,led_strip_1.Color(255,0,232));
  setBlockColor(52,led_strip_1.Color(255,0,232));
  setBlockColor(53,led_strip_1.Color(255,0,232));
  setBlockColor(54,led_strip_1.Color(255,0,232));
  setBlockColor(55,led_strip_1.Color(255,0,232));
  setBlockColor(56,led_strip_1.Color(255,0,232));
  setBlockColor(57,led_strip_1.Color(255,0,232));
  setBlockColor(64,led_strip_1.Color(255,0,232));
  setBlockColor(65,led_strip_1.Color(255,0,232));
  setBlockColor(72,led_strip_1.Color(255,0,232));
  setBlockColor(73,led_strip_1.Color(255,0,232));
  setBlockColor(74,led_strip_1.Color(255,0,232));
  setBlockColor(75,led_strip_1.Color(255,0,232));
  setBlockColor(76,led_strip_1.Color(255,0,232));
  setBlockColor(77,led_strip_1.Color(255,0,232));
  setBlockColor(78,led_strip_1.Color(255,0,232));
  setBlockColor(79,led_strip_1.Color(255,0,232));
  setBlockColor(80,led_strip_1.Color(255,0,232));
  delay(400);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // S
  
  setBlockColor(49,led_strip_1.Color(31,0,255));
  setBlockColor(50,led_strip_1.Color(31,0,255));
  setBlockColor(51,led_strip_1.Color(31,0,255));
  setBlockColor(52,led_strip_1.Color(31,0,255));
  setBlockColor(53,led_strip_1.Color(31,0,255));
  setBlockColor(56,led_strip_1.Color(31,0,255));
  setBlockColor(57,led_strip_1.Color(31,0,255));
  setBlockColor(61,led_strip_1.Color(31,0,255));
  setBlockColor(64,led_strip_1.Color(31,0,255));
  setBlockColor(65,led_strip_1.Color(31,0,255));
  setBlockColor(69,led_strip_1.Color(31,0,255));
  setBlockColor(72,led_strip_1.Color(31,0,255));
  setBlockColor(73,led_strip_1.Color(31,0,255));
  setBlockColor(77,led_strip_1.Color(31,0,255));
  setBlockColor(78,led_strip_1.Color(31,0,255));
  setBlockColor(79,led_strip_1.Color(31,0,255));
  setBlockColor(80,led_strip_1.Color(31,0,255));
  delay(400);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // A
  
  setBlockColor(50,led_strip_1.Color(255,113,0));
  setBlockColor(51,led_strip_1.Color(255,113,0));
  setBlockColor(52,led_strip_1.Color(255,113,0));
  setBlockColor(53,led_strip_1.Color(255,113,0));
  setBlockColor(54,led_strip_1.Color(255,113,0));
  setBlockColor(55,led_strip_1.Color(255,113,0));
  setBlockColor(56,led_strip_1.Color(255,113,0));
  setBlockColor(57,led_strip_1.Color(255,113,0));
  setBlockColor(61,led_strip_1.Color(255,113,0));
  setBlockColor(66,led_strip_1.Color(255,113,0));
  setBlockColor(67,led_strip_1.Color(255,113,0));
  setBlockColor(68,led_strip_1.Color(255,113,0));
  setBlockColor(69,led_strip_1.Color(255,113,0));
  setBlockColor(70,led_strip_1.Color(255,113,0));
  setBlockColor(71,led_strip_1.Color(255,113,0));
  setBlockColor(72,led_strip_1.Color(255,113,0));
  delay(400);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // I
  
  setBlockColor(57,led_strip_1.Color(138,255,0));
  setBlockColor(58,led_strip_1.Color(138,255,0));
  setBlockColor(59,led_strip_1.Color(138,255,0));
  setBlockColor(60,led_strip_1.Color(138,255,0));
  setBlockColor(61,led_strip_1.Color(138,255,0));
  setBlockColor(62,led_strip_1.Color(138,255,0));
  setBlockColor(63,led_strip_1.Color(138,255,0));
  setBlockColor(64,led_strip_1.Color(138,255,0));
  delay(400);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }

  // C
  
  setBlockColor(49,led_strip_1.Color(0,153,255));
  setBlockColor(50,led_strip_1.Color(0,153,255));
  setBlockColor(51,led_strip_1.Color(0,153,255));
  setBlockColor(52,led_strip_1.Color(0,153,255));
  setBlockColor(53,led_strip_1.Color(0,153,255));
  setBlockColor(54,led_strip_1.Color(0,153,255));
  setBlockColor(55,led_strip_1.Color(0,153,255));
  setBlockColor(56,led_strip_1.Color(0,153,255));
  setBlockColor(57,led_strip_1.Color(0,153,255));
  setBlockColor(64,led_strip_1.Color(0,153,255));
  setBlockColor(65,led_strip_1.Color(0,153,255));
  setBlockColor(72,led_strip_1.Color(0,153,255));
  setBlockColor(73,led_strip_1.Color(0,153,255));
  setBlockColor(80,led_strip_1.Color(0,153,255));
  delay(2000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // LET'S
  
  setBlockColor(1,led_strip_1.Color(255,59,0));
  setBlockColor(2,led_strip_1.Color(255,59,0));
  setBlockColor(3,led_strip_1.Color(255,59,0));
  setBlockColor(4,led_strip_1.Color(255,59,0));
  setBlockColor(5,led_strip_1.Color(255,59,0));
  setBlockColor(6,led_strip_1.Color(255,59,0));
  setBlockColor(7,led_strip_1.Color(255,59,0));
  setBlockColor(8,led_strip_1.Color(255,59,0));
  setBlockColor(16,led_strip_1.Color(255,59,0));
  setBlockColor(24,led_strip_1.Color(255,59,0));
  setBlockColor(33,led_strip_1.Color(255,59,0));
  setBlockColor(34,led_strip_1.Color(255,59,0));
  setBlockColor(35,led_strip_1.Color(255,59,0));
  setBlockColor(36,led_strip_1.Color(255,59,0));
  setBlockColor(37,led_strip_1.Color(255,59,0));
  setBlockColor(38,led_strip_1.Color(255,59,0));
  setBlockColor(39,led_strip_1.Color(255,59,0));
  setBlockColor(40,led_strip_1.Color(255,59,0));
  setBlockColor(41,led_strip_1.Color(255,59,0));
  setBlockColor(45,led_strip_1.Color(255,59,0));
  setBlockColor(48,led_strip_1.Color(255,59,0));
  setBlockColor(49,led_strip_1.Color(255,59,0));
  setBlockColor(53,led_strip_1.Color(255,59,0));
  setBlockColor(56,led_strip_1.Color(255,59,0));
  setBlockColor(57,led_strip_1.Color(255,59,0));
  setBlockColor(64,led_strip_1.Color(255,59,0));
  setBlockColor(73,led_strip_1.Color(255,59,0));
  setBlockColor(81,led_strip_1.Color(255,59,0));
  setBlockColor(82,led_strip_1.Color(255,59,0));
  setBlockColor(83,led_strip_1.Color(255,59,0));
  setBlockColor(84,led_strip_1.Color(255,59,0));
  setBlockColor(85,led_strip_1.Color(255,59,0));
  setBlockColor(86,led_strip_1.Color(255,59,0));
  setBlockColor(87,led_strip_1.Color(255,59,0));
  setBlockColor(88,led_strip_1.Color(255,59,0));
  setBlockColor(89,led_strip_1.Color(255,59,0));
  setBlockColor(98,led_strip_1.Color(0,34,255));
  setBlockColor(99,led_strip_1.Color(0,34,255));
  setBlockColor(105,led_strip_1.Color(255,59,0));
  setBlockColor(106,led_strip_1.Color(255,59,0));
  setBlockColor(107,led_strip_1.Color(255,59,0));
  setBlockColor(108,led_strip_1.Color(255,59,0));
  setBlockColor(109,led_strip_1.Color(255,59,0));
  setBlockColor(112,led_strip_1.Color(255,59,0));
  setBlockColor(113,led_strip_1.Color(255,59,0));
  setBlockColor(117,led_strip_1.Color(255,59,0));
  setBlockColor(120,led_strip_1.Color(255,59,0));
  setBlockColor(121,led_strip_1.Color(255,59,0));
  setBlockColor(125,led_strip_1.Color(255,59,0));
  setBlockColor(126,led_strip_1.Color(255,59,0));
  setBlockColor(127,led_strip_1.Color(255,59,0));
  setBlockColor(128,led_strip_1.Color(255,59,0));
  delay(1800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // PLAY
  
  setBlockColor(1,led_strip_1.Color(0,34,255));
  setBlockColor(2,led_strip_1.Color(0,34,255));
  setBlockColor(3,led_strip_1.Color(0,34,255));
  setBlockColor(4,led_strip_1.Color(0,34,255));
  setBlockColor(5,led_strip_1.Color(0,34,255));
  setBlockColor(6,led_strip_1.Color(0,34,255));
  setBlockColor(7,led_strip_1.Color(0,34,255));
  setBlockColor(8,led_strip_1.Color(0,34,255));
  setBlockColor(9,led_strip_1.Color(0,34,255));
  setBlockColor(12,led_strip_1.Color(0,34,255));
  setBlockColor(17,led_strip_1.Color(0,34,255));
  setBlockColor(20,led_strip_1.Color(0,34,255));
  setBlockColor(25,led_strip_1.Color(0,34,255));
  setBlockColor(26,led_strip_1.Color(0,34,255));
  setBlockColor(27,led_strip_1.Color(0,34,255));
  setBlockColor(28,led_strip_1.Color(0,34,255));
  setBlockColor(41,led_strip_1.Color(0,34,255));
  setBlockColor(42,led_strip_1.Color(0,34,255));
  setBlockColor(43,led_strip_1.Color(0,34,255));
  setBlockColor(44,led_strip_1.Color(0,34,255));
  setBlockColor(45,led_strip_1.Color(0,34,255));
  setBlockColor(46,led_strip_1.Color(0,34,255));
  setBlockColor(47,led_strip_1.Color(0,34,255));
  setBlockColor(48,led_strip_1.Color(0,34,255));
  setBlockColor(56,led_strip_1.Color(0,34,255));
  setBlockColor(64,led_strip_1.Color(0,34,255));
  setBlockColor(74,led_strip_1.Color(0,34,255));
  setBlockColor(75,led_strip_1.Color(0,34,255));
  setBlockColor(76,led_strip_1.Color(0,34,255));
  setBlockColor(77,led_strip_1.Color(0,34,255));
  setBlockColor(78,led_strip_1.Color(0,34,255));
  setBlockColor(79,led_strip_1.Color(0,34,255));
  setBlockColor(80,led_strip_1.Color(0,34,255));
  setBlockColor(81,led_strip_1.Color(0,34,255));
  setBlockColor(85,led_strip_1.Color(0,34,255));
  setBlockColor(90,led_strip_1.Color(0,34,255));
  setBlockColor(91,led_strip_1.Color(0,34,255));
  setBlockColor(92,led_strip_1.Color(0,34,255));
  setBlockColor(93,led_strip_1.Color(0,34,255));
  setBlockColor(94,led_strip_1.Color(0,34,255));
  setBlockColor(95,led_strip_1.Color(0,34,255));
  setBlockColor(96,led_strip_1.Color(0,34,255));
  setBlockColor(105,led_strip_1.Color(0,34,255));
  setBlockColor(106,led_strip_1.Color(0,34,255));
  setBlockColor(115,led_strip_1.Color(0,34,255));
  setBlockColor(116,led_strip_1.Color(0,34,255));
  setBlockColor(117,led_strip_1.Color(0,34,255));
  setBlockColor(118,led_strip_1.Color(0,34,255));
  setBlockColor(119,led_strip_1.Color(0,34,255));
  setBlockColor(120,led_strip_1.Color(0,34,255));
  setBlockColor(121,led_strip_1.Color(0,34,255));
  setBlockColor(122,led_strip_1.Color(0,34,255));
  delay(1800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  // SOME
  
  setBlockColor(1,led_strip_1.Color(0,255,34));
  setBlockColor(2,led_strip_1.Color(0,255,34));
  setBlockColor(3,led_strip_1.Color(0,255,34));
  setBlockColor(4,led_strip_1.Color(0,255,34));
  setBlockColor(5,led_strip_1.Color(0,255,34));
  setBlockColor(8,led_strip_1.Color(0,255,34));
  setBlockColor(9,led_strip_1.Color(0,255,34));
  setBlockColor(13,led_strip_1.Color(0,255,34));
  setBlockColor(16,led_strip_1.Color(0,255,34));
  setBlockColor(17,led_strip_1.Color(0,255,34));
  setBlockColor(21,led_strip_1.Color(0,255,34));
  setBlockColor(22,led_strip_1.Color(0,255,34));
  setBlockColor(23,led_strip_1.Color(0,255,34));
  setBlockColor(24,led_strip_1.Color(0,255,34));
  setBlockColor(33,led_strip_1.Color(0,255,34));
  setBlockColor(34,led_strip_1.Color(0,255,34));
  setBlockColor(35,led_strip_1.Color(0,255,34));
  setBlockColor(36,led_strip_1.Color(0,255,34));
  setBlockColor(37,led_strip_1.Color(0,255,34));
  setBlockColor(38,led_strip_1.Color(0,255,34));
  setBlockColor(39,led_strip_1.Color(0,255,34));
  setBlockColor(40,led_strip_1.Color(0,255,34));
  setBlockColor(41,led_strip_1.Color(0,255,34));
  setBlockColor(48,led_strip_1.Color(0,255,34));
  setBlockColor(49,led_strip_1.Color(0,255,34));
  setBlockColor(50,led_strip_1.Color(0,255,34));
  setBlockColor(51,led_strip_1.Color(0,255,34));
  setBlockColor(52,led_strip_1.Color(0,255,34));
  setBlockColor(53,led_strip_1.Color(0,255,34));
  setBlockColor(54,led_strip_1.Color(0,255,34));
  setBlockColor(55,led_strip_1.Color(0,255,34));
  setBlockColor(56,led_strip_1.Color(0,255,34));
  setBlockColor(65,led_strip_1.Color(0,255,34));
  setBlockColor(66,led_strip_1.Color(0,255,34));
  setBlockColor(67,led_strip_1.Color(0,255,34));
  setBlockColor(68,led_strip_1.Color(0,255,34));
  setBlockColor(69,led_strip_1.Color(0,255,34));
  setBlockColor(70,led_strip_1.Color(0,255,34));
  setBlockColor(71,led_strip_1.Color(0,255,34));
  setBlockColor(72,led_strip_1.Color(0,255,34));
  setBlockColor(74,led_strip_1.Color(0,255,34));
  setBlockColor(75,led_strip_1.Color(0,255,34));
  setBlockColor(82,led_strip_1.Color(0,255,34));
  setBlockColor(83,led_strip_1.Color(0,255,34));
  setBlockColor(89,led_strip_1.Color(0,255,34));
  setBlockColor(90,led_strip_1.Color(0,255,34));
  setBlockColor(91,led_strip_1.Color(0,255,34));
  setBlockColor(92,led_strip_1.Color(0,255,34));
  setBlockColor(93,led_strip_1.Color(0,255,34));
  setBlockColor(94,led_strip_1.Color(0,255,34));
  setBlockColor(95,led_strip_1.Color(0,255,34));
  setBlockColor(96,led_strip_1.Color(0,255,34));
  setBlockColor(105,led_strip_1.Color(0,255,34));
  setBlockColor(106,led_strip_1.Color(0,255,34));
  setBlockColor(107,led_strip_1.Color(0,255,34));
  setBlockColor(108,led_strip_1.Color(0,255,34));
  setBlockColor(109,led_strip_1.Color(0,255,34));
  setBlockColor(110,led_strip_1.Color(0,255,34));
  setBlockColor(111,led_strip_1.Color(0,255,34));
  setBlockColor(112,led_strip_1.Color(0,255,34));
  setBlockColor(113,led_strip_1.Color(0,255,34));
  setBlockColor(117,led_strip_1.Color(0,255,34));
  setBlockColor(120,led_strip_1.Color(0,255,34));
  setBlockColor(121,led_strip_1.Color(0,255,34));
  setBlockColor(125,led_strip_1.Color(0,255,34));
  setBlockColor(128,led_strip_1.Color(0,255,34));
  delay(1800);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  //MUSIC
  setBlockColor(1,led_strip_1.Color(0,0,255));
  setBlockColor(2,led_strip_1.Color(0,0,255));
  setBlockColor(3,led_strip_1.Color(0,0,255));
  setBlockColor(4,led_strip_1.Color(0,0,255));
  setBlockColor(5,led_strip_1.Color(0,0,255));
  setBlockColor(6,led_strip_1.Color(0,0,255));
  setBlockColor(7,led_strip_1.Color(0,0,255));
  setBlockColor(8,led_strip_1.Color(0,0,255));
  setBlockColor(10,led_strip_1.Color(0,0,255));
  setBlockColor(17,led_strip_1.Color(0,0,255));
  setBlockColor(18,led_strip_1.Color(0,0,255));
  setBlockColor(19,led_strip_1.Color(0,0,255));
  setBlockColor(20,led_strip_1.Color(0,0,255));
  setBlockColor(21,led_strip_1.Color(0,0,255));
  setBlockColor(22,led_strip_1.Color(0,0,255));
  setBlockColor(23,led_strip_1.Color(0,0,255));
  setBlockColor(24,led_strip_1.Color(0,0,255));
  setBlockColor(33,led_strip_1.Color(0,0,255));
  setBlockColor(34,led_strip_1.Color(0,0,255));
  setBlockColor(35,led_strip_1.Color(0,0,255));
  setBlockColor(36,led_strip_1.Color(0,0,255));
  setBlockColor(37,led_strip_1.Color(0,0,255));
  setBlockColor(38,led_strip_1.Color(0,0,255));
  setBlockColor(39,led_strip_1.Color(0,0,255));
  setBlockColor(40,led_strip_1.Color(0,0,255));
  setBlockColor(48,led_strip_1.Color(0,0,255));
  setBlockColor(49,led_strip_1.Color(0,0,255));
  setBlockColor(50,led_strip_1.Color(0,0,255));
  setBlockColor(51,led_strip_1.Color(0,0,255));
  setBlockColor(52,led_strip_1.Color(0,0,255));
  setBlockColor(53,led_strip_1.Color(0,0,255));
  setBlockColor(54,led_strip_1.Color(0,0,255));
  setBlockColor(55,led_strip_1.Color(0,0,255));
  setBlockColor(56,led_strip_1.Color(0,0,255));
  setBlockColor(65,led_strip_1.Color(0,0,255));
  setBlockColor(66,led_strip_1.Color(0,0,255));
  setBlockColor(67,led_strip_1.Color(0,0,255));
  setBlockColor(68,led_strip_1.Color(0,0,255));
  setBlockColor(69,led_strip_1.Color(0,0,255));
  setBlockColor(72,led_strip_1.Color(0,0,255));
  setBlockColor(73,led_strip_1.Color(0,0,255));
  setBlockColor(77,led_strip_1.Color(0,0,255));
  setBlockColor(80,led_strip_1.Color(0,0,255));
  setBlockColor(81,led_strip_1.Color(0,0,255));
  setBlockColor(85,led_strip_1.Color(0,0,255));
  setBlockColor(86,led_strip_1.Color(0,0,255));
  setBlockColor(87,led_strip_1.Color(0,0,255));
  setBlockColor(88,led_strip_1.Color(0,0,255));
  setBlockColor(97,led_strip_1.Color(0,0,255));
  setBlockColor(98,led_strip_1.Color(0,0,255));
  setBlockColor(99,led_strip_1.Color(0,0,255));
  setBlockColor(100,led_strip_1.Color(0,0,255));
  setBlockColor(101,led_strip_1.Color(0,0,255));
  setBlockColor(102,led_strip_1.Color(0,0,255));
  setBlockColor(103,led_strip_1.Color(0,0,255));
  setBlockColor(104,led_strip_1.Color(0,0,255));
  setBlockColor(113,led_strip_1.Color(0,0,255));
  setBlockColor(114,led_strip_1.Color(0,0,255));
  setBlockColor(115,led_strip_1.Color(0,0,255));
  setBlockColor(116,led_strip_1.Color(0,0,255));
  setBlockColor(117,led_strip_1.Color(0,0,255));
  setBlockColor(118,led_strip_1.Color(0,0,255));
  setBlockColor(119,led_strip_1.Color(0,0,255));
  setBlockColor(120,led_strip_1.Color(0,0,255));
  setBlockColor(121,led_strip_1.Color(0,0,255));
  setBlockColor(128,led_strip_1.Color(0,0,255));
  
  delay(2000);
  for(int i=1;i<=128;i++) {
    setBlockColor(i,led_strip_1.Color(0,0,0));
  }
  delay(1000);
  usbMIDI.sendNoteOn(0, 120, 8); 
}






