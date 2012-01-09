#ifndef PLANE_H
#define PLANE_H

#include "shape.h"
#include "material.h"

class Plane: public Shape {
public:
	Plane(Material &material) : Shape(material) {}
	virtual std::string toString() const;
	virtual int intersect(Ray &r, float t);
private:
};

#endif
