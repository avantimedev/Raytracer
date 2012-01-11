/*
 * =====================================================================================
 *
 *       Filename:  plane.cc
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

#include "plane.h"

std::string Plane::toString() const {
	std::stringstream s;
	s << "Plane";
	return s.str();
}

Vector Plane::normalAt(Vector& point) const {
	return normal;
}

int Plane::intersect(Ray &r, float &t) {
	
	// 
	/*
	 
	 double tt = normal.dot_product(r.getStart()) + distance) / normal.dot(r.getDirection());
	 
	 if (t > 0.001) {
	 	t = tt;
	 	return true;
	 } 
	  
	*/
	
	double tt = (normal * r.getStart() + distance) / (normal * r.getDirection());
	
	if (t > 0.001) {
		t = tt;
		return true;
	}
	
	return false;
}
