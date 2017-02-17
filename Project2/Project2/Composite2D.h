#pragma once
#include "Shape2D.h"
#include <vector>
#pragma once
class Composite2D :
	public Shape2D
{
private:
	vector<Shape2D*> shapes;
public:
	Composite2D(double x, double y, int color = COLOR_WHITE);
	void addShape(Shape2D &nextShape);
	void draw();
	void colorMove();
	void move();
	ostream& toString(ostream& out) const;

	~Composite2D();
};

