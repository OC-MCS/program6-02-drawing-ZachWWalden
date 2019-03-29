#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class DrawingShape 
{
//data
private:

public:
//functions
private:
public:
	/*============================================================================
	default constructor - I think this was required to compile, not sure it has been awhile
=============================================================================*/
	DrawingShape()
	{

	}
	/*============================================================================
	virtual draw - pure virtual function for drawing a shape
	return type - void
=============================================================================*/
	virtual void draw(RenderWindow& win) = 0;
	/*============================================================================
	virtual getShape - polymorphic function for returning shape setting
	return type - ShapeEnum
=============================================================================*/
	virtual ShapeEnum getShape()
	{
		return SQUARE;
	}
	/*============================================================================
	virtual getColor - polymorphic function to return the color of the shape
	return type - Color
=============================================================================*/
	virtual Color getColor()
	{
		return Color::Blue;
	}
	/*============================================================================
	virtual getLocation() - polymorphic function to return shape loaction
	return type - Vector2f
=============================================================================*/
	virtual Vector2f getLocation()
	{
		return Vector2f(1.0f, 1.0f);
	}
	/*============================================================================
	virtual getRadius - pure virtual function for getting a shapes radius setting
	return type - float
=============================================================================*/
	virtual float getRadius() = 0;
	/*============================================================================
	setRadius - polymorphic function for setting the radius
	parameters float newRadius - new setting for the radius
	rturn type - void
=============================================================================*/
	virtual void setRadius(float newRadius)
	{

	}
};
class Circle : public DrawingShape
{
	//data
private:
	// shape color
	Color color;
	// shape fill color
	Color fillColor;
	//shape type
	ShapeEnum shape = CIRCLE;
	//shape location
	Vector2f curLoc;
	// shape radius
	float radius;
	// grapics lib circle shape object
	CircleShape circ;
	
