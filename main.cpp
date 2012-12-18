#include "GKernel.h"
#include "GBasicRenderingEngine.h"
#include "utils.h"

float val = 300;
int main(int argc, char **argv) {
	float rect[] = { 0  , val,
	                 val, val,
					   0,   0,
					 val,   0 };
	float texCoords[] = {
        0.0, 1.0,
        1.0, 1.0,
        0.0, 0.0,
        1.0, 0.0
    };

	GKernel *k = GKernel::getInstance();
	GScene *scene = new GScene();
	GObject *obj = new GObject();
	GBasicRenderingEngine *bRender = new GBasicRenderingEngine();
	k->setRenderingEngine(bRender);
	printf("layer : %d\n", obj->layer);
	scene->addObject(obj);
	int width, height;
	
	
	obj->txCoord = texCoords;	
	obj->apPolygon = rect;
	obj->napVert = 4;
	k->setActiveScene(scene);
	k->initGameLoop(argc, argv);
	obj->txID = loadTextureFromPNG("test_texture.png",width,height);
	obj->moveTo(80,80);
	//bRender->moveView(80,80);
	k->startGameLoop();
	
	return 0;
}