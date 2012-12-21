#ifndef __G_BASIC_INTERACTION_ENGINE__
#define __G_BASIC_INTERACTION_ENGINE__
class GBasicInteractionEngine : public GBasicInteractionEngine {
public:
    GBasicInteractionEngine();
    void subscribeEvent(GEvent* event, GAction *action);
    void processWorld();
};
#endif
