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
	Color(const Color& color) : red(color.red), green(color.green), blue(color.blue) {}
	Color(double red, double green, double blue);
	
	double r() const;
	double g() const;
	double b() const;
	
	void operator+=(const Color& c);
	void operator/=(const double& d);
	void operator*=(const double& d);
	void operator+=(const double& d);
	void operator-=(const double& d);

	friend Color operator*(const Color& col, const double scalar);
	friend Color operator*(const double scalar, const Color& col);
	
	friend std::ostream& operator<<(std::ostream& out, const Color& c);
private:
	double red;
	double green;
	double blue;
};

#endif
