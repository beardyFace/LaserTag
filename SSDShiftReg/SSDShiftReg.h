/*
  SSDShiftReg.h - Lirbrary for controlling SSD through 595 shift registers
Henry Williams 2014
*/
#ifndef SSDShiftReg_h
#define SSDShiftReg_h

#include "Arduino.h"

class SSDShiftReg
{
  public:
	byte* digitPins;
	byte* segmentPins;
	SSDShiftReg(byte dp[], byte seg[]);
	void sevenSegDisplay(int number);
	void start();
     
  private:
	void allDispOff();
	void displayADigit(int dispno, byte digit2disp);
	void setupPins();	
};

#endif