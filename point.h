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
