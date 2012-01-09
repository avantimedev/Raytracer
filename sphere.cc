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

int Sphere::intersect(Ray &r, float &t) {

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
    }
}
