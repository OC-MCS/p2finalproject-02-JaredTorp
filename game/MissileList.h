#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class MissileList
{
private:
	
	list <Missile>ListOfMissiles;
	Texture missileTexture; //pass this by reference to use only one texture

public:


	void addMissile(Vector2f ShipPos)
	{

		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}


		Missile tempMissile(missileTexture, ShipPos);

		ListOfMissiles.push_back(tempMissile);

		 
	}


	void drawMissiles(RenderWindow& win)
	{
		list<Missile>::iterator iter;
		for (iter = ListOfMissiles.begin(); iter != ListOfMissiles.end(); iter++)
		{
			(*iter).draw(win);

		}
	}

	

	void CheckIfOffscreen()
	{

		list<Missile>::iterator iter;
		for (iter = ListOfMissiles.begin(); iter != ListOfMissiles.end(); )
		{
			if ( (*iter).getMissileYPos() < 0) //checks the y position
			{
				iter = ListOfMissiles.erase(iter); //delete the missile when it goes offscreen
				cout << ListOfMissiles.size() << endl;
			}
			else
			{
				iter++;
			}

		}

	}

	list<Missile> getListOfMissiles() 
	{
		return ListOfMissiles;
	}





};