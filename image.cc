/*
 * =====================================================================================
 *
 *       Filename:  image.cc
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

#include "image.h"
#include <iostream>

Color *Image::getColor(unsigned int x, unsigned int y) {
	return &buffer[y*width+x];
}

Color* Image::getColor(unsigned int index) {
	return &buffer[index];
}

void Image::setColor(unsigned int x, unsigned int y, Color &color) {
	if (x < width && y < height)
		buffer[y*width+x] = color;
}