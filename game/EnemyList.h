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
	Texture enemyTexture;
	


public:

	EnemyList()
	{
		//nothing, not enough details
	}


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
	

		const int offset = 75;
		int xPosition = 47;

		if (level == 1)
		{
			for (int i = 0; i < 10; i++)
			{

				Vector2f position(xPosition, 35);
				Enemy enemy(position, enemyTexture, 1.0f); //speed is 0.25f on level 1
				ListOfEnemies.push_back(enemy);
				xPosition += offset;

			}
		}
		else if (level == 2)
		{
			for (int i = 0; i < 10; i++)
			{

				Vector2f position(xPosition, 35);
				Enemy enemy(position, enemyTexture, 2.5f); //increase the speed on level 2
				ListOfEnemies.push_back(enemy);
				xPosition += offset;

			}
		}
		
	}





	//if enemy hit funtion/delete function
	//COME BACK LATER
	//list<Missile> missiles, GameSettings& GameSettings
	void CheckDeleteEnemy(MissileList& missiles, GameSettings& GameSettings)
	{
		list<Enemy>::iterator EnemyIter;
		list<Missile>::iterator MissileIter;
		bool hit = false;
		int count = 0;

		for (MissileIter = missiles.getListOfMissiles().begin(); MissileIter != missiles.getListOfMissiles().end();)
		{
			//cout << "here01" << endl;
			for (EnemyIter = ListOfEnemies.begin(); EnemyIter != ListOfEnemies.end();)
			{
				
				if ((*EnemyIter).getEnemyBounds().intersects((*MissileIter).getMissileBounds()))
				{
					
					EnemyIter = ListOfEnemies.erase(EnemyIter); //delete alien these are fine
					GameSettings.EnemyKilled(); //an enemy is killed
					hit = true;
				}
				else
				{
					EnemyIter++;
					
				}
				
			}
			if (hit)
			{
				MissileIter = missiles.getListOfMissiles().erase(MissileIter); // these are fine
				hit = false; //reset the flag if it is true
			}
			else
			{
				MissileIter++;
				
			}
			
		}


	}
	//draw the list of enemies function

	void DrawEnemies(RenderWindow& win)
	{
		/*cout << List.size() << endl;*/
		list<Enemy>::iterator iter;
		for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end(); iter++)
		{
			(*iter).draw(win);
			
		}


	}

	//delete, because the list must know which to delete


	//moving all the enemies
	void moveEnemies()
	{
		list<Enemy>::iterator iter;

		for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end(); iter++)
		{
			(*iter).EnemyMove();

		}


	}


	//this function helps us check the positions of the enemies, we want to back out once we know an enemy is too low
	 bool enemyTooLow()
	{
		 bool tooLow = false;
		 
		 list<Enemy>::iterator iter;
		 for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end() && !tooLow; iter++) //we want to back out of this loop when we know the position is too low 
		 {
			 if ((*iter).getEnemyPosition().y > 510) //roughly the position that the enemy will hit the player
			 {
				 tooLow = true;
			 }
			 

		 }

		 return tooLow;

	}


	 //this function reserts the enemies
	 void resetEnemyPositions()
	 {
		 list<Enemy>::iterator iter;
		

		 for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end(); iter++) //we want to back out of this loop when we know the position is too low 
		 {
				 Vector2f position((*iter).getEnemyXPosition(), 35);

				 (*iter).setEnemyPosition(position);

				 

		 }
	

	 }

	 void DropBomb(BombList& Bombs)
	 {
		 list<Enemy>::iterator iter;
		 int random; //int that will hold the random number
		 random = (rand() % (ListOfEnemies.size()));

		

		 //advance to that enemy
		 iter = ListOfEnemies.begin();
		 advance(iter, random); // advance is a library function that advances iterator
		 Bombs.addBomb((*iter).getEnemyPosition());

	 }

	 //get the list by reference to see if they have been killed
	 list<Enemy>& getEnemyList()
	 {
		 return ListOfEnemies;
	 }
	
	 //to delete the list
	 void DeleteList()
	 {
		 list<Enemy>::iterator iter;
		 for (iter = ListOfEnemies.begin(); iter != ListOfEnemies.end();)
		 {

			 iter = ListOfEnemies.erase(iter);

		 }

	 }



};



