#ifndef COLOR_H
#define COLOR_H

class Color {
public:
	Color();
	Color(double red, double green, double blue);
	
	double r();
	double g();
	double b();
private:
	double red;
	double green;
	double blue;
};

#endif
