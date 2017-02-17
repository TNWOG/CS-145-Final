#include "Rectangle2D.h"
#include <cmath>
#include <GL/glut.h>
#include "Scene.h"

using namespace std;

Rectangle2D::Rectangle2D(double x, double y, int color, double width, double height) : Shape2D(x, y, color)
{
	this->width = width;
	this->length = height;
}
//returns width
double Rectangle2D::getWidth()
{
	return width;
}
//returns length
double Rectangle2D::getLength()
{
	return length;
}
//returns area
double Rectangle2D::getArea() const
{
	return length*width;
}
//sets bounds
void Rectangle2D::setBounds(double width, double length)
{
	this->width = width;
	this->length = length;
}
//puts out info about shape
ostream& Rectangle2D::toString(ostream& out) const
{
	out << "Rectangle: (" << getX() << ","
		<< getY() << ") Area: "
		<< getArea() << " Color: " << (int)shapeColor->getBlue() << " " << (int)shapeColor->getGreen() << " " << (int)shapeColor->getRed() << " ";
	return out;
}
//moves the object by the factor each frame
void Rectangle2D::move()
{

	if (frames > (startAnim * DESIRED_FPS))
	{
		if ((gravity) && (getY() > floor))
		{
			yFactor = yFactor - rate;
			location.setX(location.getX() + xFactor);
			location.setY(location.getY() + yFactor);
		}
		else if ((currentMoveFrame < framesToMove) && (!gravity))
		{
			location.setX(location.getX() + xFactor);
			location.setY(location.getY() + yFactor);

			currentMoveFrame++;
		}
	}
}
//each frame incrementally changes color
void Rectangle2D::colorMove()
{
	if ((currentColorFrame < framesToColor) && (frames > startColor * DESIRED_FPS))
	{
		double frameRatioColor = currentColorFrame / (double)framesToColor;
		unsigned char red = (1.0 - frameRatioColor)*(aColor->getRed()) + (frameRatioColor)*(bColor->getRed());
		unsigned char green = (1.0 - frameRatioColor)*(aColor->getGreen()) + (frameRatioColor)*(bColor->getGreen());
		unsigned char blue = (1.0 - frameRatioColor)*(aColor->getBlue()) + (frameRatioColor)*(bColor->getBlue());
		shapeColor = new Color(red, green, blue);
		currentColorFrame++;
		 
	}
}
//draws shape
void Rectangle2D::draw()
{
	if (frames > (startDraw * DESIRED_FPS))
	{
		shapeColor->tellOpenGL();
		glPushMatrix();
		glTranslatef(getX(), getY(), 0);
		glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(width, 0);
		glVertex2f(width, -length);
		glVertex2f(0, -length);
		glEnd();
		glPopMatrix();
	}
	frames++;
}
