#pragma once

#include "Shape2D.h"
class Triangle2D :
	public Shape2D
{
private:
	Point2D a, b, c;
public:
	Triangle2D(Point2D a, Point2D b, Point2D c, int color);
	void setA(Point2D a);
	void setB(Point2D b);
	void setC(Point2D c);
	Point2D getA();
	Point2D getB();
	Point2D getC();
	void move();
	void colorMove();
	void draw();
	ostream& toString(ostream& out) const;
};
