#include "Color.h"
#include "Point2D.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#pragma once
class Shape2D
{
protected:
	int frames;
	bool gravity;
	double rate;
	double floor;
	int framesToMove;
	int currentMoveFrame;
	double xFactor;
	double yFactor;
	int framesToColor;
	int currentColorFrame;
	Color* aColor;
	Color* bColor;
	Color* shapeColor;
	Point2D location;
	
public:
	double startAnim = 0;
	double startDraw = 0;
	double startColor = 0;
	Shape2D(double x, double y, int color);
	~Shape2D();
	void setPosition(double x, double y);
	void setPosition(Point2D location);
	void setColor(int color);

	void colorGrad(int a, int b, double time);
	//changes color slightly each frame
	virtual void colorMove()=0;
	void moveTo(double x, double y, double time);
	//changes position slightly each frame
	void Gravity(bool gravity, double rate, double floor);
	virtual void move() = 0;
	double getX() const;
	double getY() const;
	Color getColor() const;
	virtual ostream& toString(ostream& out) const = 0;
	//draws shape each frame
	virtual void draw() = 0;
	friend ostream& operator<<(ostream& out, const Shape2D& shape);
};
ostream& operator<<(ostream& out, const Shape2D& shape);
