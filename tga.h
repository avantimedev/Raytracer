#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "image.h"

class TGA {
public:
	TGA(const std::string &filename);
	void output(Image &image);
private:
	std::string filename;
};
