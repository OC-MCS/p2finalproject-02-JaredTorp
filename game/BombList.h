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

	void CheckIfOffscreen()
	{

		list<Bomb>::iterator iter;
		for (iter = ListOfBombs.begin(); iter != ListOfBombs.end(); )
		{
			if ((*iter).getBombYPos() < 0) //checks the y position
			{
				iter = ListOfBombs.erase(iter); //delete the bomb when it goes offscreen

			}
			else
			{
				iter++;
			}

		}

	}

	//function checks if the player hat been hit
	bool CheckHitPlayer(Ship& player)
	{
		bool hit = false;
		list<Bomb>::iterator iter;
		for (iter = ListOfBombs.begin(); iter != ListOfBombs.end(); )
		{
			if ((*iter).getBombBounds().intersects(player.getShipBounds())) //checks the bounds and sees if they intersect
			{
				iter = ListOfBombs.erase(iter); //delete the bomb when it goes offscreen
				hit = true;
			}
			else
			{
				iter++;
			}

		}
		return hit;
	}








};