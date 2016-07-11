//useful links
//https://www.arduino.cc/en/Tutorial/ShftOut13
//https://www.arduino.cc/en/Tutorial/ShiftOut

#include <Gun.h>
#include <Player.h>
#include <SSDShiftReg.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 12);//rx tx

byte digitPinss[] = {9, 10, 11};
byte segmentPinss[] = {2, 3, 4, 5, 6, 7, 8};
SSDShiftReg ssd(digitPinss, segmentPinss);

Player player;

Gun gun;
int trigger_pin = 12;

void fire(){
//  player->fire();
}

int readValue(){
  byte upper = Serial.read();
  byte lower = Serial.read();
  return (upper<<8) | lower; //Reassemble the number
}

void setup()
{ 
  mySerial.begin(4800);
  Serial.begin(9600);
  Serial.println("Started");
  
  ssd.start();
  
  while(Serial.available() < 7){
        }
  
  player.team = Serial.read();
  player.id = Serial.read();
  player.gunType = Serial.read();
 
  player.health = readValue();
  player.armour = readValue();
  
  player.MAX_HEALTH = 100;
  
  Serial.println(player.team);
  Serial.println(player.id);
  Serial.println(player.gunType);
  Serial.println(player.health);
  Serial.println(player.armour);
  
  attachInterrupt(trigger_pin, fire, RISING);
  
  //ssd.sevenSegDisplay(player.health);
  
  Serial.println("Player Ready");
}

void loop()
{
//  int v = mySerial.available();
//  Serial.println(v);
  if(mySerial.available() > 4){
//      byte b = mySerial.readBytes(data, 3);
      char data[4]; 
      Serial.println("Got");
      data[gun.type_index] = mySerial.read();
      data[gun.team_index] = mySerial.read();
      data[gun.plyr_index] = mySerial.read();
      data[gun.guns_index] = mySerial.read();
      Serial.println(data[gun.type_index]);
      Serial.println(data[gun.team_index]);
      Serial.println(data[gun.plyr_index]);
      Serial.println(data[gun.guns_index]);

      char check = mySerial.read();
      Serial.println(check);
      if(check == 'D'){
        
//        gun.hitPlayer(&player, data);
//        gun.hitPlayer(data);
        gun.hitPlayer(&player, data);
        
        //ssd.sevenSegDisplay(player.health);
        Serial.println(player.health);
        Serial.println(player.armour);
      }
      else{
        Serial.println("failed check");
        while(!mySerial.available()){
        }
        while(mySerial.available()){
          Serial.println("reading");
          char value = mySerial.read();
          Serial.println(value);
          if(value == 'D')
            break;
        }
      }
      //Serial.write(mySerial.read())\
//      char team = data[0];
//      char player = data[1];
//      char gun = data[2];
  }
  ssd.sevenSegDisplay(player.health);
}


