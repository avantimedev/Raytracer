/*
 * =====================================================================================
 *
 *       Filename:  scene.cc
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

#include "scene.h"

int Scene::intersect(Ray &ray, float &t, const Shape* shape) {
	// look for intersection between all shapes
	t = 2000;
	std::vector<Shape*>::iterator citr;
	for (citr = shapes.begin(); citr != shapes.end(); ++citr) {
		//std::cout << (*citr) << std::endl;
		double tt = 0;
		bool coll = (*citr)->intersect(ray, t);
		if (coll && tt < t ) {
			//std::cout << "Intersect: " << (**citr) << std::endl;
			shape = *citr;
			t = tt;
			return true;
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
