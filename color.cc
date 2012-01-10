/*
 * =====================================================================================
 *
 *       Filename:  color.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/2012 20:49:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Johan Astborg (ja), into@avantimedev.net
 *        Company:  avantimedev
 *
 * =====================================================================================
 */

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

double Color::r() const {
	return red;
}

double Color::g() {
	return green;
}

double Color::b() {
	return blue;
}

void Color::operator+=(const Color &c) {
	red += c.red;
	green += c.green;
	blue += c.blue;	
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
	return out << "Color: " << c.red << " " << c.green << " " << c.blue;
}