#include "material.h"

Material::Material() {
	reflection = 0;
}

Material::Material(Color &col, double reflection) {
	this->col = col;
	this->reflection = reflection;
}
