#pragma once

const int NUM_LIVES = 3;

class GameSettings
{
private:
	int lives; //we keep track the amount of lives that the player has
	int enemiesKilled; //we keep track of the number of enemies killed
	int level; //to keep track of the level

public:
	//constructor
	GameSettings()
	{

		lives = NUM_LIVES; //set the amount of lives and store it in private data
		enemiesKilled = 0; //surely they can't kill enemies before the game starts
		level = 0; //everyone starts at the start screen
	}

	//getter for lives
	int getLives()
	{
		return lives;
	}

	//getter for The enemies killed
	int getKilled()
	{
		return enemiesKilled;
	}


	//we want to check to see if we need to end the game after the player dies
	bool isGameOver()
	{
		//returns true or false if lives = zero
		return (lives == 0); 
	
	}

	//this function decrements the lives if a bomb hits them or the enemies get too close
	void LoseLife()
	{
		lives--;
	}

	//this will increment the enemies killed
	void EnemyKilled()
	{
		enemiesKilled++;
	}

	int getLevel()
	{
		return level;
	}

	void setLevel(int num)
	{
		level = num;
	}










};