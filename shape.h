#ifndef SHAPE_H
#define SHAPE_H

#include "ray.h"
#include "point.h"
#include "material.h"

#include <string>
#include <sstream>
#include <iostream>

class Shape {
public:
	Shape(const Material &material) : material(material) {}
	virtual ~Shape();
	virtual int intersect(Ray &r, float t) = 0;
	virtual std::string toString() const;

	friend std::ostream& operator<<(std::ostream& out, const Shape& s);
private:
	const Material &material;
};

#endif
