#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"

class Image {
public:
	Image();
	Image(unsigned int width, unsigned int heigth);

	unsigned int getWidth() const;
	unsigned int getHeight() const;

	double getColor(int x, int y);
	double getColor(int index);
	void setColor(int x, int y, double color);
private:
	unsigned int width;
	unsigned int height;

	double *buffer;
};

#endif
