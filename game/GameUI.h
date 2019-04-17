#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameSettings.h"

using namespace std;
using namespace sf;

class GameUI
{
private:
RectangleShape StartBtn;
Vector2f StartPos; //is manually setting the button bad?



public:
	GameUI()
	{
		//set the position
		StartPos.x = 300;
		StartPos.y = 250;
		
		StartBtn.setPosition(StartPos);
		StartBtn.setOutlineColor(Color::Cyan);
		StartBtn.setOutlineThickness(2);
		StartBtn.setSize(Vector2f(225, 100));
		StartBtn.setFillColor(Color::Transparent);
		
	}

	//to draw the start button once the game starts we use the next draw function
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
		ScreenText.setPosition(100, 100);
		win.draw(ScreenText); //draw the string

		


		//text for the Start button
		Text StartText("START", font, 70);
		StartText.setPosition(StartPos.x, StartPos.y);
		win.draw(StartText); //draw the string

		win.draw(StartBtn);


	}

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
		Text Lives("Lives: " + to_string(obj.getLives())  , font, 25);
		Lives.setFillColor(Color::Red);
		Lives.setPosition(5, 3); //want to position it in the top left corner
		win.draw(Lives); //draw the string


		Text Enemies("Aliens Killed: " + to_string(obj.getKilled()), font, 25);
		Enemies.setFillColor(Color::Red);
		Enemies.setPosition(575, 3);
		win.draw(Enemies);

	}

	

	
	
	
	//handles pressing the start button
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

	void drawWinner(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text WinText("A Winner Is You!", font, 30);
		WinText.setFillColor(Color::White);
		WinText.setPosition(300, 400);
		win.draw(WinText);
	}

	void drawLoser(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text LoseText("The Aliens Win!", font, 30);
		LoseText.setFillColor(Color::Green);
		LoseText.setPosition(300, 400);
		win.draw(LoseText);
	}
	
};