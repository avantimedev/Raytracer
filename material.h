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

#include "color.h"

class Material {
public:
	Material();
	Material(Color &color, double reflection) : color(color), reflection(reflection) {}
	const Color *getColor() const { return &color; }
private:
	const Color color;
	double reflection;
};

#endif
