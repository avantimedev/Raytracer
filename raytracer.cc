/*
 * =====================================================================================
 *
 *       Filename:  raytracer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/2012 20:49:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Johan Astborg (ja), into@avantimedev.net
 *        Company:  avantimedev
 *
 * =====================================================================================
 */

#include "raytracer.h"

// Todo: get drawable area, image, screen etc (put(x,y, color), height, width
bool Raytracer::render(Image &image) {

	// Render target size
	int sizey = image.getHeight();
	int sizex = image.getWidth();
	
	Color &background = scene.getBackground();
	
	//std::cout << background << std::endl;
	
	std::cout << "** Start rendering..." << std::endl;

	Vector direction(0.0, 0.0, 0.5);
	
		
	// Iterate over rays created from camera. No anti-aliasing (later monte carlo)
	for (int y = 0; y < sizey; ++y) 
		for (int x = 0; x < sizex; ++x) {	
			Vector start(double(x), double(y), -1000.0);
			Ray ray(start, direction);	
			Color c(0.0,0,0);
			if(trace(ray, c)) {
				// put color
				image.setColor(x, y, c);
			} else {
				// put background color
				image.setColor(x, y, background);
			}
	}
	return true;
}

bool Raytracer::trace(Ray &ray, Color &c) {

	// Just ambient raytracing for now...

	const Shape *shape;
	float t = 2000.0;
	if (this->scene.intersect(ray, t, shape) == false) {
		return false;
	}
	
	c += *(shape->getMaterial().getColor());
	
	// Trace lights
	// Raytracing works only for point and ambient lights
	std::vector<Light*>::iterator liter;
	for (liter = scene.getLights().begin(); liter != scene.getLights().end(); ++liter) {
		// ambient light
		Light *p = *liter;
		AmbientLight *al = dynamic_cast<AmbientLight*>(p);
		if (al != NULL) {
			c += al->getColor();
		}
		
		PointLight *P = dynamic_cast<PointLight*>(p);              
		if (P == NULL)
			continue;
		
	}
	
	return true;
}
