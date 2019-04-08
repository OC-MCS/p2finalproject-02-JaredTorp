#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class GameUI
{
private:
RectangleShape StartBtn;
Vector2f StartPos; //is manually setting the button bad?
bool isGameStarted;

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
		
		//set the game started equal to false, because we don't start the game right off the bat
		isGameStarted = false;
	}

	//to draw the start button
	void draw(RenderWindow& win)
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

	void handleMouseUp(Vector2f mouse)
	{
		if (StartBtn.getGlobalBounds().contains(mouse)) //mouse is a Vector2f
		{
			//get rid of the Start Button
			//get rid of the screen
			//run the game
			isGameStarted = true;
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

	bool getGameStarted() const
	{
		return isGameStarted;
	}
};