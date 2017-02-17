#pragma once
#include "GLUTScene.h"
#include "Shape2D.h"
#include <vector>
class Scene 
	: public GLUTScene
{
private:
	vector<Shape2D*> shapes;
	double xPos;
	double yPos;
	double xSize;
	double ySize;
public:
	Scene(double xPos = 0, double yPos = 0, int xSize = 100, int ySize = 100);
	void setPosition(double xPos, double yPos);
	void setSize(double xSize, double ySize);
	void addShape(Shape2D& nextShape);
	void deleteShape(int index);
	void print();
	void draw() const;
	void nextFrame();
	int getShapeCount() const;
	Shape2D* getShape(int index);
	friend ostream& operator<<(ostream& out, Scene scene);
};
ostream& operator<<(ostream& out, Scene scene);
