#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	//Drawing space visible to user
	Square drawingSpace;
	//this rectangle is checked for the mouse when adding a shape
	Square drawRect;
public:
	/*============================================================================
	constructs the drawing ui shapes
	parameters - Vector2f p - posisiotn for drawing space
=============================================================================*/
	DrawingUI(Vector2f p)
	{
		//intialize valuse for ui drawing space
		drawingSpace.setPosition(p);
		drawingSpace.setSize(Vector2f(550.0f, 500.0f));
		drawingSpace.setColor(Color::White);
		drawingSpace.setFillColor(Color::Transparent);
		//initialize values for invisible drawing space
		drawRect.setPosition(Vector2f(204.0f, 54.0f));
		drawRect.setSize(Vector2f(502.0f, 452.0f));
		drawRect.setColor(Color::Transparent);
		drawRect.setFillColor(Color::Transparent);
	}
	/*============================================================================
	draw - draws the drawing ui
	parameters - RenderWindow& win ref to window
				, ShapeMgr *mgr - ref to the spae mgr
	return type - void
=============================================================================*/
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		//get pointer to shape vector
		vector<DrawingShape*> *vec = mgr->returnVecPtr();
		//draw the drawing space
		drawingSpace.draw(win);
		drawRect.draw(win);
		//draw shapes
		for (int i = 0; i < vec->size(); i++)
		{
			vec->operator[](i)->draw(win);
		}
	}
	/*============================================================================
	isMouseInCanvas - checks to see if the mouse is in the drawing canvas
	parameters - Vector2f mousePos - position of the mouse
	return type - bool
=============================================================================*/
	bool isMouseInCanvas(Vector2f mousePos)
	{
		//status flag
		bool mouseInCanvas = false;
		//check global bounds
		if (drawRect.getGlobalBounds().contains(mousePos))
		{
			mouseInCanvas = true;
		}
		return mouseInCanvas; 
	}
	/*============================================================================
	setDrawingSpaceSize - sets the drawing space size
	parameters - Vector2f newSize - new drawing space size (for variable sizes)
=============================================================================*/
	void setDrawingSpaceSize(Vector2f newSize)
	{
		drawRect.setSize(newSize);
	}
};

