#include "scene.h"

int Scene::intersect(Ray &ray, float t, const Shape* shape) {
	// look for intersection between all shapes
	std::vector<Shape*>::iterator citr;
	for (citr = shapes.begin(); citr != shapes.end(); ++citr) {
		std::cout << (*citr) << std::endl;
		std::cout << ((Shape*)*citr)->intersect(ray, t);
	}

	return 0;
}
