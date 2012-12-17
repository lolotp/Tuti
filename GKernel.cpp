#include "GKernel.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GKernel *GKernel::instance = NULL;

GKernel::GKernel() : activeScene(NULL){
};

GKernel* GKernel::getInstance() {
	if (instance == NULL) {
		instance = new GKernel();
	}
	return instance;
};
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black    
    glDisable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
	glOrtho (0, Width, Height, 0, 0, 1);    

    glMatrixMode(GL_MODELVIEW);
}

void GKernel::initGameLoop(int argc, char**argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tuti exp windows");
	glutDisplayFunc(&drawScene);
	glutIdleFunc(&drawScene);
	InitGL(640,480);
	glutMainLoop();
};

void GKernel::setRenderingEngine(GRenderingEngine *_renderEngine) {
	renderEngine = _renderEngine;
};

void GKernel::drawScene() {
	GKernel *cur = getInstance();
	cur->renderEngine->drawScene(cur->activeScene);
};

void GKernel::setActiveScene(GScene *scene) {
	activeScene = scene;
}