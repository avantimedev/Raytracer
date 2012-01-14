#ifndef CANVAS_H
#define CANVAS_H

class Canvas {
public:
	Canvas(unsigned int w, unsigned int h) : width(w), height(h) {}

	unsigned int getWidth() const { return width; }
	unsigned int getHeight() const { return height; }

protected:
	unsigned int width;
	unsigned int height;
};

#endif