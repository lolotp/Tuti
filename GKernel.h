#ifndef __GKERNEL__
#define __GKERNEL__

#include "GScene.h"
#include "GRenderingEngine.h"
#include "GInteractionEngine.h"
class GKernel {
private:
    GScene* activeScene;
    GRenderingEngine *renderEngine;
    GInteractionEngine *interactionEngine;
    static void drawScene();
    static void processWorld();
    static GKernel *instance;
    GKernel();
public:
    void startGameLoop();
    void initGameLoop(int argc, char **argv);
    void setActiveScene(GScene* scene);
    void setRenderingEngine(GRenderingEngine *renderEngine);
    void setInteractionEngine(GInteractionEngine *interactionEngine);
    static GKernel* getInstance();
};

#endif
