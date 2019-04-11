#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

//this class handles a single enemy's attributes
using namespace sf;


class Enemy
{
private:
	Sprite enemy;
	Texture enemyTexture;

public:
	
	Enemy()
	{
		if (!enemyTexture.loadFromFile("Alien.png"))
		{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}
		//set the texture of the enemy
		enemy.setTexture(enemyTexture);
		//
		
		
		/*enemy.setPosition(400, 0);*/




	}




	//testing the draw function for the enemy, we will be using this in the  

	/*void draw(RenderWindow& win)
	{
		win.draw(enemy);
	}*/


	//Delete this later, I just want to see if the png works
	//void EnemyMove()
	//{
	//	const float SPEED = 1.0f;
	//			
	//		
	//	enemy.move(0, SPEED);
	//		
	//	
	//}





};