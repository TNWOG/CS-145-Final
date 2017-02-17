#include "Shape2D.h"
#include "Circle2D.h"
#include "Square2D.h"
#include "Rectangle2D.h"
#include "Triangle2D.h"
#include "Composite2D.h"
#include "Scene.h"
#include "Point2D.h"
#include <gl/glut.h>
#include <cstdlib>
#include <ctime>


int main(int argc, char** argv) {
	Scene scene(0, 0, 800, 600);
	//Background
	Rectangle2D sky(0, 600, COLOR_LIGHTBLUE, 800, 600);
	Rectangle2D land(0, 100, COLOR_GREEN, 800, 100);
	land.colorGrad(COLOR_GREEN, 0x090909, 5);
	land.startColor = 3;
	Composite2D set(0, 0);
	set.addShape(sky); set.addShape(land);
	//Volcano
	Triangle2D left(Point2D(75, 100), Point2D(375, 100), Point2D(375, 300), COLOR_DARKGRAY);
	Triangle2D right(Point2D(425, 100), Point2D(425, 300), Point2D(725, 100), COLOR_DARKGRAY);
	Rectangle2D center(375, 300, COLOR_DARKGRAY, 50, 200);
	Composite2D Volcano(0, 0);
	Volcano.addShape(left); Volcano.addShape(right); Volcano.addShape(center);

	//lava
	int lavaNum = 5000; // number of circles, the larger, the more lag :/
	Circle2D * lava = new Circle2D[lavaNum];
	srand(unsigned(time(NULL)));
	for (int i = 0;i < lavaNum; i++)
	{
		double loc = (double)rand() / (RAND_MAX + 1);
		double siz = (double)rand() / (RAND_MAX + 1);
		double start = (double)rand() / (RAND_MAX + 1);
		double fun = siz/loc; //Change fun to any of the  3 above for different and COOL results!!!
		lava[i] = *(new Circle2D(400, 295, COLOR_ORANGE, 1 + siz*4));
		lava[i].moveTo(loc*800, 800, .8 + siz);
		lava[i].Gravity(true, 1, 105);
		lava[i].startDraw = 2.5 + (5 * fun);
		lava[i].startAnim = 2.5 + (5 * fun);
		lava[i].colorGrad(COLOR_ORANGE, COLOR_BLACK, 2);
		lava[i].startColor = 2.5 + (9 * fun);
	}

	scene.addShape(set);
	scene.addShape(Volcano);
	for (int i = 0; i < lavaNum; i++)
	{
		scene.addShape(lava[i]);
	}
	scene.startEventLoop();

	return 0;
}