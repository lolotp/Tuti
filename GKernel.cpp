#include "GKernel.h"
#include <GL/glut.h>

GKernel *GKernel::instance = NULL;

GKernel::GKernel() : activeScene(NULL){
};

GKernel* GKernel::getInstance() {
    if (instance == NULL) {
        instance = new GKernel();
    }
    return instance;
};

const int WindowsWidth = 640;
const int WindowsHeight = 480;

void GKernel::initGameLoop(int argc, char**argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(WindowsWidth, WindowsHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Tuti exp windows");
    glutDisplayFunc(&drawScene);
    glutIdleFunc(&processWorld);
    renderEngine->initGL(WindowsWidth, WindowsHeight);
    
};

void GKernel::startGameLoop() {
    glutMainLoop();
}

void GKernel::setRenderingEngine(GRenderingEngine *_renderEngine) {
    renderEngine = _renderEngine;
};

void GKernel::setInteractionEngine(GInteractionEngine *_interactionEngine) {
    interactionEngine = _interactionEngine;
}

void GKernel::drawScene() {
    GKernel *cur = getInstance();
    cur->renderEngine->drawScene(cur->activeScene);
};

void GKernel::processWorld() {
    GKernel *cur = getInstance();
    cur->interactionEngine->processWorld();
}

void GKernel::setActiveScene(GScene *scene) {
    activeScene = scene;
}