#include <SSDShiftReg.h>

byte digitPins[3];
byte segmentPins[7];

const byte SevenSeg[16] = 
{
     // Hex digits
     B11111100, B01100000, B11011010, B11110010,   // 0123
     B01100110, B10110110, B10111110, B11100000,   // 4567
     B11111110, B11110110, B11101110, B00111110,   // 89AB
     B00011010, B01111010, B10011110, B10001110,   // CDEF
  
};

SSDShiftReg::SSDShiftReg(byte dp[], byte seg[])
{
	digitPins = dp;
	segmentPins = seg;

	//digitPins[0] = one;
	//digitPins[1] = two;
	//digitPins[2] = three;
	//segmentPins[0] = a;
	//segmentPins[1] = b;
	//segmentPins[2] = c;
	//segmentPins[3] = d;
	//segmentPins[4] = e;
	//segmentPins[5] = f;
	//segmentPins[6] = g;
	//setupPins();
}

void SSDShiftReg::start(){

	for (byte digit=0 ; digit < 3; digit++) {
 	   	pinMode(digitPins[digit], OUTPUT);
		digitalWrite(digitPins[digit], HIGH);
//		digitalWrite(digitPins[digit], LOW);
	}

	for (byte digit=0 ; digit < 7; digit++) {
 	   	pinMode(segmentPins[digit], OUTPUT);
		//digitalWrite(segmentPins[digit], HIGH);
		digitalWrite(segmentPins[digit], LOW);
	}


/*
	pinMode(digitPins[0], OUTPUT);    
    	pinMode(digitPins[1], OUTPUT);
	pinMode(digitPins[2], OUTPUT);
    
	pinMode(segmentPins[0], OUTPUT);    
	pinMode(segmentPins[1], OUTPUT);
	pinMode(segmentPins[2], OUTPUT);
	pinMode(segmentPins[3], OUTPUT);
	pinMode(segmentPins[4], OUTPUT);
	pinMode(segmentPins[5], OUTPUT);
	pinMode(segmentPins[6], OUTPUT);
*/
	//SevenSegDisplay(123);
}

void SSDShiftReg::allDispOff()
{
	//Serial.println("Clear");
  // Turn all cathode drivers off
  digitalWrite(digitPins[0], LOW);   
  digitalWrite(digitPins[1], LOW);   
  digitalWrite(digitPins[2], LOW);
}

void SSDShiftReg::displayADigit(int dispno, byte digit2disp)
{ 
	allDispOff();  // Turn off all cathode drivers.

	byte number = SevenSeg[digit2disp];
	digitalWrite(segmentPins[0], !bitRead(number, 7));
	digitalWrite(segmentPins[1], !bitRead(number, 6));
	digitalWrite(segmentPins[2], !bitRead(number, 5));
	digitalWrite(segmentPins[3], !bitRead(number, 4));
	digitalWrite(segmentPins[4], !bitRead(number, 3));
	digitalWrite(segmentPins[5], !bitRead(number, 2));
	digitalWrite(segmentPins[6], !bitRead(number, 1));
  
	digitalWrite(digitPins[dispno], HIGH);  // Drive one cathode low to turn on display.
  
	delay(5);  // Wait a bit for POV

}

void SSDShiftReg::sevenSegDisplay(int number)
{
	//Serial.println("First");
  int d1,d2,d3,d4; // Temporary values for thousands, hundreds, tens and units
  
  if (number > 9999)
     number = 9999;  // Do some bounds checks to avoid strangeness
  if (number < 0)
     number = 0;
  
  d1 = (int) (number / 1000);    // Get thousands
  number = number - (d1 * 1000);
  d2 = (int) (number / 100);     // Get hundreds
  number = number - (d2 * 100);
  d3 = (int) (number / 10);      // Get tens
  d4 = number - (d3* 10);        // Get units
  
  displayADigit(0,d2);  // Show thousands
  displayADigit(1,d3);  // Show hundreds
  displayADigit(2,d4);  // Show tens
//  DisplayADigit(disp4,byte(SevenSeg[d4]));  // Show units

}

void SSDShiftReg::setupPins(){
    
    
//  digitalWrite(digitPins[0], HIGH);   
//  digitalWrite(digitPins[1], HIGH);   
//  digitalWrite(digitPins[2], HIGH);

  //SevenSegDisplay(123);
}
