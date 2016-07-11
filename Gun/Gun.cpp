#include <Gun.h>
#include <Player.h>

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

	void Gun::adminHit(Player* player, char data[]){
	 //instant kill
	 //revive
	  char instruction = data[inst];
	  switch(instruction){
		case 'B':
	//          player->heal(MAX_HEALTH);
	//          player.heal(1000);
		  break;
	  }
	}

	void Gun::processGun(char data[], Player* player){
	  //postive  = damage
	  //negative = heal 
	  char gun_type = data[guns_index];
	  switch(gun_type)
	  {
		//normal damage
		//normal heal
		case 'A':{
		  if(player->team == data[team_index])
			player->heal(5); 
		  else
			player->damage(5); 
		}
		break;
		
		//normal damage
		case 'B':{
		  if(player->team != data[team_index])
			player->damage(10);
		}
		break;
		
		//normal heal
		case 'C':{
		  if(player->team == data[team_index])
			player->heal(10);
		}
		break;
		
		//penetrates armour
		case 'E':{
		  if(player->team != data[team_index])
			player->removeHealth(10);
		}
		break;
				
		//partially penetrates armour
		case'F':{
		  if(player->team != data[team_index]){
			int damage = 10;
			int extra = player->removeArmour(damage);
			player->removeHealth(damage/2 + extra);
		  }
		}
		break;
		
		default:
		  break;
	  }
	}
	
	void Gun::playerHit(Player* player, char data[]){
	  processGun(data, player);
	}
	
	
	void Gun::hitPlayer(Player* player, char data[]){
	 char player_type = data[type_index];
	 switch(player_type)
	 {
	   case 'A'://admin
		 adminHit(player, data);    
		 break;
	   case 'B'://player
		 playerHit(player, data);
		 break;
	   default:
		 break;

	 }
	}
	 
	
