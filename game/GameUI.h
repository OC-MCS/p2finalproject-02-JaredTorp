#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameSettings.h"

using namespace std;
using namespace sf;

class GameUI
{
private:
RectangleShape StartBtn; //rectangleshape for the button
Vector2f StartPos; //position of the start button



public:

	//======================================================
	// function name: GameUI
	// parameters: none
	// return type: none, constructor
	//======================================================
	GameUI()
	{
		//set the position
		StartPos.x = 300;
		StartPos.y = 250;
		
		StartBtn.setPosition(StartPos); //set the position of the button
		StartBtn.setOutlineColor(Color::Cyan); //cyan
		StartBtn.setOutlineThickness(2); //2 thickness
		StartBtn.setSize(Vector2f(225, 100)); //sets the size
		StartBtn.setFillColor(Color::Transparent); //transparentfill
		
	}

	//======================================================
	// function name: drawStart
	// parameters: RenderWindow to draw it
	// return type: none, void
	//======================================================
	void drawStart(RenderWindow& win)
	{
		//draw the start button
		//load the font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}
		
		//text for the Start button
		Text ScreenText("Jared Torp's ''Amazing'' Game", font, 50);
		ScreenText.setPosition(100, 100); //sets the position
		win.draw(ScreenText); //draw the string

		


		//text for the Start button
		Text StartText("START", font, 70);
		StartText.setPosition(StartPos.x, StartPos.y); //sets the position
		win.draw(StartText); //draw the string

		win.draw(StartBtn); //draw the button


	}
	
	//======================================================
	// function name: setGameStarted
	// parameters:	RenderWindow& win- pass this to draw
	//GameSettings& obj - passing the gamesettings object by reference 
	// return type: none, void
	//======================================================
	void drawGame(RenderWindow& win, GameSettings& obj)
	{
		
		//draw the lives counter
		//load the font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		//text for the Start button
		Text Lives("Lives: " + to_string(obj.getLives())  , font, 25); //draws the lives and gets the lives
		Lives.setFillColor(Color::Cyan);
		Lives.setPosition(5, 3); //want to position it in the top left corner
		win.draw(Lives); //draw the string


		Text Enemies("Aliens Killed: " + to_string(obj.getKilled()), font, 25);//draws the killed and gets the killed
		Enemies.setFillColor(Color::Cyan);
		Enemies.setPosition(575, 3); //want the position in the top right corner
		win.draw(Enemies); //draw the string

	}

	

	
	
	
	//======================================================
	// function name: handleMouseUp
	// parameters:	Vector2f mouse- pass the position of the mouse
	//GameSettings& obj - passing the gamesettings object by reference 
	// return type: none, void
	//======================================================
	void handleMouseUp(Vector2f mouse, GameSettings& obj)
	{
		if (StartBtn.getGlobalBounds().contains(mouse)) //mouse is a Vector2f
		{
			//get rid of the Start Button
			//get rid of the screen
			//run the game
			obj.setGameStarted(true) ; //this will start level 1
			
		}
	}





	//======================================================
	// function name: die
	// parameters: string msg- we pass the message if failed
	// return type: none, its a void
	//======================================================
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}



	//======================================================
	// function name: drawWinner
	// parameters: REnderWindow&- to draw
	// return type: none, its a void
	//======================================================
	void drawWinner(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text WinText("A Winner Is You!", font, 30); //creates a text object for the winner
		WinText.setFillColor(Color::White); 
		WinText.setPosition(300, 400); //sets the position lower than the start button
		win.draw(WinText); //draw
	}
	
	//======================================================
	// function name: drawLoser
	// parameters: REnderWindow&- to draw
	// return type: none, its a void
	//======================================================
	void drawLoser(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text LoseText("The Aliens Win!", font, 30);//creates a text object for the Loser
		LoseText.setFillColor(Color::Green); //green aliens
		LoseText.setPosition(300, 400); //sets the position lower than the start button
		win.draw(LoseText); //draw
	}
	
};