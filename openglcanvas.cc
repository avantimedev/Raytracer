#ifdef __APPLE__
#include "openglcanvas.h"

GLubyte checkImage[600][800][4];

void OpenGLCanvas::resizeWindow(int w, int h) {
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	// Define the portion of the window used for OpenGL rendering.
	glViewport(0, 0, w, h);	// View port uses whole window

	// Set up the projection view matrix: orthographic projection
	// Determine the min and max values for x and y that should appear in the window.
	// The complication is that the aspect ratio of the window may not match the
	//		aspect ratio of the scene we want to view.
	w = (w==0) ? 1 : w;
	h = (h==0) ? 1 : h;
	if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
		scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
		center = (Xmax+Xmin)/2;
		windowXmin = center - (center-Xmin)*scale;
		windowXmax = center + (Xmax-center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
		center = (Ymax+Ymin)/2;
		windowYmin = center - (center-Ymin)*scale;
		windowYmax = center + (Ymax-center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}
	
	// Now that we know the max & min values for x & y that should be visible in the window,
	//		we set up the orthographic projection.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	//glOrtho( windowXmin, windowXmax, windowYmin, windowYmax, -1, 1 );
	gluOrtho2D(0.0, (double)w, 0.0, (double)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLCanvas::myKeyboardFunc(unsigned char key, int, int) {
	switch ( key ) {
		case 27: // "27" is theEscape key
			exit(1);
	}
}

void OpenGLCanvas::drawScene(void) {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*
		for (int y = 0; y < 600; y++)
			for (int x = 0; x < 800; x++) {
				checkImage[y][x][0] = 255;
				checkImage[y][x][1] = 255;
				checkImage[y][x][2] = 255;
				checkImage[y][x][3] = 255;
			}
	*/
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glEnable(GL_BLEND);	 // added
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);	// added
	//glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(0.0, 0.0);
	glDrawPixels(800, 600, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void OpenGLCanvas::setColor(unsigned int x, unsigned int y, const Color &color) {
		checkImage[y][x][0] = color.r() * 255;
		checkImage[y][x][1] = color.g() * 255;
		checkImage[y][x][2] = color.b() * 255;
		checkImage[y][x][3] = 255;	
		
		for (int y = 0; y < 600; y++)
			for (int x = 0; x < 800; x++) {
				checkImage[y][x][0] = 255;
				checkImage[y][x][1] = 255;
				checkImage[y][x][2] = 255;
				checkImage[y][x][3] = 255;
			}
}
#endif	
