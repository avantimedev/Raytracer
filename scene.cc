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

#include <limits>

int Scene::intersect(Ray& ray, double& rayPos, Surface** surface) {
	bool sceneCol = false;
	rayPos = std::numeric_limits<double>::infinity();	
	std::vector<Surface*>::iterator citr;
	
	for (citr = surfaces.begin(); citr != surfaces.end(); citr++) {
		double t;
		bool objCol = false;
		objCol = (*citr)->intersect(ray, t);
		if (objCol == true && t < rayPos) {
			rayPos = t;
			*surface = *citr;
			sceneCol = true;
		}
	}	
	return sceneCol;	
}

int Scene::intersect_shadow(Ray& ray, double& rayPos, Surface**) {
	bool sceneCol = false;
	rayPos = std::numeric_limits<double>::infinity();	
	std::vector<Surface*>::iterator citr;
	
	for (citr = surfaces.begin(); citr != surfaces.end(); citr++) {
		double t;
		bool objCol = false;
		objCol = (*citr)->intersect(ray, t);
		if (objCol == true && t < rayPos) {
			return true;
		}
	}
	return sceneCol;	
}

void Scene::addShape(Surface* surface) {
	surfaces.push_back(surface);	
}

void Scene::addLight(Light* light) {
	lights.push_back(light);
}

Color& Scene::getBackground() {
	return background;
}
