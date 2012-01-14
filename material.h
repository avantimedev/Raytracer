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
#include "point.h"

#include <cmath>

class Material {
public:
	Material();
	Material(const Color& color, double ka, double kd, double ks, double n, double kr) : color(color), ka(ka), kd(kd), ks(ks), n(n), kr(kr) {}

	//const Color& getColor(const Vector& point) const { return color; }
	
	const Color getColor(const Point& point) const {
		
		if (n == 100) {
			double x = point.getX();
			double y = point.getY();
			
			x = (x - floor(x / 1.0) * 1.0);
		  	y = (y - floor(y / 1.0) * 1.0);
			
			if (x < 0.5 && y < 0.5 || x > 0.5 && y > 0.5) return Color(0,0,0);
			return Color(1.0, 1.0, 1.0);
		}		
		return color;
	}
	
	double aCoeff() const { return ka; }
	double dCoeff() const { return kd; }
	double sCoeff() const { return ks; }
	double rCoeff() const { return kr; }
	
	friend std::ostream& operator<<(std::ostream& out, const Material& m);
private:
	const Color &color;
	double ka; // ambient coefficient
	double kd; // diffuse coefficient (eg ball bearings have low kd)
	double ks; // specular coefficient (how much light reflects of the surface)
	double n; // specular parameter
	double kr; // reflection coefficient
};

#endif
