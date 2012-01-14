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


double Color::r() const {
	return red;
}

double Color::g() const {
	return green;
}

double Color::b() const {
	return blue;
}

void Color::operator+=(const Color& c) {
	red += c.red;
	green += c.green;
	blue += c.blue;	
}

void Color::operator/=(const double& d) {
	red /= d;
	green /= d;
	blue /= d;
}

void Color::operator*=(const double& d) {
	red *= d;
	green *= d;
	blue *= d;
}

void Color::operator+=(const double& d) {
	red += d;
	green += d;
	blue += d;
}

void Color::operator-=(const double& d) {
	red -= d;
	green -= d;
	blue -= d;
}

Color operator*(const Color& col, const double scalar) {
	return Color(col.red * scalar, col.green * scalar, col.blue * scalar);
}

Color operator*(const double scalar, const Color& col) {
	return Color(col.red * scalar, col.green * scalar, col.blue * scalar);
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
	return out << "Color: " << c.red << " " << c.green << " " << c.blue;
}