#ifndef __G_MOVE_ACTION__
#define __G_MOVE_ACTION__

#include <ctime>
#include "GObject.h"

#include "GAction.h"
class GMoveAction : public GAction {
    GObject* movingObj;
    float speed;
    float tx, ty;
    clock_t curTime;
    bool init;
    double speedx,speedy;
public:
    GMoveAction(GObject *_movingObj, float _speed, float _tx, float _ty);
    void doAction(GEvent* eventData);
};

#endif