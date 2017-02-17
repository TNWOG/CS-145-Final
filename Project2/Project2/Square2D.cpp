#include "Square2D.h"
#include <cmath>
#include <GL/glut.h>
#include "Scene.h"

using namespace std;

Square2D::Square2D(double x, double y, int color, double length) : Shape2D(x, y, color)
{
	this->length = length;
}
//returns length
double Square2D::getLength()
{
	return length;
}
//returns area
double Square2D::getArea() const
{
	return length*length;
}
//sets size
void Square2D::setBounds(double length)
{

	this->length = length;
}
//puts out info
ostream& Square2D::toString(ostream& out) const
{
	out << "Square: (" << getX() << ","
		<< getY() << ") Area: "
		<< getArea() << " Color: " << (int)shapeColor->getBlue() << " " << (int)shapeColor->getGreen() << " " << (int)shapeColor->getRed() << " ";
	return out;
}
//changes position slightly each frame
void Square2D::move()
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
//changes color slightly each frame
void Square2D::colorMove()
{
	if ((currentColorFrame < framesToColor) && (frames > startColor * DESIRED_FPS))
	{
		double frameRatioColor = currentColorFrame / (double)framesToColor;
		unsigned char red = (1 - frameRatioColor)*aColor->getRed() + (frameRatioColor)*bColor->getRed();
		unsigned char green = (1 - frameRatioColor)*aColor->getGreen() + (frameRatioColor)*bColor->getGreen();
		unsigned char blue = (1 - frameRatioColor)*aColor->getBlue() + (frameRatioColor)*bColor->getBlue();
		shapeColor = new Color(red, green, blue);
		currentColorFrame++;
	}
}
//draws shape each frame
void Square2D::draw()
{
	if (frames > (startDraw * DESIRED_FPS))
	{
		shapeColor->tellOpenGL();
		glPushMatrix();
		glTranslatef(getX(), getY(), 0);
		glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(length, 0);
		glVertex2f(length, -length);
		glVertex2f(0, -length);
		glEnd();
		glPopMatrix();
	}
	frames++;
}
