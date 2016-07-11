#include <SevSeg.h>
SevSeg sevseg; //Instantiate a seven segment object
void setupSSD(){
   byte numDigits = 3;
   byte digitPins[] = {9, 12, 13};
   byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 11};
   sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
   sevseg.setNumber(314,0);
}

void setup(){
  setupSSD();
}

void loop(){
  sevseg.refreshDisplay();

}
