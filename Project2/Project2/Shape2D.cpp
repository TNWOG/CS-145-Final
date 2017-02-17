#include "GLUTScene.h"
#include "Shape2D.h"
#include "Color.h"
int color;


Shape2D::Shape2D(double x, double y, int color) : location(Point2D(x,y))
{
	shapeColor = new Color(color);
}
//sets position
Shape2D::~Shape2D()
{
	delete shapeColor;
	delete aColor;
	delete bColor;
}
void Shape2D::setPosition(double x, double y)
{
	Point2D temp(x, y);
	location = temp;
}
//sets position using point2D
void Shape2D::setPosition(Point2D location)
{
	this->location = location;
}
//sets color
void Shape2D :: setColor(int color)
{
	shapeColor = new Color(color);
}
//sets color to change to
void Shape2D::colorGrad(int a, int b, double time)
{
	this->aColor = new Color(a);
	this->bColor = new Color(b);
	framesToColor = time *DESIRED_FPS;
	currentColorFrame = 0;
}
//sets factor to move by each frame
void Shape2D::moveTo(double x, double y, double time)
{
	framesToMove = time *DESIRED_FPS;
	xFactor = (x - location.getX()) / framesToMove;
	yFactor = (y - location.getY()) / framesToMove;
	currentMoveFrame = 0;
}
//adds gravity 
void Shape2D::Gravity(bool gravity, double rate, double floor)
{
	this->rate = rate;
	this->gravity = gravity;
	this->floor = floor;
}

//return x
double Shape2D::getX() const
{
	return location.getX();
}
//return y
double Shape2D::getY() const
{
	return location.getY();
}
//return color
Color Shape2D::getColor() const
{
	return *shapeColor;
}
//overloads out operator
ostream& operator<<(ostream& out, const Shape2D& shape)
{
	shape.toString(out);
	return out;
}