/*
 * =====================================================================================
 *
 *       Filename:  point.h
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

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
	
	double getX() const { return x; }
	double getY() const { return y; }
	
private:
	double x;
	double y;

	friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

#endif
