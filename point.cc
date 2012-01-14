#include "point.h"

std::ostream& operator<<(std::ostream& out, const Point& p) {
	return out << "Point: {" << p.x << ", " << p.y << "}";
}
