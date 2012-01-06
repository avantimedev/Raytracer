#include "vector.h"
#include "scene.h"
#include "sphere.h"
#include "image.h"
#include "tga.h"
#include "ray.h"
#include "point.h"

void raytrace() {

	int sizex = 640;
	int sizey = 480;	
	float t = 2000.0;

	Vector v(0.0, 0.0, 0.5);

	Color color(1.0, 0.0, 0.0);
	Material material(color, 0.2);
	//Vector point(233.0, 290.0, 0.0);
	//Vector point(407.0, 290.0, 0.0);
	Vector point(320.0, 140.0, 0.0);
	Sphere sphere(material, point, 100.0);

	Image image(640, 480);

    for (int y = 0; y < sizey; ++y) 
    for (int x = 0; x < sizex; ++x) {

		//ray viewRay = { {float(x), float(y), -1000.0f}, { 0.0f, 0.0f, 1.0f}};
		Vector p(double(x), double(y), -1000.0);
		Ray ray(p, v);
		//std::cout << ray << std::endl;

		if (sphere.intersect(ray, t)) {
			image.setColor(x, y, 0xFFFFFF);		
		}
	}

	TGA tga("hello.tga");
	tga.output(image);
}

int main() 
{
	// Build scene
	Scene scene();
	raytrace();

	//Image image(640, 480);
	//TGA tga("hello.tga");
	//tga.output(image);
}

