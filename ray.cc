#include "ray.h"

Ray::Ray() {
}

Ray::Ray(Vector &start, Vector &direction) {
	this->start = start;
	this->direction = direction;
}

const Vector& Ray::getStart() const {
	return start;
}

const Vector& Ray::getDirection() const {
	return direction;
}

std::ostream& operator<<(std::ostream& out, const Ray& r) {
	return out << "Ray: {" << r.start << ", " << r.direction << "}";
}


