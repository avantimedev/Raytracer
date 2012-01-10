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

int Scene::intersect(Ray &ray, float &t, Surface** surface) {
	// look for intersection between all shapes
	t = 2000;
	std::vector<Surface*>::iterator citr;
	bool coll = false;
	float tt = 0;
	for (citr = surfaces.begin(); citr != surfaces.end(); ++citr) {
		//std::cout << (*citr) << std::endl;
		coll = (*citr)->intersect(ray, t);
		if (coll && tt < t) {
			//std::cout << "Intersect: " << (**citr) << std::endl;
			//std::cout << "Collide: " << t << std::endl;
			*surface = *citr;
			tt = t;
			return true;
		}
	}
	
	//if (coll) return true;
	
	return false;
}

void Scene::addShape(Surface *surface) {
	surfaces.push_back(surface);	
}

void Scene::addLight(Light *light) {
	lights.push_back(light);
}

Color& Scene::getBackground() {
	return background;
}
