/*
 * =====================================================================================
 *
 *       Filename:  shape.h
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
	Surface(const Material& material) : material(material), r((rand() / double(RAND_MAX))) {}
	virtual ~Surface();
	
	virtual int intersect(Ray& r, float& t) = 0;
	//virtual box boundingbox() = 0;
	virtual std::string toString() const;
	//const Material& getMaterial() const { return material; }
	//const Material* getMaterial() const { return &material; }
	const Color getColor() { return Color(0.1,0.0,0.0); }
	
	friend std::ostream& operator<<(std::ostream& out, const Surface& s);
private:	
	const double r;
	const Material& material;
};

#endif
