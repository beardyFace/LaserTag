/*
  Player.h - Library for Player
Henry Williams 2015
*/
#ifndef Gun_h
#define Gun_h

#include "Arduino.h"
#include "Player.h"

class Gun{
public:
	//always 0	
	const int type_index = 0;
 
	//admin index A
	const int inst = 1; //instruction
	const int NU1 = 2;
	const int NU2 = 3;

	//player index B
	const int team_index = 1;
	const int plyr_index = 2;
	const int guns_index = 3;
 
	void adminHit(Player* player, char data[]);
     
    void playerHit(Player* player, char data[]);
      
    void processGun(char data[], Player* player);

	void hitPlayer(Player* player, char data[]);
};

#endif