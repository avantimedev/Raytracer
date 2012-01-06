#include "ray.h"
#include "point.h"

class Shape {
public:
	Shape();
	int intersect(Ray &r);
	int inside(Point &pt);
private:
};
