#pragma once

#include "Enemy.h"
#include <list>
#include "missile.h"
#include "missileList.h"

//this class is for a list of enemies
//this is the container class for the list of enemies

class EnemyList
{
private:
	list <Enemy>ListOfEnemies;
	Texture enemyTexture;



public:
	EnemyList()
	{
		if (!enemyTexture.loadFromFile("Alien.png"))
		{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}

			const int offset = 75;
			int xPosition = 47;

			for (int i = 0; i < 10; i++)
			{
				Vector2f position(xPosition, 35);

				Enemy enemy(position, enemyTexture);

				ListOfEnemies.push_back(enemy);

				xPosition += offset;

			}

	}



	//if enemy hit funtion/delete function
	//COME BACK LATER
	//list<Missile> missiles, GameSettings& GameSettings
	void CheckDeleteEnemy(list<Missile> missiles, GameSettings& GameSettings)
	{
		list<Enemy>::iterator EnemyIter;
		list<Missile>::iterator MissileIter;
	
		for (EnemyIter = ListOfEnemies.begin(); EnemyIter != ListOfEnemies.end();)
		{
			//cout << "here01" << endl;
			for (MissileIter = missiles.begin(); MissileIter != missiles.end();)
			{
				//cout << "here02" << endl;
				if (EnemyIter->getEnemyBounds().intersects(MissileIter->getMissileBounds()))
				{
					EnemyIter = ListOfEnemies.erase(EnemyIter); //delete alien these are fine
					MissileIter = missiles.erase(MissileIter); // these are fine
					GameSettings.EnemyKilled(); //an enemy is killed
				}
				else
				{
					
					EnemyIter++;
					MissileIter++;
				}
				
			}
			
		}


	}

	
	
	
	
	
	
	//position function should be in main?


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


};



