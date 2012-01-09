#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

class Material {
public:
	Material();
	Material(Color &col, double reflection);
	Color *getColor();
private:
	Color col;
	double reflection;
};

#endif
