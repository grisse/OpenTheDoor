#include "Scene03.h"

Scene03::Scene03(){}
Scene03::~Scene03(){}

void Scene03::GameMainLoop(float fTimeDelta){
	
}

void Scene03::MouseMove(const float fMouseX, const float fMouseY){
	tools.BiggerSprite(1,"checkpointBackButton",fMouseX,fMouseY);
}

void Scene03::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	if(dIsPointInSprite("checkpointBackButton",fMouseX,fMouseY)){
		dLoadMap("GameMainInterface.t2d");
		SceneState=0;
	}
}

void Scene03::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){}
void Scene03::KeyDown(const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress){}
void Scene03::KeyUp(const int iKey){}
void Scene03::SpriteColSprite(const char *szSrcName, const char *szTarName){}