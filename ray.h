/*
 * =====================================================================================
 *
 *       Filename:  ray.h
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

#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vector.h"

class Ray {
public:
	Ray();
	Ray(const Vector& start, const Vector& direction);

	const Vector& getStart() const;
	const Vector& getDirection() const;
	
	Vector pointAt(double l) {
		return start + (direction * l);
	}
	
	Ray reflectAt(Vector& normal, Vector& point) {
		Vector tmp = normal * (2 * (normal * direction));
		return Ray(point, direction - tmp);
		//return Ray(normal, point);
	}
	
private:
	Vector start;
	Vector direction;

	friend std::ostream& operator<<(std::ostream& out, const Ray& r);
};

#endif
