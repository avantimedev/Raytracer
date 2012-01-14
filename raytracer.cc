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
bool Raytracer::render(Image& image) {

	// Render target size
	int sizey = image.getHeight();
	int sizex = image.getWidth();
	
	Color &background = scene.getBackground();
	
	Camera camera(Vector(0,0,0), Vector(0,0,0), PI / 5.0);
	camera.initView(sizex, sizey);
	
	Color c((rand() / double(RAND_MAX)), 0.0, 0.0);	
	Color c2((rand() / double(RAND_MAX)), 0.0, 0.0);	
	for (int y = 0; y < sizey; ++y) 
		for (int x = 0; x < sizex; ++x) {	
			Ray ray = camera.rayAt(x,y);
			if(trace(ray, c, 0)) {
				// Simple Supersampling (anti aliasing)
				for (double i=0;i<1.0;i+=0.25) {
					Ray ray = camera.rayAt(double(x)+i,double(y)+i);
					trace(ray, c2, 0);
					c += c2;
				}
				c*=0.2;
				image.setColor(x, y, c);
			} else {
				image.setColor(x, y, background);
			}
	}
	
	return true;
}

bool Raytracer::trace(Ray& ray, Color& c, int depth) {

	Surface *surface = NULL;
	double t = 0.0;
	if (this->scene.intersect(ray, t, &surface) == false) {
		return false;
	}

	c = Color(0.0, 0.0, 0.0);

	// TODO: Create shade function...

	Vector colPoint = ray.pointAt(t);
	
	std::vector<Light*>::iterator liter;
	for (liter = scene.getLights().begin(); liter != scene.getLights().end(); ++liter) {
		// ambient light
		Light *p = *liter;
		
		AmbientLight *al = dynamic_cast<AmbientLight*>(p);
		if (al != NULL) {
			c += surface->colorAt(colPoint) * surface->getMaterial().aCoeff();
		}
		
		PointLight *pl = dynamic_cast<PointLight*>(p);              
		if (pl == NULL)
			continue;
		
		// Calculate light component from point light
		Vector newStart = (ray.getStart() + ray.getDirection() * t);
		Vector dist = (pl->getPosition() - newStart).normalize();
		Vector n = surface->normalAt(newStart);// newStart - surface->getPosition();

		// Flip normal if pointing in wrong dir.
		if((n * ray.getDirection()) > 0.0) n=-n;

		double tt = 0;		
		Ray toLight = Ray(colPoint, (pl->getPosition() - colPoint).normalize());
		Surface *surface2 = NULL;
		if (this->scene.intersect_shadow(toLight, tt, &surface2) == true)
			continue;
		
		if (n * dist >= 0.0) {
			Vector arg = (dist * (1/t));
			Ray lightRay(newStart, arg);
			
			float lambert = (lightRay.getDirection() * n);
			Color cl = pl->getColor();
			c += surface->colorAt(colPoint) * lambert * surface->getMaterial().dCoeff();
			c += surface->colorAt(colPoint) * lambert * surface->getMaterial().dCoeff();
			c += surface->colorAt(colPoint) * lambert * surface->getMaterial().dCoeff();
			c += surface->colorAt(colPoint) * lambert * surface->getMaterial().dCoeff();
			c += surface->colorAt(colPoint) * lambert * surface->getMaterial().dCoeff();
			c += surface->colorAt(colPoint) * lambert * surface->getMaterial().dCoeff();
			c += surface->colorAt(colPoint) * lambert * surface->getMaterial().dCoeff();
			c += cl * lambert * surface->getMaterial().dCoeff();
		}
		
		// Phong lighting
		//vector3 V = a_Ray.GetDirection();
		//vector3 R = L - 2.0f * DOT( L, N ) * N;
		//float dot = DOT( V, R );
		// Vector from hit point to light source (toLight)
		// Hit point surface normal (n)
		// V - viewing vector (ray.getDirection)
		Vector R = (2*n*(n*toLight.getDirection())-toLight.getDirection()).normalize();
		
		double Is = 0;
		double dot = R * ray.getDirection().normalize();
		if (dot < 0) {
			Is = 0.6 * powf( dot, 20 );//(R * ray.getDirection())*(R * ray.getDirection())*(R * ray.getDirection())*(R * ray.getDirection());
		}
		c += Is;
	}
	
	// Reflection
	Vector normal = surface->normalAt(colPoint);
	Ray reflectRay = ray.reflectAt(normal, colPoint);	
	Color reflect;
	
	if (depth < maxDepth) {
		trace(reflectRay, reflect, depth + 1);
	}
	
	c += reflect * surface->getMaterial().rCoeff();
	
	// Refraction
	
	
	return true;
}
