#include "GBasicInteractionEngine.h"

GBasicInteractionEngine::GBasicInteractionEngine() {
    eventList.resize(3);
};

GEventID GBasicInteractionEngine::registerEvent() {
    int ret = eventList.size();
    eventList.resize(eventList.size() + 1);
    eventList[ret] = NULL;
    return ret;
};

void GBasicInteractionEngine::emitEvent(GEventID id, GEvent *eventData) {
    eventQueue.push( std::make_pair(id, eventData));
};

SubsID GBasicInteractionEngine::subscribeEvent(GEventID id, GAction *action) {
    if (id >= eventList.size()) return 0;
    GActionNode* newNode = new GActionNode();
    newNode->action = action;
    if (eventList[id] != NULL)
        eventList[id]->prev = newNode;
    newNode->nxt  = eventList[id];
    newNode->prev = NULL;
    eventList[id] = newNode;
    return (SubsID) newNode;
};

void GBasicInteractionEngine::unsubscribeEvent(SubsID subsID) {
    GActionNode *node = (GActionNode*) subsID;
    GActionNode *prev = node->prev;
    GActionNode *nxt = node->nxt;
    for (unsigned i = 0; i < eventList.size(); i++) {
        if (eventList[i] == node) eventList[i] = nxt;
    }
    if (prev != NULL) prev->nxt = nxt;
    if (nxt != NULL) nxt->prev = prev;
    delete node;
};

void GBasicInteractionEngine::processWorld() {    
    GActionNode *head = eventList[FrameEvent];
    while (head != NULL) {
        head->action->doAction(NULL);
        std::cout<<"processing events"<<std::endl;
        head = head->nxt;
    }
};
