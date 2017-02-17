#include "Color.h"

#include <GL/glut.h>
#include <cstdio>
#include <cmath>

#define GAMMA	(1.0/2.2)

Color::Color(unsigned char red, unsigned char green, unsigned char blue,
	unsigned char alpha)
{
	// Copy the color channels
	vals[0] = red;
	vals[1] = green;
	vals[2] = blue;
	vals[3] = alpha;

	// Apply gamma correction (will look dim without this)
	gammaEncode();
}

Color::Color(unsigned int RGBHex, unsigned char alpha)
{
	// Copy the alpha value
	vals[3] = alpha;

	// Separate out the red, green, and blue from the hex value
	vals[2] = (unsigned char)(RGBHex & 0x0000FF);
	vals[1] = (unsigned char)((RGBHex & 0x00FF00) >> 8);
	vals[0] = (unsigned char)((RGBHex & 0xFF0000) >> 16);

	// This is here to help with debugging should something be wrong with colors.
	// Note: If you uncomment this you will get extra output.
	//printf("#%6X --> [%u, %u, %u]\n", RGBHex, vals[0], vals[1], vals[2]);

	// Note: Web hex values usually do not need gamma correction
}

void Color::tellOpenGL() const
{
	// Set this color as the currently active OpenGL color
	glColor4ubv((const GLubyte*)vals);
}

// Getters for the different components of this color
unsigned char Color::getRed() const { return vals[0]; }
unsigned char Color::getGreen() const { return vals[1]; }
unsigned char Color::getBlue() const { return vals[2]; }
unsigned char Color::getAlpha() const { return vals[3]; }

// Gamma correction: this brightens the color slightly so that
// it looks correct on the monitor.  Adjust GAMMA above to modify.
// (see https://en.wikipedia.org/wiki/Gamma_correction for details)
void Color::gammaEncode()
{
	double Rf = pow(vals[0] / 255.0, GAMMA);
	double Gf = pow(vals[1] / 255.0, GAMMA);
	double Bf = pow(vals[2] / 255.0, GAMMA);

	vals[0] = (unsigned char)floor(Rf * 255 + 0.5);
	vals[1] = (unsigned char)floor(Gf * 255 + 0.5);
	vals[2] = (unsigned char)floor(Bf * 255 + 0.5);
}