	//functions
public:
	/*============================================================================
	default constructor - compiler griped without it
=============================================================================*/
	Circle()
	{

	}
	/*============================================================================
	Circle - constructor for Circle
	parameters - Vector2f pos position for new  circle
				, Color newColor color for new circle
				, Color newFillColor fill color for new circle
				, float newRadius radius for new circle
=============================================================================*/
	Circle(Vector2f pos, Color newColor, Color newFillColor, float newRadius) : DrawingShape()
	{
		curLoc = pos;
		color = newColor;
		fillColor = newFillColor;
		radius = newRadius;
	}
	/*============================================================================
	draw - draw function that overrides from base class
	parameters - RenderWindow& win reference to the window
	return type - void
=============================================================================*/
	virtual void draw(RenderWindow& win)
	{
		circ.setPosition(curLoc);
		circ.setRadius(radius);
		circ.setOutlineThickness(2);
		circ.setOutlineColor(color);
		circ.setFillColor(fillColor);
		win.draw(circ);
	}
	/*============================================================================
	setColor - sets the color of the shape
	parameters - Color newColor - new color for the shape
	return type - void
=============================================================================*/
	void setColor(Color newColor)
	{
		color = newColor;
	}
	/*============================================================================
	setPosition - sets a new position for the shape
	parameters - Vector2f newPos - new position
	return type - void
=============================================================================*/
	void setPosition(Vector2f newPos)
	{
		curLoc = newPos;
	}
	/*============================================================================
	setFillColor - sets the fill color for the shape
	parameters - Color newFillColor new fill color for the shape
	return type - void
=============================================================================*/
	void setFillColor(Color newFillColor)
	{
		fillColor = newFillColor;
	}
	/*============================================================================
	getShape - returns what kind of shape this is
	return type - ShapeEnum
=============================================================================*/
	ShapeEnum getShape()
	{
		return shape;
	}
	/*============================================================================
	getColor - returns shape's color
	return type - Color
=============================================================================*/
	Color getColor()
	{
		return color;
	}
	/*============================================================================
	getLocation - returns shapes loaction
	return type - Vector2f
=============================================================================*/
	Vector2f getLocation()
	{
		return curLoc;
	}
	/*============================================================================
	getRadius - returns the shape's radius
	return type - float
=============================================================================*/
	float getRadius()
	{
		return radius;
	}
	/*============================================================================
	setRadius - sets a new radius for the circle
	prameters - float newRadius - new radius
	return type - vois
=============================================================================*/
	void setRadius(float newRadius)
	{
		radius = newRadius;
	}
	/*============================================================================
	getGlobalBounds - returns the global bouns of the shape
	return type - FloatRect
=============================================================================*/
	FloatRect getGlobalBounds()
	{
		return circ.getGlobalBounds();
	}
};
class Square :  public DrawingShape
{
//data
private:
	// shape color
	Color color;
	// shape fill color
	Color fillColor;
	// shape type
	ShapeEnum shape = SQUARE;
	// shape loaction
	Vector2f curLoc;
	// shape size
	float radius;
	// graphics lib rectangle object
	RectangleShape rect;
	
//functions
private:
public:
	/*============================================================================
	default cons - needed to compile to my knowledge
=============================================================================*/
	Square()
	{

	}
	/*============================================================================
	constructor for Square 
	parameters - Vector2f pos new posistion
				, Color newColor - new color
				, Color newFillColor - new fill color
				, float newRadius - new radius
=============================================================================*/
	Square(Vector2f pos, Color newColor, Color newFillColor, float newRadius) : DrawingShape()
	{
		curLoc = pos;
		color = newColor;
		fillColor = newFillColor;
		radius = newRadius;
		rect.setSize(Vector2f(2*radius, 2*radius));
	}
	/*============================================================================
	draw - draw function that overrides from base class
	parameters - RenderWindow& win reference to the window
	return type - void
=============================================================================*/
	virtual void draw(RenderWindow& win)
	{
		rect.setPosition(curLoc);
		rect.setOutlineColor(color);
		rect.setOutlineThickness(2);
		rect.setFillColor(fillColor);
		
		// renders a RectangleShape
		win.draw(rect);

	}
	/*============================================================================
	setColor - sets the color of the shape
	parameters - Color newColor - new color for the shape
	return type - void
=============================================================================*/
	void setColor(Color newColor)
	{
		color = newColor;
	}
	/*============================================================================
	setPosition - sets a new position for the shape
	parameters - Vector2f newPos - new position
	return type - void
=============================================================================*/
	void setPosition(Vector2f newPos)
	{
		curLoc = newPos;
	}
	/*============================================================================
	setFillColor - sets the fill color for the shape
	parameters - Color newFillColor new fill color for the shape
	return type - void
=============================================================================*/
	void setFillColor(Color newFillColor)
	{
		fillColor = newFillColor;
	}
	/*============================================================================
	setSize - sets the size of the square
	parameters - Vector2f - size - new size
	return type - void
=============================================================================*/
	void setSize(Vector2f size)
	{
		rect.setSize(size);
	}
	/*============================================================================
	getColor - returns shape's color
	return type - Color
=============================================================================*/
	ShapeEnum getShape()
	{
		return shape;
	}
	/*============================================================================
	getColor - returns shape's color
	return type - Color
=============================================================================*/
	Color getColor()
	{
		return color;
	}
	/*============================================================================
	getLocation - returns shapes loaction
	return type - Vector2f
=============================================================================*/
	Vector2f getLocation()
	{
		return curLoc;
	}
	/*============================================================================
	setRadius - sets a new radius for the circle
	prameters - float newRadius - new radius
	return type - vois
=============================================================================*/
	float getRadius()
	{
		return radius;
	}
	/*============================================================================
	setRadius - sets a new radius for the circle
	prameters - float newRadius - new radius
	return type - vois
=============================================================================*/
	void setRadius(float newRadius)
	{
		radius = newRadius;
	}
	/*============================================================================
	getGlobalBounds - returns the global bouns of the shape
	return type - FloatRect
=============================================================================*/
	FloatRect getGlobalBounds()
	{
		return rect.getGlobalBounds();
	}
};



