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

#include "triangle.h"

std::string Triangle::toString() const {
	std::stringstream s;
	s << "Triangle";
	return s.str();
}

Vector Triangle::normalAt(Vector&) const {
	return (v1 - v2) ^ (v0 - v2);
}

bool Triangle::intersect(Ray& r, double& t) {
	
	// the moller-trumbore test
	Vector edge1, edge2, tvec, pvec, qvec;
	double det, inv_det;
	double u, v;
	
	edge1 = v1 - v0;
	edge2 = v2 - v0;
	pvec = r.getDirection() ^ edge2; // cross
	
	det = edge1 * pvec; // dot
	
	if (det > -0.000001 && det < 0.000001)
		return false;
		
	inv_det = 1.0 / det;
	
	tvec = r.getStart() - v0;
	u = (tvec * pvec) * inv_det;
	
	if (u < 0.0 || u > 1.0)
		return false;
		
	qvec = tvec ^ edge1; // cross
	v = (r.getDirection() * qvec) * inv_det;
	if (v < 0.0 || u + v > 1.0)
		return false;
		
	t = (edge2 * qvec) * inv_det;
	if (t > 0.0)
	return true;
}
