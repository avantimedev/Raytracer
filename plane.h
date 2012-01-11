/*
 * =====================================================================================
 *
 *       Filename:  plane.h
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

#ifndef PLANE_H
#define PLANE_H

#include "surface.h"
#include "material.h"
#include "vector.h"

class Plane: public Surface {
public:
	Plane(const Vector normal, const double distance, Material &material) : Surface(material), normal(normal), distance(distance) {}
	virtual std::string toString() const;
	virtual int intersect(Ray &r, float &t);
	virtual Vector normalAt(Vector& point) const;
private:
	const Vector normal;
	const double distance;
};

#endif
