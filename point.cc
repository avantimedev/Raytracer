#include "point.h"

Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
	return out << "Point: {" << p.x << ", " << p.y << ", " << p.z << "}";
}
