#ifndef __G_BASIC_INTERACTION_ENGINE__
#define __G_BASIC_INTERACTION_ENGINE__
#include "GInteractionEngine.h"
#include <queue>

struct GActionNode {
    GAction *action;
    GAction *nxt, *prev;
};
//note, this implementation only works on 32-bit system
//unsure about 64-bit system
class GBasicInteractionEngine : public GInteractionEngine {
private:
    vector< GActionNode* > eventList;
    std::queue< pair<GEventID, GEvent *eventData> > eventQueue;
public:
    GBasicInteractionEngine();    
    GEventID registerEvent() = 0;
    SubsID   subscribeEvent(GEventID, GAction *action);
    void     unsubscribeEvent(SubsID subsID);
    void     emitEvent(GEventID id, GEvent *eventData);
    void     processWorld();
};
#endif
