#include "scene.h"

int Scene::intersect(Ray &ray, float t, const Shape* shape) {
	// look for intersection between all shapes
	std::vector<Shape*>::iterator citr;
	for (citr = shapes.begin(); citr != shapes.end(); ++citr) {
		//std::cout << (*citr) << std::endl;
		if ((*citr)->intersect(ray, t)) {
			std::cout << "Intersect: " << (**citr) << std::endl;
			shape = *citr;
		}
	}

	return 0;
}

void Scene::addShape(Shape *shape) {
	shapes.push_back(shape);	
}

void Scene::addLight(Light *light) {
	lights.push_back(light);
}

Color& Scene::getBackground() {
	return background;
}
