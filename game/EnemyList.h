#pragma once

#include "Enemy.h"
#include <list>

//this class is for a list of enemies
//this is the container class for the list of enemies

class EnemyList
{
private:
	list <Enemy>List;
	



public:
	EnemyList()
	{

		const int offset = 50;
		int xPosition = 10;

		for (int  i= 0; i < 10; i++)
		{
		Vector2f position(xPosition,5);

		Enemy enemy(position);

		List.push_back(enemy);
		
		xPosition += offset;
		
		}


		







	}



	//if enemy hit funtion/delete function

	//position function should be in main?


	//draw the list of enemies function

	void DrawEnemies(RenderWindow& win)
	{
		list<Enemy>::iterator iter;
		for (iter = List.begin(); iter != List.end(); iter++)
		{
			(*iter).draw(win);

		}


	}





};