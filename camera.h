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

const double PI = 3.1415926535897932384626433832795;

class Camera {
public:
	Camera(const Vector &pos, const Vector &dir, double fov = PI / 4.0) : pos(pos), dir(dir), fov(fov) { }
	//~Camera();

	void initView(int width, int height) {
		this->height = height;
		this->width = width;
	}

	Ray rayAt(int u, int v) {
		/*
		double fovx = PI / 4.0;
		double fovy = fovx * static_cast<double>(height) / static_cast<double>(width);
		tan_x = tan(fovx);
		tan_y = tan(fovy);

		// (u,v) -> (x,y) in the plane (view-plane)
		double x = ((2*u - static_cast<double>(width)) / static_cast<double>(width)) * tan_x;
		double y = ((2*v - static_cast<double>(height)) / static_cast<double>(height)) * tan_y;
		
		// Ray goes from camera at (0,0,0) -> view plane at (x, y, -1)
		Vector direction(x, y, 1.0);
		return Ray(pos, direction.normalize());
		
		Vector lookFrom(0,0,0);
		Vector lookAt(0,0,1);
		Vector lookUp(0,0,0);
		double fov = PI / 4.0;
		Vector diff = lookAt - lookFrom;
		Vector N = (lookAt - lookFrom) / diff.length();
		Vector U = N;
		*/

		// New camera code
		Vector lookFrom(0,0,-5);
		Vector lookAt(0,0,15);
		Vector viewUp(0,1,0);
		double fov = PI / 4.0;

		Vector diff = lookAt - lookFrom;
		Vector N = (lookAt - lookFrom) / diff.length();
		Vector diff2 = N ^ viewUp;
		Vector U = (N ^ viewUp) / diff2.length();
		Vector diff3 = U ^ N;
		Vector V = (U ^ N) / diff3.length();

		Vector xInc = U * (2*tan(fov/2.0))/width;
		Vector yInc = V * (2*tan(fov/2.0))/width;

		Vector diff4 = N + 0.5*(2*v+1-height)*yInc + 0.5*(2*u+1-width)*xInc;
		Vector dir = (N + 0.5*(2*v+1-height)*yInc + 0.5*(width-2*u+1)*xInc)/diff4.length();
		return Ray(pos, dir.normalize());
	}

	friend std::ostream& operator<<(std::ostream &out, const Camera &c);
private:	
	Vector pos;
	Vector dir;
	double fov; // Default 45 degrees
	Vector top;
	double tan_x;
	double tan_y;
	int height;
	int width;
};

#endif
