#include "raytracer.h"

bool Raytracer::render() {

	int sizey = 640;
	int sizex = 480;
	Vector direction(0.0, 0.0, 0.5);
	
	for (int y = 0; y < sizey; ++y) 
		for (int x = 0; x < sizex; ++x) {	
			Vector start(double(x), double(y), -1000.0);
			Ray ray(start, direction);
			trace(ray);		
	}
	return true;
}

bool Raytracer::trace(Ray &ray) {

	Shape *shape;
	double t = 2000.0;
	if (this->scene.intersect(ray, t, shape) == false) {
		return false;
	}
	return true;
}
