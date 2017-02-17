#pragma once
#include "Shape2D.h"
class Circle2D :
	public Shape2D
{
private:
	double radius;
public:
	Circle2D(double x = 0, double y = 0, int color = COLOR_WHITE, double radius = 0);
	double getRadius();
	void move();
	void colorMove();
	double getArea() const;
	void setRadius(double radius);
	ostream& toString(ostream& out) const;
	void draw();
};
