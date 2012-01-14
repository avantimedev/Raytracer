#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "surface.h"
#include "material.h"
#include "vector.h"

class Triangle: public Surface {
public:
	Triangle(const Material& material, const Vector& v0, const Vector& v1, const Vector& v2) : Surface(material), v0(v0), v1(v1), v2(v2) {}
	virtual std::string toString() const;
	virtual bool intersect(Ray& r, double& t);
	virtual Vector normalAt(Vector& point) const;

	virtual Point toUV(const Vector& point) const {
		return Point(point.getX(), point.getZ());
	}
  
private:
	const Vector v0;
	const Vector v1;
	const Vector v2;
};

#endif