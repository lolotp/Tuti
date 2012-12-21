#ifndef __G_BASIC_INTERACTION_ENGINE__
#define __G_BASIC_INTERACTION_ENGINE__
#include "GInteractionEngine.h"


class GBasicInteractionEngine : public GInteractionEngine {
public:
    GBasicInteractionEngine();
    void subscribeEvent(GEvent* event, GAction *action);
    void processWorld();
};
#endif
