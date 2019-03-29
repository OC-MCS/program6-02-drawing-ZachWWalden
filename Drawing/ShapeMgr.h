#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

short int colorToInteger(Color color);

Color intToColor(short int color);

// struct to represent 1 shape for the file
struct ShapesFile
{
	float radius;
	short int colorFile;
	ShapeEnum shape;
	Vector2f location;
};

class ShapeMgr
{
private:
	// main shape vector
	vector<DrawingShape *> shapeVec;
	// undo history shape vector (for undoing an undo)
	vector<DrawingShape*> redoHistoryVec;
public:
	/*============================================================================
	defaut constructor - sort of pointless I guess
=============================================================================*/
	ShapeMgr()
	{
	}
	/*============================================================================
	addShape - adds a new circle or square to the shape vector
	parameters - Vector2f pos - position of new shape
				, ShapeEnum whichShape - what kind of new shape
				, Color color - new shape's color
				, float radius - new shapes size
	return type - void
=============================================================================*/
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color, float radius)
	{
		// check if new shape thpe is a circle
		if (whichShape == CIRCLE)
		{
			// alloacte new Circle, add its address to the vector
			Circle* newCircle = new Circle(pos, color, color, radius);
			shapeVec.push_back(newCircle);
		}
		else
		{
			// alloacte new Circle, add its address to the vector
			Square* newSqaure = new Square(pos, color, color, radius);
			shapeVec.push_back(newSqaure);
		}

	}
	/*============================================================================
	readFile - reads in the settings from the file and sets the current settings to them
	parameters - fstream& fileIn - reference to the fstream from main
	returntype - void
=============================================================================*/
	void readFile(fstream &fileIn)
	{
		ShapesFile shapes;

		while (fileIn.read(reinterpret_cast<char*>(&shapes), sizeof(ShapesFile)))
		{
			// check if new shape thpe is a square
			Color newColor = intToColor(shapes.colorFile);
			if (shapes.shape == SQUARE)
			{
				// allocate, add to vec
				Square *newSquare = new Square(shapes.location, newColor, newColor, shapes.radius);
				shapeVec.push_back(newSquare);
			}
			else
			{
				//allocate add to vector
				Circle *newCircle = new Circle(shapes.location, newColor, newColor, shapes.radius);
				shapeVec.push_back(newCircle);
			}
		}
	}
	/*============================================================================
	writeFile - writes current settings to file
	parameters - fstream& fileIn - reference to the fstream from main
	returntype - void
=============================================================================*/
	void writeFile(fstream &fileOut)
	{
		ShapesFile shapes;
		//write
		for (int i = 0; i < shapeVec.size(); i++)
		{
			shapes.colorFile = colorToInteger(shapeVec[i]->getColor());
			shapes.shape = shapeVec[i]->getShape();
			shapes.location = shapeVec[i]->getLocation();
			shapes.radius = shapeVec[i]->getRadius();
			fileOut.write(reinterpret_cast<char*>(&shapes), sizeof(ShapesFile));
		}
	}
	/*============================================================================
	returnVecPtr() - returns a pointer to the shape vector
	return type - vector<DrawingShape*>*
=============================================================================*/
	vector<DrawingShape*>* returnVecPtr()
	{
		//make a pointer to the vector
		vector<DrawingShape*>* ptr = &shapeVec;
		return ptr;
	}
	/*============================================================================
	clearVector - clears the vector of shapes
	return type - void
=============================================================================*/
	void clearVector()
	{
		// clear vector
		for (int i = 0; i < shapeVec.size(); i++)
		{
			delete shapeVec[i];
		}
		shapeVec.clear();
	}
	/*============================================================================
	undo - remove the last shape that was added to the vector
	return type - void
=============================================================================*/
	void undo()
	{
		if (shapeVec.size() > 0)
		{
			redoHistoryVec.push_back(shapeVec.at(shapeVec.size() - 1));
			shapeVec.pop_back();
		}
	}
	/*============================================================================
	redo - redo the last undone shape 
	return type - void
=============================================================================*/
	void redo()
	{
		if (redoHistoryVec.size() > 0)
		{
			shapeVec.push_back(redoHistoryVec.at(redoHistoryVec.size() - 1));
			redoHistoryVec.pop_back();
		}

	}
};
