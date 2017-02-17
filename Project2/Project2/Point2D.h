#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


#pragma once
class Point2D
{
private:
	double x, y;
public:
	//simple getters and setter setup
	//I felt like it was simple enough functions
	//to be just in the header. Future, more complex, functions
	//would be put in the normal .cpp file.
	Point2D(double x = 0, double y = 0) : x(x), y(y) {}
	void setY(double y)
	{
		this->y = y;
	}
	void setX(double x)
	{
		this->x = x;
	}
	double getX() const
	{
		return x;
	}
	double getY() const
	{
		return y;
	}
	friend ostream& operator<<(ostream& out, Point2D shape)
	{
			out << "(" << shape.getX() << "," << shape.getY() << ")";
			return out;
	}
};
ostream& operator<<(ostream& out, Point2D shape);
