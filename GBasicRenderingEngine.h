#ifndef __G_BASIC_RENDERING_ENGINE__
#define __G_BASIC_RENDERING_ENGINE__

#include "GRenderingEngine.h"

class GBasicRenderingEngine : public GRenderingEngine {
private:
    int top, left;
    int width, height;
public:
    GBasicRenderingEngine();
    void drawScene(GScene *scene);
    void initGL(int width, int height);
    void moveView(int newTop, int newLeft);
};

#endif