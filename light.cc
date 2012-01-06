#include "light.h"

Light::Light() {
}

Light::Light(Point &pos, Color &col) {
	this->pos = pos;
	this->col = col;
}
