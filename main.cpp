#include <iostream>
using namespace std;

#include "GKernel.h"
#include "GMoveAction.h"
#include "GBasicRenderingEngine.h"
#include "GBasicInteractionEngine.h"
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
    GRenderingEngine *bRender = new GBasicRenderingEngine();
    GInteractionEngine *bItr = new GBasicInteractionEngine();
    k->setRenderingEngine(bRender);
    k->setInteractionEngine(bItr);
    printf("layer : %d\n", obj->layer);
    scene->addObject(obj);
    int width, height;
    
    
    obj->txCoord = texCoords;	
    obj->apPolygon = rect;
    obj->napVert = 4;
    k->setActiveScene(scene);
    k->initGameLoop(argc, argv);
    obj->txID = loadTextureFromPNG("test_texture.png",width,height);
    
    GMoveAction *act = new GMoveAction(obj, 100, 100,100);
    bItr->subscribeEvent(1, act);
    k->startGameLoop();
    return 0;
}