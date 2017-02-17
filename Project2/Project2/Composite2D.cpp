#include "Composite2D.h"
#include "GLUTScene.h"



Composite2D::Composite2D(double x, double y, int color) : Shape2D(x, y, color)
{
}
//Adds Shape to Composite Shape
void Composite2D::addShape(Shape2D & nextShape)
{
	double a = getX();
	double b = getY();
	double x = nextShape.getX() + a;
	double y = nextShape.getY() + b;
	nextShape.setPosition(Point2D(x, y));
	shapes.push_back(&nextShape);
}
//Calls Shapes individual draw functions
void Composite2D::draw()
{
	if (frames > (startDraw * DESIRED_FPS))
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->draw();
		}
	}
	frames++;
}
//calls individual colorMove funtions
void Composite2D::colorMove()
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->colorMove();
	}
}
//Sets factor to move by each frame
void Composite2D::move()
{

	if (frames > (startAnim * DESIRED_FPS))
	{
		if ((gravity) && (getY() > floor))
		{
			yFactor = yFactor - rate;
			location.setX(location.getX() + xFactor);
			location.setY(location.getY() + yFactor);
			for (int i = 0; i < shapes.size(); i++)
			{
				double a = shapes[i]->getX();
				double b = shapes[i]->getY();
				shapes[i]->setPosition(a + xFactor, b + yFactor);
			}
		}
		else if ((currentMoveFrame < framesToMove) && (!gravity))
		{
			location.setX(location.getX() + xFactor);
			location.setY(location.getY() + yFactor);

			currentMoveFrame++;
			for (int i = 0; i < shapes.size(); i++)
			{
				double a = shapes[i]->getX();
				double b = shapes[i]->getY();
				shapes[i]->setPosition(a + xFactor, b + yFactor);
			}
		}
	}
}
//use for outputting to console
ostream & Composite2D::toString(ostream & out) const
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->toString(out);
	}
	return out;
}


Composite2D::~Composite2D()
{
}