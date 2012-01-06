#include "tga.h"

TGA::TGA(const std::string &filename) {
	this->filename = filename;
}

void TGA::output(Image &image) {

	std::ofstream outputfile(filename.c_str(), std::ios_base::binary);

	std::cout << image.getWidth() << std::endl;
	std::cout << image.getHeight() << std::endl;

	if (!outputfile.is_open()) return;

	// TGA Header
	outputfile.put(0);
	outputfile.put(0);
    outputfile.put(2);
    outputfile.put(0);
	outputfile.put(0);
    outputfile.put(0);
	outputfile.put(0);
    outputfile.put(0);
    outputfile.put(0);
	outputfile.put(0); 
    outputfile.put(0);
	outputfile.put(0);
    outputfile.put(static_cast<unsigned char>(image.getWidth() & 0x00FF)).put(static_cast<unsigned char>((image.getWidth() & 0xFF00) / 256));
    outputfile.put(static_cast<unsigned char>(image.getHeight() & 0x00FF)).put(static_cast<unsigned char>((image.getHeight() & 0xFF00) / 256));
    outputfile.put(24);
    outputfile.put(0);

	for (unsigned int i=0;i<image.getWidth()*image.getHeight();i++) {
		Color *color = image.getColor(i);		
		outputfile.put(static_cast<unsigned char>(std::min(color->b()*255.0,255.0)));
		outputfile.put(static_cast<unsigned char>(std::min(color->g()*255.0, 255.0)));
		outputfile.put(static_cast<unsigned char>(std::min(color->r()*255.0, 255.0)));		
	}
	outputfile.close();
}
