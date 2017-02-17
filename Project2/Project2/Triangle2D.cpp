#include "Triangle2D.h"
#include <GL/glut.h>
#include "Scene.h"

//point2d based approach to creating triangles, more freedom and control
//using 'a' point for main location, seems like a sensical choice since first point
Triangle2D::Triangle2D(Point2D a, Point2D b, Point2D c, int color):  Shape2D(a.getX(), a.getY(), color), a(a), b(b), c(c)
{

}
//sets a
void Triangle2D::setA(Point2D a)
{
	this->a = a;
}

void Triangle2D::setB(Point2D b)
{
	this->b = b;
}
void Triangle2D::setC(Point2D c)
{
	this->c = c;
}
//returns a
Point2D Triangle2D::getA()
{
	return a;
}
Point2D Triangle2D::getB()
{
	return b;
}
Point2D Triangle2D::getC()
{
	return c;
}
//moves slightly each frame
void Triangle2D::move()
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
void Triangle2D::colorMove()
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
void Triangle2D::draw()
{
	if (frames > (startDraw * DESIRED_FPS))
	{
		shapeColor->tellOpenGL();
		glPushMatrix();
		glTranslatef(getX(), getY(), 0);
		glBegin(GL_TRIANGLES);
		glVertex2f(0, 0);
		glVertex2f(b.getX() - a.getX(), b.getY() - a.getY());
		glVertex2f(c.getX() - a.getX(), c.getY() - a.getY());
		glEnd();
		glPopMatrix();
	}
	frames++;
}
//puts out info
ostream& Triangle2D::toString(ostream& out) const
{
	out << "Triangle A: " << a << " B: " << b
		<< " C: " << c << " Color: " << (int)shapeColor->getBlue() << " " << (int)shapeColor->getGreen() << " " << (int)shapeColor->getRed() << " ";
	return out;
}