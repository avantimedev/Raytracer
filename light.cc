#include "light.h"

Light::Light() {
}

Light::Light(Vector &pos, Color &col) {
	this->pos = pos;
	this->col = col;
}
