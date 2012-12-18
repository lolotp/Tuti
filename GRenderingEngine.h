#ifndef __G_RENDERING_ENGINE__
#define __G_RENDERING_ENGINE__

#include "GScene.h"

class GRenderingEngine {
public:
	virtual void drawScene(GScene *scene) = 0;
	virtual void initGL(int width, int height) = 0;
	virtual void moveView(int newTop, int newLeft) = 0;
};
#endif