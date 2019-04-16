#pragma once

#include "Bomb.h"
#include <list>


class BombList
{
private:
	list<Bomb> ListOfBombs;
	Texture bombTexture;



public:
	
	void addBomb(Vector2f EnemyPos)
	{
		if (!bombTexture.loadFromFile("Bomb.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}


		Bomb tempBomb(bombTexture, EnemyPos);


		ListOfBombs.push_back(tempBomb); //pushback the list of Bombs
	}

	//go through the list and draw the bombs
	void drawBombs(RenderWindow& win)
	{
		list<Bomb>::iterator iter;
		for (iter = ListOfBombs.begin(); iter != ListOfBombs.end(); iter++)
		{
			(*iter).draw(win);

		}
	}










};