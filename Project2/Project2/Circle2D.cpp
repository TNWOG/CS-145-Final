#include "Circle2D.h"
#include <cmath>
#include <GL/glut.h>
#include "Scene.h"

using namespace std;

Circle2D::Circle2D(double x, double y, int color, double radius) : Shape2D(x,y,color)
{
	this->radius = radius;
}
//returns radius
double Circle2D::getRadius()
{
	return radius;
}
//returns area
double Circle2D::getArea() const
{
	double pi = 3.1415926535897;
	return pow(radius, 2) * pi;
}
//sets radius
void Circle2D::setRadius(double radius)
{
	this->radius = radius;
}
//puts out info about circle
ostream& Circle2D::toString(ostream& out) const
{
	out << "Circle: (" << getX() << ","
		<< getY() << ") Radius: " << radius << " Area: "
		<< getArea() << " Color " << (int)shapeColor->getBlue() << " " << (int)shapeColor->getGreen() << " " << (int)shapeColor->getRed() << " ";
	return out;
}
//moves shape each frame
void Circle2D::move()
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
//changes color each frame
void Circle2D::colorMove()
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
void Circle2D::draw()
{
	if (frames > (startDraw * DESIRED_FPS))
	{
		shapeColor->tellOpenGL();
		glPushMatrix();
		glTranslatef(getX(), getY(), 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0, 0);
		glVertex2f(sin(0)*radius, cos(0)*radius);
		glVertex2f(sin(.25)*radius, cos(.25)*radius);
		glVertex2f(sin(.5)*radius, cos(.5)*radius);
		glVertex2f(sin(.75)*radius, cos(.75)*radius);
		glVertex2f(sin(1)*radius, cos(1)*radius);
		glVertex2f(sin(1.25)*radius, cos(1.25)*radius);
		glVertex2f(sin(1.5)*radius, cos(1.5)*radius);
		glVertex2f(sin(1.75)*radius, cos(1.75)*radius);
		glVertex2f(sin(2)*radius, cos(2)*radius);
		glVertex2f(sin(2.25)*radius, cos(2.25)*radius);
		glVertex2f(sin(2.5)*radius, cos(2.5)*radius);
		glVertex2f(sin(2.75)*radius, cos(2.75)*radius);
		glVertex2f(sin(3)*radius, cos(3)*radius);
		glVertex2f(sin(3.25)*radius, cos(3.25)*radius);
		glVertex2f(sin(3.5)*radius, cos(3.5)*radius);
		glVertex2f(sin(3.75)*radius, cos(3.75)*radius);
		glVertex2f(sin(4)*radius, cos(4)*radius);
		glVertex2f(sin(4.25)*radius, cos(4.25)*radius);
		glVertex2f(sin(4.5)*radius, cos(4.5)*radius);
		glVertex2f(sin(4.75)*radius, cos(4.75)*radius);
		glVertex2f(sin(5)*radius, cos(5)*radius);
		glVertex2f(sin(5.25)*radius, cos(5.25)*radius);
		glVertex2f(sin(5.5)*radius, cos(5.5)*radius);
		glVertex2f(sin(5.75)*radius, cos(5.75)*radius);
		glVertex2f(sin(6)*radius, cos(6)*radius);
		glVertex2f(sin(6.25)*radius, cos(6.25)*radius);
		glVertex2f(sin(0)*radius, cos(0)*radius);
		glEnd();
		glPopMatrix();
	}
	frames++;
}
