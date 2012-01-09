#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"

class Image /* : public Canvas*/{
public:
	Image();
	Image(unsigned int width, unsigned int heigth);

	unsigned int getWidth() const;
	unsigned int getHeight() const;

	Color* getColor(int x, int y);
	Color* getColor(int index);
	void setColor(int x, int y, Color &color);
private:
	unsigned int width;
	unsigned int height;

	Color *buffer;
};

#endif
