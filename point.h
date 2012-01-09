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
	Point();
	Point(double x, double y, double z);
private:
	double x;
	double y;
	double z;

	friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

#endif
