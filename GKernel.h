#ifndef __GKERNEL__
#define __GKERNEL__

#include "GScene.h"
#include "GRenderingEngine.h"
class GKernel {
private:
    GScene* activeScene;
    GRenderingEngine *renderEngine;
    static void drawScene();
    static GKernel *instance;
    GKernel();
public:
    void startGameLoop();
    void initGameLoop(int argc, char **argv);
    void setActiveScene(GScene* scene);
    void setRenderingEngine(GRenderingEngine *renderEngine);
    static GKernel* getInstance();
};

#endif
