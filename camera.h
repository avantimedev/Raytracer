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
#include "matrix.h"

const double PI = 3.1415926535897932384626433832795;

class Camera {
public:
	Camera(const Vector& pos, const Vector& dir, double fov = PI / 4.0) : pos(pos), dir(dir), fov(fov) { 
		// New camera code
		Vector lookFrom(0,0,-5);
		Vector lookAt(0,0,5);
		Vector viewUp(0,1,0);
		fov = PI / 4.0;

		width = 1024;
		height = 768;

		Vector diff = lookAt - lookFrom;
		N = (lookAt - lookFrom) / diff.length(); // Normalize
		Vector diff2 = N ^ viewUp;
		Vector U = (N ^ viewUp) / diff2.length(); // Normalize
		Vector diff3 = U ^ N;
		Vector V = (U ^ N) / diff3.length(); // Normalize

		xInc = U * (2*tan(fov/2.0))/width;
		yInc = V * (2*tan(fov/2.0))/width;

		/*
		// Image plane corners
		Vector p1 = Vector(-1,1,0); // Upper left
		Vector p2 = Vector(1,1,0); // Upper right
		Vector p3 = Vector(1,-1,0); // Lower right
		Vector p4 = Vector(-1,-1,0); // Lower left

		// Calc camera direction vector
		Vector zaxis = (lookAt - lookFrom).normalize();
		
		// Camera lookup (y-axis)
		Vector up = Vector(0,1,0)

		// Create camera view system basis
		Vector xaxis = up ^ zaxis;
		*/
		
	}
	//~Camera();

	void initView(int width, int height) {
		this->height = height;
		this->width = width;
	}

	Ray rayAt(double u, double v) {
		Vector lookFrom(0,1,-1);
		Vector lookAt(0,0,10);

		double f = (lookAt - lookFrom).length();

		int width = 1024;
		int height = 768;

		// Image plane corners
		Vector p1 = Vector(-4, 3, 0); // Upper left
		Vector p2 = Vector( 4, 3, 0); // Upper right
		Vector p3 = Vector( 4,-3, 0); // Lower right
		Vector p4 = Vector(-4,-3, 0); // Lower left

		// Calc camera direction vector
		Vector zdir = (lookAt - lookFrom).normalize();
		
		// Camera lookup (y-axis)
		Vector up = Vector(0,1,0);

		// Create camera view system basis
		Vector xaxis = up ^ zdir; // (cross)
		Vector yaxis = xaxis ^ -zdir; // (cross)
		Vector zaxis = (xaxis ^ yaxis).normalize(); // (cross)

		// Move camera
		Matrix m;
		m.elems[0] = xaxis.getX(), m.elems[1] = xaxis.getY(), m.elems[2] = xaxis.getZ();
		m.elems[4] = yaxis.getX(), m.elems[5] = yaxis.getY(), m.elems[6] = yaxis.getZ();
		m.elems[8] = zaxis.getX(), m.elems[9] = zaxis.getY(), m.elems[10] = zaxis.getZ();
		m.invert();
		m.elems[3] = lookFrom.getX(), m.elems[7] = lookFrom.getY(), m.elems[11] = lookFrom.getZ();

		// Calculate interpolation vectors
		Vector dx = ((p2 - p1) * (1.0 / width));
		Vector dy = ((p1 - p4) * (1.0 / height));

		lookFrom = m.transform(lookFrom);
		p1 = m.transform(p1);
		p2 = m.transform(p2);
		p3 = m.transform(p3);
		p4 = m.transform(p4);

		Vector tdir = (zdir*f + dx*(2*u+1-width)*0.5 + dy*(2*v+1-height)*0.5).normalize();
		Ray ray(lookFrom, tdir);
		return ray;
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

	Vector N;
	Vector xInc;
	Vector yInc;
};

#endif
