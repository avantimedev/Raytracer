/*
 * =====================================================================================
 *
 *       Filename:  main.cc
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

#include "vector.h"
#include "scene.h"
#include "sphere.h"
#include "image.h"
#include "tga.h"
#include "ray.h"
#include "point.h"
#include "light.h"
#include "raytracer.h"
#include "plane.h"
#include "matrix.h"

#include <cmath>

void testRender(const std::string filename) {
	
	Color background(0,0,0);
	Scene scene(background);

	//scene.addShape(new Sphere(Material(Color(1.0, 0.0, 1.0), 0.2, 0.1, 0.4, 2), Vector(-1.0, 0.0, 10.0), 1.0));
	//scene.addShape(new Sphere(Material(Color(1.0, 0.0, 1.0), 0.2, 0.1, 0.4, 2), Vector(1.0, 0.0, 10.0), 1.0));

	//scene.addShape(new Plane(Material(Color(0.5, 0.5, 0.5), 0.2, 0.1, 0.4, 2), Vector(0.0, 1.0, 0.0), -1.0));

	//scene.addLight(new PointLight(Color(0.9, 0.9, 0.9), Vector(6, 6, 0)));
	scene.addShape(new Sphere(Material(Color(1.0, 0.0, 0.0), 0.2, 0.1, 0.4, 2), Vector(4.0, 0.0, 20.0), 1.9));
	scene.addShape(new Sphere(Material(Color(0.0, 1.0, 0.0), 0.2, 0.1, 0.4, 2), Vector(0.0, 0.0, 20.0), 1.9));	
	scene.addShape(new Sphere(Material(Color(0.0, 0.0, 1.0), 0.2, 0.1, 0.4, 2), Vector(-4.0, 0.0, 20.0), 1.9));
	scene.addShape(new Plane(Material(Color(0.5, 0.5, 0.5), 0.2, 0.1, 0.4, 2), Vector(0.0, 1.0, 0.0), -1.0));
	scene.addLight(new PointLight(Color(2.0, 2.0, 2.0), Vector(1, 2, 15)));
	
	Raytracer raytracer(scene);

	Image image(800, 600);
	raytracer.render(image);
	TGA tga(filename);
	tga.output(image);
}

void testcamera() {
	Vector lookFrom(0,0,0);
	Vector lookAt(0,0,1);
	Vector viewUp(0,1,0);
	double fov = 0.5;
	int width = 512;
	int height = 512;

	Vector diff = lookAt - lookFrom;
	Vector N = (lookAt - lookFrom) / diff.length();
	Vector diff2 = N ^ viewUp;
	Vector U = (N ^ viewUp) / diff2.length();
	Vector diff3 = U ^ N;
	Vector V = (U ^ N) / diff3.length();
	
	Vector xInc = U * (2*tan(fov/2.0))/width;
	Vector yInc = V * (2*tan(fov/2.0))/width;
	int x, y;
	
	Vector diff4 = N + 0.5*(2*y+1-height)*yInc + 0.5*(2*x+1-width)*xInc;
	
	Vector dir = (N + 0.5*(2*y+1-height)*yInc + 0.5*(2*x+1-width)*xInc)/diff4.length();
	
	std::cout << "O: " << lookFrom << std::endl;
	std::cout << "N: " << N << std::endl;
	std::cout << "U: " << U << std::endl;
	std::cout << "V: " << V << std::endl;
	std::cout << "yInc: " << yInc << std::endl;
	std::cout << "xInc: " << xInc << std::endl;
}

void testmatrix() {
	Matrix m;
	Matrix n;
	std::cout << m << std::endl;
	m.identity();
	std::cout << m << std::endl;
	std::cout << m(0,0) << std::endl;
	n.identity();
	std::cout << m * n << std::endl;
}

int main() 
{
	testRender("hello.tga");	
	//testcamera();
}

