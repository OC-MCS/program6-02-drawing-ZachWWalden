#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

//struct to represent the sttings in the file
struct SettingsFile
{
	// stores radius
	float radius;
	// integer representation of color
	short int colorFile;
	// stores shape type
	ShapeEnum shape;
};

short int colorToInteger(Color color);
Color intToColor(short int color);
// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	//Shape setting
	ShapeEnum curShape;
	//color setting
	Color curColor;
	//radius setting
	float radius;
public:
	/*============================================================================
	SettingsMgr - constuctor for SettingsMgr
	parameters - Color startingColor the color setting the program starts with, 
				ShapeEnum startingShape the shape setting the program starts with,
				float startingRadius - the radius zetting the program starts with.
				
=============================================================================*/
	SettingsMgr(Color startingColor, ShapeEnum startingShape, float startingRadius)
	{
		curColor = startingColor;
		curShape = startingShape;
		radius = startingRadius;
	}
	/*============================================================================
	readFile - reads in the settings from the file and sets the current settings to them
	parameters - fstream& fileIn - reference to the fstream from main
	returntype - void
=============================================================================*/
	void readFile(fstream &fileIn)
	{
		// read from file
		SettingsFile settings;
		fileIn.read(reinterpret_cast<char*>(&settings), sizeof(SettingsFile));
		setCurShape(settings.shape);
		setCurColor(intToColor(settings.colorFile));
		setCurRadius(settings.radius);
	}
	/*============================================================================
	writeFile - writes current settings to file
	parameters - fstream& fileIn - reference to the fstream from main
	returntype - void
=============================================================================*/
	void writeFile(fstream &fileOut)
	{
		//write to file
		SettingsFile settings;

		settings.colorFile = colorToInteger(getCurColor());
		settings.shape = getCurShape();
		settings.radius = getCurRadius();

		fileOut.write(reinterpret_cast<char*>(&settings), sizeof(SettingsFile));
	}
	/*============================================================================
	getCurColor - returns the current color setting
	return type - Color
=============================================================================*/
	Color getCurColor()
	{
		return curColor; // just to make it compile 
	}
	/*============================================================================
	getCurShape - returns the current shape stting
	return type - ShapeEnum
=============================================================================*/
	ShapeEnum getCurShape()
	{
		return curShape; // just to make it compile;
	}
	/*============================================================================
	getCurRadius - returns the current radius setting
	return type - float
=============================================================================*/
	float getCurRadius()
	{
		return radius;
	}
	/*============================================================================
	setCurColor - sets the color setting to the passed color
	parameters - Color newColorSetting - new color
	return type - vois
=============================================================================*/
	void setCurColor(Color newColorSetting)
	{
		curColor = newColorSetting;
	}
	/*============================================================================
	setCurShape - sets the shape setting to the passed ShapeEnum
	parameters - ShapeEnum newShapeSetting - new shape setting
=============================================================================*/
	void setCurShape(ShapeEnum newShapeSetting)
	{
		curShape = newShapeSetting;
	}
	/*============================================================================
	setCurRadius - set the radius setting to the passed radius
	parameters - float newRadius - new radius setting
	return type - void
=============================================================================*/
	void setCurRadius(float newRadius)
	{
		radius = newRadius;
	}
	/*============================================================================
	incrementRadius increments the radius setting by 1
	return type - void
=============================================================================*/
	void incrementRadius()
	{
		// increment
		if (radius < 130.0f)
			radius++;
	}
	/*============================================================================
	decrementRadius - decrements the radius
	return type - void
=============================================================================*/
	void decrementRadius()
	{
		//decrement
		if (radius > 0.0f)
			radius--;
	}
};
