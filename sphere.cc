/*
 * =====================================================================================
 *
 *       Filename:  sphere.cc
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

#include "sphere.h"
#include <cmath>

std::string Sphere::toString() const {
	std::stringstream s;
	s << "Sphere";
	return s.str();
}

Vector Sphere::normalAt(Vector& point) const {
	return (point - position).normalize();
}

bool Sphere::intersect(Ray& r, double& t) {

	const Vector v = r.getStart() - position;
	const double Denominator = 2.0 * r.getDirection().length() * r.getDirection().length();
	const double a = 2.0 * v * r.getDirection();
	const double Delta = (a * a) - (2 * Denominator) * (v.length() * v.length() - (radius * radius));
	
	if (Delta > 0.0) {
		const double b = std::sqrt(Delta);
		const double First = (-a - b) / Denominator;
		const double Second = (-a + b) / Denominator;
		if (First < Second && First > 0.001)
			t = First;
		else {
			if (Second > 0.001)
				t = Second;
			else {
				if (First > 0.001) 
					t = First;
				else return false;
			}
		}
		return true;
	}
	else return false;
}
