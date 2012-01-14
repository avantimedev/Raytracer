/*
 * =====================================================================================
 *
 *       Filename:  raytracer.h
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

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "ray.h"
#include "scene.h"
#include "image.h"

class Raytracer {
public:
	Raytracer(Scene &scene) : scene(scene), maxDepth(10) {}
	bool render(Image &image);
private:
	Scene &scene;
	bool trace(Ray& ray, Color& c, int depth);
	int maxDepth;
};

#endif
