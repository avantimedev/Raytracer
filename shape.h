#ifndef SHAPE_H
#define SHAPE_H

#include "ray.h"
#include "point.h"
#include "material.h"

class Shape {
public:
	Shape(const Material &material) : material(material) {}
	virtual ~Shape();
	virtual int intersect(Ray &r, float t) = 0;
private:
	const Material &material;
};

#endif
