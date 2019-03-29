//================================================
//Zach Walden
// Program 6 Drawing
//================================================
#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;


void writeToFile(SettingsMgr & setMgr, ShapeMgr & shapMgr);
void readFromFile(SettingsMgr & setMgr, ShapeMgr &shapeMgr);
short int colorToInteger(Color color);
Color intToColor(short int color);


// Finish this code. Other than where it has comments telling you to 
// add code, you shouldn't need to add any logic to main to satisfy
// the requirements of this programming assignment

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(600);

	//initialize settings and shapes
	SettingsMgr settingsMgr(Color::Blue, ShapeEnum::CIRCLE, 20.0f);
	ShapeMgr    shapeMgr;
	// read in from file
	readFromFile(settingsMgr, shapeMgr);
	SettingsUI  settingsUI(&settingsMgr, &shapeMgr); 
	DrawingUI   drawingUI(Vector2f(200, 50));

	

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
			{
				window.close();
				writeToFile(settingsMgr, shapeMgr);
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos);
			}
			else if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));

				settingsUI.handleMouseHold(mousePos);

				// check to see if mouse is in the drawing area
				if (drawingUI.isMouseInCanvas(mousePos))
				{
					// add a shape to the list based on current settings
					drawingUI.setDrawingSpaceSize(Vector2f(543.0f - 2 * settingsMgr.getCurRadius(), 493.0f - 2 * settingsMgr.getCurRadius()));
					// handle mouse hold on buttons
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor(), settingsMgr.getCurRadius());
				}
			}
		}

		// The remainder of the body of the loop draws one frame of the animation
		window.clear(Color::Black);

		// this should draw the left hand side of the window (all of the settings info)
		settingsUI.draw(window);

		// this should draw the rectangle that encloses the drawing area, then draw the
		// shapes. This is passed the shapeMgr so that the drawingUI can get the shapes
		// in order to draw them. This redraws *all* of the shapes every frame.
		drawingUI.draw(window, &shapeMgr);

		window.display();
	} // end body of animation loop

	return 0;
}
/*============================================================================
	readFromFile - reads in settings and shapes from file
	parameters - SettingsMgr & setMgr ref to settings manager
				, ShapeMgr &shapeMgr ref to shape manager
=============================================================================*/
void readFromFile(SettingsMgr & setMgr, ShapeMgr &shapeMgr)
{
	
	
	fstream fileRead;
	fileRead.open("shapes.bin", ios::binary | ios::in);

	setMgr.readFile(fileRead);
	
	shapeMgr.readFile(fileRead);
	
	fileRead.close();
}
/*============================================================================
	writeToFile - writes settings and then shapes to file
	parameters - SettingsMgr & setMgr ref to settings manager
				, ShapeMgr &shapeMgr ref to shape manager
=============================================================================*/
void writeToFile(SettingsMgr & setMgr, ShapeMgr &shapMgr)
{
	fstream fileWrite;
	fileWrite.open("shapes.bin", ios::binary | ios::out);

	setMgr.writeFile(fileWrite);
	shapMgr.writeFile(fileWrite);
	
	fileWrite.close();
}
/*============================================================================
	colorToInteger - returns a short integer when given 1 of 4 Colors
	parameters - Color color - color to e converted
=============================================================================*/
short int colorToInteger(Color color)
{
	short int returnInt = -1;
	if (color == Color::Blue)
		returnInt = 0;
	else if (color == Color::Red)
		returnInt = 1;
	else if (color == Color::Green)
		returnInt = 2;
	else if (color == Color::White)
		returnInt = 4;

	return returnInt;
}
/*============================================================================
	intToColor - returns 1 of four Colors when given 1 of 4 short ints
	parameters - short int color - int used to store the shape's color in the file
=============================================================================*/
Color intToColor(short int color)
{
	Color newColor;

	if (color == 0)
		newColor = Color::Blue;
	else if (color == 1)
		newColor = Color::Red;
	else if (color == 2)
		newColor = Color::Green;
	else if (color == 4)
		newColor = Color::White;

	return newColor;
}