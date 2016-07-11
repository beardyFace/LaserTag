/*
  Player.h - Library for Player
Henry Williams 2014
*/
#ifndef Player_h
#define Player_h

#include "Arduino.h"

class Player{
  
public:
    char team;
    char gunType;
    char id;
    int health;
    int armour;
    boolean alive;
    int MAX_HEALTH;  

  void heal(int heal);
  
  void damage(int damage); 
  
  void removeHealth(int damage);
  
  int removeArmour(double damage);
    
  boolean sameTeam(char value);
};

#endif