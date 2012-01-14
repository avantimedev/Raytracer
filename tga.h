/*
 * =====================================================================================
 *
 *       Filename:  tga.h
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

#ifndef TGA_H
#define TGA_H

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "image.h"

class TGA {
public:
	TGA(const std::string& filename);
	void output(Image& image);
private:
	std::string filename;
};

#endif