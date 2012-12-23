#ifndef __G_INTERACTION_ENGINE__
#define __G_INTERACTION_ENGINE__

#include "GEvent.h"
#include "GAction.h"

typedef unsigned int GEventID;
typedef unsigned int SubsId; //SubscriptionID
class GInteractionEngine {
public:
    static const unsigned int ClickEvent = 0;
    static const unsigned int FrameEvent = 1;
    static const unsigned int KeyEvent   = 2;
    virtual GEventID registerEvent() = 0;
    virtual void     subscribeEvent(GEventID, GAction *action) = 0;
    virtual SubsID   emitEvent(GEventID id, GEvent *eventData) = 0;
    virtual void     unsubscribeEvent(SubsID subsID) = 0;
    virtual void     processWorld() = 0;
};
#endif
