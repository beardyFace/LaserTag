#include <Player.h>
#include <SSDShiftReg.h>
#include <SoftwareSerial.h>

byte digitPinss[] = {9, 12, 13};
byte segmentPinss[] = {2, 3, 4, 5, 6, 7, 8};
SSDShiftReg ssd(digitPinss, segmentPinss);

//byte digitPinss[] = {9, 12, 13};
//byte segmentPinss[] = {2, 3, 4, 5, 6, 7, 8};
//
//const byte SevenSeg[16] = 
//{
//     // Hex digits
//     B11111100, B01100000, B11011010, B11110010,   // 0123
//     B01100110, B10110110, B10111110, B11100000,   // 4567
//     B11111110, B11110110, B11101110, B00111110,   // 89AB
//     B00011010, B01111010, B10011110, B10001110,   // CDEF
//  
//};
//
//void AllDispOff()
//{
//  // Turn all cathode drivers off
//  digitalWrite(digitPins[0], LOW);   
//  digitalWrite(digitPins[1], LOW);   
//  digitalWrite(digitPins[2], LOW);
//}
//
//void DisplayADigit(int dispno, byte digit2disp)
//{
//  
//  // Turn off the shift register pins
//  // while you're shifting bits:
////  digitalWrite(latchPin, LOW);
//  
//  AllDispOff();  // Turn off all cathode drivers.
//  
//  // shift the bits out:
////  shiftOut(dataPin, clockPin, LSBFIRST, digit2disp);
//  
////  digitalWrite(latchPin, HIGH);  // Set latch high to set segments.
//    byte number = SevenSeg[digit2disp];
//    digitalWrite(segmentPins[0], !bitRead(number, 7));
//    digitalWrite(segmentPins[1], !bitRead(number, 6));
//    digitalWrite(segmentPins[2], !bitRead(number, 5));
//    digitalWrite(segmentPins[3], !bitRead(number, 4));
//    digitalWrite(segmentPins[4], !bitRead(number, 3));
//    digitalWrite(segmentPins[5], !bitRead(number, 2));
//    digitalWrite(segmentPins[6], !bitRead(number, 1));
//  
//  digitalWrite(digitPins[dispno], HIGH);  // Drive one cathode low to turn on display.
//  
//  delay(5);  // Wait a bit for POV
//
//}
//
//void SevenSegDisplay(int number)
//{
//  int d1,d2,d3,d4; // Temporary values for thousands, hundreds, tens and units
//  
//  if (number > 9999)
//     number = 9999;  // Do some bounds checks to avoid strangeness
//  if (number < 0)
//     number = 0;
//  
//  d1 = (int) (number / 1000);    // Get thousands
//  number = number - (d1 * 1000);
//  d2 = (int) (number / 100);     // Get hundreds
//  number = number - (d2 * 100);
//  d3 = (int) (number / 10);      // Get tens
//  d4 = number - (d3* 10);        // Get units
//  
//  DisplayADigit(0,d2);  // Show thousands
//  DisplayADigit(1,d3);  // Show hundreds
//  DisplayADigit(2,d4);  // Show tens
////  DisplayADigit(disp4,byte(SevenSeg[d4]));  // Show units
//
//}
//
void setup(){
  Serial.begin(9600);
//  
//    pinMode(9, OUTPUT);    
//    pinMode(12, OUTPUT);
//    pinMode(13, OUTPUT);
//    
//    pinMode(2, OUTPUT);    
//    pinMode(3, OUTPUT);
//    pinMode(4, OUTPUT);
//    pinMode(5, OUTPUT);
//    pinMode(6, OUTPUT);
//    pinMode(7, OUTPUT);
//    pinMode(8, OUTPUT);
//////    
//  digitalWrite(9, HIGH);   
//  digitalWrite(12, HIGH);   
//  digitalWrite(13, HIGH);
//
//  //SevenSegDisplay(123);

//        for (byte digit=0 ; digit < 3; digit++) {
// 	   	pinMode(digitPins[digit], OUTPUT);
//		digitalWrite(digitPins[digit], HIGH);
////		digitalWrite(digitPins[digit], LOW);
//	}
//
//	for (byte digit=0 ; digit < 7; digit++) {
// 	   	pinMode(segmentPins[digit], OUTPUT);
//		//digitalWrite(segmentPins[digit], HIGH);
//		digitalWrite(segmentPins[digit], LOW);
//	}
//    ssd.digitPins[0] = 9;
//    ssd.digitPins[1] = 12;
//    ssd.digitPins[2] = 13;
//    
//    ssd.segmentPins[0] = 2;
//    ssd.segmentPins[1] = 3;
//    ssd.segmentPins[2] = 4;
//    ssd.segmentPins[3] = 5;
//    ssd.segmentPins[4] = 6;
//    ssd.segmentPins[5] = 7;
//    ssd.segmentPins[6] = 8;
    
    ssd.start();
}


void loop(){
//   for (int j=0; j<20; j++){
    ssd.sevenSegDisplay(421);   
//  SevenSegDisplay(421);
//     delay(1000);
//   }
}
