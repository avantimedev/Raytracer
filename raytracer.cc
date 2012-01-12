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
#include "camera.h"

#include <cmath>

// Todo: get drawable area, image, screen etc (put(x,y, color), height, width
bool Raytracer::render(Image &image) {

	// Render target size
	int sizey = image.getHeight();
	int sizex = image.getWidth();
	
	Color &background = scene.getBackground();
	
	//std::cout << background << std::endl;
	
	std::cout << "** Start rendering..." << std::endl;

//	Vector direction(0.0, 0.0, -1.0);
	
	// Camera at 0,0,0 look at 0,0,1?
	
	std::cout << rand() / double(RAND_MAX) << std::endl;
	
	// Camera(Vector &pos, Vector &dir, double fov = PI / 4.0) : pos(pos), dir(dir), fov(fov) { }
	Camera camera(Vector(0,0,0), Vector(0,0,0), PI / 5.0);
	camera.initView(sizex, sizey);
	
	// Iterate over rays created from camera. No anti-aliasing (later monte carlo)
	Color c((rand() / double(RAND_MAX)), 0.0, 0.0);	
	Color c2((rand() / double(RAND_MAX)), 0.0, 0.0);	
	for (int y = 0; y < sizey; ++y) 
		for (int x = 0; x < sizex; ++x) {	
			//Vector start(double(x), double(y), 1.0);			
			//Ray ray(start, direction);
			Ray ray = camera.rayAt(x,y);
			if(trace(ray, c)) {
				// Simple Supersampling (anti aliasing)
				/*
				for (double i=0;i<1.0;i+=0.25) {
					//Vector start(double(x)+i, double(y)+i, 1.0);			
					//Ray ray(start, direction);
					Ray ray = camera.rayAt(x,y);
					trace(ray, c2);
					c += c2;
					c /= 2.0;
				}*/
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

	Surface *surface = NULL;
	double t = 0.0;
	if (this->scene.intersect(ray, t, &surface) == false) {
		return false;
	}
	
	if (surface != 0) {
		//std::cout << surface << std::endl;
		//c = surface->getMaterial().getColor();
	}
	
	c = Color(0,0,0);
	
	//std::cout << surface->getMaterial() << std::endl;
	
	// Trace lights
	// Raytracing works only for point and ambient lights

	// TODO: Create shade function...	

	std::vector<Light*>::iterator liter;
	for (liter = scene.getLights().begin(); liter != scene.getLights().end(); ++liter) {
		// ambient light
		Light *p = *liter;
		
		AmbientLight *al = dynamic_cast<AmbientLight*>(p);
		if (al != NULL) {
			c += surface->getMaterial().getColor() * 0.9;
		}
		
		PointLight *pl = dynamic_cast<PointLight*>(p);              
		if (pl == NULL)
			continue;
		
		// Calculate light component from point light
		Vector newStart = (ray.getStart() + ray.getDirection() * t);
		Vector dist = (pl->getPosition() - newStart).normalize();
		Vector n = surface->normalAt(newStart);// newStart - surface->getPosition();

		// flip normal if pointing in wrong dir.
		if((n * ray.getDirection()) > 0.0) n=-n;

		// Check if in shadow (object in the way for ray from hit point to light source)
		// Create ray from point to PointLight
		//Vector newDir = t*ray.getDirection();
		Ray rayToLight = Ray(newStart, pl->getPosition().normalize());
		double tmax = (newStart - pl->getPosition().normalize()).length();
		//std::cout << tmax << std::endl;
		double tt = 0;
		//if (this->scene.intersect(rayToLight, tt, &surface) == true)
			//if (tt > 0 && tt < tmax) continue;
		//	continue;

		/*
		double temp = n * n;
		if (temp == 0.0) continue;
		temp = 1.0 / sqrt(temp);
		n = n * temp;
		*/
		if (n * dist >= 0.0f) {
			//Vector arg = (dist * (1/t)).normalize();
			Vector arg = (dist * (1/t));
			Ray lightRay(newStart, arg);
			
			float lambert = (lightRay.getDirection() * n);
			//Color c(lambert * 0.9, lambert* 0.0, lambert * 0.0);
			Color cl = pl->getColor();
			c += surface->getMaterial().getColor() * lambert;
			c += surface->getMaterial().getColor() * lambert;
			c += surface->getMaterial().getColor() * lambert;
			c += surface->getMaterial().getColor() * lambert;
			c += surface->getMaterial().getColor() * lambert;
			c += surface->getMaterial().getColor() * lambert;
			c += surface->getMaterial().getColor() * lambert;
			c += cl * lambert;

			//image.setColor(x, y, c);
		}	
	}
	
	return true;
}
