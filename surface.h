/*
 * =====================================================================================
 *
 *       Filename:  surface.h
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

#ifndef SURFACE_H
#define SURFACE_H

#include "ray.h"
#include "point.h"
#include "material.h"

#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Surface {
public:
	Surface(const Material& material) : material(material) {}
	//Surface(const Color& color) : color(color) {}
	virtual ~Surface();
	
	virtual bool intersect(Ray& r, double& t) = 0;
	//virtual box boundingbox() = 0;
	virtual std::string toString() const;
	
	virtual Vector normalAt(Vector& point) const = 0;
	
	const Material& getMaterial() const { return material; }
	
	virtual Vector toUV(const Vector &Point) const = 0;
  
	const Color colorAt(const Vector& point) const {
		return material.getColor(toUV(point));
	}
	
	//const Material* getMaterial() const { return &material; }
	//const Color& getColor() const { return color; }
	
	friend std::ostream& operator<<(std::ostream& out, const Surface& s);
private:	
	const Material& material;
	//const Color& color;
};

#endif
