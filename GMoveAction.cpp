#include "GMoveAction.h"
#include <cmath>

#define eps 1e-9

GMoveAction::GMoveAction(GObject *_movingObj, 
                         float _speed, 
                         float _tx, 
                         float _ty) : movingObj(_movingObj),
                                      speed(_speed),
                                      tx(_tx),
                                      ty(_ty), init(false) { 
                                      
    double dist = sqrt((tx - movingObj->xPos)*(tx - movingObj->xPos) + (ty - movingObj->yPos)*(ty - movingObj->yPos));
    double timeNeeded = dist / speed; //speed unit is pixels per second
    speedx = (tx - movingObj->xPos) / timeNeeded;
    speedy = (ty - movingObj->yPos) / timeNeeded;
};


void GMoveAction::doAction(GEvent *eventData) {
    if (!init) {
        init = true;
        curTime = clock();
    }else {
        double elapsed = (double)(clock() - curTime) / CLOCKS_PER_SEC;
        if (fabs(elapsed) < eps) return;
        curTime = clock();
        double distx = speedx * elapsed;
        double disty = speedy * elapsed;
        float curX = movingObj->xPos, curY = movingObj->yPos;
        //std::cout<<"info speedx"<<speedx<<" speedy:"<<speedy<<" elapsed:"<<elapsed<<std::endl;
        //std::cout<<curX + distx<<","<<curY + disty<<std::endl;
        if (fabs(curX + distx - tx) < 1 && fabs(curX + disty - ty) < 1) {            
            movingObj->moveTo(tx, ty);
            speedx = speedy = 0;
        }
        else 
            movingObj->moveTo(curX + distx, curY + disty);
    }
};