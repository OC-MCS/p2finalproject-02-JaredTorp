#pragma once


class GameSettings
{
private:
	int lives; //we keep track the amount of lives that the player has
	int enemiesKilled; //we keep track of the number of enemies killed
	int level; //to keep track of the level
	int dropRate; //to keep track of the frequency of things being dropped
	bool isGameStarted; //to see if the game has started

public:
	//constructor
	GameSettings()
	{

		lives = 3; //set the amount of lives and store it in private data
		enemiesKilled = 0; //surely they can't kill enemies before the game starts
		level = 1; //sets to the first level
		dropRate = 120; //drops a bomb every 120 frames, 2 seconds
		isGameStarted = false; //because we dont want to start the game off the bat
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

	int getDropRate()
	{
		return dropRate;
	}

	void setDropRate(int num)
	{
		dropRate = num;
	}
	
	//to check if the game has started
	bool getGameStarted()
	{
		return isGameStarted;
	}

	void setGameStarted(bool x)
	{
		isGameStarted = x;
	}

	void setLives(int num)
	{
		lives = num;

	}









};