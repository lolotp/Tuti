#ifndef __GOBJECT__
#define __GOBJECT__

#include "TutiConstants.h"

class GObject {
public:
    GObject();
    
    //appearance polygon
    float *apPolygon; ///arrays of points in appearance polygon (will just be a rectangle most of the time)
    int    napVert;   ///number of points in appearance polygon
    
    //collision polygon
    float *clPolygon; ///arrays of points in collision polygon (first iteration: just rectangle)
    int   nclVert;    ///number of points in collision polygon
    
    //texture coordinates
    float *txCoord;    ///coordinates of the texture	
    unsigned int txID; ///ID of the texture that is going to be used
    
    //object's position
    int layer;
    float xPos, yPos;
    
    void moveTo(float newX, float newY);
};
#endif
