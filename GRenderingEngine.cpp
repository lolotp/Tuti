#include "GRenderingEngine.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int cnt = 0;

 void GRenderingEngine::drawScene(GScene *activeScene) {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View
    glTranslatef(0.0f,0.0f,-1.0f);
	
	if (activeScene != NULL) {
		std::vector<Layer>& layers = activeScene->objByLayer;
		std::vector<GObject*> objList = activeScene->objList;
		for (std::vector<Layer>::iterator it =  layers.begin(); it != layers.end(); it++) {
			for (hash_set<GObjectID>::iterator objIt = (*it).begin(); objIt != (*it).end(); objIt++) {
				GObject *obj = objList[ (*objIt) ];
				
				glEnableClientState(GL_VERTEX_ARRAY);
				glVertexPointer(TUTI_DIM, GL_FLOAT, 0, obj->apPolygon);
				glDrawArrays(GL_TRIANGLE_STRIP, 0, obj->napVert);
				glDisableClientState(GL_VERTEX_ARRAY);	
			}
		}
	}
    // swap buffers to display, since we're double buffered.
    glutSwapBuffers();
}