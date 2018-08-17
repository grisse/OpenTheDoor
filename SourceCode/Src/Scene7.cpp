#include "Scene7.h"

Scene7::Scene7() {}

Scene7::~Scene7() {}

void Scene7::init(){
	clickSeventhBottle=0;
	clickSeventhMugun=0;
	clickSeventhGuanzi=0;
	clickSmallSeventhBottle=0;
	clickSmallSeventhMugun=0;
	clickSmallSeventhGuanzi=0;
	openSeventhMirrorYes=0;
	openSeventhToiletYes=0;
}


void Scene7::GameMainLoop(float fTimeDelta){
	tools.ShowItems(clickSeventhBottle,"seventhBottle","seventhBottle2","smallSeventhBottle",0,0,1);
	tools.ShowItems(clickSeventhMugun,"seventhMugun","smallSeventhMugun",0,1);
	tools.ShowItems(openSeventhMirrorYes,"smallSeventhMugun","seventhMirror",0,1);
	tools.ShowItems(clickSeventhGuanzi,"seventhGuanzi","smallSeventhGuanzi",0,1);
	tools.ShowItems(openSeventhToiletYes,"seventhTolinetGai","smallSeventhBottle",0,0);

}

void Scene7::MouseMove(const float fMouseX, const float fMouseY){
	tools.BiggerSprite(1,"seventhBackButton",fMouseX,fMouseY);

	if(tools.SpriteMoveTo(clickSmallSeventhBottle,"smallSeventhBottle","seventhTolinetGai",fMouseX,fMouseY,100000)){
		openSeventhToiletYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSeventhMugun,"smallSeventhMugun","seventhMirror",fMouseX,fMouseY,100000)){
		openSeventhMirrorYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSeventhGuanzi,"smallSeventhGuanzi","",fMouseX,fMouseY,100000)){
		//openSeventhMirrorYes=1;
	}

}

void Scene7::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=1;
	tools.ClickChangeScene("seventhBackButton","CheckpointSeventh_one.t2d",fMouseX,fMouseY);

	tools.ClickChangeScene("clickareaSeventhBathtub","CheckpointSeventh_twoBathtub.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSeventhCabinet","CheckpointSeventh_threeCabinet.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSeventhToilet","CheckpointSeventh_fourToilet.t2d",fMouseX,fMouseY);


	if(dIsPointInSprite("seventhBottle",fMouseX,fMouseY)){
		clickSeventhBottle=1;
	}
	if(dIsPointInSprite("seventhMugun",fMouseX,fMouseY)){
		clickSeventhMugun=1;
	}
	if(!dIsSpriteVisible("seventhTolinetGai") && dIsPointInSprite("seventhGuanzi",fMouseX,fMouseY)){
		clickSeventhGuanzi=1;
	}
	if(dIsSpriteVisible("smallSeventhBottle") && dIsPointInSprite("smallSeventhBottle",fMouseX,fMouseY)){
		clickSmallSeventhBottle=1;
	}
	if(dIsSpriteVisible("smallSeventhMugun") && dIsPointInSprite("smallSeventhMugun",fMouseX,fMouseY)){
		clickSmallSeventhMugun=1;
	}
	if(dIsSpriteVisible("smallSeventhGuanzi") && dIsPointInSprite("smallSeventhGuanzi",fMouseX,fMouseY)){
		clickSmallSeventhGuanzi=1;
	}

}

void Scene7::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;
	tools.SpriteReturnItembar(clickSmallSeventhBottle,"smallSeventhBottle",-50.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSeventhMugun,"smallSeventhMugun",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSeventhGuanzi,"smallSeventhGuanzi",-50.5f,41.f,1000.f);
	
}

void Scene7::KeyDown(const int iKey, const int bAltPress, const int bShiftPress, const int bCtrlPress){}

void Scene7::KeyUp( const int iKey ){}

void Scene7::SpriteColSprite(const char *szSrcName, const char *szTarName){}