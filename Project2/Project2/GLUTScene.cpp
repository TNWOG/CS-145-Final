#include "GLUTScene.h"

#include <gl/glut.h>
#include <gl/GL.h>

#define TIMER_ANIMATION_ID	255

GLUTScene* GLUTScene::activeScene = NULL;
bool GLUTScene::animationTimerActive = true;

GLUTScene::GLUTScene(unsigned int width, unsigned int height)
	: windowWidth(width), windowHeight(height)
{
	// Compute the proper milliseconds for the desired frames-per-second
	timeoutMillis = 1000 / DESIRED_FPS;
}

void GLUTScene::startEventLoop()
{
	// Make this the active scene
	activeScene = this;

	// Initialize GLUT and OpenGL
	initGLUT();

	// Start the GLUT event loop
	glutMainLoop();
}

void GLUTScene::startAnimationTimer()
{
	// Check if the animation timer is already running
	if (!animationTimerActive)
	{
		// Make the animation timer as active
		animationTimerActive = true;

		// Set the first timer event to fire
		glutTimerFunc(activeScene->timeoutMillis,
			GLUTScene::timerEvent, TIMER_ANIMATION_ID);
	}
}

void GLUTScene::stopAnimationTimer()
{
	// Make the animation timer inactive
	// This causes the timer event to stop resetting itself
	animationTimerActive = false;
}

void GLUTScene::initGLUT()
{
	// init GLUT
	int fakeArgc = 1;
	char** fakeArgv = new char*[1];
	fakeArgv[0] = "nothing.exe";
	glutInit(&fakeArgc, fakeArgv);
	delete[] fakeArgv;

	// Setup the window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(activeScene->windowWidth, activeScene->windowHeight);
	glutCreateWindow("My 2D Scene");

	// Establish our event callback functions
	glutDisplayFunc(GLUTScene::drawEvent);
	glutReshapeFunc(GLUTScene::resizeEvent);

	// Set the first timer callback if it is active
	if (animationTimerActive)
	{
		glutTimerFunc(activeScene->timeoutMillis,
			GLUTScene::timerEvent, TIMER_ANIMATION_ID);
	}
}

void GLUTScene::resizeEvent(int width, int height)
{
	// Copy the new window dimensions
	activeScene->windowWidth = (unsigned int)width;
	activeScene->windowHeight = (unsigned int)height;

	// Setup the mapping from scene to pixel coordinates
	glViewport(0, 0, width, height);

	// Setup the projection matrix for simple 2D coordinates
	// in units of pixels
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	gluOrtho2D(0, width - 1, 0, height - 1);

	// Return to the model-view matrix and clear it
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
}

void GLUTScene::drawEvent()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the scene
	if (activeScene != NULL)
	{
		activeScene->draw();
	}

	// Swap buffers
	glutSwapBuffers();
}

// Called when the timer triggers
void GLUTScene::timerEvent(int timerID)
{
	// Make sure this is our animation timer
	if (timerID == TIMER_ANIMATION_ID)
	{
		// Check if the animation is still active
		if (animationTimerActive)
		{
			// Request a new timer event so this happens in a continuous loop
			glutTimerFunc(activeScene->timeoutMillis,
				GLUTScene::timerEvent, TIMER_ANIMATION_ID);

			// Advance the active scene to the next frame (you implement this!)
			activeScene->nextFrame();

			// Request that the scene update (causes draw() to be called)
			glutPostRedisplay();
		}
	}
}