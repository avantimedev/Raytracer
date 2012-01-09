#include "plane.h"

std::string Plane::toString() const {
	std::stringstream s;
	s << "Plane";
	return s.str();
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
	return false;
}
