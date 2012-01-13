/*
 * =====================================================================================
 *
 *       Filename:  material.h
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

#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>

#include "color.h"
#include "vector.h"

class Material {
public:
	Material();
	Material(const Color &color, double ka, double kd, double ks, double n) : color(color), ka(ka), kd(kd), ks(ks), n(n) {}
	const Color& getColor() const { return color; }
	
	Color getColor(const Vector&) const {
		return color;
	}
	
	double aCoeff() { return ka; }
	double dCoeff() { return kd; }
	double sCoeff() { return ks; }
	friend std::ostream& operator<<(std::ostream& out, const Material& m);
private:
	const Color &color;
	double ka; // ambient coefficient
	double kd; // diffuse coefficient (eg ball bearings have low kd)
	double ks; // specular coefficient (how much light reflects of the surface)
	double n; // specular parameter
};

#endif
