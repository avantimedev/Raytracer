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

int Scene::intersect(Ray &ray, double &rayPos, Surface** surface) {
	// look for intersection between all shapes
	
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
			return true;
		}
	}
	
	return sceneCol;
	
	
	/*
	rayPos = std::numeric_limits<double>::infinity();
	std::vector<Surface*>::iterator citr;
	bool coll = false;
	double tt = 0;
	for (citr = surfaces.begin(); citr != surfaces.end(); ++citr) {
		//std::cout << (*citr) << std::endl;
		double t;
		coll = (*citr)->intersect(ray, t);
		if (coll && t < rayPos) {
			//std::cout << "Intersect: " << (**citr) << std::endl;
			//std::cout << "Collide: " << t << std::endl;
			*surface = *citr;
			rayPos = t;
			return true;
		}
	}
	
	//if (coll) return true;
	
	return false;
	*/		
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
