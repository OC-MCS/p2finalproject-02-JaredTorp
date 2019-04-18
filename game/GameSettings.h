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
	//======================================================
	// function name: GameSettings()
	// parameters: none
	// return type: none, constructor
	//======================================================
	GameSettings()
	{

		lives = 3; //set the amount of lives and store it in private data
		enemiesKilled = 0; //surely they can't kill enemies before the game starts
		level = 1; //sets to the first level
		dropRate = 120; //drops a bomb every 120 frames, 2 seconds
		isGameStarted = false; //because we dont want to start the game off the bat
	}

	//======================================================
	// function name: getLives()
	// parameters: none
	// return type: int- getting the number of lives
	//======================================================
	int getLives()
	{
		return lives; //return the lives
	}

	//======================================================
	// function name: getKilled()
	// parameters: none
	// return type: int- getting the number killed enemies
	//======================================================
	int getKilled()
	{
		return enemiesKilled; //returning the killed enemies
	}



	//======================================================
	// function name: LoseLife()
	// parameters: none
	// return type: void
	//======================================================
	void LoseLife()
	{
		lives--; //decrement the lives when lost
	}

	//======================================================
	// function name: EnemyKilled()
	// parameters: none
	// return type: void
	//======================================================
	void EnemyKilled()
	{
		enemiesKilled++; //increment the enemies killed
	}
	
	//======================================================
	// function name: setEnemyKilled()
	// parameters: int num, passing the number to set the killd
	// return type: void
	//======================================================
	void setEnemyKilled(int num)
	{
		enemiesKilled = num; //setting the number to enemieskilled
	}

	//======================================================
	// function name: getLevel()
	// parameters: none
	// return type: int num, return the integer level
	//======================================================
	int getLevel()
	{
		return level; //return the level
	}
	
	//======================================================
	// function name: setLevel()
	// parameters: int num, passing a number
	// return type: none, void
	//======================================================
	void setLevel(int num)
	{
		level = num;
	}

	//======================================================
	// function name: getDropRate()
	// parameters: none
	// return type: int, retruns the number of frames
	//======================================================
	int getDropRate()
	{
		return dropRate; //return the drop rate
	}
	
	//======================================================
	// function name: setDropRate()
	// parameters: int, sets the number of frames
	// return type: none
	//======================================================
	void setDropRate(int num)
	{
		dropRate = num;
	}
	
	//======================================================
	// function name: getGameStarted
	// parameters: none
	// return type: bool, will return true if the game is started
	//======================================================
	bool getGameStarted()
	{
		return isGameStarted; //return if the game is started
	}
	
	//======================================================
	// function name: setGameStarted
	// parameters: bool, we pass a bool to set the game started
	// return type: none
	//======================================================
	void setGameStarted(bool x)
	{
		isGameStarted = x;
	}
	//======================================================
	// function name: setLives
	// parameters: int num, to reset lives
	// return type: none, void
	//======================================================
	void setLives(int num)
	{
		lives = num; //set the lives equal to num

	}









};