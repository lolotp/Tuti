#ifndef __G_BASIC_RENDERING_ENGINE__
#define __G_BASIC_RENDERING_ENGINE__

#include "GRenderingEngine.h"

class GBasicRenderingEngine : public GRenderingEngine {
public:
	void drawScene(GScene *scene);
	void initGL(int width, int height);
};

#endif