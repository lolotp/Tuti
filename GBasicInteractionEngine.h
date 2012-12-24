#ifndef __G_BASIC_INTERACTION_ENGINE__
#define __G_BASIC_INTERACTION_ENGINE__
#include "GInteractionEngine.h"
#include <queue>
#include <vector>

struct GActionNode {
    GAction *action;
    GActionNode *nxt, *prev;
};
//note, this implementation only works on 32-bit system
//unsure about 64-bit system
class GBasicInteractionEngine : public GInteractionEngine {
private:
    std::vector< GActionNode* > eventList;
    std::queue< std::pair<GEventID, GEvent *> > eventQueue;
public:
    GBasicInteractionEngine();    
    GEventID registerEvent() = 0;
    SubsID   subscribeEvent(GEventID, GAction *action);
    void     unsubscribeEvent(SubsID subsID);
    void     emitEvent(GEventID id, GEvent *eventData);
    void     processWorld();
};
#endif
