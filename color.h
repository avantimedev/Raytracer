/*
 * =====================================================================================
 *
 *       Filename:  color.h
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

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
public:
	Color();
	Color(const Color &color) : red(color.red), green(color.green), blue(color.blue) {}
	Color(double red, double green, double blue);
	
	double r() const;
	double r();
	double g();
	double b();
	
	void operator+=(const Color &c);
	
	friend std::ostream& operator<<(std::ostream& out, const Color& c);
private:
	double red;
	double green;
	double blue;
};

#endif
