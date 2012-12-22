#include "GBasicInteractionEngine.h"

GBasicInteractionEngine::GBasicInteractionEngine() {
    eventList.resize(3);
};

GEventID GBasicInteractionEngine::registerEvent() {
    int ret = eventList.size();
    eventList.resize(eventList.size() + 1);
    return ret;
};

void GBasicInteractionEngine::emitEvent(GEventID id, GEvent *eventData) {
    eventQueue.push( make_pair(id, eventData));
};

void GBasicInteractionEngine::subscribeEvent(GEventID id, GAction *action) {
    if (id >= eventList.size()) return;
    eventList[id].push_back(action);    
};

void GBasicInteractionEngine::processWorld() {
    list<GAction*>::iterator it;
    list<GAction*> &frEventActions = eventList[FrameEvent];
    for (it = frEventActions.begin(); it != frEventActions.end(); it++) {
        (*it).doAction(NULL);
    }
};
