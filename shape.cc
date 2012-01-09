#include "shape.h"

Shape::~Shape() {
}


std::string Shape::toString() const {
	std::stringstream s;
	s << "Shape";
	return s.str();
}

std::ostream& operator<<(std::ostream& out, const Shape& s) {
	return out << s.toString();
}
