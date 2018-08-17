#include "Scene.h"
#include "LessonX.h"
#include "CommonAPI.h"
#include <Stdio.h>
#include "stdio.h"
#include "Scene0.h"
#include "Scene01.h"
#include "Scene1.h"

Scene::Scene() {}

Scene::~Scene() {}

void Scene::GameMainLoop(float fTimeDelta){}

void Scene::MouseMove(const float fMouseX, const float fMouseY){}

void Scene::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){}

void Scene::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){}

void Scene::KeyDown(const int iKey, const int bAltPress, const int bShiftPress, const int bCtrlPress){}

void Scene::KeyUp( const int iKey ){}

void Scene::SpriteColSprite(const char *szSrcName, const char *szTarName){}