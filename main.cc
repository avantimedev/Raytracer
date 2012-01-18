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
#include "triangle.h"
#include "matrix.h"
#ifdef __APPLE__
#include "openglcanvas.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

void testRender1(const std::string filename) {
	
	Color background(0,0,0);
	Scene scene(background);

	std::cout << "@ Creating scene 1" << std::endl;

	// Surfaces
	scene.addShape(new Sphere(Material(Color(1.0, 0.0, 0.0), 0.2, 0.8, 0.4, 2, 0.05), Vector(4.0, 1.0, 20.0), 1.9));
	scene.addShape(new Sphere(Material(Color(0.0, 1.0, 0.0), 0.2, 0.8, 0.4, 2, 0.05), Vector(0.0, 1.0, 20.0), 1.9));	
	scene.addShape(new Sphere(Material(Color(0.0, 0.0, 1.0), 0.2, 0.8, 0.4, 2, 0.05), Vector(-4.0, 1.0, 20.0), 1.9));
	scene.addShape(new Plane(Material(Color(0.5, 0.5, 0.5), 0.08, 0.8, 0.4, 100, 0.7), Vector(0.0, 1.0, 0.0), -1.0));

	// Lights
	scene.addLight(new PointLight(Color(1.0, 1.0, 1.0), Vector(1, 4, 12)));
	scene.addLight(new AmbientLight(Color(0.2, 0.2, 0.2)));
	
	Raytracer raytracer(scene);

	Image image(1920, 1200);
	
	std::cout << "@ Start rendering scene 1" << std::endl;
	raytracer.render(image);
	std::cout << "@ Finished rendering" << std::endl;
	TGA tga(filename);
	tga.output(image);
}

void testRender2(const std::string filename) {
	
	Color background(0,0,0);
	Scene scene(background);

	std::cout << "@ Creating scene 2" << std::endl;

	// Surfaces
	// scene.addShape(new Sphere(Material(Color(1.0, 0.2, 0.5), 0.2, 0.8, 0.4, 0.1, 0.05), Vector(0.0, 0, 10.0), 1));
	scene.addShape(new Sphere(Material(Color(0.1, 0.1, 0.15), 0.2, 0.8, 0.4, 0.1, 0.05), Vector(0.0, 0, 10.0), 1));
	scene.addShape(new Plane(Material(Color(0.5, 0.5, 0.5), 0.08, 0.5, 0.1, 100, 0.2), Vector(0.0, 1.0, 0.0), -1.0));

	// Lights
	scene.addLight(new PointLight(Color(1.0, 1.0, 1.0), Vector(1, 4.8, 7)));
	scene.addLight(new PointLight(Color(1.0, 1.0, 1.0), Vector(-1, 4.8, 7)));
	scene.addLight(new AmbientLight(Color(0.2, 0.2, 0.2)));
	
	Raytracer raytracer(scene);

	Image image(800, 600);
	
	std::cout << "@ Start rendering scene 2" << std::endl;
	raytracer.render(image);
	std::cout << "@ Finished rendering" << std::endl;
	TGA tga(filename);
	tga.output(image);
}

void testRender3(const std::string filename) {
	
	Color background(0,0,0);
	Scene scene(background);

	std::cout << "@ Creating scene 3" << std::endl;

	scene.addShape(new Sphere(Material(Color(0.3, 0.3, 0.3), 0.2, 0.8, 0.4, 0.2, 0.06), Vector(0.1, 1.5, 16.0), 2));
	scene.addShape(new Sphere(Material(Color(0.8, 0.1, 0.1), 0.2, 0.8, 0.4, 0.1, 0.03), Vector(2, 0.1, 13.0), 1));
	scene.addShape(new Sphere(Material(Color(0.1, 0.1, 0.8), 0.2, 0.8, 0.4, 0.1, 0.03), Vector(-2, 0.1, 13.0), 1));
	scene.addShape(new Plane(Material(Color(0.5, 0.5, 0.5), 0.08, 0.5, 0.1, 101, 0.7), Vector(0.0, 1.0, 0.0), -1.0));

	// Lights
	scene.addLight(new PointLight(Color(1.0, 1.0, 1.0), Vector(4, 4.8, 7)));
	scene.addLight(new PointLight(Color(1.0, 1.0, 1.0), Vector(-4, 9, 12)));
	scene.addLight(new AmbientLight(Color(0.2, 0.2, 0.2)));
	
	Raytracer raytracer(scene);

	Image image(1920, 1080);
	
	std::cout << "@ Start rendering scene 3" << std::endl;
	raytracer.render(image);
	std::cout << "@ Finished rendering" << std::endl;
	TGA tga(filename);
	tga.output(image);
}

void testRender4(const std::string filename) {
	
	Color background(0,0,0);
	Scene scene(background);

	std::cout << "@ Creating scene 4" << std::endl;

	scene.addShape(new Triangle(Material(Color(0.9, 0.3, 0.3), 0.2, 0.8, 0.4, 0.2, 0.06), Vector(0.0, 0.0, 16.0), Vector(3.0, 0.0, 16.0), Vector(0.0, 3.0, 16.0)));
	//scene.addShape(new Sphere(Material(Color(0.8, 0.1, 0.1), 0.2, 0.8, 0.4, 0.1, 0.03), Vector(2, 0.1, 13.0), 1));
	//scene.addShape(new Sphere(Material(Color(0.1, 0.1, 0.8), 0.2, 0.8, 0.4, 0.1, 0.03), Vector(-2, 0.1, 13.0), 1));
	scene.addShape(new Plane(Material(Color(0.5, 0.5, 0.5), 0.08, 0.5, 0.1, 101, 0.7), Vector(0.0, 1.0, 0.0), -1.0));

	// Lights
	scene.addLight(new PointLight(Color(1.0, 1.0, 1.0), Vector(4, 4.8, 7)));
	//scene.addLight(new PointLight(Color(1.0, 1.0, 1.0), Vector(-4, 9, 12)));
	scene.addLight(new AmbientLight(Color(0.2, 0.2, 0.2)));
	
	Raytracer raytracer(scene);

	Image image(800, 600);
	
	std::cout << "@ Start rendering scene 4" << std::endl;
	raytracer.render(image);
	std::cout << "@ Finished rendering" << std::endl;
	TGA tga(filename);
	tga.output(image);
}
#ifdef __APPLE__
void testRenderScreen() {
	OpenGLCanvas canvas(800,600);
	canvas.setColor(100,100, Color(1.0, 0, 0));
}
#endif

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
	int x = 0;
	int y = 0;
	
	Vector diff4 = N + 0.5*(2*y+1-height)*yInc + 0.5*(2*x+1-width)*xInc;	
	Vector dir = (N + 0.5*(2*y+1-height)*yInc + 0.5*(2*x+1-width)*xInc)/diff4.length();
	
	std::cout << "O: " << lookFrom << std::endl;
	std::cout << "N: " << N << std::endl;
	std::cout << "U: " << U << std::endl;
	std::cout << "V: " << V << std::endl;
	std::cout << "yInc: " << yInc << std::endl;
	std::cout << "xInc: " << xInc << std::endl;
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}

void testtriangle() {
	//Triangle
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
	n.inverse();
	std::cout << n.inverse() << std::endl;
	std::cout << n << std::endl;
}

int main() 
{
	std::cout << "Avantime Ray Tracer version 0.0.4" << std::endl;
	std::cout << "Copyright 2011-2012 Johan Astborg" << std::endl;
	testmatrix();
	//testRender1("hello.tga");
	//testRender2("hello.tga");
	//testRenderScreen();
	//testcamera();
	//testtriangle();
}

