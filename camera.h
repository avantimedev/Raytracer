/*
 * =====================================================================================
 *
 *       Filename:  camera.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2012 18:37:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Johan Astborg (ja), into@avantimedev.net
 *        Company:  avantimedev
 *
 * =====================================================================================
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <cmath>

#include "ray.h"
#include "vector.h"

const double PI = 3.141592654;

class Camera {
public:
	Camera(Vector &pos, Vector &dir, double fov = PI / 4.0) : pos(pos), dir(dir), fov(fov) { }
	virtual ~Camera();

	void initView(int height, int width) {
		this->height = height;
		this->width = width;		
	}

	Ray rayAt(int u, int v) {
		double fovx = fov;
		double fovy = fovx * (static_cast<double>(height) / static_cast<double>(width));
		tan_x = tan(fovx);
		tan_y = tan(fovy);

		// (u,v) -> (x,y) in the plane (view-plane)
		double x = ((2*u - static_cast<double>(width)) / static_cast<double>(width)) * tan_x;
		double y = ((2*v - static_cast<double>(height)) / static_cast<double>(height)) * tan_y;
		
		// Ray goes from camera at (0,0,0) -> view plane at (x, y, -1)
		Vector direction(x, y, -1.0);
		return Ray(pos, direction);
	}

	friend std::ostream& operator<<(std::ostream &out, const Camera &c);
private:
	double fov; // Default 45 degrees
	Vector pos;
	Vector dir;
	Vector top;
	double tan_x;
	double tan_y;
	int height;
	int width;
};

#endif
