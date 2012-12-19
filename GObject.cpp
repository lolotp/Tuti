#include "GObject.h"

GObject::GObject() : layer(0), xPos(0), yPos(0) {	
};

void GObject::moveTo(float newX, float newY) {
    for (int i = 0; i < napVert; i++) {
        apPolygon[(i<<1)] += (newX-xPos);
        apPolygon[(i<<1)+1] += (newY-yPos);
    }
    xPos = newX;
    yPos = newY;
}
