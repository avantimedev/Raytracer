/*
 * =====================================================================================
 *
 *       Filename:  light.h
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

#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "color.h"

class Light {
public:
	Light(const Color &color) : color(color) {}
	virtual ~Light() {}
	Color &getColor() { return color; }
private:
	Color color;
};

class PointLight : public Light {
public:
	PointLight(const Color &color) : Light(color) {}
	Vector &getPosition() { return pos; }
private:
	Vector pos;
};

class AmbientLight : public Light {
public:
	AmbientLight(const Color &color) : Light(color) {}
private:
};

#endif
