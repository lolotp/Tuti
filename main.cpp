#include <iostream>
using namespace std;

#include "GKernel.h"
#include "GAction.h"
#include "GBasicRenderingEngine.h"
#include "GBasicInteractionEngine.h"
#include "utils.h"

float val = 300;
class GMoveAction : public GAction {
    GObject* movingObj;
    float speed;
    float tx, ty;
public:
    GMoveAction(GObject *_movingObj, float _speed, float _tx, float _ty) : movingObj(_movingObj),
                                                                           speed(_speed),
                                                                           tx(_tx),
                                                                           ty(_ty){};
    void doAction(GEvent* eventData) {
        cout<<"here"<<endl;
        float curX = movingObj->xPos, curY = movingObj->yPos;
        movingObj->moveTo(curX + speed, curY + speed);
        if (curX > tx || curY > ty) speed = 0;
    };
};
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
    //obj->moveTo(80,80);
    //bRender->moveView(80,80);
    
    GMoveAction *act = new GMoveAction(obj, 0.1, 800,800);
    //bItr->subscribeEvent(1, act);
    k->startGameLoop();
    return 0;
}