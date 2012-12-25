#include "GBasicInteractionEngine.h"

GBasicInteractionEngine::GBasicInteractionEngine() {
    eventList.resize(3);
    for (unsigned i = 0; i < 3; i++) {
        eventList[i] = new GActionNode();
        eventList[i]->nxt = eventList[i]->prev = NULL;
        eventList[i]->action = NULL;
    }
};

GEventID GBasicInteractionEngine::registerEvent() {
    int ret = eventList.size();
    eventList.resize(eventList.size() + 1);
    eventList[ret] = new GActionNode();
    eventList[ret]->nxt = eventList[ret]->prev = NULL;
    eventList[ret]->action = NULL;
    return ret;
};

void GBasicInteractionEngine::emitEvent(GEventID id, GEvent *eventData) {
    eventQueue.push( std::make_pair(id, eventData));
};

SubsID GBasicInteractionEngine::subscribeEvent(GEventID id, GAction *action) {
    if (id >= eventList.size()) return 0;
    GActionNode* newNode = new GActionNode();
    newNode->action = action;
    newNode->nxt = eventList[id]->nxt;    
    if (eventList[id]->nxt != NULL)
        eventList[id]->nxt->prev = newNode;    
    newNode->prev = eventList[id];
    eventList[id]->nxt = newNode;
    return (SubsID) newNode;
};

void GBasicInteractionEngine::unsubscribeEvent(SubsID subsID) {
    GActionNode *node = (GActionNode*) subsID;
    GActionNode *prev = node->prev;
    GActionNode *nxt = node->nxt;    
    if (prev != NULL) prev->nxt = nxt;
    if (nxt != NULL) nxt->prev = prev;
    delete node;
};

void GBasicInteractionEngine::processWorld() {    
    GActionNode *head = eventList[FrameEvent]->nxt;
    while (head != NULL) {
        head->action->doAction(NULL);
        std::cout<<"processing events"<<std::endl;
        head = head->nxt;
    }
};
