#include "GBasicRenderingEngine.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int cnt = 0;

void GBasicRenderingEngine::initGL(int width, int height) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black    
    glDisable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
	glEnable(GL_TEXTURE_2D);
	printf("enabled texture 2D\n");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
	glOrtho (0, width, height, 0, 0, 1);    

    glMatrixMode(GL_MODELVIEW);
};

void GBasicRenderingEngine::drawScene(GScene *activeScene) {
	
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();				// Reset The View
	
	if (activeScene != NULL) {
		std::vector<Layer>& layers = activeScene->objByLayer;
		std::vector<GObject*> objList = activeScene->objList;
		for (std::vector<Layer>::iterator it =  layers.begin(); it != layers.end(); it++) {
			for (hash_set<GObjectID>::iterator objIt = (*it).begin(); objIt != (*it).end(); objIt++) {
				GObject *obj = objList[ (*objIt) ];
				
				glEnableClientState(GL_VERTEX_ARRAY);				
				glEnableClientState(GL_TEXTURE_COORD_ARRAY);				
				
				glBindTexture(GL_TEXTURE_2D, obj->txID);
				glVertexPointer(TUTI_DIM, GL_FLOAT, 0, obj->apPolygon);
				glTexCoordPointer(TUTI_DIM, GL_FLOAT, 0, obj->txCoord);
				glDrawArrays(GL_TRIANGLE_STRIP, 0, obj->napVert);
				
				glDisableClientState(GL_VERTEX_ARRAY);
				glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			}
		}
	}
    // swap buffers to display, since we're double buffered.
    glutSwapBuffers();
}