/*
 * =====================================================================================
 *
 *       Filename:  scene.h
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

	Color& getBackground();

	int intersect(Ray &ray, float &t, const Shape* shape);

	std::vector<Light*> &getLights() { return lights; }
	
private:

	std::vector<Light*> lights;
	std::vector<Shape*> shapes;

	Color background;

	// Camera

	int width;
	int height;
};

#endif
