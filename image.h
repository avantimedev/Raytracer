/*
 * =====================================================================================
 *
 *       Filename:  image.h
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

#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"
#include "canvas.h"

class Image : public Canvas {
public:
	Image(unsigned int width, unsigned int heigth) : Canvas(width, heigth) { 
		buffer = new Color[width*heigth];
	}

	Color* getColor(unsigned int x, unsigned int y);
	Color* getColor(unsigned int index);
	void setColor(unsigned int x, unsigned int y, Color &color);
private:
	Color *buffer;
};

#endif
