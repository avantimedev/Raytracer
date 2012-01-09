#include "plane.h"

std::string Plane::toString() const {
	std::stringstream s;
	s << "Plane";
	return s.str();
}

int Plane::intersect(Ray &r, float t) {
	return false;
}
