#ifndef __G_ACTION__
#define __G_ACTION__

#include "GEvent.h"

class GAction {
public:
    virtual void doAction(GEvent *eventData);
};

#endif
