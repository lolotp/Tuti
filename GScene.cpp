#include "GScene.h"
using namespace std;

GScene::GScene() {
};

GObjectID GScene::addObject(GObject *obj) {	
	int objLayer = obj->layer;
	int ret = objList.size();	
	objList.push_back(obj);
	if (objLayer >= objByLayer.size()) objByLayer.resize(objLayer + 1);
	objByLayer[ objLayer ].insert(ret);	
	return ret;
};
