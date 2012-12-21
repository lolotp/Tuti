#ifndef __G_INTERACTION_ENGINE__
#define __G_INTERACTION_ENGINE__

#include "GEvent.h"
#include "GAction.h"

class GInteractionEngine {
public:
    virtual void subscribeEvent(GEvent* event, GAction *action) = 0;
};
#endif