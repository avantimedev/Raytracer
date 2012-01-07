#include "vector.h"
#include "scene.h"
#include "sphere.h"
#include "image.h"
#include "tga.h"
#include "ray.h"
#include "point.h"
#include "light.h"

#include <cmath>

void raytrace() {

	int sizex = 640;
	int sizey = 480;	
	float t = 2000.0;
	float red = 0, green = 0, blue = 0;
	
	Vector v(0.0, 0.0, 0.5);
	
	Color color(1.0, 0.0, 0.0);
	Material material(color, 0.2);
	//Vector point(233.0, 290.0, 0.0);
	//Vector point(407.0, 290.0, 0.0);
	Vector point(320.0, 140.0, 0.0);
	Sphere sphere(material, point, 100.0);
	
	Vector lightpos(0.0, 240.0, -100.0);  
	Color lightcol(1.0, 1.0, 1.0);
	Light light(lightpos, lightcol);
	Image image(640, 480);

	for (int y = 0; y < sizey; ++y) 
   	for (int x = 0; x < sizex; ++x) {

		Vector p(double(x), double(y), -1000.0);
		Ray ray(p, v);
		float coef = 1.0f;
        int level = 0;

		if (sphere.intersect(ray, t)) {
			
			Vector newStart = ray.getStart() + ray.getDirection() * t;  
			Vector dist = lightpos - newStart;
			Vector n = newStart - point;
			double temp = n * n;
			if (temp == 0.0) continue;
			temp = 1.0 / sqrt(temp);
			n = n * temp;
			
			if (n * dist >= 0.0f) {
				Vector arg = dist * (1/t);
				Ray lightRay(newStart, arg);
				
				float lambert = (lightRay.getDirection() * n) * 3;
				Color c(lambert * 0.9, lambert* 0.0, lambert * 0.0);
				image.setColor(x, y, c);
			}
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

