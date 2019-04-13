#pragma once

#include "Enemy.h"
#include <list>

//this class is for a list of enemies
//this is the container class for the list of enemies

class EnemyList
{
private:
	list <Enemy>List;
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

				List.push_back(enemy);

				xPosition += offset;

			}

	}



	//if enemy hit funtion/delete function

	//position function should be in main?


	//draw the list of enemies function

	void DrawEnemies(RenderWindow& win)
	{
		/*cout << List.size() << endl;*/
		list<Enemy>::iterator iter;
		for (iter = List.begin(); iter != List.end(); iter++)
		{
			(*iter).draw(win);
			
		}


	}

	//delete, because the list must know which to delete


	//moving all the enemies
	void moveEnemies()
	{
		list<Enemy>::iterator iter;
		for (iter = List.begin(); iter != List.end(); iter++)
		{
			(*iter).EnemyMove();

		}


	}


	//this function helps us check the positions of the enemies, we want to back out once we know an enemy is too low
	 bool enemyTooLow()
	{
		 bool tooLow = false;
		 
		 list<Enemy>::iterator iter;
		 for (iter = List.begin(); iter != List.end() && !tooLow; iter++) //we want to back out of this loop when we know the position is too low 
		 {
			 if ((*iter).getEnemyPosition().y > 510) //roughly the position that the enemy will hit the player
			 {
				 tooLow = true;
			 }
			 

		 }

		 return tooLow;

	}

	 void resetEnemyPositions()
	 {
		 list<Enemy>::iterator iter;
		 const int offset = 75;
		 int xPosition = 47;

		 for (iter = List.begin(); iter != List.end(); iter++) //we want to back out of this loop when we know the position is too low 
		 {
				 Vector2f position(xPosition, 35);

				 (*iter).setEnemyPosition(position);

				 xPosition += offset;

		 }
	

	 }


};