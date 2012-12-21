#ifndef __GSCENE__
#define __GSCENE__

#include "TutiConstants.h"
#include "GObject.h"
#include <vector>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

#define hash_set std::tr1::unordered_set 
#define hash_map std::tr1::unordered_map 

typedef  unsigned int         GObjectID;
typedef  hash_set<GObjectID>  Layer;

//TODO: redesign GScene to improve efficiency of removing objects
class GScene {
private:
    std::vector< Layer > objByLayer;
    std::vector<GObject*> objList;
public:
    GScene();
    GObjectID addObject(GObject *obj);
    //removeObject
    friend class GBasicRenderingEngine;
};
#endif
