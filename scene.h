#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "material.h"
#include "light.h"
#include "shape.h"
#include "color.h"

class Scene {
public:
	Scene(Color &background) : background(background) {}

	void addShape(Shape *shape);
	void addLight(Light *light);

	int intersect(Ray &ray, float t, const Shape* shape);

private:

	std::vector<Light*> lights;
	std::vector<Shape*> shapes;

	Color background;

	// Camera

	int width;
	int height;
};

#endif
