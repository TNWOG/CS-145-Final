#pragma once
#include "Shape2D.h"
class Rectangle2D :
	public Shape2D
{
private:
	double width;
	double length;
public:
	Rectangle2D(double x, double y, int color, double width, double height);
	double getWidth();
	double getLength();
	void move();
	void colorMove();
	double getArea() const;
	void setBounds(double width, double length);

	ostream& toString(ostream& out) const;
	void draw();
};

