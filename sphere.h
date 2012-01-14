/*
 * =====================================================================================
 *
 *       Filename:  sphere.h
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

#ifndef SPHERE_H
#define SPHERE_H

#include "material.h"
#include "point.h"
#include "ray.h"
#include "surface.h"

class Sphere : public Surface {
public:
	Sphere(const Material& material, const Vector& position, double radius) : Surface(material) {
		this->position = position;
		this->radius = radius;
	}
	virtual std::string toString() const;
	virtual bool intersect(Ray& r, double& t);
	virtual Vector normalAt(Vector& point) const;

	virtual Point toUV(const Vector&) const {
		return Point(0,0);
	}
private:
	Vector position;
	double radius;
};

#endif
