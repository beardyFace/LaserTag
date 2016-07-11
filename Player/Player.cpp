#include <Player.h>

    char team;
    char gunType;
    char id;
    int health;
    int armour;
    boolean alive;
    int MAX_HEALTH = 100;
  
  void Player::heal(int heal){
    health += heal;
    if(health > MAX_HEALTH)
      health = MAX_HEALTH;
  }
  
  void Player::removeHealth(int damage){
    health -= damage;
    if(health < 0)
      health = 0; 
    if(health >= MAX_HEALTH)
      health = MAX_HEALTH;
      
    if(health == 0)
      alive = false;
  }
  
  int Player::removeArmour(double damage){
    armour -= damage;
    if(armour < 0){
      int diff = -armour;
      armour = 0; 
      return diff;
    }
    if(armour >= MAX_HEALTH)
      armour = MAX_HEALTH;
    return 0;
  }

  void Player::damage(int damage){
    damage = removeArmour(damage);
    removeHealth(damage);
  }
  
  boolean Player::sameTeam(char value){
    return value == team;
  }
