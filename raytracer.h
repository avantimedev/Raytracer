#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "ray.h"
#include "scene.h"

class Raytracer {
public:
	Raytracer(Scene &scene) : scene(scene) {}
	bool render();
private:
	Scene &scene;
	bool trace(Ray &ray);
};

#endif
