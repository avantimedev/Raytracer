#include "color.h"

Color::Color() {
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(double red, double green, double blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

double Color::r() {
	return red;
}

double Color::g() {
	return green;
}

double Color::b() {
	return blue;
}
