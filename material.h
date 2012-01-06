#include "color.h"

class Material {
public:
	Material();
	Material(Color &col, double reflection);
private:
	Color col;
	double reflection;
};
