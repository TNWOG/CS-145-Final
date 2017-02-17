#include "Scene.h"
#include "GLUTScene.h"



//initializes the scene
Scene::Scene(double xPos, double yPos, int xSize, int ySize) : GLUTScene(xSize, ySize)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->xSize = xSize;
	this->ySize = ySize;
}
//sets its position in the frame
void Scene::setPosition(double xPos, double yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
}
//sets size
void Scene::setSize(double xSize, double ySize)
{
	this->xSize = xSize;
	this->ySize = ySize;
}
//adds by reference a shape to the vector
void Scene::addShape(Shape2D& nextShape)
{
	shapes.push_back(&nextShape);
}
//deletes a shape in the vector
void Scene::deleteShape(int index)
{
	shapes.erase(shapes.begin()+index);
}
//adds a complex shape made of multiple shapes

//returns the amount of shapes in the vector
int Scene::getShapeCount() const
{
	return shapes.size();
}
//returns a shape
Shape2D* Scene::getShape(int index)
{
	return shapes[index];
}
//prints all the shapes
void Scene::print()
{
	cout << "Objects Present: " << endl;
	for (int i = 0; i < getShapeCount(); i++)
	{
		cout << *shapes[i] << endl;
	}
}
void Scene::draw() const
{
	
	for (int i = 0; i < getShapeCount(); i++)
	{
		shapes[i]->draw();
	}
}
void Scene::nextFrame()
{
	static unsigned int counter;
	
	for (int i = 0; i < getShapeCount(); i++)
	{
		shapes[i]->move();
	}
	for (int i = 0; i < getShapeCount(); i++)
	{
		shapes[i]->colorMove();
	}
	if (counter > DESIRED_FPS * 4)
	{
		//print(); //calls every objects print, will stall with lots of objects
		counter = 0;
	}
	counter++;
}
