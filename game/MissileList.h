#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class MissileList
{
private:
	
	list <Missile>ListOfMissiles; //list of missiles
	Texture missileTexture; //pass this by reference to use only one texture

public:

	//======================================================
	// function name: addMissile
	// parameters: Vector2f ShipPos
	// return type: none, its a void
	//======================================================
	void addMissile(Vector2f ShipPos)
	{

		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}


		Missile tempMissile(missileTexture, ShipPos); //creates a temporary missile, sets the position of the ships'

		ListOfMissiles.push_back(tempMissile); //push back the list

		 
	}

	//======================================================
	// function name: drawMissiles
	// parameters: REnderWindow&- to draw
	// return type: none, its a void
	//======================================================
	void drawMissiles(RenderWindow& win)
	{
		list<Missile>::iterator iter;
		for (iter = ListOfMissiles.begin(); iter != ListOfMissiles.end(); iter++)
		{
			(*iter).draw(win); //calls the draw function

		}
	}
	
	
	//======================================================
	// function name: CheckIfOffscreen
	// parameters: none
	// return type: none, its a void
	//======================================================
	void CheckIfOffscreen()
	{

		list<Missile>::iterator iter;
		for (iter = ListOfMissiles.begin(); iter != ListOfMissiles.end(); )
		{
			if ( (*iter).getMissileYPos() < 0) //checks the y position
			{
				iter = ListOfMissiles.erase(iter); //delete the missile when it goes offscreen
				
			}
			else
			{
				iter++;
			}

		}

	}

	//======================================================
	// function name: getListOfMissile()
	// parameters: none
	// return type: list<missiles>& - 
	//======================================================
	list<Missile>& getListOfMissiles() 
	{
		return ListOfMissiles; //return the list of missiles
	}


	//======================================================
	// function name: DeleteList()
	// parameters: none
	// return type: void
	//======================================================
	void DeleteList()
	{
		list<Missile>::iterator iter;
		for (iter = ListOfMissiles.begin(); iter != ListOfMissiles.end();)
		{
		
				iter = ListOfMissiles.erase(iter); //erase that missile
			
		}

	}




};