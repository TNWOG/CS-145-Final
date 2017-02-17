#pragma once

// This is the desired frames-per-second of the animation.
// Change this to control the speed of the animation. It is
// only approximate.  A value of 15 or greater is needed for
// smooth motion.
#define DESIRED_FPS		30

// This object contains all the logic necessary to create a window
// for drawing with OpenGL.  It uses the GLUT library and establishes
// standard display, reshape, and animation timer callback functions.
class GLUTScene
{
public:
	// Construct a new window with the given width and height
	GLUTScene(unsigned int width, unsigned int height);

	// Destroy the scene (overridden by child)
	virtual ~GLUTScene() {}

	// Call this once to start drawing the loop
	// Note: this takes control of the program and NEVER returns
	void startEventLoop();

	// Call these functions to start/stop the animation timer.
	// Note: by default, the animation timer is already started.
	static void startAnimationTimer();
	static void stopAnimationTimer();

	// Override this function to draw the scene.  It is called
	// automatically by the event loop every time the frame is
	// advanced (or you can force it by calling glutPostRedisplay())
	virtual void draw() const = 0;

	// Override this function to advance to the next frame of
	// animation.  The scene will automatically redraw AFTER
	// this function returns.
	virtual void nextFrame() = 0;

protected:
	// The current dimensions of the window
	unsigned int windowWidth, windowHeight;

	// The minimum amout of milliseconds between frames
	// Set DESIRED_FPS to initialize this value for a particular FPS
	//
	// Note: If it takes longer than this to draw the scene then the
	//		 time passed will be greater than this number.  This is
	//		 only a minimum.
	unsigned int timeoutMillis;

private:
	/* You should not need to mess with things below this line
	which is why they are private! */

	// Weather or not the animation timer is currently active.
	// When this is true, the animation timer will automatically
	// Reset itself using 'timeoutMillis'.  Access this through
	// the startAnimationTimer and stopAnimationTimer functions.
	static bool animationTimerActive;

	// The currently active scene for use with the events below
	static GLUTScene* activeScene;

	// Initialize the GLUT and OpenGL system
	static void initGLUT();

	// GLUT events handlers
	static void resizeEvent(int width, int height);
	static void drawEvent();
	static void timerEvent(int timerID);
};