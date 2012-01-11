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

/*
Sphere::Sphere(Material &material, Vector &position, double radius) {
	this->material = material;
	this->position = position;
	this->radius = radius;
}*/
/*
Material *Sphere::getMaterial() {
	return &material;
}*/

std::string Sphere::toString() const {
	std::stringstream s;
	s << "Sphere";
	return s.str();
}

Vector Sphere::normalAt(Vector& point) const {
	return (point - position).normalize();
}

int Sphere::intersect(Ray &r, double &t) {
	/*
	double a = r.getDirection() * r.getDirection();
	double b = 2 * (r.getDirection() * r.getStart());
	double c = (r.getStart() - position) * (r.getStart() - position) - radius * radius;

	float disc = b * b - 4 * a * c;

	if (disc < 0) return false;
	
	double distSqrt = sqrt(disc);
	double q;
	if (b < 0) {
        q = (-b - distSqrt)/2.0;
    } else {
        q = (-b + distSqrt)/2.0;
	}
	double t0 = q / a;
    double t1 = c / q;

    if (t0 > t1) {      
        double temp = t0;
        t0 = t1;
        t1 = temp;
    }

	if (t1 < 0)
        return false;

 	if (t0 < 0) {
       	t = t1;
        return true;
    } else {
        t = t0;
        return true;
    }*/
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
	return false;
}
