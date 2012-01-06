#include "image.h"

Image::Image() {
	width = 0;
	height = 0;
}

Image::Image(unsigned int width, unsigned int heigth) {
	this->width = width;
	this->height = heigth;

	buffer = new Color[width*heigth];
}

Color *Image::getColor(int x, int y) {
	return &buffer[y*width+x];
}

Color* Image::getColor(int index) {
	return &buffer[index];
}

void Image::setColor(int x, int y, Color &color) {
	buffer[y*width+x] = color;
}

unsigned int Image::getWidth() const {
	return width;
}

unsigned int Image::getHeight() const {
	return height;
}
