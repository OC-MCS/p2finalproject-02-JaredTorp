#pragma once

#include "Bomb.h"
#include <list>


class BombList
{
private:
	list<Bomb> ListOfBombs; //list of bombs
	Texture bombTexture; //holds the texture

public:
	//======================================================
	// function name: addBomb
	// parameters: Vector2f EnemyPos- we pass the enemy's position
	// return type: none, its a void
	//======================================================
	void addBomb(Vector2f EnemyPos)
	{
		if (!bombTexture.loadFromFile("Bomb.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}


		Bomb tempBomb(bombTexture, EnemyPos); //create a temp bomb object


		ListOfBombs.push_back(tempBomb); //pushback the list of Bombs
	}

	//======================================================
	// function name: drawBombs()
	// parameters: RenderWindow& window- pass this to draw bombs
	// return type: none, its a void
	//======================================================
	void drawBombs(RenderWindow& win)
	{
		list<Bomb>::iterator iter;
		for (iter = ListOfBombs.begin(); iter != ListOfBombs.end(); iter++)
		{
			(*iter).draw(win); //draw each bomb

		}
	}
	 

	//======================================================
	// function name: CheckIfOffscreen
	// parameters: none
	// return type: none, its a void
	//======================================================
	void CheckIfOffscreen()
	{

		list<Bomb>::iterator iter;
		for (iter = ListOfBombs.begin(); iter != ListOfBombs.end(); )
		{
			if ((*iter).getBombYPos() > 600) //checks the y position if they go offscreen
			{
				iter = ListOfBombs.erase(iter); //delete the bomb when it goes offscreen

			}
			else
			{
				iter++; //increment iter
			}

		}
		

	}

	//======================================================
	// function name: CheckHitPlayer
	// parameters: Ship& player- pass the Ship object by reference to check if the player is hit
	// return type: bool, this will return true or false
	//======================================================
	bool CheckHitPlayer(Ship& player)
	{
		bool hit = false; //set the bool to false
		list<Bomb>::iterator iter;
		for (iter = ListOfBombs.begin(); iter != ListOfBombs.end(); )
		{
			if ((*iter).getBombBounds().intersects(player.getShipBounds())) //checks the bounds and sees if they intersect
			{
				iter = ListOfBombs.erase(iter); //delete the bomb
				hit = true; //the player was hit!
			}
			else
			{
				iter++; //increment iter
			}

		}
		return hit; //return the bool
	}

	//======================================================
	// function name: DeleteList()
	// parameters: none
	// return type: none, its a void
	//======================================================
	void DeleteList()
	{
		list<Bomb>::iterator iter;
		for (iter = ListOfBombs.begin(); iter != ListOfBombs.end();)
		{

			iter = ListOfBombs.erase(iter); //erase the bomb

		}

	}








};