#pragma once

#include "Enemy.h"
#include <list>
#include "missile.h"
#include "missileList.h"
#include "BombList.h"
#include <stdlib.h>

//this class is for a list of enemies
//this is the container class for the list of enemies

class EnemyList
{
private:
	list <Enemy>ListOfEnemies; //to control the list of bombs
	Texture enemyTexture; //to store the texture of the enemy
	


public:

	EnemyList()
	{
		//nothing, not enough details to create enemies off the bat
	}

	//======================================================
	// function name: CreateEnemies
	// parameters: int level, we need to know which level
	// return type: none, its a void
	//======================================================
	void createEnemies(int level)
	{
		//level 1 texture
		if (level == 1)
		{
			if (!enemyTexture.loadFromFile("Alien.png"))
			{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
			}
		}
		//level 2 texture
		else if (level == 2)
		{
			if (!enemyTexture.loadFromFile("Lv2Alien.png"))
			{
				cout << "Unable to load enemy texture!" << endl;
				exit(EXIT_FAILURE);
			}
		}
	

		const int offset = 75; //sets an offset of 75 to space the enemies
		float xPosition = 47; //sets all enemies x position

		if (level == 1)
		{
			for (int i = 0; i < 10; i++)
			{

				Vector2f position(xPosition, 35); //sets a position
				Enemy enemy(position, enemyTexture, 1.0); //create an enemy object with speed is 0.25 on level 1
				ListOfEnemies.push_back(enemy); //push back the list
				xPosition += offset; //add the offset

			}
		}
		else if (level == 2)
		{
			for (int i = 0; i < 10; i++)
			{

				Vector2f position(xPosition, 35);
				Enemy enemy(position, enemyTexture, 2.5); //this code does the same thing as level one EXCEPT it increases the speed on level 2
				ListOfEnemies.push_back(enemy);
				xPosition += offset;

			}
		}
		
	}





	//======================================================
	// function name: CheckDeleteEnemy
	// parameters: MissileList& missiles- pass a missilelist object
	// Gamesettings& Gamesettings- need to pass this to keep track of the enemies killed
	// return type: none, its a void
	//======================================================
	void CheckDeleteEnemy(MissileList& missiles, GameSettings& GameSettings)
	{
		list<Enemy>::iterator EnemyIter; //enemies' iter
		list<Missile>::iterator MissileIter;//missiles' iter
		bool hit = false; //assuming it is false, cant get hit before we even check
		

		for (MissileIter = missiles.getListOfMissiles().begin(); MissileIter != missiles.getListOfMissiles().end();) //go through missile list
		{
		
			for (EnemyIter = ListOfEnemies.begin(); EnemyIter != ListOfEnemies.end();) //through the enemy list
			{
				
				if ((*EnemyIter).getEnemyBounds().intersects((*MissileIter).getMissileBounds())) //if they intersect
				{
					
					EnemyIter = ListOfEnemies.erase(EnemyIter); //delete alien 
					GameSettings.EnemyKilled(); //an enemy is killed
					hit = true; //the enemy is hit
				}
				else
				{
					EnemyIter++; //increment iter
					
				}
				
			}
			if (hit) //if the player was hit
			{
				MissileIter = missiles.getListOfMissiles().erase(MissileIter); // delete the missile
				hit = false; //reset the flag if it is true
			}
			else
			{
				MissileIter++; //increment iter
				
			}
			
		}


	}
	
	//======================================================
	// function name: DrawEnemies
	// parameters: RenderWindow&- pass the window by reference
	// return type: none, its a void
	//======================================================
	void DrawEnemies(RenderWindow& win)
	{
		
		list<Enemy>::iterator iter;
		for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end(); iter++)
		{
			(*iter).draw(win); //draw each enemy
			
		}


	}




	//======================================================
	// function name: moveEnemies()
	// parameters: none
	// return type: none, its a void
	//======================================================
	void moveEnemies()
	{
		list<Enemy>::iterator iter;

		for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end(); iter++)
		{
			(*iter).EnemyMove(); //calls to move each enemy

		}


	}


	//======================================================
	// function name: enemyTooLow()
	// parameters: none
	// return type: bool, needs to return true or false
	//======================================================
	 bool enemyTooLow()
	{
		 bool tooLow = false; //they cant be too low off the bat, duh
		 
		 list<Enemy>::iterator iter;
		 for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end() && !tooLow; iter++) //we want to back out of this loop when we know the position is too low 
		 {
			 if ((*iter).getEnemyPosition().y > 510) //roughly the position that the enemy will hit the player
			 {
				 tooLow = true; //they are too low
			 }
			 

		 }

		 return tooLow; //return the bool

	}


	 //======================================================
	// function name: resetEnemyPosition()
	// parameters: none
	// return type: none its a void
	//======================================================
	 void resetEnemyPositions()
	 {
		 list<Enemy>::iterator iter;
		

		 for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end(); iter++) //we want to back out of this loop when we know the position is too low 
		 {
				 Vector2f position((*iter).getEnemyXPosition(), 35); //get x position of the enemy

				 (*iter).setEnemyPosition(position); //set that enemies positon back up top

				 

		 }
	

	 }

	//======================================================
	// function name: DropBomb()
	// parameters: BombList& Bombs- we pass the list of Bombs
	// return type: none its a void
	//======================================================
	 void DropBomb(BombList& Bombs)
	 {
		 list<Enemy>::iterator iter;
		 int random; //int that will hold the random number
		 random = (rand() % (ListOfEnemies.size())); //get the random number from the size of the enemies

		

		 //advance to that enemy
		 iter = ListOfEnemies.begin(); //set the iter to the beginning of the list
		 advance(iter, random); //advances iterator
		 Bombs.addBomb((*iter).getEnemyPosition()); //add a bomb to the list, passing the rando's position

	 }

	 //======================================================
	// function name: getEnemyList()
	// parameters: none
	// return type: list<Enemy>&
	//======================================================
	 list<Enemy>& getEnemyList()
	 {
		 return ListOfEnemies;//return the list
	 }
	 
	 
	//======================================================
	// function name: DeleteList()
	// parameters: none
	// return type: none, void
	//======================================================
	 void DeleteList()
	 {
		 list<Enemy>::iterator iter;
		 for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end();)
		 {

			 iter = ListOfEnemies.erase(iter); //deletes the enemy, will eventually delete all the enemies

		 }

	 }



};



