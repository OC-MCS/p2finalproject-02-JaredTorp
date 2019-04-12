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
	
	

public:
	


	//overloaded constructor that accepts an int for the "name" of the enemy and its position
	Enemy(Vector2f pos, Texture& enemyTexture)
	{

		
		//set the texture of the enemy
		enemy.setTexture(enemyTexture);

		enemy.setPosition(pos);
	}


	

	//testing the draw function for the enemy, we will be using this in the  

	void draw(RenderWindow& win)
	{
		win.draw(enemy);
	}


	//funtion to set the speed of the nemy
	void EnemyMove()
	{
		const float SPEED = 1.0f;
				
			
		enemy.move(0, SPEED);
			
		
	}



	




};