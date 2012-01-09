/*
 * =====================================================================================
 *
 *       Filename:  shape.cc
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
