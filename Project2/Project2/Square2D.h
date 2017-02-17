#pragma once
#include "Shape2D.h"
class Square2D :
	public Shape2D
{
private:
	double length;
public:
	Square2D(double x, double y, int color, double length);
	double getLength();
	double getArea() const;
	void move();
	void colorMove();
	void setBounds(double length);
	ostream& toString(ostream& out) const;
	void draw();
};
