#include "material.h"
#include "point.h"
#include "ray.h"

class Sphere {
public:
	Sphere();
	Sphere(Material &material, Vector &position, double radius);

	Material *getMaterial();
	bool intersect(const Ray &r, float &t);
private:
	Material material;	
	Vector position;
	double radius;
};
