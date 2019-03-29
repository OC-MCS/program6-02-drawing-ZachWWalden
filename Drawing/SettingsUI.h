#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:

	//buttons
	Circle blueButton, redButton, greenButton, circleButton;
	Square squareButton, clearButton, undoButton, redoButton;
	Square radAdjustBot, radAdjustMid, radAdjustTop;

	//manager pointers
	SettingsMgr* mgrPtr;
	ShapeMgr* shapPtr;

	// text intializers
	Font font;
	Text text[9], radius;
	String words[9] = {"Undo", "Clear", "Selected Color", "Selected Shape", "Up", "Down", "Redo", "Resize", "Edit"};
	Vector2f wordPos[9] = { {30.0f, 118.0f},{30.0f, 58.0f},{30.0f, 150.0f},{30.0f, 400.0f}, {130.0f, 58.0f}, {120.0f, 118.0f}, {30.0f, 88.0f} , {113.0f, 28.0f}, {35.0f,28.0f} };
	Color wordColor[9] = { Color::Black, Color::Black, Color::White, Color::White, Color::Black, Color::Black, Color::Black, Color::White, Color::White};
	
	/*============================================================================
	initializeSettingsUI - intializes all settings ui elements
	return type - void
=============================================================================*/
	void initializeSettingUI()
	{
		if (!font.loadFromFile("arial.ttf"))
		{
			cout << "font load failed\n";
			exit(-1);
		}

		//intialize texts
		for (int i = 0; i < 9; i++)
		{
			text[i].setFont(font);
			text[i].setCharacterSize(20);
			text[i].setFillColor(wordColor[i]);
			text[i].setString(words[i]);
			text[i].setPosition(wordPos[i]);
		}

		//intialize radius setting display
		radius.setFont(font);
		radius.setCharacterSize(20);
		radius.setFillColor(Color::Black);
		radius.setString(getString());
		radius.setPosition(Vector2f(135.0f, 88.0f));

		//intialize radius adjust top button
		radAdjustTop.setPosition(Vector2f(120.0f, 60.0f));
		radAdjustTop.setColor(Color::White);
		radAdjustTop.setFillColor(Color::White);
		radAdjustTop.setSize(Vector2f(50.0f, 20.0f));

		//initialize rect to hold the text of radius setting
		radAdjustMid.setPosition(Vector2f(120.0f, 90.0f));
		radAdjustMid.setColor(Color::White);
		radAdjustMid.setFillColor(Color::White);
		radAdjustMid.setSize(Vector2f(50.0f, 20.0f));

		//intialize radius adjust bottom button
		radAdjustBot.setPosition(Vector2f(120.0f, 120.0f));
		radAdjustBot.setColor(Color::White);
		radAdjustBot.setFillColor(Color::White);
		radAdjustBot.setSize(Vector2f(50.0f, 20.0f));

		// initialize the clear button
		clearButton.setPosition(Vector2f(30.0f, 60.0f));
		clearButton.setColor(Color::White);
		clearButton.setFillColor(Color::White);
		clearButton.setSize(Vector2f(50.0f, 20.0f));

		// initialize the undo button
		undoButton.setPosition(Vector2f(30.0f, 120.0f));
		undoButton.setColor(Color::White);
		undoButton.setFillColor(Color::White);
		undoButton.setSize(Vector2f(50.0f, 20.0f));

		//initialize the redo button
		redoButton.setPosition(Vector2f(30.0f, 90.0f));
		redoButton.setColor(Color::White);
		redoButton.setFillColor(Color::White);
		redoButton.setSize(Vector2f(50.0f, 20.0f));

		//initialize the blue color button
		blueButton.setPosition(Vector2f(73.0f, 190.0f));
		blueButton.setColor(Color::Blue);
		blueButton.setRadius(20.0f);
		if (mgrPtr->getCurColor() == Color::Blue)
			blueButton.setFillColor(Color::Blue);
		
		//initialize the red color button
		redButton.setPosition(Vector2f(73.0f, 250.0f));
		redButton.setColor(Color::Red);
		redButton.setRadius(20.0f);
		if (mgrPtr->getCurColor() == Color::Red)
			redButton.setFillColor(Color::Red);

		//initialize the green color button
		greenButton.setPosition(Vector2f(73.0f, 310.0f));
		greenButton.setColor(Color::Green);
		greenButton.setRadius(20.0f);
		if (mgrPtr->getCurColor() == Color::Green)
			greenButton.setFillColor(Color::Green);

		//initialize the circle shape button
		circleButton.setPosition(Vector2f(73.0f,440.0f));
		circleButton.setColor(Color::White);
		circleButton.setRadius(20.0f);
		if (mgrPtr->getCurShape() == CIRCLE)
			circleButton.setFillColor(Color::White);

		//initialize the square shape button
		squareButton.setPosition(Vector2f(73.0f, 500.0f));
		squareButton.setColor(Color::White);
		squareButton.setSize(Vector2f(35.0f, 35.0f));
		if (mgrPtr->getCurShape() == SQUARE)
			squareButton.setFillColor(Color::White);
	}
	/*============================================================================
	getString - returns a string for the current radius setting
	return type - String
=============================================================================*/
	String getString()
	{
		return to_string(static_cast<int>(mgrPtr->getCurRadius()));
	}
