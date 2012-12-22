#ifndef __G_BASIC_INTERACTION_ENGINE__
#define __G_BASIC_INTERACTION_ENGINE__
#include "GInteractionEngine.h"
#include <queue>

class GBasicInteractionEngine : public GInteractionEngine {
private:
    vector< list<GAction*> > eventList;
    std::queue< pair<GEventID, GEvent *eventData> > eventQueue;
public:
    GBasicInteractionEngine();    
    GEventID registerEvent() = 0;
    void     subscribeEvent(GEventID, GAction *action) = 0;
    void     emitEvent(GEventID id, GEvent *eventData) = 0;
    void     processWorld();
};
#endif
