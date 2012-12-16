#include "GKernel.h"

float val = 0.5;
int main(int argc, char **argv) {
	float rect[] = {-val, val,
	                -val,-val,
					 val,-val,
					 val, val };
	GKernel *k = GKernel::getInstance();
	GScene *scene = new GScene();
	GObject *obj = new GObject();
	printf("layer : %d\n", obj->layer);
	scene->addObject(obj);
	obj->apPolygon = rect;
	obj->napVert = 4;
	k->setActiveScene(scene);
	k->initGameLoop(argc, argv);
	return 0;
}