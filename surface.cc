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

#include "surface.h"

Surface::~Surface() {
}

std::string Surface::toString() const {
	std::stringstream s;
	s << "Surface";
	return s.str();
}

std::ostream& operator<<(std::ostream& out, const Surface& s) {
	return out << s.toString();
}
