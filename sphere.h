#ifndef SPHERE_H
#define SPHERE_H

#include "material.h"
#include "point.h"
#include "ray.h"
#include "shape.h"

class Sphere : public Shape {
public:
	Sphere(Material &material, Vector &position, double radius) : Shape(material) {
		this->position = position;
		this->radius = radius;
	}
	virtual int intersect(Ray &r, float t);
private:
	Vector position;
	double radius;
};

#endif