public:
	/*============================================================================
	constructs the settings ui
	parameters - SettingsMgr *mgr - pointer to the settings manager,
				ShapeMgr* shapePtr - pointer the the shape manager
=============================================================================*/
	SettingsUI(SettingsMgr *mgr, ShapeMgr* shapePtr)
	{
		//intialize pointers and buttons
		mgrPtr = mgr;
		shapPtr = shapePtr;
		initializeSettingUI();
	}
	/*============================================================================
	handleMouseUp - handles when the left mouse button is released
	parameters - Vector2f mouse - mouse position
	return type - void
=============================================================================*/
	void handleMouseUp(Vector2f mouse)
	{
		//check which button was pressed
		if (blueButton.getGlobalBounds().contains(mouse))
		{
			mgrPtr->setCurColor(Color::Blue);
			blueButton.setFillColor(Color::Blue);
			redButton.setFillColor(Color::Transparent);
			greenButton.setFillColor(Color::Transparent);
		}
		else if(redButton.getGlobalBounds().contains(mouse))
		{
			mgrPtr->setCurColor(Color::Red);
			redButton.setFillColor(Color::Red);
			blueButton.setFillColor(Color::Transparent);
			greenButton.setFillColor(Color::Transparent);
		}
		else if (greenButton.getGlobalBounds().contains(mouse))
		{
			mgrPtr->setCurColor(Color::Green);
			greenButton.setFillColor(Color::Green);
			blueButton.setFillColor(Color::Transparent);
			redButton.setFillColor(Color::Transparent);
		}
		else if (circleButton.getGlobalBounds().contains(mouse))
		{
			mgrPtr->setCurShape(CIRCLE);
			circleButton.setFillColor(Color::White);
			squareButton.setFillColor(Color::Transparent);
		}
		else if (squareButton.getGlobalBounds().contains(mouse))
		{
			mgrPtr->setCurShape(SQUARE);
			squareButton.setFillColor(Color::White);
			circleButton.setFillColor(Color::Transparent);
		}
		else if (clearButton.getGlobalBounds().contains(mouse))
		{
			shapPtr->clearVector();
		}
	}
	/*============================================================================
	handleMouseHold - handles when the left mouse button is held
	parameters - Vector2f mouse - mouse position
	return type - void
=============================================================================*/
	void handleMouseHold(Vector2f mouse)
	{
		// check which button was pressed
		if (radAdjustTop.getGlobalBounds().contains(mouse))
		{
		mgrPtr->incrementRadius();
		}
		else if (radAdjustBot.getGlobalBounds().contains(mouse))
		{
		mgrPtr->decrementRadius();
		}
		else if (undoButton.getGlobalBounds().contains(mouse))
		{
			shapPtr->undo();
		}
		else if (redoButton.getGlobalBounds().contains(mouse))
		{
			shapPtr->redo();
		}
	}
	/*============================================================================
	draw - draws the settings ui
	parameters - RenderWindow& win - ref to the graphics windoww
=============================================================================*/
	void draw(RenderWindow& win)
	{
		// draw ui
		radAdjustTop.draw(win);
		radAdjustMid.draw(win);
		radAdjustBot.draw(win);
		clearButton.draw(win);
		undoButton.draw(win);
		blueButton.draw(win);
		redButton.draw(win);
		greenButton.draw(win);
		circleButton.draw(win);
		squareButton.draw(win);
		redoButton.draw(win);

		radius.setString(getString());
		win.draw(radius);
		for (int i = 0; i < 9; i++)
		{
			win.draw(text[i]);
		}

	}

};
