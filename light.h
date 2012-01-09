#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "color.h"

class Light {
public:
	Light();
	Light(Vector &pos, Color &col);
private:
	Vector pos;
	Color col;
};

#endif
