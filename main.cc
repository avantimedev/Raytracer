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

void testRender() {
	
	Color background(0,0,0);
	Scene scene(background);

	scene.addShape(new Sphere(Material(Color(1.0, 0.0, 0.0), 0.2, 0.1, 0.4, 2), Vector(300, 120, 20.0), 100.0));
	scene.addShape(new Sphere(Material(Color(0.0, 1.0, 0.0), 0.2, 0.1, 0.4, 2), Vector(260, 200, 60.0), 100.0));
	scene.addShape(new Plane(Material(Color(0.0, 0.0, 1.0), 0.2, 0.1, 0.4, 2), Vector(0.0, 1.0, 0.0), -1.0));
	scene.addLight(new AmbientLight(Color(0.1, 0.1, 0.1)));
	scene.addLight(new PointLight(Color(0.5, 0.5, 0.5), Vector(150, 420, -200.0)));
	Raytracer raytracer(scene);

	// Todo: change to take screen obj, or image, should be both
	Image image(800, 600);
	raytracer.render(image);
	TGA tga("hello.tga");
	tga.output(image);
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
	// Build scene
	//Scene scene();
	//raytrace();

	//Image image(640, 480);
	//TGA tga("hello.tga");
	//tga.output(image);

	testRender();
	//testmatrix();
}

