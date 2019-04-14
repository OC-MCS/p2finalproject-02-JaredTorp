#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class MissileList
{
private:
	
	list <Missile>List;
	Texture missileTexture; //pass this by reference to use only one texture

public:
	/////////////////////////////////////////////////////
	//will we have a constructor for missileList???
	MissileList()
	{
	



	}
	/////////////////////////////////////////////////////

	void addMissile()
	{

		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}


		Missile tempMissile(missileTexture);
		List.push_back(tempMissile);

		 
	}


	void drawMissiles(RenderWindow& win, bool& flag)
	{
		list<Missile>::iterator iter;
		for (iter = List.begin(); iter != List.end(); iter++)
		{
			(*iter).draw(win, flag);

		}
	}

	void setMissilePosition(Vector2f pos)
	{
		list<Missile>::iterator iter;
		for (iter = List.begin(); iter != List.end(); iter++)
		{
			(*iter).setMissilePosition(pos);

		}
	}







};