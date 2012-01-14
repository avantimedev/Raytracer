/*
 * =====================================================================================
 *
 *       Filename:  point.cc
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

#include "ray.h"

Ray::Ray() {
}

Ray::Ray(const Vector& start, const Vector& direction) {
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


