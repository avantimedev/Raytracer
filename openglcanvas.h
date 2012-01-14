#ifndef OPENGLCANVAS_H
#define OPENGLCANVAS_H

#include "canvas.h"
#include "color.h"

#include <GLUT/glut.h>	// OpenGL Graphics Utility Library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double Xmin = 0.0, Xmax = 3.0;
const double Ymin = 0.0, Ymax = 3.0;

class OpenGLCanvas : public Canvas {
public:
	OpenGLCanvas(const unsigned int w, const unsigned int h) : Canvas(w, h) { 

		char **argv = new char*[1];
		argv[0] = new char[10];
		strncpy(argv[0], "test", 4);
		int argc = 1;
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowPosition(20, 60 );
		glutInitWindowSize(800, 600 );
		glutCreateWindow("Avantime Ray Tracer version 0.0.4");
		glutKeyboardFunc(OpenGLCanvas::myKeyboardFunc);
		glutReshapeFunc(OpenGLCanvas::resizeWindow);
		glutDisplayFunc(OpenGLCanvas::drawScene);
		
		glutMainLoop();
	}
	static void setColor(unsigned int x, unsigned int y, const Color &color);
	
	static void resizeWindow(int w, int h);
	static void myKeyboardFunc(unsigned char key, int x, int y);
	static void drawScene(void);
	
private:
	
};

#endif