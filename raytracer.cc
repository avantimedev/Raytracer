#include "raytracer.h"

// Todo: get drawable area, image, screen etc (put(x,y, color), height, width
bool Raytracer::render() {

	// Render target size
	int sizey = 640;
	int sizex = 480;

	std::cout << "Start rendering..." << std::endl;

	Vector direction(0.0, 0.0, 0.5);
	
	// Iterate over rays created from camera. No anti-aliasing (later monte carlo)
	for (int y = 0; y < sizey; ++y) 
		for (int x = 0; x < sizex; ++x) {	
			Vector start(double(x), double(y), -1000.0);
			Ray ray(start, direction);	
			if(trace(ray)) {
				// put color
			} else {
				// put background color
			}
	}
	return true;
}

bool Raytracer::trace(Ray &ray) {

	// Just ambient raytracing for now...

	Shape *shape;
	double t = 2000.0;
	if (this->scene.intersect(ray, t, shape) == false) {
		return false;
	}
	return true;
}
